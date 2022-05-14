1. Memory map =>  Bus => 
    APB2 peripheral clock enable register

 GPIOB peripheral clock  Enable :


Bit 3 IOPBEN: I/O port B clock enable
Set and cleared by software.
0: I/O port B clock disabled
1:I/O port B clock enabled

0x4002 1000 - 0x4002 13FF Reset and clock control RCC

APB2 peripheral clock enable register (RCC_APB2ENR)
Address: 0x18
Reset value: 0x0000 0000

GPIO functional description
● Input floating
● Input pull-up
● Input-pull-down
● Analog Input
● Output open-drain
● Output push-pull
● Alternate function push-pull
● Alternate function open-drain

Port bit configuration table
General purpose output => Push-pull
CNF1   CNF0   MODE1   MODE0   PxODR register

General-purpose and alternate-function I/Os (GPIOs and AFIOs)
Port configuration register low

8.2.1 Port configuration register low (GPIOx_CRL) (x=A..G)
8.2.4 Port output data register (GPIOx_ODR) (x=A..G)

--------------------------------------

0x4001 0C00 - 0x4001 0FFF GPIO Port B
Port configuration register low (GPIOx_CRL) (x=A..G)
Address offset: 0x00
Port output data register (GPIOx_ODR) (x=A..G)
Address offset: 0x0C

位运算符有7个，分为两类：位逻辑运算和移位运算。位逻辑运算符包括按位取反（~）、按位与（&）、按位或（|）和按位异或（^）4种，。移位运算符包括左移（<<）、右移（>>）和无符号右移（>>>）3种。位运算符只能用于整型数据，包括byte、short、int、long和char类型。下表列出了各种位运算符的功能与示例。假设a = 10, b = 3。
~运算符是对运算数的每一位按位取反。


0011 1100
0000 1101

与操作符 “&”，如果两个输入位都是 1，那么输出位是 1，否则输入位是 0；
或操作符 “|” ，如果两个输入位有一个是 1，那么输出位是 1，只有两个输入位都是 0，输出位才是 0；
异或运算符 “^”，如果两个输入位都为 1 或者都为 0，那么输出位是 0，否则输出位是 1。
非运算符 “~”，这个一元操作符，只能对一个数操作，规则是输出位与输入位相反。

&
如果相对应位都是1，则结果为1，否则为0
A & B得到 12，即0000 1100

|
如果相对应位都是0，则结果为0，否则为1
A | B得到61，即 0011 1101

^
如果相对应位值相同，则结果为0，否则为1
A ^ B得到 49，即 0011 0001

~
按位取反运算符翻转操作数的每一位，即0变成1，1变成0。
~A得到 -61，即1100 0011

<<
按位左移运算符。左操作数按位左移右操作数指定的位数。（低位补零）
A << 2得到 240，即 1111 0000

>>
“有符号”按位右移运算符。左操作数按位右移右操作数指定的位数。该操作符使用 “符号扩展”：若符号为正，则高位插入 0；若符号为负，则高位插入 1。
A >> 2得到15即 1111

>>>
“无符号”按位右移补零操作符。左操作数的值按右操作数指定的位数右移，移动得到的空位以零填充。该操作符使用 “零扩展”，无论正负，都在高位插入 0。


数字的二进制表现形式为 “有符号的二进制补码”。
原码：数字的二进制表示法，最高位为符号位， “ 0 ” 为正，“ 1 ” 为负。
反码：正数的反码与原码相同，负数的反码对原码逐位取反，符号位除外。
补码：正数的补码与原码相同，负数的补码在其反码末位加 1。
负数的二进制算法（以 -6 为例）：
1）将 -6 的绝对值转化为二进制，即：00000000 00000000 00000000 00000110
2）求该二进制数的反码，即：11111111 11111111 11111111 11111001


~ 取反 对一个二进制数按位取反，即将0变1，1变0。

& 按位与 0&0=0; 0&1=0; 1&0=0; 1&1=1；即：两位同时为“1，结果才为“1，否则为0。

| 按位或 参加运算的两个对象只要有一个为1，其值为1。
0 | 0=0； 0 | 1=1； 1 | 0=1； 1 | 1=1；

^ 异或 参加运算的两个对象，如果两个相应位为“异”（值不同），则该位结果为1，否则为0。
0^0=0； 0^1=1； 1^0=1； 1^1=0；




tar -tf xx | xargs rm -rf

将操作数中第N位置1,其他位不变 :  num = num | 1 << n ;
将操作数中第N位置0,其他位不变 :  num = num & ~(1 << n) ;
测试第n位 : if(num & 1 << n)






















