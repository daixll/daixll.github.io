



```sh
src/gz openwrt_core http://downloads.openwrt.org/releases/23.05.4/targets/mediatek/filogic/packages
src/gz openwrt_base http://downloads.openwrt.org/releases/23.05.4/packages/aarch64_generic/base
src/gz openwrt_luci http://downloads.openwrt.org/releases/23.05.4/packages/aarch64_generic/luci
src/gz openwrt_packages http://downloads.openwrt.org/releases/23.05.4/packages/aarch64_generic/packages
src/gz openwrt_routing http://downloads.openwrt.org/releases/23.05.4/packages/aarch64_generic/routing
src/gz openwrt_telephony http://downloads.openwrt.org/releases/23.05.4/packages/aarch64_generic/telephony
```

```sh
src/gz immortalwrt_core https://downloads.immortalwrt.org/releases/23.05.4/targets/rockchip/armv8/packages
src/gz immortalwrt_base https://downloads.immortalwrt.org/releases/23.05.4/packages/aarch64_generic/base
src/gz immortalwrt_luci https://downloads.immortalwrt.org/releases/23.05.4/packages/aarch64_generic/luci
src/gz immortalwrt_packages https://downloads.immortalwrt.org/releases/23.05.4/packages/aarch64_generic/packages
src/gz immortalwrt_routing https://downloads.immortalwrt.org/releases/23.05.4/packages/aarch64_generic/routing
src/gz immortalwrt_telephony https://downloads.immortalwrt.org/releases/23.05.4/packages/aarch64_generic/telephony
```



### ImmortalWrt

`vim /etc/config/network`

<br>

### HomeProxy

[homeproxy 教程](https://www.youtube.com/watch?v=nNRpbn9M2Lc)



<br>

### OpenVPN


[openwrt ovpn教程](https://www.youtube.com/watch?v=yb-g4ZaNm9Y)

[openvpn 网络速率优化](http://www.xixicool.com/870.html)

实际上删除 openvpn comp_lzo 即可

防火墙设置：
    forwarded ipv4 来自所有区域，ip 10.0.1.0/24 到 lan，静态重写到源 ip 10.0.0.2

