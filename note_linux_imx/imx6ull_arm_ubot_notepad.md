Linux 内核编译完成以后会在 arch/arm/boot 目录下生成 zImage 镜像文件
如果使用设备树
的话还会在 arch/arm/boot/dts 目录下开发板对应的.dtb(设备树)文件



33.4.1 从 EMMC 启动 Linux 系统

setenv bootargs 'console=ttymxc0,115200 root=/dev/mmcblk1p2 rootwait rw'
setenv bootcmd 'mmc dev 1; fatload mmc 1:1 80800000 zImage; fatload mmc 1:1 83000000 imx6ull-14x14-emmc-4.3-800x480-c.dtb; bootz 80800000 - 83000000;'

33.4.2 从网络启动 Linux 系统

setenv bootargs 'console=ttymxc0,115200 root=/dev/mmcblk1p2 rootwait rw'

setenv bootcmd 'tftp 80800000 zImage; tftp 83000000 imx6ull-alientek-emmc.dtb; bootz 80800000 - 83000000'
saveenv









fatls mmc 1:1    //查看emmc 1：1 文件
fatload  mmc 1:1 80800000 zImage
fatload  mmc 1:1 83000000 imx6ull-14x14-emmc-4.3-480x272-c.dtb
bootz 80800000-83000000

./imxdownload u-boot.bin /dev/sdd


setenv ipaddr 192.168.2.250
setenv ethaddr 88:55:c8:c4:30:3e
setenv gatewayip 192.168.2.1
setenv netmask 255.255.255.0
setenv serverip 192.168.2.2

    tftp 80800000 zImage
    fatwrite mmc 1:1 80800000 zImage 6788f8



uboot 初次编译:
    sudo apt-get install libncurses5-dev  //一定要安装
    sudo apt-get install lzop

    sudo apt-get install build-essential

tar -vxjf uboot-imx-2016.03-2.1.0-g8b546e4.tar.bz2

#!/bin/bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mx6ull_14x14_ddr512_emmc_defconfig
make V=1 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j12

/*
 mx6ull_14x14_ddr512_emmc_defconfig   配置文件在 uboot源码的 configs 目录中
u-boot.imx 就是我们最终要烧写到开发板中的 uboot 镜像文件    */

./mx6ull_alientek_emmc.sh
./imxdownload u-boot.bin /dev/sdd //烧写到 SD 卡，不能烧写到/dev/sda 或 sda1 设备里面！



30.4.1 信息查询命令  


    bdinfo      DRAM 的起始地址和大小、启动参数保存起始地址、波特率、sp(堆栈指针)起始地址等信息
    printenv 
     version
    setenv bootdelay 5



    nfs 80800000 192.168.1.253:/home/xxx/zImage





    mmc list 
    mmc dev
    mmc info mmc part
    0 个分区存放 uboot，第 1 个分区存放 Linux 镜像文件和设备树，第 2 个分区存放根文件系统
    mmc dev 1 2     将 EMMC 的分区 2 设置为当前 MMC 设备

    fatload mmc 1:1 80800000 zImage  //fatload 命令用于将指定的文件读取到 DRAM 中
    fatls mmc 1:1          //“fatls”命令查看一下 EMMC 分区 1 里面的文件         

30.4.7 EXT 格式文件系统操作命令
    ext4ls mmc 1:2

30.4.9 BOOT 操作命令
    uboot 的本质工作是引导 Linux，所以 uboot 肯定有相关的 boot(引导)命令来启动 Linux。常
        用的跟 boot 有关的命令有：bootz、bootm 和 boot。

    tftp 80800000 zImage
    tftp 83000000 imx6ull-14x14-emmc-7-1024x600-c.dtb
    bootz 80800000 - 83000000



uboot_Linux 内核启动:
    mmc dev 1 //切换到 EMMC
    fatload mmc 1:1 0x80800000 zImage //读取 zImage 到 0x80800000 处
    fatload mmc 1:1 0x83000000 imx6ull-14x14-evk.dtb //读取设备树到 0x83000000 处
    bootz 0x80800000 - 0x83000000 //启动 Linux

或者:

    setenv bootcmd 'mmc dev 1; fatload mmc 1:1 80800000 zImage; fatload mmc 1:1 83000000        imx6ull-alientek-emmc.dtb; bootz 80800000 - 83000000;'


环境变量 bootargs:

    /*mmcargs=setenv bootargs console=${console},${baudrate} root=${mmcroot}*/
    mmcargs=setenv bootargs console= ttymxc0, 115200 root= /dev/mmcblk1p2 rootwait rw


33.4.2 从网络启动 Linux 系统:
    setenv bootargs 'console=ttymxc0,115200 root=/dev/mmcblk1p2 rootwait rw'
    setenv bootcmd 'tftp 80800000 zImage; tftp 83000000 imx6ull-alientek-emmc.dtb; bootz
        80800000 - 83000000'
    saveenv

uboot 移植到此结束，简单总结一下 uboot 移植的过程：

     uboot 可以通过 mx6ull_alientek_emmc_defconfig 来配置，或者通过文件 mx6ull_alientek_emmc.h 

    ①、不管是购买的开发板还是自己做的开发板，基本都是参考半导体厂商的 dmeo 板，而
         半导体厂商会在他们自己的开发板上移植好 uboot、linux kernel 和 rootfs 等，最终制作好 BSP
         包提供给用户。我们可以在官方提供的 BSP 包的基础上添加我们的板子，也就是俗称的移植。
②、我们购买的开发板或者自己做的板子一般都不会原封不动的照抄半导体厂商的 demo
      板，都会根据实际的情况来做修改，既然有修改就必然涉及到 uboot 下驱动的移植。
③、一般 uboot 中需要解决串口、NAND、EMMC 或 SD 卡、网络和 LCD 驱动，因为 uboot
        的主要目的就是启动 Linux 内核，所以不需要考虑太多的外设驱动。
④、在 uboot 中添加自己的板子信息，根据自己板子的实际情况来修改 uboot 中的驱动。



34.1 U-Boot 图形化配置体验
    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mx6ull_alientek_emmc_defconfig
    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig


    如果已经在 uboot 的顶层 Makefile 中定义了 ARCH 和 CROSS_COMPILE 的值，那么上述命令可以简化为：
    make mx6ull_alientek_emmc_defconfig
    make menuconfig
