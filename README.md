# ProgramOS
The program of operating system.  
其实名为+1's大家懂的。

## 环境安装
+ 首先请确认已经安装好了[`Ubuntu`](http://www.ubuntu.com/download/desktop)和[`bochs`](http://sourceforge.net/projects/bochs/)，本项目默认运行在64位系统中，如果是32位需要修改Makefile。  
+ 在Terminal中完成项目的获取和配置  
```bash
  $ git clone https://github.com/Winely/ProgramOS.git  
  $ cd ProgramOS/ProgramOS-master
```
+ 假如是32位机器，需要将最外层`Makefile`和`command/Makefile`中的LD及gcc参数进行修改
+ bochs配置文件`bochsrc`中的`romimage`,`vgaromimage`和`keymap`的路径可能需要根据机器进行修改
+ 确定bochs无误后运行脚本即可（可能需要输入密码）
```bash
  $ . plus1s
```
  然后输入回车和c即可。  

## 功能介绍
再说吧：）
