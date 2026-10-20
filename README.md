# rtl8xxxu with RTL8188EU AP mode (out of tree)

The mainline `rtl8xxxu` driver from Ubuntu's 7.0.0-38 kernel (upstream
7.0.14) with Georg Müller's RFC v3 series that enables AP mode on the
RTL8188EU, plus three fixes for that series. Built as an out-of-tree
module that replaces the in-kernel `rtl8xxxu` through DKMS.

Patches on top of the import:

1. `move dynamic_tx_rpt_timing_counter from ra_info to priv` (RFC v3 1/4)
2. `handle rate control for 8188e a per mac_id` (RFC v3 2/4)
3. `update max report mac id on station add / remove for 8188e chips` (RFC v3 3/4)
4. `Enable AP mode for RTL8188EU` (RFC v3 4/4)
5. `bound AP station macids by the chip's max_macid_num`
6. `harden 8188e TX report parsing in AP mode`
7. `put the macid into 8188e TX descriptors`

Upstream series: https://patchwork.kernel.org/project/linux-wireless/list/?series=1066375

## Build

    make

## Install

    sudo dkms add .
    sudo dkms install rtl8xxxu-ap/7.0.14-ap2

DKMS only builds this for 7.0.x kernels (`BUILD_EXCLUSIVE_KERNEL`).

## Remove

    sudo dkms remove rtl8xxxu-ap/7.0.14-ap2 --all
