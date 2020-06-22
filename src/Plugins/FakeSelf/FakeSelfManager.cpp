#include "FakeSelfManager.hpp"
#include <Utils/_Syscall.hpp>
#include <Utils/Kernel.hpp>
#include <Utils/Kdlsym.hpp>
#include <Utils/Logger.hpp>

#include <Mira.hpp>
#include <Boot/Config.hpp>
#include <Plugins/PluginManager.hpp>

#include <OrbisOS/Utilities.hpp>

extern "C"
{
    #include <sys/sysent.h>
};

using namespace Mira::Plugins;

//SelfContext* FakeSelfManager::m_LastContext = nullptr;

const uint8_t FakeSelfManager::c_ExecAuthInfo[] =
{
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x20,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
	0x00, 0x40, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t FakeSelfManager::c_DynlibAuthInfo[] =
{
	0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x30, 0x00, 0x30,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00,
	0x00, 0x40, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

FakeSelfManager::FakeSelfManager()
{
    auto sv = (struct sysentvec*)kdlsym(self_orbis_sysvec);
	struct sysent* sysents = sv->sv_table;
	uint8_t* s_TrampolineA = reinterpret_cast<uint8_t*>(sysents[SYS___MAC_GET_PID].sy_call);
    uint8_t* s_TrampolineB = reinterpret_cast<uint8_t*>(sysents[SYS___MAC_GET_PROC].sy_call);
    uint8_t* s_TrampolineC = reinterpret_cast<uint8_t*>(sysents[SYS___MAC_SET_PROC].sy_call);
    uint8_t* s_TrampolineD = reinterpret_cast<uint8_t*>(sysents[SYS___MAC_GET_FD].sy_call);
    uint8_t* s_TrampolineE = reinterpret_cast<uint8_t*>(sysents[SYS___MAC_GET_FILE].sy_call);

    HookFunctionCall(s_TrampolineA, reinterpret_cast<void*>(OnSceSblAuthMgrVerifyHeader), kdlsym(sceSblAuthMgrVerifyHeader_hookA));
    HookFunctionCall(s_TrampolineB, reinterpret_cast<void*>(OnSceSblAuthMgrVerifyHeader), kdlsym(sceSblAuthMgrVerifyHeader_hookB));
    HookFunctionCall(s_TrampolineC, reinterpret_cast<void*>(OnSceSblAuthMgrIsLoadable2), kdlsym(sceSblAuthMgrIsLoadable2_hook));
    HookFunctionCall(s_TrampolineD, reinterpret_cast<void*>(SceSblAuthMgrSmLoadSelfBlock_Mailbox), kdlsym(sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook));
    HookFunctionCall(s_TrampolineE, reinterpret_cast<void*>(SceSblAuthMgrSmLoadSelfSegment_Mailbox), kdlsym(sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook));

    //m_SceSblServiceMailboxHook = new Utils::Hook(kdlsym(sceSblServiceMailbox), reinterpret_cast<void*>(OnSceSblServiceMailbox));
    //m_SceSblAuthMgrVerifyHeaderHook = new Utils::Hook(kdlsym(sceSblAuthMgrVerifyHeader), reinterpret_cast<void*>(OnSceSblAuthMgrVerifyHeader));
    //m_SceSblAuthMgrIsLoadable2Hook = new Utils::Hook(kdlsym(sceSblAuthMgrIsLoadable2), reinterpret_cast<void*>(OnSceSblAuthMgrIsLoadable2));
    //m_SceSblACMgrGetPathIdHook = new Utils::Hook(kdlsym(sceSblACMgrGetPathId), OnSceSblACMgrGetPathId);

    //m__SceSblAuthMgrSmLoadSelfBlockHook = new Utils::Hook(kdlsym(_sceSblAuthMgrSmLoadSelfBlock), reinterpret_cast<void*>(On_SceSblAuthMgrSmLoadSelfBlock));
    //m__SceSblAuthMgrSmLoadSelfSegmentHook = new Utils::Hook(kdlsym(_sceSblAuthMgrSmLoadSelfSegment), reinterpret_cast<void*>(On_SceSblAuthMgrSmLoadSelfSegment));
}

FakeSelfManager::~FakeSelfManager()
{
    /*if (m_SceSblServiceMailboxHook != nullptr)
    {
        (void)m_SceSblServiceMailboxHook->Disable();
        delete m_SceSblServiceMailboxHook;
        m_SceSblServiceMailboxHook = nullptr;
    }

    if (m_SceSblAuthMgrVerifyHeaderHook != nullptr)
    {
        (void)m_SceSblAuthMgrVerifyHeaderHook->Disable();
        delete m_SceSblAuthMgrVerifyHeaderHook;
        m_SceSblAuthMgrVerifyHeaderHook = nullptr;
    }

    if (m_SceSblAuthMgrIsLoadable2Hook != nullptr)
    {
        (void)m_SceSblAuthMgrIsLoadable2Hook->Disable();
        delete m_SceSblAuthMgrIsLoadable2Hook;
        m_SceSblAuthMgrIsLoadable2Hook = nullptr;
    }

    if (m__SceSblAuthMgrSmLoadSelfBlockHook != nullptr)
    {
        (void)m__SceSblAuthMgrSmLoadSelfBlockHook->Disable();
        delete m__SceSblAuthMgrSmLoadSelfBlockHook;
        m__SceSblAuthMgrSmLoadSelfBlockHook = nullptr;
    }

    if (m__SceSblAuthMgrSmLoadSelfSegmentHook!= nullptr)
    {
        (void)m__SceSblAuthMgrSmLoadSelfSegmentHook->Disable();
        delete m__SceSblAuthMgrSmLoadSelfSegmentHook;
        m__SceSblAuthMgrSmLoadSelfSegmentHook = nullptr;
    }*/
}

int FakeSelfManager::OnSceSblAuthMgrIsLoadable2(SelfContext* p_Context, SelfAuthInfo* p_OldAuthInfo, int32_t p_PathId, SelfAuthInfo* p_NewAuthInfo)
{
    auto sceSblAuthMgrIsLoadable2 = (int(*)(SelfContext* p_Context, SelfAuthInfo* p_OldAuthInfo, int32_t p_PathId, SelfAuthInfo* p_NewAuthInfo))kdlsym(sceSblAuthMgrIsLoadable2);

    if (p_Context == nullptr)
    {
        WriteLog(LL_Error, "invalid context");
        return sceSblAuthMgrIsLoadable2(p_Context, p_OldAuthInfo, p_PathId, p_NewAuthInfo);
    } 
    
    if (p_Context->format == SelfFormat::Elf || IsFakeSelf(p_Context))
    {
        WriteLog(LL_Debug, "building fake self information");
        return BuildFakeSelfAuthInfo(p_Context, p_OldAuthInfo, p_NewAuthInfo);
    }        
    else
        return sceSblAuthMgrIsLoadable2(p_Context, p_OldAuthInfo, p_PathId, p_NewAuthInfo);
}

/*int FakeSelfManager::OnSceSblServiceMailbox(uint32_t p_ServiceId, void* p_Request, void* p_Response)
{
    auto sceSblServiceMailbox = (int(*)(uint32_t p_ServiceId, void* p_Request, void* p_Response))kdlsym(sceSblServiceMailbox);

    auto s_Request = static_cast<MailboxMessage*>(p_Request);
    if (s_Request == nullptr)
    {
        WriteLog(LL_Error, "invalid request");
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    }

    // Only hook on the needed service id
    if (p_ServiceId != 0)
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    
    switch (s_Request->funcId)
    {
    case LoadSelfSegment:
        return SceSblAuthMgrSmLoadSelfSegment_Mailbox(p_ServiceId, p_Request, p_Response);
    case LoadSelfBlock:
        return SceSblAuthMgrSmLoadSelfBlock_Mailbox(p_ServiceId, p_Request, p_Response);
    default:
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    }
}*/

int FakeSelfManager::AuthSelfHeader(SelfContext* p_Context)
{    
    auto sceSblAuthMgrVerifyHeader = (int(*)(SelfContext* p_Context))kdlsym(sceSblAuthMgrVerifyHeader);

    bool s_IsUnsigned = p_Context->format == SelfFormat::Elf || IsFakeSelf(p_Context);
    if (s_IsUnsigned)
    {
        WriteLog(LL_Debug, "fixing unsigned");
        auto s_OldFormat = p_Context->format;
        auto s_OldTotalHeaderSize = p_Context->totalHeaderSize;

        // Get the mini-syscore.elf binary
        SelfHeader* s_Header = (SelfHeader*)kdlsym(mini_syscore_self_binary);

        auto s_NewTotalHeaderSize = s_Header->headerSize + s_Header->metaSize;

        // Allocate some memory to hold our header size
        auto s_Temp = new uint8_t[s_NewTotalHeaderSize];
        if (s_Temp == nullptr)
        {
            WriteLog(LL_Error, "could not allocate new total header size (%x).", s_NewTotalHeaderSize);
            return ENOMEM;
        }

        // Backup our current header
        memcpy(s_Temp, p_Context->header, s_NewTotalHeaderSize);

        // Copy over mini-syscore.elf's header
        memcpy(p_Context->header, s_Header, s_NewTotalHeaderSize);

        // Change the format
        p_Context->format = SelfFormat::Self;
        p_Context->totalHeaderSize = s_NewTotalHeaderSize;

        // xxx: call the original method using a real SELF file
        auto s_Result = sceSblAuthMgrVerifyHeader(p_Context);

        // Restore everything
        memcpy(p_Context->header, s_Temp, s_NewTotalHeaderSize);
        p_Context->format = s_OldFormat;
        p_Context->totalHeaderSize = s_OldTotalHeaderSize;

        delete [] s_Temp;

        return s_Result;
    }
    else
        return sceSblAuthMgrVerifyHeader(p_Context);
}

int FakeSelfManager::OnSceSblAuthMgrVerifyHeader(SelfContext* p_Context)
{
    auto _sceSblAuthMgrSmStart = (void(*)(void**))kdlsym(_sceSblAuthMgrSmStart);

    void* s_Temp = nullptr;
    _sceSblAuthMgrSmStart(&s_Temp);

    return AuthSelfHeader(p_Context);
}

SblMapListEntry* FakeSelfManager::SceSblDriverFindMappedPageListByGpuVa(vm_offset_t p_GpuVa)
{
    if (p_GpuVa == 0)
    {
        WriteLog(LL_Error, "invalid gpu va");
        return nullptr;
    }
    
    SblMapListEntry* s_Entry = *(SblMapListEntry**)kdlsym(gpu_va_page_list);
    while (s_Entry)
    {
        if (s_Entry->gpuVa == p_GpuVa)
            return s_Entry;
        s_Entry = s_Entry->next;
    }

    return nullptr;
}

vm_offset_t FakeSelfManager::SceSblDriverGpuVaToCpuVa(vm_offset_t p_GpuVa, size_t* p_NumPageGroups)
{
    SblMapListEntry* s_Entry = SceSblDriverFindMappedPageListByGpuVa(p_GpuVa);
    if (s_Entry == nullptr)
    {
        WriteLog(LL_Error, "invalid gpu va entry");
        return 0;
    }
    
    if (p_NumPageGroups != nullptr)
        *p_NumPageGroups = s_Entry->numPageGroups;
    
    return s_Entry->cpuVa;
}

bool FakeSelfManager::IsFakeSelf(SelfContext* p_Context)
{
    auto _sceSblAuthMgrGetSelfInfo = (int (*)(SelfContext* ctx, void *exInfo))kdlsym(_sceSblAuthMgrGetSelfInfo);
    if (p_Context == nullptr)
    {
        WriteLog(LL_Error, "invalid context");
        return false;
    }
    
    SelfExInfo* s_Info = nullptr;
    if (p_Context != nullptr && p_Context->format == SelfFormat::Self)
    {
        auto s_Ret = _sceSblAuthMgrGetSelfInfo(p_Context, &s_Info);  
        if (s_Ret)
            s_Ret = 0;
        
        WriteLog(LL_Debug, "ptype: (%d)", s_Info->ptype);
        return (int32_t)s_Info->ptype == SelfPtypeFake;
    }
    else
        return false;
}

int FakeSelfManager::SceSblAuthMgrGetElfHeader(SelfContext* p_Context, Elf64_Ehdr** p_OutElfHeader)
{
    if (p_Context == nullptr)
        return -EAGAIN;
    
    if (p_Context->format == SelfFormat::Elf)
    {
        WriteLog(LL_Debug, "elf format");
        auto s_ElfHeader = reinterpret_cast<Elf64_Ehdr*>(p_Context->header);
        if (s_ElfHeader != nullptr)
            *p_OutElfHeader = s_ElfHeader;
        
        return 0;
    }
    else if (p_Context->format == SelfFormat::Self)
    {
        WriteLog(LL_Debug, "self format");
        auto s_SelfHeader = reinterpret_cast<SelfHeader*>(p_Context->header);
        size_t s_PdataSize = s_SelfHeader->headerSize - sizeof(SelfEntry) * s_SelfHeader->numEntries - sizeof(SelfHeader);
        if (s_PdataSize >= sizeof(Elf64_Ehdr) && (s_PdataSize & 0xF) == 0)
        {
            auto s_ElfHeader = reinterpret_cast<Elf64_Ehdr*>((uint8_t*)s_SelfHeader + sizeof(SelfHeader) + sizeof(SelfEntry) * s_SelfHeader->numEntries);
            if (s_ElfHeader)
                *p_OutElfHeader = s_ElfHeader;
            
            return 0;
        }

        WriteLog(LL_Error, "-EALREADY");
        return -EALREADY;
    }

    WriteLog(LL_Error, "-EAGAIN");
    return -EAGAIN;
}

int FakeSelfManager::BuildFakeSelfAuthInfo(SelfContext* p_Context, SelfAuthInfo* p_ParentAuthInfo, SelfAuthInfo* p_AuthInfo)
{
    auto _sceSblAuthMgrGetSelfInfo = (int (*)(SelfContext* ctx, void *exInfo))kdlsym(_sceSblAuthMgrGetSelfInfo);

    if (p_Context == nullptr || p_ParentAuthInfo == nullptr || p_AuthInfo == nullptr)
    {
        WriteLog(LL_Error, "invalid context (%p) || parentAuthInfo (%p) || authInfo (%p)", p_Context, p_ParentAuthInfo, p_AuthInfo);
        return -EINVAL;
    }
    
    if (!IsFakeSelf(p_Context))
    {
        WriteLog(LL_Error, "not fake self");
        return -EINVAL;
    }

    SelfExInfo* s_ExInfo = nullptr;
    int32_t s_Result = _sceSblAuthMgrGetSelfInfo(p_Context, &s_ExInfo);
    if (s_Result)
    {
        WriteLog(LL_Error, "could not get self info (%d).", s_Result);
        return s_Result;
    }

    Elf64_Ehdr* s_ElfHeader = nullptr;
    s_Result = SceSblAuthMgrGetElfHeader(p_Context, &s_ElfHeader);
    if (s_Result)
    {
        WriteLog(LL_Error, "could not get elf header (%d).", s_Result);
        return s_Result;
    }

    if (s_ElfHeader == nullptr)
    {
        WriteLog(LL_Error, "elf header invalid");
        return -ESRCH;
    }
    
    SelfAuthInfo s_Info = { 0 };
    s_Result = SceSblAuthMgrGetSelfAuthInfoFake(p_Context, &s_Info);
    if (s_Result)
    {
        switch (s_ElfHeader->e_type)
        {
        case ET_EXEC:
        case ET_SCE_EXEC:
        case ET_SCE_EXEC_ASLR:
            memcpy(&s_Info, FakeSelfManager::c_ExecAuthInfo, sizeof(s_Info));
            s_Result = 0;
            break;
        case ET_SCE_DYNAMIC:
            memcpy(&s_Info, FakeSelfManager::c_DynlibAuthInfo, sizeof(s_Info));
            s_Result = 0;
            break;
        default:
            s_Result = ENOTSUP;
            return s_Result;
        }

        s_Info.paid = s_ExInfo->paid;
    }

    if (p_AuthInfo)
        memcpy(p_AuthInfo, &s_Info, sizeof(*p_AuthInfo));

    return s_Result;
}

int FakeSelfManager::SceSblAuthMgrGetSelfAuthInfoFake(SelfContext* p_Context, SelfAuthInfo* p_Info)
{
    if (p_Context == nullptr)
    {
        WriteLog(LL_Error, "invalid context");
        return -EAGAIN;
    }
    
    if (p_Context->format == SelfFormat::Elf)
    {
        WriteLog(LL_Error, "invalid format");
        return -EAGAIN;
    }
    
    SelfHeader* s_Header = reinterpret_cast<SelfHeader*>(p_Context->header);
    SelfFakeAuthInfo* s_FakeInfo = reinterpret_cast<SelfFakeAuthInfo*>(p_Context->header + s_Header->headerSize + s_Header->metaSize - 0x100);

    if (s_FakeInfo->size == sizeof(s_FakeInfo->info))
    {
        memcpy(p_Info, &s_FakeInfo->info, sizeof(*p_Info));
        return 0;
    }

    WriteLog(LL_Error, "ealready");
    return -EALREADY;
}

int FakeSelfManager::SceSblAuthMgrSmLoadSelfBlock_Mailbox(uint32_t p_ServiceId, void* p_Request, void* p_Response)
{
    auto sceSblServiceMailbox = (int(*)(uint32_t p_ServiceId, void* p_Request, void* p_Response))kdlsym(sceSblServiceMailbox);   
#if MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_405 || MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_455 || MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_474
	register SelfContext* s_Context = nullptr ("r14");
#elif MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_501 || MIRA_PLATFORM >= MIRA_PLATFORM_ORBIS_BSD_503 || MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_505 || MIRA_PLATFORM >= MIRA_PLATFORM_ORBIS_BSD_620 || MIRA_PLATFORM >= MIRA_PLATFORM_ORBIS_BSD_650
	uint8_t* frame = (uint8_t*)__builtin_frame_address(1);
	SelfContext* s_Context = *(SelfContext**)(frame - 0x1C8);
#elif MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_555
	uint8_t* frame = (uint8_t*)__builtin_frame_address(1);
	SelfContext* s_Context = *(SelfContext**)(frame - 0x1B8);
#endif	

    auto s_RequestMessage = static_cast<MailboxMessage*>(p_Request);
    if (s_RequestMessage == nullptr)
    {
        WriteLog(LL_Error, "invalid request message");
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    }
    
    // Disgusting hack, we hook the caller of this, save the context, then continue as normal
    // Then we pick up the context later
    //SelfContext* s_Context = FakeSelfManager::m_LastContext;
    // Check our context
    if (s_Context == nullptr)
    {
        WriteLog(LL_Error, "could not load self BLOCK, could not get the self context");
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    }

    bool s_IsUnsigned = s_Context->format == SelfFormat::Elf;
    if (!s_IsUnsigned)
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);

    WriteLog(LL_Error, "unsigned/fake (s)elf detected");

    // TODO: Remove after testing
    auto s_Test1 = *(uint32_t*)&s_RequestMessage->unk08;
    auto s_Test2 = s_RequestMessage->unk08;
    if (s_Test1 != s_Test2)
        WriteLog(LL_Error, "test1 != test2");
    
    // Do these ever change?
    vm_offset_t s_SegmentDataGpuVa = *(uint32_t*)&s_RequestMessage->unk08;
    vm_offset_t s_CurrentDataGpuVa = *(uint32_t*)(((uint8_t*)p_Response) + 0x50);
    vm_offset_t s_CurrentData2GpuVa = *(uint32_t*)(((uint8_t*)p_Response) + 0x58);
    
    uint32_t s_DataOffset = *(uint32_t*)(((uint8_t*)p_Response) + 0x44);
    uint32_t s_DataSize = *(uint32_t*)(((uint8_t*)p_Response) + 0x48);

    vm_offset_t s_SegmentDataCpuVa = SceSblDriverGpuVaToCpuVa(s_SegmentDataGpuVa, nullptr);
    vm_offset_t s_CurrentDataCpuVa = SceSblDriverGpuVaToCpuVa(s_CurrentDataGpuVa, nullptr);
    vm_offset_t s_CurrentData2CpuVa = s_CurrentData2GpuVa ? SceSblDriverGpuVaToCpuVa(s_CurrentData2GpuVa, nullptr) : 0;

    if (s_SegmentDataCpuVa && s_CurrentDataCpuVa)
    {
        if (s_CurrentData2GpuVa && s_CurrentData2GpuVa != s_CurrentDataGpuVa && s_DataOffset > 0)
        {
            // xxx: data spans two consecutive memory's pages, so we need to copy twice
            uint32_t s_Size1 = PAGE_SIZE - s_DataOffset;
            memcpy((uint8_t*)s_SegmentDataCpuVa, (const uint8_t*)s_CurrentDataCpuVa, s_Size1);

            // PATCH: Prevent *potential* kpanic here
            if (s_CurrentData2CpuVa != 0)
                memcpy((uint8_t*)s_SegmentDataCpuVa + s_Size1, (const uint8_t*)s_CurrentData2CpuVa, s_DataSize - s_Size1);
        }
        else
            memcpy((uint8_t*)s_SegmentDataCpuVa, (const uint8_t*)s_CurrentDataCpuVa + s_DataOffset, s_DataSize);
    }

    s_RequestMessage->retVal = 0;
    return 0;
}

int FakeSelfManager::SceSblAuthMgrSmLoadSelfSegment_Mailbox(uint32_t p_ServiceId, void* p_Request, void* p_Response)
{
    auto sceSblServiceMailbox = (int(*)(uint32_t p_ServiceId, void* p_Request, void* p_Response))kdlsym(sceSblServiceMailbox);   
#if MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_455 || MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_474
	uint8_t* frame = (uint8_t*)__builtin_frame_address(1);
	SelfContext* s_Context = *(SelfContext**)(frame - 0x100);
#elif MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_501 || MIRA_PLATFORM >= MIRA_PLATFORM_ORBIS_BSD_503 || MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_505
  uint8_t* frame = (uint8_t*)__builtin_frame_address(1);
	SelfContext* s_Context = *(SelfContext**)(frame - 0x100);
#elif MIRA_PLATFORM == MIRA_PLATFORM_ORBIS_BSD_555 || MIRA_PLATFORM >= MIRA_PLATFORM_ORBIS_BSD_620 || MIRA_PLATFORM >= MIRA_PLATFORM_ORBIS_BSD_650
   uint8_t* frame = (uint8_t*)__builtin_frame_address(1);
   SelfContext* s_Context = *(SelfContext**)(frame - 0x100);
#endif

    auto s_RequestMessage = static_cast<MailboxMessage*>(p_Request);
    if (s_RequestMessage == nullptr)
    {
        WriteLog(LL_Error, "invalid response");
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    }
    
    //SelfContext* s_Context = FakeSelfManager::m_LastContext;
    if (s_Context == nullptr)
    {
        WriteLog(LL_Error, "could not load segment, could not get self context.");
        return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
    }

    bool s_IsUnsigned = s_Context && IsFakeSelf(s_Context);
    if (s_IsUnsigned)
    {
        WriteLog(LL_Debug, "unsigned/fake (s)elf detected clearing ret val");
        s_RequestMessage->retVal = 0;
        return 0;
    }
    
    return sceSblServiceMailbox(p_ServiceId, p_Request, p_Response);
}

bool FakeSelfManager::OnLoad()
{
    // Clear out any stale contexts
    //m_LastContext = nullptr;

    /*if (m_SceSblAuthMgrIsLoadable2Hook != nullptr)
        (void)m_SceSblAuthMgrIsLoadable2Hook->Enable();
    
    if (m_SceSblAuthMgrVerifyHeaderHook != nullptr)
        (void)m_SceSblAuthMgrVerifyHeaderHook->Enable();
    
    if (m_SceSblServiceMailboxHook != nullptr)
        (void)m_SceSblServiceMailboxHook->Enable();

    if (m__SceSblAuthMgrSmLoadSelfBlockHook != nullptr)
        (void)m__SceSblAuthMgrSmLoadSelfBlockHook->Enable();
    
    if (m__SceSblAuthMgrSmLoadSelfSegmentHook != nullptr)
        (void)m__SceSblAuthMgrSmLoadSelfSegmentHook->Enable();*/
    
    WriteLog(LL_Debug, "FakeSelfManager loaded...");
    return true;
}

bool FakeSelfManager::OnUnload()
{
    /*if (m_SceSblAuthMgrIsLoadable2Hook != nullptr)
        (void)m_SceSblAuthMgrIsLoadable2Hook->Disable();
    
    if (m_SceSblAuthMgrVerifyHeaderHook != nullptr)
        (void)m_SceSblAuthMgrVerifyHeaderHook->Disable();
    
    if (m_SceSblServiceMailboxHook != nullptr)
        (void)m_SceSblServiceMailboxHook->Disable();

    if (m__SceSblAuthMgrSmLoadSelfBlockHook != nullptr)
        (void)m__SceSblAuthMgrSmLoadSelfBlockHook->Disable();
    
    if (m__SceSblAuthMgrSmLoadSelfSegmentHook != nullptr)
        (void)m__SceSblAuthMgrSmLoadSelfSegmentHook->Disable();
    
    // Clear out any stale contexts
    m_LastContext = nullptr;*/
    
    WriteLog(LL_Debug, "FakeSelfManager unloaded...");
    return true;
}

bool FakeSelfManager::OnSuspend()
{
    // Don't touch the hooks here, leave them in-tact
    return true;
}

bool FakeSelfManager::OnResume()
{
    // Don't touch the hooks here, leave them in-tact
    return true;
}

// Credits: m0rph
void FakeSelfManager::HookFunctionCall(uint8_t* p_HookTrampoline, void* p_Function, void* p_Address)
{
    uint8_t* s_HookPayload = p_HookTrampoline;
    uint16_t* s_TempAddress = reinterpret_cast<uint16_t*>(p_HookTrampoline);
    s_TempAddress++;

    uint64_t* s_FunctionAddress = reinterpret_cast<uint64_t*>(s_TempAddress);

    cpu_disable_wp();

    // mov rax
    s_HookPayload[0] = 0x48;
    s_HookPayload[1] = 0xB8;

    *s_FunctionAddress = reinterpret_cast<uint64_t>(p_Function);

    s_HookPayload[0x0A] = 0xFF;
    s_HookPayload[0x0B] = 0xE0;

    int32_t s_CallAddress = (int32_t)(p_HookTrampoline - (uint8_t*)p_Address) - 5;
    s_HookPayload = reinterpret_cast<uint8_t*>(p_Address);
    s_HookPayload++;
    int32_t* s_Pointer = reinterpret_cast<int32_t*>(s_HookPayload);
    *s_Pointer = s_CallAddress;

    cpu_enable_wp();
}
