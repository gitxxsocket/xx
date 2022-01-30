tar -tf xx | xargs rm -rf


将操作数中第N位置1,其他位不变 :  num = num | 1 << n ;
将操作数中第N位置0,其他位不变 :  num = num & ~(1 << n) ;
测试第n位 : if(num & 1 << n)

对driver的成员做了进一步赋值，对于driver结构体中几个函数实现方法进行了重新赋值，
因为对于不论属于哪种总线的驱动程序，都需要定义一个driver专用的结构体来维护驱动程序，比如I2C、spi、USB等。
这些总线在实现上
是不同的，但是linux内核要求不论那种总线都要有device_driver类型的成员，有些属性和函数的实现是由device_driver继承来的，类似于类的继承的概念；但是有些成员和函数是要重新编写的，这就类似于面向对象的多态，如在不同的总线下，probe、remove、shutdown几种实现方法不一样。


arm-linux-gnueabihf-gcc chrdevbaseApp.c -o chrdevbaseApp

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





make -j32
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


