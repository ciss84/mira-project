#pragma once

#if MIRA_PLATFORM==MIRA_PLATFORM_ORBIS_BSD_620
/*
These are the required functions in order for the Oni Framework to operate properly
These are all offsets into the base of the kernel. They expect all standard FreeBSD 9 prototypes

The reason we do not hardcode offsets here, is due to the different platforms that are supported, and
for the platforms that do enable kernel ASLR (Address Space Layout Randomization?)
*/

#define kdlsym_addr__mtx_lock_flags                        0x0
#define kdlsym_addr__mtx_lock_sleep                        0x0
#define kdlsym_addr__mtx_lock_spin_flags                   0x0
#define kdlsym_addr__mtx_unlock_flags                      0x0
#define kdlsym_addr__mtx_unlock_sleep                      0x0
#define kdlsym_addr__mtx_unlock_spin_flags                 0x0
#define kdlsym_addr__sceSblAuthMgrGetSelfInfo              0x0
#define kdlsym_addr__sceSblAuthMgrSmStart                  0x0
#define kdlsym_addr__sx_init_flags                         0x0
#define kdlsym_addr__sx_slock                              0x0
#define kdlsym_addr__sx_sunlock                            0x0
#define kdlsym_addr__sx_xlock                              0x0
#define kdlsym_addr__sx_xunlock                            0x0
#define kdlsym_addr__thread_lock_flags                     0x0
#define kdlsym_addr__vm_map_lock_read                      0x0
#define kdlsym_addr__vm_map_unlock_read                    0x0
#define kdlsym_addr_AesCbcCfb128Decrypt                    0x0
#define kdlsym_addr_AesCbcCfb128Encrypt                    0x0
#define kdlsym_addr_allproc                                0x0
#define kdlsym_addr_allproc_lock                           0x0
#define kdlsym_addr_avcontrol_sleep                        0x0
#define kdlsym_addr_cloneuio                               0x0
#define kdlsym_addr_console_cdev                           0x0
#define kdlsym_addr_console_write                          0x0
#define kdlsym_addr_contigfree                             0x0
#define kdlsym_addr_contigmalloc                           0x0
#define kdlsym_addr_copyin                                 0x0
#define kdlsym_addr_copyinstr                              0x0
#define kdlsym_addr_copyout                                0x0
#define kdlsym_addr_critical_enter                         0x0
#define kdlsym_addr_critical_exit                          0x0
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
#define kdlsym_addr_malloc                                 0x0
#define kdlsym_addr_memcmp                                 0x0
#define kdlsym_addr_memcpy                                 0x0
#define kdlsym_addr_memmove                                0x0
#define kdlsym_addr_memset                                 0x0
#define kdlsym_addr_mini_syscore_self_binary               0x0
#define kdlsym_addr_mount_arg                              0x0
#define kdlsym_addr_mount_argb                             0x0
#define kdlsym_addr_mount_argf                             0x0
#define kdlsym_addr_mtx_destroy                            0x0
#define kdlsym_addr_mtx_init                               0x0
#define kdlsym_addr_mtx_lock_sleep                         0x0
#define kdlsym_addr_mtx_unlock_sleep                       0x0
#define kdlsym_addr_name_to_nids                           0x0
#define kdlsym_addr_pause                                  0x0
#define kdlsym_addr_pfind                                  0x0
#define kdlsym_addr_pmap_activate                          0x0
#define kdlsym_addr_printf                                 0x0
#define kdlsym_addr_prison0                                0x0
#define kdlsym_addr_proc0                                  0x0
#define kdlsym_addr_proc_reparent                          0x0
#define kdlsym_addr_proc_rwmem                             0x0
#define kdlsym_addr_realloc                                0x0
#define kdlsym_addr_rootvnode                              0x0
#define kdlsym_addr_RsaesPkcs1v15Dec2048CRT                0x0
#define kdlsym_addr_sbl_eap_internal_partition_key         0x0
#define kdlsym_addr_sbl_keymgr_buf_gva                     0x0
#define kdlsym_addr_sbl_keymgr_buf_va                      0x0
#define kdlsym_addr_sbl_keymgr_key_rbtree                  0x0
#define kdlsym_addr_sbl_keymgr_key_slots                   0x0
#define kdlsym_addr_sbl_pfs_sx                             0x0
#define kdlsym_addr_sbl_drv_msg_mtx                        0x0
#define kdlsym_addr_sceSblACMgrGetPathId                   0x0
#define kdlsym_addr_sceSblAuthMgrIsLoadable2               0x0
#define kdlsym_addr_sceSblAuthMgrSmVerifyHeader            0x0
#define kdlsym_addr_sceSblAuthMgrVerifyHeader              0x0
#define kdlsym_addr_sceSblDriverSendMsg                    0x0
#define kdlsym_addr_sceSblGetEAPInternalPartitionKey       0x0
#define kdlsym_addr_sceSblKeymgrClearKey                   0x0
#define kdlsym_addr_sceSblKeymgrSetKeyForPfs               0x0
#define kdlsym_addr_sceSblKeymgrSetKeyStorage              0x0
#define kdlsym_addr_sceSblKeymgrSmCallfunc                 0x0
#define kdlsym_addr_sceSblPfsSetKeys                       0x0
#define kdlsym_addr_sceSblRngGetRandomNumber               0x0
#define kdlsym_addr_sceSblServiceMailbox                   0x0
#define kdlsym_addr_self_orbis_sysvec                      0x0
#define kdlsym_addr_Sha256Hmac                             0x0
#define kdlsym_addr_snprintf                               0x0
#define kdlsym_addr_spinlock_exit                          0x0
#define kdlsym_addr_sprintf                                0x0
#define kdlsym_addr_sscanf                                 0x0
#define kdlsym_addr_strcmp                                 0x0
#define kdlsym_addr_strdup                                 0x0
#define kdlsym_addr_strlen                                 0x0
#define kdlsym_addr_strncmp                                0x0
#define kdlsym_addr_strstr                                 0x0
#define kdlsym_addr_sys_accept                             0x0
#define kdlsym_addr_sys_bind                               0x0
#define kdlsym_addr_sys_close                              0x0
#define kdlsym_addr_sys_dup2                               0x0
#define kdlsym_addr_sys_fstat                              0x0
#define kdlsym_addr_sys_getdents                           0x0
#define kdlsym_addr_sys_kill                               0x0
#define kdlsym_addr_sys_listen                             0x0
#define kdlsym_addr_sys_lseek                              0x0
#define kdlsym_addr_sys_mkdir                              0x0
#define kdlsym_addr_sys_mlock                              0x0
#define kdlsym_addr_sys_mlockall                           0x0
#define kdlsym_addr_sys_mmap                               0x0
#define kdlsym_addr_sys_munmap                             0x0
#define kdlsym_addr_sys_nmount                             0x0
#define kdlsym_addr_sys_open                               0x0
#define kdlsym_addr_sys_ptrace                             0x0
#define kdlsym_addr_sys_read                               0x0
#define kdlsym_addr_sys_recvfrom                           0x0
#define kdlsym_addr_sys_rmdir                              0x0
#define kdlsym_addr_sys_sendto                             0x0
#define kdlsym_addr_sys_setuid                             0x0
#define kdlsym_addr_sys_shutdown                           0x0
#define kdlsym_addr_sys_socket                             0x0
#define kdlsym_addr_sys_stat                               0x0
#define kdlsym_addr_sys_unlink                             0x0
#define kdlsym_addr_sys_unmount                            0x0
#define kdlsym_addr_sys_wait4                              0x0
#define kdlsym_addr_sys_write                              0x0
#define kdlsym_addr_trap_fatal                             0x0
#define kdlsym_addr_utilUSleep                             0x0
#define kdlsym_addr_vm_fault_disable_pagefaults            0x0
#define kdlsym_addr_vm_fault_enable_pagefaults             0x0
#define kdlsym_addr_vm_map_lookup_entry                    0x0
#define kdlsym_addr_vmspace_acquire_ref                    0x0
#define kdlsym_addr_vmspace_alloc                          0x0
#define kdlsym_addr_vmspace_free                           0x0
#define kdlsym_addr_vn_fullpath                            0x0
#define kdlsym_addr_vsnprintf                              0x0
#define kdlsym_addr_wakeup                                 0x0
#define kdlsym_addr_Xfast_syscall                          0x0
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

// SceShellCore patches - enable VR without spoof
#define ssc_enable_vr                                       0x0

// flatz allow sys_dynlib_dlsym in all processes
#define kdlsym_addr_sys_dynlib_dlsym_patch                  0x0

// make pkgs installer working with external hdd
#define ssc_make_pkgs_installer_working_with_external_hdd   0x0

// enable support with 7.xx external hdd
#define ssc_enable_support_external_hdd                     0x0              

// Patch debug setting             
#define ssc_Patch_debug_settingA                            0x0
#define ssc_Patch_debug_settingB                            0x0
#define ssc_Patch_debug_settingC                            0x0
#define ssc_Patch_debug_settingD                            0x0

// SceShellUI - remote play related patching
#define ssu_CreateUserForIDU_patch                          0x0
#define ssu_remote_play_menu_patch                          0x0

// SceRemotePlay - enabler patches
#define srp_enabler_patch1                                  0x0
#define srp_enabler_patch2                                  0x0

// disable screenshot block
#define ssc_disable_screenshot_patch                        0x0

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

