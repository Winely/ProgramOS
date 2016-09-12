# ProgramOS
The program of operating system.  
其实名为+1's大家懂的。  
基于教材《ORANGE'S: 一个操作系统的实现》中的orange's系统，使用的参考源码为随书代码中的`chapter11/a`。

## 环境安装和运行
+ 首先请确认已经安装好了[`Ubuntu`](http://www.ubuntu.com/download/desktop)和[`bochs`](http://sourceforge.net/projects/bochs/)，本项目默认运行在64位系统中，如果是32位需要修改Makefile。  
+ 在Terminal中完成项目的获取和配置  
```bash
  $ git clone https://github.com/Winely/ProgramOS.git  
  $ cd ProgramOS
```
+ 80m.img为一张80兆软盘，其中存放了用户级应用，已经完成了编译和写入，所以不需要再make install。具体的源码可以参考`/commands`。  
  另外，由于通过git直接传输.gz文件会导致格式损坏，所以我们将压缩后的`80m.img.gz`改名为`.bin`文件强制使用二进制方式传输，以保证数据不受损。因此需要先改回`.gz`并进行解压。
```bash
  $ mv 80m.img.bin 80m.img.gz
  $ sudo apt-get install gzip   //若已安装gzip可跳过这行
  $ gunzip 80m.img.gz
```
+ 假如是32位机器，需要将最外层`Makefile`和`command/Makefile`中的LD及gcc参数进行修改（删除-m32和-m elf_i386参数）再进行make；  
  bochs配置文件`bochsrc`中的`romimage`,`vgaromimage`和`keymap`的路径可能需要根据运行机器的bochs具体安装路径进行修改
+ 确定bochs配置无误后编译运行即可。
```bash
  $ mkdir /mnt/floppy     //用于镜像软盘挂载。若该路径已存在可跳过。如果换为其他挂载点需要修改Makefile中的相关路径。
  $ sudo make image
  $ bochs -f bochsrc
```
+ 然后输入回车和c即可。  
+ 注意：请在make之前确认makefile无误，否则可能导致系统镜像文件·a.img·损坏。如遇此情况请重新下载……

## 功能介绍
+ 计算器   
+ 万年历
+ 开机动画
+ 石头剪刀布
+ 非常简单的help和echo应用

## 文件
+ 用户级应用在/command
