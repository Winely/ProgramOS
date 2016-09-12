# ProgramOS
The program of operating system.  
其实名为+1's大家懂的。

## 环境安装和运行
+ 首先请确认已经安装好了[`Ubuntu`](http://www.ubuntu.com/download/desktop)和[`bochs`](http://sourceforge.net/projects/bochs/)，本项目默认运行在64位系统中，如果是32位需要修改Makefile。  
+ 在Terminal中完成项目的获取和配置  
```bash
  $ git clone https://github.com/Winely/ProgramOS.git  
  $ cd ProgramOS/ProgramOS-master
  $ sudo apt-get install gzip （若已安装gzip可跳过这行）
  $ gunzip 80m.img.gz
  $ sudo make image
```
+ 假如是32位机器，需要将最外层`Makefile`和`command/Makefile`中的LD及gcc参数进行修改再进行make
+ bochs配置文件`bochsrc`中的`romimage`,`vgaromimage`和`keymap`的路径可能需要根据运行机器的bochs具体安装路径进行修改
+ 确定bochs配置无误后编译运行即可。
```bash
  $ bochs -f bochsrc
```
  然后输入回车和c即可。  

## 功能介绍
+ 计算器   
+ 万年历
+ 开机动画
+ 石头剪刀布
+ 非常简单的help和echo应用

## 文件
+ 用户级应用在/command
