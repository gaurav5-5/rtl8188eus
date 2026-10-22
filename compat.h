/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Shims that let this 7.0-based rtl8xxxu build on older kernels.
 * Built and tested against 7.0 and 6.8 (Jetson tegra); every shim
 * compiles away on 7.0.
 */

#ifndef _RTL8XXXU_COMPAT_H
#define _RTL8XXXU_COMPAT_H

#include <linux/version.h>
#include <linux/slab.h>
#include <linux/debugfs.h>
#include <net/mac80211.h>

/* kmalloc_obj() arrived in 7.0; GFP defaults to GFP_KERNEL */
#ifndef kmalloc_obj
#define __rtl8xxxu_kmalloc_obj(VAR_OR_TYPE, GFP, ...) \
	kmalloc(sizeof(VAR_OR_TYPE), GFP)
#define kmalloc_obj(...) __rtl8xxxu_kmalloc_obj(__VA_ARGS__, GFP_KERNEL)
#endif

/* Read-only debugfs files used plain file_operations before 6.14 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 14, 0)
#define debugfs_short_fops file_operations
#endif

/* CSA helpers took no link_id before MLO CSA support in 6.10 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 10, 0)
#define ieee80211_beacon_cntdwn_is_complete(vif, link_id) \
	ieee80211_beacon_cntdwn_is_complete(vif)
#define ieee80211_csa_finish(vif, link_id) ieee80211_csa_finish(vif)
#endif

/*
 * Chanctx emulation helpers arrived in 6.9. Before that mac80211 drove
 * drivers without chanctx ops through ->config() itself, so leave the
 * ops unset.
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 9, 0)
#define ieee80211_emulate_add_chanctx NULL
#define ieee80211_emulate_remove_chanctx NULL
#define ieee80211_emulate_change_chanctx NULL
#define ieee80211_emulate_switch_vif_chanctx NULL
#endif

#endif /* _RTL8XXXU_COMPAT_H */
