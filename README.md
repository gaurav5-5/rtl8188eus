# rtl8xxxu with RTL8188EU AP mode (out of tree)

The mainline `rtl8xxxu` driver from Ubuntu's 7.0.0-38 kernel (upstream
7.0.14) with Georg Müller's RFC v3 series that enables AP mode on the
RTL8188EU, plus seven fixes for that series. Built as an out-of-tree
module that replaces the in-kernel `rtl8xxxu` through DKMS.

Patches on top of the import:

1. `move dynamic_tx_rpt_timing_counter from ra_info to priv` (RFC v3 1/4)
2. `handle rate control for 8188e a per mac_id` (RFC v3 2/4)
3. `update max report mac id on station add / remove for 8188e chips` (RFC v3 3/4)
4. `Enable AP mode for RTL8188EU` (RFC v3 4/4)
5. `bound AP station macids by the chip's max_macid_num`
6. `harden 8188e TX report parsing in AP mode`
7. `put the macid into 8188e TX descriptors`
8. `only warn about an invalid TX report item 0 in station mode`
9. `wait for the beacon URB before polling BCN_VALID`
10. `accept PS-Poll frames in AP mode`
11. `backport to the 6.8 Jetson tegra kernel` (build only)
12. `fall back to a random MAC address for a blank EFuse`

Upstream series: https://patchwork.kernel.org/project/linux-wireless/list/?series=1066375

## Build

    make

## Install

    sudo dkms add .
    sudo dkms install rtl8xxxu-ap/7.0.14-ap7

DKMS only builds this for 7.0.x and 6.8.x kernels (`BUILD_EXCLUSIVE_KERNEL`).
`compat.h` and the `LINUX_VERSION_CODE` guards in `core.c` cover the 6.8
API (Jetson 6.8.12-tegra); they compile away on 7.0.

## Remove

    sudo dkms remove rtl8xxxu-ap/7.0.14-ap7 --all
