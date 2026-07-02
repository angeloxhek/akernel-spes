#include <linux/types.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jump_label.h>

DEFINE_STATIC_KEY_FALSE(ksu_input_hook_key_false);
EXPORT_SYMBOL(ksu_input_hook_key_false);

DEFINE_STATIC_KEY_FALSE(ksu_init_rc_hook_key_false);
EXPORT_SYMBOL(ksu_init_rc_hook_key_false);

bool ksu_is_input_hook_enabled __aligned(4) = false;
EXPORT_SYMBOL(ksu_is_input_hook_enabled);

int ksu_vfs_read_hook_func(void) { return 0; }
EXPORT_SYMBOL(ksu_vfs_read_hook_func);

int susfs_run_sus_path_loop(void *arg) { return 0; }
EXPORT_SYMBOL(susfs_run_sus_path_loop);

extern void ksu_sucompat_init(void);
int __init ksu_sucompat_init_bridge(void) {
    ksu_sucompat_init();
    return 0;
}

bool ksu_is_init_rc_hook_enabled __aligned(4) = false;
EXPORT_SYMBOL(ksu_is_init_rc_hook_enabled);

void ksu_handle_vfs_fstat(int fd, loff_t *kstat_size_ptr)
{
	
}
EXPORT_SYMBOL(ksu_handle_vfs_fstat);