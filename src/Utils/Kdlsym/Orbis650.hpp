#pragma once
#include <Boot/Config.hpp>

#if MIRA_PLATFORM==MIRA_PLATFORM_ORBIS_BSD_650
/*
These are the required functions in order for the Oni Framework to operate properly
These are all offsets into the base of the kernel. They expect all standard FreeBSD 9 prototypes

The reason we do not hardcode offsets here, is due to the different platforms that are supported, and
for the platforms that do enable kernel ASLR (Address Space Layout Randomization?)
*/

#define kdlsym_addr__mtx_lock_flags                        0x00401840
#define kdlsym_addr__mtx_lock_sleep                        0x00401B30
#define kdlsym_addr__mtx_lock_spin_flags                   0x00402380
#define kdlsym_addr__mtx_unlock_flags                      0x00402830
#define kdlsym_addr__mtx_unlock_sleep                      0x00402AD0
#define kdlsym_addr__mtx_unlock_spin_flags                 0x00402B40 
#define kdlsym_addr__sceSblAuthMgrGetSelfInfo              0x0065CC70
#define kdlsym_addr__sceSblAuthMgrSmStart                  0x0065CCBE
#define kdlsym_addr__sx_init_flags                         0x0
#define kdlsym_addr__sx_slock                              0x000F6150 
#define kdlsym_addr__sx_sunlock                            0x000F8AB0
#define kdlsym_addr__sx_xlock                              0x000F7AD0
#define kdlsym_addr__sx_xunlock                            0x000F8C90 
#define kdlsym_addr__thread_lock_flags                     0x00402830
#define kdlsym_addr__vm_map_lock_read                      0x00296D60
#define kdlsym_addr__vm_map_unlock_read                    0x00296D87
#define kdlsym_addr_AesCbcCfb128Decrypt                    0x003A3CC0
#define kdlsym_addr_AesCbcCfb128Encrypt                    0x003A2CA0
#define kdlsym_addr_allproc                                0x0
#define kdlsym_addr_allproc_lock                           0x0
#define kdlsym_addr_avcontrol_sleep                        0x006FF700
#define kdlsym_addr_cloneuio                               0x002A8390
#define kdlsym_addr_console_cdev                           0x022C0CD8
#define kdlsym_addr_console_write                          0x000ECB60
#define kdlsym_addr_contigfree                             0x000F2700
#define kdlsym_addr_contigmalloc                           0x000F0F70
#define kdlsym_addr_copyin                                 0x001EA7B0 
#define kdlsym_addr_copyinstr                              0x001EA900
#define kdlsym_addr_copyout                                0x001EA060
#define kdlsym_addr_critical_enter                         0x0028FB19
#define kdlsym_addr_critical_exit                          0x0028FB38
#define kdlsym_addr_deci_tty_write                         0x0
#define kdlsym_addr_destroy_dev                            0x0
#define kdlsym_addr_dmem_start_app_process                 0x0
#define kdlsym_addr_dynlib_do_dlsym                        0x0
#define kdlsym_addr_dynlib_find_obj_by_handle              0x0
#define kdlsym_addr_eventhandler_deregister                0x0
#define kdlsym_addr_eventhandler_find_list                 0x0
#define kdlsym_addr_eventhandler_register                  0x0
#define kdlsym_addr_exec_new_vmspace                       0x0
#define kdlsym_addr_faultin                                0x0
#define kdlsym_addr_fget_unlocked                          0x0
#define kdlsym_addr_fpu_kern_ctx                           0x0
#define kdlsym_addr_fpu_kern_enter                         0x0
#define kdlsym_addr_fpu_kern_leave                         0x0
#define kdlsym_addr_free                                   0x0
#define kdlsym_addr_gdt                                    0x0
#define kdlsym_addr_gpu_va_page_list                       0x0
#define kdlsym_addr_icc_nvs_read                           0x0
#define kdlsym_addr_kern_close                             0x0
#define kdlsym_addr_kern_ioctl                             0x0
#define kdlsym_addr_kern_mkdirat                           0x0
#define kdlsym_addr_kern_open                              0x0
#define kdlsym_addr_kern_openat                            0x0
#define kdlsym_addr_kern_readv                             0x0
#define kdlsym_addr_kern_reboot                            0x0
#define kdlsym_addr_kern_sysents                           0x0
#define kdlsym_addr_kern_thr_create                        0x0
#define kdlsym_addr_kernel_map                             0x0
#define kdlsym_addr_kernel_mount                           0x0
#define kdlsym_addr_killproc                               0x0
#define kdlsym_addr_kmem_alloc                             0x0
#define kdlsym_addr_kmem_free                              0x0
#define kdlsym_addr_kproc_create                           0x0
#define kdlsym_addr_kproc_exit                             0x0
#define kdlsym_addr_kthread_add                            0x0
#define kdlsym_addr_kthread_exit                           0x0
#define kdlsym_addr_M_IOV                                  0x0
#define kdlsym_addr_M_LINKER                               0x0
#define kdlsym_addr_M_MOUNT                                0x0
#define kdlsym_addr_M_TEMP                                 0x0
#define kdlsym_addr_make_dev_p                             0x0
#define kdlsym_addr_malloc                                 0x0010E250 //	FFFFFFFF8220D7A0
#define kdlsym_addr_memcmp                                 0x00050AC0 //	FFFFFFFF82407A90
#define kdlsym_addr_memcpy                                 0x001EA530 //	FFFFFFFF825C1200
#define kdlsym_addr_memmove                                0x0
#define kdlsym_addr_memset                                 0x003205C0	
#define kdlsym_addr_mini_syscore_self_binary               0x014C9D48	
#define kdlsym_addr_mount_arg                              0x0
#define kdlsym_addr_mount_argb                             0x0
#define kdlsym_addr_mount_argf                             0x0
#define kdlsym_addr_mtx_destroy                            0x0
#define kdlsym_addr_mtx_init                               0x00402780 //	FFFFFFFF82696C30
#define kdlsym_addr_mtx_lock_sleep                         0x00401D70 //	FFFFFFFF82696230
#define kdlsym_addr_mtx_unlock_sleep                       0x004020A0 //	FFFFFFFF82696560
#define kdlsym_addr_name_to_nids                           0x0
#define kdlsym_addr_pause                                  0x0
#define kdlsym_addr_pfind                                  0x004034E0 //	FFFFFFFF8253D8E0
#define kdlsym_addr_pmap_activate                          0x002EAFD0 //	FFFFFFFF8225A280
#define kdlsym_addr_printf                                 0x00436040 //	FFFFFFFF82322ED0
#define kdlsym_addr_prison0                                0x010986A0 //	FFFFFFFF8333D4F8
#define kdlsym_addr_proc0                                  0x01AA4600 //	FFFFFFFF844BFA40
#define kdlsym_addr_proc_reparent                          0x00035330 //	FFFFFFFF82606340
#define kdlsym_addr_proc_rwmem                             0x0030D150 //	FFFFFFFF8230EA60
#define kdlsym_addr_realloc                                0x0010E590 //	FFFFFFFF8220DAD0
#define kdlsym_addr_rootvnode                              0x022C1A70 //	FFFFFFFF84500320
#define kdlsym_addr_RsaesPkcs1v15Dec2048CRT                0x001FD7D0 //	?? can't backtrace to it on 650
#define kdlsym_addr_sbl_eap_internal_partition_key         0x02790C90 //	FFFFFFFF848DCCD0
#define kdlsym_addr_sbl_keymgr_buf_gva                     0x0
#define kdlsym_addr_sbl_keymgr_buf_va                      0x0
#define kdlsym_addr_sbl_keymgr_key_rbtree                  0x0
#define kdlsym_addr_sbl_keymgr_key_slots                   0x0
#define kdlsym_addr_sbl_pfs_sx                             0x0271E5D8 //	FFFFFFFF84879040
#define kdlsym_addr_sbl_drv_msg_mtx                        0x0
#define kdlsym_addr_sceSblACMgrGetPathId                   0x0
#define kdlsym_addr_sceSblAuthMgrIsLoadable2               0x0063C4F0 //	FFFFFFFF8285C400
#define kdlsym_addr_sceSblAuthMgrSmStart                   0x006418E0 //	FFFFFFFF8285D0F0
#define kdlsym_addr_sceSblAuthMgrSmVerifyHeader            0x00642B40 //	FFFFFFFF8285EC50
#define kdlsym_addr_sceSblAuthMgrVerifyHeader              0x0063C550 //	FFFFFFFF8285C460
#define kdlsym_addr_sceSblDriverSendMsg                    0x0061D7F0 //	FFFFFFFF82837720 sceSblDriverSendMsg
#define kdlsym_addr_sceSblGetEAPInternalPartitionKey       0x006256E0 //	FFFFFFFF8283F190
#define kdlsym_addr_sceSblKeymgrClearKey                   0x0062DB10 //	FFFFFFFF828497C0
#define kdlsym_addr_sceSblKeymgrSetKeyForPfs               0x0062D780 //	FFFFFFFF82849440
#define kdlsym_addr_sceSblKeymgrSetKeyStorage              0x0
#define kdlsym_addr_sceSblKeymgrSmCallfunc                 0x0062E2A0 //	FFFFFFFF82849010
#define kdlsym_addr_sceSblPfsSetKeys                       0x0061EFA0 //	FFFFFFFF82841160
#define kdlsym_addr_sceSblRngGetRandomNumber               0x0
#define kdlsym_addr_sceSblServiceMailbox                   0x00632540 //	FFFFFFFF8284C860
#define kdlsym_addr_sceSblACMgrGetPathId                   0x0
#define kdlsym_addr_self_orbis_sysvec                      0x019BBCD0
#define kdlsym_addr_Sha256Hmac                             0x002D55B0 //	FFFFFFFF825357C0
#define kdlsym_addr_snprintf                               0x00436350 //	FFFFFFFF823231E0
#define kdlsym_addr_spinlock_exit                          0x0
#define kdlsym_addr_sprintf                                0x0
#define kdlsym_addr_sscanf                                 0x00175900 //	FFFFFFFF82443460
#define kdlsym_addr_strcmp                                 0x001D0FD0 //	FFFFFFFF82541460
#define kdlsym_addr_strdup                                 0x001C1C30 //	FFFFFFFF82450110
#define kdlsym_addr_strlen                                 0x003B71A0 //	FFFFFFFF82443030
#define kdlsym_addr_strncmp                                0x0
#define kdlsym_addr_strstr                                 0x0017DFB0 //	FFFFFFFF82681440
#define kdlsym_addr_sys_accept                             0x0031A170 //	FFFFFFFF823C6190
#define kdlsym_addr_sys_bind                               0x00319820 //	FFFFFFFF823C5820
#define kdlsym_addr_sys_close                              0x000C0EB0 //	FFFFFFFF82449040
#define kdlsym_addr_sys_dup2                               0x000BF050 //	FFFFFFFF82447220
#define kdlsym_addr_sys_fstat                              0x000C1430 //	FFFFFFFF824495E0
#define kdlsym_addr_sys_getdents                           0x00341390 //	FFFFFFFF826A3ED0
#define kdlsym_addr_sys_kill                               0x000D19D0 //	FFFFFFFF8222B5C0
#define kdlsym_addr_sys_listen                             0x00319A60 //	FFFFFFFF823C5A60
#define kdlsym_addr_sys_lseek                              0x0033D9F0 //	FFFFFFFF826A05A0
#define kdlsym_addr_sys_mkdir                              0x00340B50 //	FFFFFFFF826A36B0
#define kdlsym_addr_sys_mlock                              0x0013E250 //	FFFFFFFF822AC1E0
#define kdlsym_addr_sys_mlockall                           0x0013E300 //	FFFFFFFF822AC290
#define kdlsym_addr_sys_mmap                               0x0013D230 //	FFFFFFFF822AB1A0
#define kdlsym_addr_sys_munmap                             0x0013D9A0 //	FFFFFFFF822AB8F0
#define kdlsym_addr_sys_nmount                             0x001DE2E0 //	FFFFFFFF822AB8F0
#define kdlsym_addr_sys_open                               0x0033B990 //	FFFFFFFF8269E5C0
#define kdlsym_addr_sys_ptrace                             0x0030D5E0 //	FFFFFFFF8230F100
#define kdlsym_addr_sys_read                               0x00152AB0 //	FFFFFFFF8259B370
#define kdlsym_addr_sys_recvfrom                           0x0031B460 //	FFFFFFFF823C7430
#define kdlsym_addr_sys_rmdir                              0x00340ED0 //	FFFFFFFF826A3A30
#define kdlsym_addr_sys_sendto                             0x0031AD10 //	FFFFFFFF823C6D00
#define kdlsym_addr_sys_setuid                             0x00054950 //	FFFFFFFF8230BA00
#define kdlsym_addr_sys_shutdown                           0x0031B6A0 //	FFFFFFFF823C7680
#define kdlsym_addr_sys_socket                             0x00318EE0 //	FFFFFFFF823C4F00
#define kdlsym_addr_sys_stat                               0x0033DFE0 //	FFFFFFFF826A0B80
#define kdlsym_addr_sys_unlink                             0x0033D3D0 //	FFFFFFFF8269FF60
#define kdlsym_addr_sys_unmount                            0x001DFC70 //	FFFFFFFF82640F20
#define kdlsym_addr_sys_wait4                              0x00035470 //	FFFFFFFF82606480
#define kdlsym_addr_sys_write                              0x00152FC0 //	FFFFFFFF8259B860
#define kdlsym_addr_trap_fatal                             0x00171580 //	FFFFFFFF824ECF30	? code is diff in trap
#define kdlsym_addr_utilUSleep                             0x00658C30 //	FFFFFFFF82899BF0
#define kdlsym_addr_vm_fault_disable_pagefaults            0x0
#define kdlsym_addr_vm_fault_enable_pagefaults             0x0
#define kdlsym_addr_vm_map_lookup_entry                    0x0019F760 //	FFFFFFFF8264CF80
#define kdlsym_addr_vmspace_acquire_ref                    0x0019EF90 //	FFFFFFFF8264C7E0
#define kdlsym_addr_vmspace_alloc                          0x0019EB20 //	FFFFFFFF8264C360
#define kdlsym_addr_vmspace_free                           0x0019EDC0 //	FFFFFFFF8264C610
#define kdlsym_addr_vn_fullpath                            0x0
#define kdlsym_addr_vsnprintf                              0x004363F0 //	FFFFFFFF82323280
#define kdlsym_addr_wakeup                                 0x003FB940 //	FFFFFFFF82429CF0
#define kdlsym_addr_Xfast_syscall                          0x000001C0 //	FFFFFFFF822001C0	lol 
#define kdlsym_addr_setidt                                 0x0

// Kernel Hooks
#define kdlsym_addr_printf_hook                            0x0

// FakeSelf hooks
#define kdlsym_addr_sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook        0x0
#define kdlsym_addr_sceSblAuthMgrIsLoadable2_hook                             0x0
#define kdlsym_addr_sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook 0x0
#define kdlsym_addr_sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook   0x0
#define kdlsym_addr_sceSblAuthMgrVerifyHeader_hookA                           0x0
#define kdlsym_addr_sceSblAuthMgrVerifyHeader_hookB                           0x0

// FakePkg hooks
#define kdlsym_addr_sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook       0x0
#define kdlsym_addr_sceSblKeymgrInvalidateKey__sx_xlock_hook                  0x0
#define kdlsym_addr_npdrm_decrypt_isolated_rif__sceSblKeymgrSmCallfunc_hook   0x0
#define kdlsym_addr_npdrm_decrypt_rif_new__sceSblKeymgrSmCallfunc_hook        0x0
#define kdlsym_addr_mountpfs__sceSblPfsSetKeys_hookA                          0x0
#define kdlsym_addr_mountpfs__sceSblPfsSetKeys_hookB                          0x0

// SceShellCore patches - call sceKernelIsGenuineCEX
#define ssc_sceKernelIsGenuineCEX_patchA                    0x0
#define ssc_sceKernelIsGenuineCEX_patchB                    0x0
#define ssc_sceKernelIsGenuineCEX_patchC                    0x0
#define ssc_sceKernelIsGenuineCEX_patchD                    0x0
#define ssc_sceKernelIsGenuineCEX_patchE                    0x0

// SceShellCore patches - call RemotePackages
#define ssc_sceKernelIsGenuineCEX_patchF                    0x0

// enable savedata mounting
#define ssc_sceKernelIsGenuineCEX_patchG                    0x0
#define ssc_sceKernelIsGenuineCEX_patchH                    0x0
#define ssc_sceKernelIsGenuineCEX_patchI                    0x0
#define ssc_sceKernelIsGenuineCEX_patchJ                    0x0
#define ssc_sceKernelIsGenuineCEX_patchK                    0x0
#define ssc_sceKernelIsGenuineCEX_patchL                    0x0
#define ssc_sceKernelIsGenuineCEX_patchM                    0x0
#define ssc_sceKernelIsGenuineCEX_patchN                    0x0
#define ssc_sceKernelIsGenuineCEX_patchO                    0x0

// SceShellCore patches - call nidf_libSceDipsw
#define ssc_nidf_libSceDipsw_patchA                         0x0
#define ssc_nidf_libSceDipsw_patchB                         0x0
#define ssc_nidf_libSceDipsw_patchC                         0x0
#define ssc_nidf_libSceDipsw_patchD                         0x0

#define ssc_enable_fakepkg_patch                            0x0

// SceShellCore patches - use free prefix instead fake
#define ssc_fake_to_free_patch                              0x0

// flatz allow sys_dynlib_dlsym in all processes
#define kdlsym_addr_sys_dynlib_dlsym_patch                  0x0

// make pkgs installer working with external hdd
#define ssc_make_pkgs_installer_working_with_external_hdd   0x0

// enable support with 7.xx external hdd
#define ssc_enable_support_external_hdd                     0x0              

// SceShellUI patches - debug patches
#define ssu_sceSblRcMgrIsAllowDebugMenuForSettings_patch    0x0
#define ssu_sceSblRcMgrIsStoreMode_patch                    0x0

// sceRegMgr
#define kdlsym_addr_sceRegMgrGetInt                         0x0
#define kdlsym_addr_sceRegMgrSetInt                         0x0
#define kdlsym_addr_sceRegMgrGetBin                         0x0
#define kdlsym_addr_sceRegMgrSetBin                         0x0
#define kdlsym_addr_sceRegMgrGetStr                         0x0
#define kdlsym_addr_sceRegMgrSetStr                         0x0

// Debug (Not needed to port)
#define kdlsym_addr_g_obi_create                           0x0
#define kdlsym_addr_g_obi_destroy                          0x0
#define kdlsym_addr_g_obi_read                             0x0
#define kdlsym_addr_g_part_ox_get_bank                     0x0
#define kdlsym_addr_hexdump                                0x0

#endif
