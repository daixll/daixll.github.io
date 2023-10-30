---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---


### DDNS 及 内网穿透

* NO-IP [管理面板](https://my.noip.com/dynamic-dns) [官方文档](https://www.noip.com/support/knowledgebase/install-linux-3-x-dynamic-update-client-duc/) [Linux ipv6](https://www.noip.com/support/knowledgebase/automatic-ipv6-updates-linux-duc/)
  > 只能搞一个域名
    1. 下载 [下载地址](https://my.noip.com/dynamic-dns/duc)
    2. 解压 `tar -xf noip*.tar.gz`
    3. 安装 `cd binaries && apt install ./noip-duc_3.0.0-beta.5_amd64.deb`
    4. `noip-duc --username 账号 --password 密码 -g 域名 --ip-method http://ip1.dynupdate6.no-ip.com/`


<details><summary>内网穿透(有备无患, 无奈之举)</summary>

* 小鸡穿透 [管理面板](https://console.chickfrp.com/#/penManage/tunnel) [官方文档](http://help.chickfrp.com/#/%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8)
    > 固定ip, 高带宽(1.25MB/s), 高流量(5GB)
    1. 下载 `wget https://chickfrp.com/download/frp045/linux/frp_0.45.0_linux_amd64.tar.gz` 
    2. 解压 `tar -zxvf frp*.tar.gz`
    3. 复制管理面板中的配置文件代码
    4. 替换 frpc.ini
    5. 穿透 `./frpc`

* cpolar [管理面板](https://dashboard.cpolar.com/status) [官方文档](https://www.cpolar.com/docs)
    > cpolar不能固定ip, 但流量无限
    1. 安装 `curl -sL https://git.io/cpolar | sudo bash`
    2. 查看 `token`在管理面板
    3. 认证 `cpolar authtoken 你的token`
    4. 穿透 `cpolar http 9070`

* 花生壳 [管理面板](https://console.hsk.oray.com/forward) [官方文档](https://service.oray.com/question/11630.html)
    > 花生壳可以配置两个固定ip
    1. 安装 `dpkg -i phddns-5.0.0-amd64.deb`
    2. 运行 `phddns start`
    3. 查看 `phddns status`
    4. 登录 `sn码` + `admin` 登录管理面板  
    5. 穿透 管理面板添加映射  


</details>