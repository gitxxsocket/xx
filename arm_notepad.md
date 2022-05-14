

nVuTeApTarDnyNYkBQc3m9bp8rH4LDgnf8XXeg8S
q7JtBs7Ju9UueJw6qHWm6mgcRnTYhReN59pPvGws
rRzQRrdbuPgpEuUacykTZbMrG8MQmBMGfU8G6H8U
t2Uqb3ekxvD3smZPVWwHa7JAxpdRns5APPQPNem6
H5mY2wsb8ZamwqSUWnpsPKuPhdNL9G4MQUE8nLhj
QfJAymyxB7Kts8eqc7DxjpxTz36Sc7cm89HKLtNN
8fh8LPQ7w7hWyrrAzVAH6APTKAKCXcrArG5Q7qn3
uzL6k89FWSSFZT2Ej42stePDSN5eFpUHWrxMXxfy
PEp9YtEhcPyVYh6YnqjvAtAcL4LxXCRx3JqFbhYS
Kg96YQVYK5BUdB7pMUbHAkv9ndq2y2jDm9L3qeyQ
pBbhvpq6yPCshSUDzLPJTqUPPESKxQvGhMc2kXVr
hhBZf39peFqrn4MGZPRxevcmHYgnagEYQqBmz8CT
9fDTCHU2zYXpMQGcxra4AJCkTARqdmDsy4qvhJPe
qCGN5DwBw7MxGbvs4TU9p59aMGpsSz9QjHuxFeM

[Lee@leedd tmp]$ tar -zcvf  test.tar.gz    test        ### 打包后以gzip压缩
[Lee@leedd tmp]$ tar -jcvf  test.tar.bz2   test        ### 打包后以bzip2压缩

添加环境变量#
​ 随后将C:\msys64\mingw64\bin添加到Path中，输入clang -v，如果想测试之前安装的Clangd，只需输入clangd即可

{
    "cmake.generator": "MinGW Makefiles"
}

**程序运行时动态连接。多个进程可以连接同一个共享库。**
#include "..."; 语句将首先在工作目录寻找相应文件。如果使用gcc时，增加-I选项，将在-I提供的路径中寻找。

首先，编译stack.c:
$gcc -c -fPIC -o mystack.o mystack.c
-c表示只编译(compile)，而不连接。-o选项用于说明输出(output)文件名。gcc将生成一个目标(object)文件mystack.o。

注意-fPIC选项。PIC指Position Independent Code。共享库要求有此选项，以便实现动态连接(dynamic linking)。

生成共享库:
$gcc -shared -o libmystack.so mystack.o
库文件以lib开始。共享库文件以.so为后缀。-shared表示生成一个共享库。
这样，共享库就完成了。.so文件和.h文件都位于当前工作路径(.)。

$gcc -c -fPIC -o mystack.o mystack.c
$gcc -shared -o libmystack.so mystack.o

$gcc -g -o test test.c -lmystack -L. -Wl,-rpath=.

tar -tf xx | xargs rm -rf


将操作数中第N位置1,其他位不变 :  num = num | 1 << n ;
将操作数中第N位置0,其他位不变 :  num = num & ~(1 << n) ;
测试第n位 : if(num & 1 << n)


假如我们现在在dev分支上，刚开发完项目，执行了下列命令：
git  add .
git  commit -m '提交的备注信息'
git  push -u origin dev

想将dev分支合并到master分支，操作如下：

    1、首先切换到master分支上

git  checkout master

    2、如果是多人开发的话 需要把远程master上的代码pull下来

git pull origin master
//如果是自己一个开发就没有必要了，为了保险期间还是pull

    3、然后我们把dev分支的代码合并到master上

git  merge dev

    4、然后查看状态及执行提交命令

git status

On branch master
Your branch is ahead of 'origin/master' by 12 commits.
  (use "git push" to publish your local commits)
nothing to commit, working tree clean

//上面的意思就是你有12个commit，需要push到远程master上 
> 最后执行下面提交命令
git push origin master

    5其他命令

更新远程分支列表
git remote update origin --prune

查看所有分支
git branch -a

删除远程分支Chapater6
git push origin --delete Chapater6

删除本地分支 Chapater6
git branch -d  Chapater6

1 git remote add origin https://

2 git config core.sparsecheckout true

3 echo "  ???  " >> .git/info/sparse-checkout

4 git pull --depth 

1 origin master

git pull origin master

git config --global user.name "Git账号" git config --global user.email "Git邮箱"

ssh-keygen -t rsa -C "your_email@example.com"

eval $(ssh-agent -s)

ssh-keygen -t rsa -C "_______@outlook.com"




//////////////////////////////////////////////////////////////////////////////////





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





    /////////////////////////////////////////////////////////////////////////////////////


    
“/proc/device-tree     //查看有没有节点

-> Device Drivers
    -> LED Support (NEW_LEDS [=y])
        ->LED Support for GPIO connected LEDs
/sys/bus/platform/devices  leds
“sys/class/leds/red/brightness
echo 1 > /sys/class/leds/red/brightness /

modprobe chrdevbase.ko
cat /proc/devices
lsmod  命令即可查看当前系统中存在的模块
mknod /dev/chrdevbase c 200 0    创建设备节点文件
以使用“ls /dev/chrdevbase -l”命令查看
rmmod chrdevbase.ko

tftp -g -r embedexpert 192.168.1.2
-g表示下载文件(get)
-p表示上传文件(put)
-l表示本地文件名(local file)
-r表示远程主机的文件名(remote file)

echo none > /sys/class/leds/sys-led/trigger // 改变 LED 的触发模式
/lib/modules/4.1.15-g0423506
modprobe led.ko 
mknod /dev/led c 200 0
./ledApp /dev/led 1


42.2.1 mdev 机制
    busybox 会创建一个 udev 的简化版本—mdev，所以在嵌入式 Linux 中我们使用
    mdev 来实现设备节点文件的自动创建与删除，Linux 系统中的热插拔事件也由 mdev 管理，在
    /etc/init.d/rcS 文件中如下语句：

    echo /sbin/mdev > /proc/sys/kernel/hotplug

    上述命令设置热插拔事件由 mdev 来管理，关于 udev 或 mdev 更加详细的工作原理这里就
    不详细探讨了，我们重点来学习一下如何通过 mdev 来实现设备文件节点的自动创建与删除。

42.2.1 创建和删除类
    自动创建设备节点的工作是在驱动程序的入口函数中完成的，一般在 cdev_add 函数后面添
    加自动创建设备节点相关代码。首先要创建一个 class 类，class 是个结构体，定义在文件
    include/linux/device.h 里面。class_create 是类创建函数，class_create 是个宏定义
    struct class *__class_create(
        struct module *owner,       //
        const char *name,struct 
        lock_class_key *key )

 owner 一般为 THIS_MODULE，参数 name 是类名字 返回值是个指向结构体 class 的指针，也就是创建的类。
    类删除函数为 class_destroy:
    void class_destroy(struct class *cls);

42.2.2 创建设备
    struct device *device_create(struct class *class,
        struct device *parent,
         dev_t devt,
        void *drvdata,
        const char *fmt, ...)
        参数 parent 是父
设备，一般为 NULL，也就是没有父设备；参数 devt 是设备号；参数 drvdata 是设备可能会使用
的一些数据，一般为 NULL；参数 fmt 是设备名字，如果设置 fmt=xxx 的话，就会生成/dev/xxx
这个设备文件。返回值就是创建好的设备。

void device_destroy(struct class *class, dev_t devt)
参数 class 是要删除的设备所处的类，参数 devt 是要删除的设备号。


42.3 设置文件私有数据
    每个硬件设备都有一些属性，比如主设备号(dev_t)，类(class)、设备(device)、开关状态(state)
    等等，在编写驱动的时候你可以将这些属性全部写成变量的形式


45.1 pinctrl 子系统
    pinctrl 子系统源码目录为 drivers/pinctrl。
    在文件drivers/pinctrl/freescale/pinctrl-imx6ul.c

    #define MX6UL_PAD_UART1_RTS_B__GPIO1_IO19 0x0090 0x031C 0x0000 0x5 0x0
    <mux_reg conf_reg input_reg mux_mode input_val>


        arm-linux-gnueabihf-gcc ledApp.c -o ledApp


/sys/class/gpio   96+14=110
echo 110 > /sys/class/gpio/export
echo in /sys/class/gpio/gpio110/direction
cat /sys/class/gpio/gpio110/value
echo 110 > /sys/class/gpio/unexport


#!/bin/sh
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- imx_v7_defconfig
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- all -j4


    252 ARCH ?= arm
    253 CROSS_COMPILE ?= arm-linux-gnueabihf
设置好以后我们就可以使用如下命令编译 Linux 了：
make xxx_defconfig //使用默认配置文件配置 Linux  imx_v7_defconfig
make menuconfig //启动图形化配置界面   
make -j16 //编译 Linux


tftp 80800000 zImage;tftp 83000000 imx6ull-alientek-emmc.dtb;bootz 80800000 - 83000000 

console=ttymxc0,115200 root=/dev/nfs rw nfsroot=192.168.1.250:/home/zuozhongkai/linux/nfs/
rootfs ip=192.168.1.251:192.168.1.250:192.168.1.1:255.255.255.0::eth0:off


