# Linux入门
该教程针对低年级**没有接触过**或**较少使用**Linux的同学，带大家了解Linux的基本知识，基本操作方式。从简单的文件操作到权限管理、进程管理、环境配置、软件包管理等实用内容，让大家学完后能顺利的在Linux中编译执行自己的程序，同时通过学习Linux的基本知识能够理解以前在编程和配置环境中遇到的问题和不懂的地方。

教程分为以下几个部分：
- Linux基本概念介绍
- 安装属于自己的Linux系统(双系统or虚拟机or服务器)
- shell的基本使用(获取帮助，文件操作，重定向)
- 实用操作(权限管理，进程管理，环境配置，软件包管理)
- 运行你的程序(包括编译程序与运行脚本。c++程序,python脚本)

## 1.Linux基本概念 
### 1.1 Linux的历史(内容均来自维基百科)
1964年，Multics(多任务信息与计算系统)由贝尔实验室、麻省理工学院及美国通用电气公司所共同参与研发，并安装在大型主机上。

1969年贝尔实验室退出Multics项目，贝尔实验室的工程师，肯·汤普逊和丹尼斯·里奇以B语言和汇编语言为基础发展出UNIX。

之后的十年中Unix在学术机构和大型企业中得到广泛应用，当时拥有UNIX的AT&T公司以低廉的价格将UNIX源码授权给学术机构做**研究**或**教学**使用，许多机构基于此源码发展出了一些“UNIX变种”。其中最著名的是BSD。

我们经常听到的“类Unix系统”指的就是各种Unix的派生系统，比如基于BSD的FreeBSD,OpenBSD,以及各种与传统Unix类似的系统，如Minix,Linux。

拥有Unix的AT&T公司认识到了其商业价值后，不再授权Unix的源码给学术机构并且对Unix及其变种声明了著作权权利。这时GNU计划出现了，GNU是"**G**NU is **N**ot **U**nix"的 ***递归缩写***。其目标是创建一套完全**自由**的操作系统。为保证GNU软件可以自由地“使用、复制、修改和发布”，所有GNU软件都包含一份在禁止其他人添加任何限制的情况下，授权所有权利给任何人的协议条款，GNU通用公共许可证。

直到1990年，GNU计划已经开发出了强大的文字编辑器Emacs,C语言编译器GCC,以及大部分UNIX系统的程序库和工具。唯独没有完成重要的操作系统内核。

1991年，Linus Benedict Torvalds发帖说明自己基于爱好在编写操作系统。许多人为这个项目贡献了代码。1991年9月Linux内核版本0.01终于发布，共有10,239行代码。由于GNU项目创造了很多操作系统需要的组件而内核无法使用，BSD操作系统正在经历法律纠纷(没错，就是AT&T干的)，早期功能有限的Linux迅速获得了开发人员和用户。

我们现在所说的Linux,通常应该指的是GNU/Linux,即GNU计划的组件与Linux内核的组合。到现在这个操作系统应该称为Linux还是GNU/Linux还存在着争议。
### 1.2 发行版
通常情况下，Linux被打包成供个人计算机和服务器使用的**发行版**，主流的Linux发布版有Debian(及其派生版本Ubuntu,Linux Mint),Fedora(及相关版本Red Hat Enterprise Linux,CentOS(停止维护))和openSUSE。发行版包含了内核，支持内核的使用程序和库，带有大量可以满足各类需求的程序。
## 2.安装属于自己的Linux系统 
### 2.1 服务器 
租借装有Linux系统的云服务器，从阿里云、腾讯云、华为云等地方租，一般针对学生有优惠。


优点：使用任何设备都可以连接访问，24小时不间断运行。可以用来搭建个人网站等。

缺点：有网的地方才能用，要钱
### 2.2 双系统
考虑到娱乐需求（主要是打游戏），大家还是比较习惯用windows或者mac，大部分人不会让电脑上只存在一个Linux系统。这时可以选择安装双系统，选择一个自己喜欢的发行版按照网上的教程安装即可~不详细说明。

优点：使用双系统，当你使用其中一个系统时，系统其实无法察觉到电脑上还有另一个系统。你正在使用的系统可以占用电脑所有的硬件资源，保证运行的效率。

缺点：系统是要占掉一部分硬盘空间的，对于硬盘容量吃紧的同学不太友好，而且安装的过程并不是那么简单。启动引导可能会出现各种各样奇怪的问题。
### 2.3 虚拟机
有人想同时操作Windows和Linux两个系统，比如在Windows上用onenote写笔记并且同时使用Linux。虚拟机通过软件模拟出完整的硬件系统功能，将模拟出的系统完全隔离出来，你可以操作现有系统一样操作虚拟系统，虚拟系统不会对现有系统造成影响。

优点：同时操作两个系统，配置比双系统简单。

缺点：无法占用全部资源，配置差的电脑用可能卡。
### 2.4 wsl(仅windows用户)
对想使用Linux的Windows用户来说wsl应该是最香的选择了。wsl是Windows Subsystem for Linux的简称。wsl有wsl1 wsl2两个版本，他们体系结构上有着比较大的区别。由于wsl1并非独立的虚拟机，为了体验更完整的Linux，我们安装wsl2即可。

安装方法参考 https://docs.microsoft.com/zh-cn/windows/wsl/install-win10

我的电脑已经安装了wsl2并且选择的分发版是Ubuntu-20.04。选择的终端应用程序是Windows Terminal。



### 2.5 vscode+Linux
vscode不管是对于远程连接服务器还是本地的wsl都有很好的支持，使用插件后可以直接在vscode中连接你的wsl或者远程Linux系统，查看、编辑文件等。
## 3.shell的基本使用 10min
当我们提到“学习Linux”的时候，通常都是从学习Linux命令行开始，而这里的命令行实际上指的是"shell"。shell是一个接收键盘输入的命令并把命令传递给操作系统来执行的程序。sh是最初的UNIX shell程序。现在几乎所有的Linux发行版都会提供bash，bash来自GNU项目，是sh的增强版本。

在使用图形用户界面的时候我们需要用终端仿真器程序与shell交互，对windows用户推荐使用Windows Terminal。

注：shell不仅仅是强大的命令行接口，还是一个脚本语言解释器，可以运行我们编写的shell脚本来完成许多复杂的任务。这部分内容无法在这里讲清楚，有兴趣可以自己去学习编写shell脚本。
### 3.1 第一次发出命令
按惯例我们应该进行Hello,World。在shell中输入
``` bash
echo "Hello,World!"
```
我们向系统发出指令，让其执行echo，"Hello,World!"是传入的参数。echo顾名思义，就是让系统“发出回声”，输出我们传入的内容。

演示结果：
``` 
qyh@LAPTOP-TRJ8FFIK:~$ echo "Hello,world!"
Hello,world!
```


### 3.2 什么是命令？
通过示例我们知道通过命令就能让系统做我们要求它做的事，那么命令的本质是什么？有以下四种情况：
- 可执行程序。包括被编译成二进制文件的程序(如C,C++编写的程序)和脚本语言编写的程序(如shell,Python等脚本语言写的程序)
- shell内置命令。bash内部自带的命令，比如之前用的echo。
- shell函数，合并到环境变量中的小型shell脚本（记得之前提到过shell也是脚本语言解释器）。这里不讨论
- alias命令。
  
通过type命令，我们可以识别一个命令属于上面四种的哪一种：
``` 
qyh@LAPTOP-TRJ8FFIK:~$ type type
type is a shell builtin
qyh@LAPTOP-TRJ8FFIK:~$ type echo
echo is a shell builtin
qyh@LAPTOP-TRJ8FFIK:~$ type ls
ls is aliased to `ls --color=auto'
qyh@LAPTOP-TRJ8FFIK:~$ type cp
cp is /usr/bin/cp
```
会发现type,echo都是内置命令，ls实际上是一个“别名”（使用alias得到的），cp则是可执行程序（顺便显示了它的文件夹）。

通过which命令我们可以显示可执行程序的位置，注意它只用于可执行程序！对于内置命令和命令别名没有用。
```
qyh@LAPTOP-TRJ8FFIK:~$ which ls
/usr/bin/ls
```

* 通过`alias`定义自己的命令：
  先为自己想定义的命令想一个名字，比如`foo`,然后用`type foo`来查看这个名字有没有被使用过。没有被使用过的话我们就可以用。我们希望这个命令是“进入根目录并显示所有文件”
  `alias foo="cd /;ls"`。定义后我们在命令行输入`foo`，便会进入根目录并显示该目录下文件。
  ```
  qyh@LAPTOP-TRJ8FFIK:~$ type foo
  -bash: type: foo: not found
  qyh@LAPTOP-TRJ8FFIK:~$ alias foo="cd /;ls"
  qyh@LAPTOP-TRJ8FFIK:~$ type foo
  foo is aliased to `cd /;ls'
  qyh@LAPTOP-TRJ8FFIK:~$ foo
  bin   dev  home  lib    lib64   lost+found  mnt  proc  run   snap  sys  usr
  boot  etc  init  lib32  libx32  media       opt  root  sbin  srv   tmp  var
  ```
### 3.3 随时获取帮助
很多时候我们可能会忘了某个命令怎么用，我们可以直接百度或者google。在没有网络或者想直接了解一个命令的情况下，也有许多方式让我们向shell寻求帮助。

1. help 获得shell内置命令的帮助文档
2. --help选项
3. man 程序手册页
4. apropos 显示合适的命令
5. whatis 命令简要描述
6. info 程序info条目

几种常用的方法已经列在上面，请牢牢记住这些求助的方式，在使用时遇到问题可以直接使用它们。下面对比较方便的前三种方法做一下演示，并且告诉大家如何看懂帮助
对于内置的命令，直接使用`help 命令名称`就可以，首先我们查看`help`命令自身的用法
```
qyh@LAPTOP-TRJ8FFIK:~$ help help
help: help [-dms] [pattern ...]
    Display information about builtin commands.

    Displays brief summaries of builtin commands.  If PATTERN is
    specified, gives detailed help on all commands matching PATTERN,
    otherwise the list of help topics is printed.

    Options:
      -d        output short description for each topic
      -m        display usage in pseudo-manpage format
      -s        output only a short usage synopsis for each topic matching
                PATTERN

    Arguments:
      PATTERN   Pattern specifying a help topic

    Exit Status:
    Returns success unless PATTERN is not found or an invalid option is given.
```
首行`help: help [-dms] [pattern ...]`告诉了我们该命令的使用格式，`[-dms]`表示可以选择的选项，每个选项的含义都在下方给出了说明，`[pattern]`则为我们要查看的内置命令的名字，是可以一次输入多个命令来查看的。尝试加上选项地使用help查看`cd`命令和`help`命令：
```
qyh@LAPTOP-TRJ8FFIK:~$ help -d cd help
cd - Change the shell working directory.
help - Display information about builtin commands.
```
`help -d cd help`表示显示cd和help的简短描述。我们可以使用help查看内置命令用法并且根据提示写出自己想要的命令。
除了内置命令我们需要使用很多别的可执行程序，这时我们可以使用`--help`选项，例如查看`mkdir`命令的帮助：
```
qyh@LAPTOP-TRJ8FFIK:~$ mkdir --help
Usage: mkdir [OPTION]... DIRECTORY...
Create the DIRECTORY(ies), if they do not already exist.

Mandatory arguments to long options are mandatory for short options too.
  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask
  -p, --parents     no error if existing, make parent directories as needed
  -v, --verbose     print a message for each created directory
  -Z                   set SELinux security context of each created directory
                         to the default type
      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux
                         or SMACK security context to CTX
      --help     display this help and exit
      --version  output version information and exit

GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Report mkdir translation bugs to <https://translationproject.org/team/>
Full documentation at: <https://www.gnu.org/software/coreutils/mkdir>
or available locally via: info '(coreutils) mkdir invocation'
```
比较详细地解释了命令的用法和各种选项，显示格式和使用help查看类似。注意这里我们会发现，选项有*长选项*和*短选项*之分，很多选项都有这两个版本，比如`-v`和`--verbose`，它们具有一样的效果，区别是短选项好写。(长选项多用于shell脚本的编写，可以提升脚本可读性)
最后来看man的用法，man命令可以显示程序的手册页，会提供很详细的程序信息，如`man ls`查看ls的手册页
```
LS(1)                                               User Commands                                               LS(1)

NAME
       ls - list directory contents

SYNOPSIS
       ls [OPTION]... [FILE]...

DESCRIPTION
       List  information  about the FILEs (the current directory by default).  Sort entries alphabetically if none of
       -cftuvSUX nor --sort is specified.

       Mandatory arguments to long options are mandatory for short options too.

       -a, --all
              do not ignore entries starting with .

       -A, --almost-all
              do not list implied . and ..

       --author
              with -l, print the author of each file

       -b, --escape
              print C-style escapes for nongraphic characters

       --block-size=SIZE
              with -l, scale sizes by SIZE when printing them; e.g., '--block-size=M'; see SIZE format below

 Manual page ls(1) line 1 (press h for help or q to quit)
```
此时会进入一个这样的界面，而不是像之前那样直接把所有信息在控制台打印出来。因为man实际上是通过调用名为`less`的阅读器来显示，之后再给大家介绍`less`的使用方法。大家现在只要知道在这个界面下按`q`可以退出，方向键和PageUp,PageDown可以翻页就行。

以上就是对命令的基本介绍，了解到了怎么查看命令的帮助和怎么使用命令，遇到新的没见过的命令时应该也能很快上手了。接下来的部分基本就是介绍各种常用命令了。
### 3.4 文件管理
#### 3.4.1 了解Linux的文件系统
类Unix操作系统的文件存放方式和大家常用的Windows其实是相同的，都是以分层目录的方式来组织文件的。文件夹里包含着子文件夹和文件，是一种树形结构。与Windows不同的是在Linux里面我们不是先进到C盘或者D盘再开文件夹，我们仅有一个根目录，就是`/`。
所有以`/`开头的路径都是绝对路径，不以`/`开头的路径都被视为相对路径。
使用`pwd`查看当前路径
```
qyh@LAPTOP-TRJ8FFIK:/home$ pwd
/home
```
当前正处在`/home`目录下，使用`ls`列出当前目录下的文件或者文件夹(子目录)
```
qyh@LAPTOP-TRJ8FFIK:/home$ ls
qyh
```
发现有一个文件夹，可以使用`cd`命令切换工作目录
```
qyh@LAPTOP-TRJ8FFIK:/home$ cd qyh
qyh@LAPTOP-TRJ8FFIK:~$ pwd
/home/qyh
```
这里的`qyh`前面是没有`/`的，所以被理解为相对路径。如果要回到`/home`目录，我们可以使用绝对路径
```
qyh@LAPTOP-TRJ8FFIK:~$ cd /home
qyh@LAPTOP-TRJ8FFIK:/home$ pwd
/home
```
`/home`最前面是`/`，表示系统的根目录，所以会被理解为绝对路径。

我们可以进入系统根目录，查看根目录下都有什么
```
qyh@LAPTOP-TRJ8FFIK:/home$ cd /
qyh@LAPTOP-TRJ8FFIK:/$ ls
bin   dev  home  lib    lib64   lost+found  mnt  proc  run   snap  sys  usr
boot  etc  init  lib32  libx32  media       opt  root  sbin  srv   tmp  var
```
这里面的文件夹是几乎所有Linux文件都有的，/bin是Bianaries的缩写，存放常用的命令。/boot存放Linux启动使用的一些核心文件。/dev为设备，表示Linux连接的设备。在万物皆文件的Linux里访问设备的方式和访问文件是相同的。/etx是Etcetera的简写，用来存放系统管理所需要的配置文件和子文件。/home是用户的主目录，Linux作为多用户系统，每个用户都会被分配一个自己的目录，比如刚刚我演示的/home/qyh这个目录就是属于我的主目录。/lib存放系统基本的动态链接共享库，作用类似Windows里的DLL。/mnt允许用户临时挂在别的文件系统，若你使用wsl,你的windows上的C盘D盘等都会被挂载在这里，如下
```
qyh@LAPTOP-TRJ8FFIK:/$ cd mnt
qyh@LAPTOP-TRJ8FFIK:/mnt$ ls
c  d  e  f  i  j  k  wsl
```
/root是系统管理员的目录。/sbin就是属于管理员的/bin。/usr是unix shared resources的缩写，是很重要的目录，用户很多应用程序和文件都放在这里，类似windows的program files。
这些文件夹的含义没必要特别去记，多用几次就大概知道了。个人感觉用得比较多的就是/bin,/home,/etc,/usr这几个。
#### 3.4.2 工作目录及相关操作(pwd,ls,cd)
之前提到了几个命令，现在稍微详细地介绍一下
当我们只有命令行可以用的时候，我们没有可视化的文件管理系统，无法直观的看到文件结构。我们仅能处于一个工作目录中，相当于我们在文件系统树的一个节点上，使用`pwd`就可以查看当前我们处在的工作目录(即我们在文件树的哪个节点上)。pwd会显示出绝对路径。
`ls`可以说是最常用的命令之一，可以列出当前工作目录下的目录和文件，我们可以用之前学到的`ls --help`来查看其用法。`ls`的选项非常多，这里没法一一讲解。常用的有：
-a:列出所有文件，隐藏文件也会被列出
-h:以人们可读的方式列出(用人可读的文件大小，前提是采用了长格式)
-l:长格式
-r,--reverse:用相反的顺序显示结果
-S:按文件大小显示
-t:按时间顺序
比如我要按时间顺序列，以人能阅读的方式，列出所有文件：
```
qyh@LAPTOP-TRJ8FFIK:/mnt/f/workPlace/learnLinux$ ls -ahtl
total 40K
-rwxrwxrwx 1 qyh qyh  17K Mar 19 15:52 Notes.md
drwxrwxrwx 1 qyh qyh 4.0K Mar 11 22:15 ..
-rwxrwxrwx 1 qyh qyh  17K Mar  5 11:36 test
drwxrwxrwx 1 qyh qyh 4.0K Mar  5 11:36 .
-rwxrwxrwx 1 qyh qyh  111 Mar  5 11:36 test.cpp
drwxrwxrwx 1 qyh qyh 4.0K Mar  1 15:01 .git
-rwxrwxrwx 1 qyh qyh   66 Mar  1 15:01 .gitattributes
-rwxrwxrwx 1 qyh qyh   33 Mar  1 15:01 README.md
```

`cd`更改当前工作目录，之前已经提到过可以用相对路径名和绝对路径名来切换路径。还有几个用法没有讲:
`.`表示工作目录,`..`表示工作目录父目录，`-`表示上一个目录,`~`表示用户的目录。
用cd加上它们就能切换到指定的目录。而直接使用`cd`不加参数，会切换到当前用户主目录(和`cd ~`效果相同)。
```
qyh@LAPTOP-TRJ8FFIK:/mnt/f/workPlace/learnLinux$ cd
qyh@LAPTOP-TRJ8FFIK:~$ pwd
/home/qyh
```
#### 3.4.3 查看文件(file,less)
`file`后面加上文件名可以查看文件类型
```
qyh@LAPTOP-TRJ8FFIK:/mnt/f/workPlace/learnLinux$ file Notes.md
Notes.md: UTF-8 Unicode text, with very long lines
```
`less`可以查看文件的内容，使用方式为`less filename`。之后进入到了阅读文件的界面，使用page up或者b向后翻页，page down向前翻页，箭头键每次移动一行，G跳转到文件结尾，q退出，h显示帮助界面。输入`/characters`可以查找指定字符串，按n向下查找下一个字符串
#### 3.4.4 操作文件(通配符简介*(不一定讲),cp,mv,mkdir,rm,ln)
通配符是shell非常强大的特性，类似正则表达式。这里只介绍最常用的两个通配符，其他的大家可以自己去学习。
*代表任意多个字符，0个到多个都行。？代表匹配单个字符，不包括0个。比如`b*.txt`就代表了所有以b开头的`.txt`文件。可以方便地批量处理文件。
下面简单地介绍常用的文件操作命令，具体的选项大家之后可以通过help获取。
mkdir——创建目录
`mkdir directory ...`
可以一次创建多个
cp——复制文件和目录
`cp item1 item2`
把单个文件item1的内容复制到item2
`cp item... directory`
复制多个文件到文件夹中。
最常用的选项有-i,使用该选项，在复制的时候遇到重复文件会向用户询问。-r表示递归地复制，当复制目录地时候必须加这个。
可以利用通配符来进行复制，比如把所有jpg图片都复制到一个文件夹：
`cp *.jpg pictures`

mv——移动和重命名
使用格式和cp一样
`mv item1 item2`
把单个文件item1的内容移动到item2，若item2本来不存在，这个操作就相当于把item1重命名为了item2。
`mv item... directory`
移动多个文件到文件夹中。
选项-i和cp中一样，覆盖文件时提示用户确认。移动文件夹的时候不需要加别的选项。

rm——删除文件和目录
`rm item..`
一定要小心地使用！选项-i意义和之前说的一样，提示用户确认，-r表示递归地删除目录下所有东西。-f表示忽略不存在的文件且不需要提示确认。

ln——创建链接
`ln file link`创建硬链接
`ln -s item link`创建符号链接
简要地介绍一下硬链接，是最初UNIX用于创建链接地方式，默认情况下，每个文件都会有一个硬链接，该硬链接会给文件命名。但是硬链接不能引用文件系统之外的文件，无法引用目录。当一个文件所有的硬链接都被删除，它才会被真正删除。我们更常用的是符号链接
符号链接和Windows的快捷方式十分相似。直接当作快捷方式来使用就行。如果一个符号链接指向的文件被删除了，那这个符号链接就是一个坏链接，虽然存在，但是不指向任何文件。
### 3.5 重定向介绍
这一节要讲的内容是I/O重定向，这可能是命令行最酷的功能了。大家都知道I/O代表的是input和output，通过这个功能，我们可以把命令行的输出结果定向到文件中，也可以让命令行读取文件的中的内容作为输入。我们还可以通过管道把多个命令拼接变为非常强大的命令。
#### 3.5.1 标准输入输出和标准错误
当我们运行程序的时候，会看到不同的输出。比如我们使用ls列出文件，成功时可以看到结果的输出，编译出现错误会看到错误的提示
```
qyh@LAPTOP-TRJ8FFIK:~$ ls
Makefile   clear.py  code.o  data.dat    paper.aux  paper.pdf  plot-data.png  test-copy.txt
bubble.py  code.c    code.s  learnLinux  paper.log  paper.tex  plot.py        test.txt
```
```
qyh@LAPTOP-TRJ8FFIK:~$ ls code
ls: cannot access 'code': No such file or directory
```
实际上错误信息和运行正确时看到的信息来自于不同的地方。
UNIX有一切皆文件的思想，所有的这些程序如ls，会把它们运行的结果发送到一个称为“标准输出”(standard error,简称stdout)的特殊文件中，而程序的状态信息被发送到被称为“标准错误”(standard error,stderr)的特殊文件中。默认情况下，标准输出和标准错误都被链接到了屏幕上，而不会被保存在磁盘中。所以我们运行程序的时候会直接在屏幕上看到结果和错误信息。
而程序的输入来自“标准输入”(standard inputmstdin)。默认情况下标准输入连接到键盘上。
所以所谓的I/O重定向功能，就是改变程序内容发送的目的地和程序接受内容的来源，来达到我们想要的效果。
比如我们想保存当前目录下文件的详细信息到文件中，就需要让ls把结果输出到文件中，这时候我们只需要使用符号">"即可。
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l >ls-out.txt
```
我创建了名为IO的文件夹，在这个文件夹下有一个test.txt。用ls -l查看。
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l
total 4
-rw-r--r-- 1 qyh qyh 12 Mar 25 16:23 test.txt
```
现在我在这个文件夹下运行命令，并把输出重定向到ls-out.txt中，现在再使用ls -l,发现
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l
total 8
-rw-r--r-- 1 qyh qyh 102 Mar 25 16:24 ls-out.txt
-rw-r--r-- 1 qyh qyh  12 Mar 25 16:23 test.txt
```
多出了文件ls-out.txt，查看这个文件的内容：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat ls-out.txt
total 4
-rw-r--r-- 1 qyh qyh  0 Mar 25 16:24 ls-out.txt
-rw-r--r-- 1 qyh qyh 12 Mar 25 16:23 test.txt
```
显示出的是ls -l的结果，但和我们当初直接运行命令看到的不一样
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l
total 4
-rw-r--r-- 1 qyh qyh 12 Mar 25 16:23 test.txt
```
原因是当我们使用">"重定向输出到文件时，如果那个文件存在，会将那个文件清空并向里面输入(就像C语言等编程语言中文件读取的"w"模式)，如果文件不存在，就会先创建那个文件。这里运行`ls -l >ls-out.txt`，由于`ls-out.txt`不存在，所以先创建了这个空文件，然后执行`ls -l`，把结果输出到文件中，自然这次`ls -l`就显示出了刚刚创建的新文件，可以看到文件的大小是0。

现在我们接着上一步，在这个文件夹下故意执行一个错的命令，让ls列出一个不存在的文件夹,并且重定向到ls-out.txt中，查看结果：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l unknow >ls-out.txt
ls: cannot access 'unknow': No such file or directory
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat ls-out.txt
```
会发现错误信息直接显示了出来，查看ls-out.txt的时候没有输出任何内容：这次重定向根本没有传输任何信息给ls-out.txt，而是把错误显示在了屏幕上。这是因为`>`仅仅重定向了标准输出，而错误信息默认输出到了标准错误中，那么怎么把标准错误输出到文件中呢？使用`2>`就可以了：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l unknow 2>ls-out.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat ls-out.txt
ls: cannot access 'unknow': No such file or directory
```
这样我们就成功让标准错误输出到了文件中。为啥要这样呢，实际上在shell内部，给了文件流三个索引，0代表标准输入，1代表标准输出，2代表标准错误。所以想把文件的输出重定向，也可以用`1>`来代替`>`。

由于`command > file`相当于"只写模式",所以我们可以直接用`> file`来达到清空文件或者创建新文件的效果。
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls
ls-out.txt  test.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ >new_file.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls
ls-out.txt  new_file.txt  test.txt
```
有的时候我们并不想让输出内容覆盖整个文件，而是添加在文件末尾(即append模式)，这时使用`>>`就可以实现。当然如果文件本来不存在，`>>`的效果就和`>`一样，会创建新的空文件并向其中写入。
重复命令三次并查看结果
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l >>ls-a.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l >>ls-a.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l >>ls-a.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat ls-a.txt
total 8
-rw-r--r-- 1 qyh qyh  0 Mar 25 16:49 ls-a.txt
-rw-r--r-- 1 qyh qyh 54 Mar 25 16:35 ls-out.txt
-rw-r--r-- 1 qyh qyh  0 Mar 25 16:47 new_file.txt
-rw-r--r-- 1 qyh qyh 12 Mar 25 16:23 test.txt
total 12
-rw-r--r-- 1 qyh qyh 198 Mar 25 16:49 ls-a.txt
-rw-r--r-- 1 qyh qyh  54 Mar 25 16:35 ls-out.txt
-rw-r--r-- 1 qyh qyh   0 Mar 25 16:47 new_file.txt
-rw-r--r-- 1 qyh qyh  12 Mar 25 16:23 test.txt
total 12
-rw-r--r-- 1 qyh qyh 401 Mar 25 16:49 ls-a.txt
-rw-r--r-- 1 qyh qyh  54 Mar 25 16:35 ls-out.txt
-rw-r--r-- 1 qyh qyh   0 Mar 25 16:47 new_file.txt
-rw-r--r-- 1 qyh qyh  12 Mar 25 16:23 test.txt
```
有的时候我们希望把错误信息和输出信息定向到同一个文件，此时有两种做法，第一个是传统做法
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l >ls-out.txt 2>&1
```
注意必须要按照这个格式书写，如果把顺序改成了`2>&1>ls-out.txt`，标准错误就会被定向到屏幕上。
所以我更推荐比较新的bash中提供的更加方便的写法：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l &>ls-out.txt
```
使用"&>"表示标准输出和标准错误都重定向到指定文件中。

输出的垃圾桶:/dev/null,当你不想要某个输出，就把输出重定向到/dev/null这个特殊的文件中。
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l &>/dev/null
```

cat(concatenate)命令的功能是把多个文件连接在一起，格式为`cat [file ...]`。它会把连接后的结果直接输出，如果只有一个文件作为参数，cat就相当于显示该文件中的内容。(实际上也经常这么用)
很多命令都和cat一样是需要接受一些参数的，我们就用cat来举例如何实现标准输入的重定向。
首先创建文件hello.txt,里面写了"Hello,world"。我们可以直接用cat查看
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat hello.txt
Hello,world
```
如果我们不给cat传递参数：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat
```
程序会挂起，此时cat希望从标准输入——即键盘中获取内容，我们用键盘输入一些内容后，俺Ctrl+D告知cat输入完毕
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat
Hello,world
Hello,world
```
cat会输出我们输入的内容。现在我们不通过默认的标准输入(键盘)传递内容，而是使用重定向符`<`来传递：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat <hello.txt
Hello,world
```
此时，hello.txt中的内容会代替键盘输入传递给cat,我们可以看到输出的内容就是hello.txt的内容。

通过上面几条运行命令的方法和结果，我们明白了`<`可以把文件中的内容传递给命令作为命令的输入。
接下来我们就来学习更有用的传递内容给命令的方式：管道。

#### 3.5.2 管道
管道的格式为
`command1 | command2`
它的功能就是把`command1`的输出发送到`command2`，是一个相当方便的功能。比如我们可以把ls的输出发送到less，来查看ls的输出(尤其是在文件很多的时候，这样是很方便的)
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l | less
```
```
total 16
-rw-r--r-- 1 qyh qyh  12 Mar 25 17:04 hello.txt
-rw-r--r-- 1 qyh qyh 604 Mar 25 16:49 ls-a.txt
-rw-r--r-- 1 qyh qyh 202 Mar 25 16:57 ls-out.txt
-rw-r--r-- 1 qyh qyh   0 Mar 25 16:47 new_file.txt
-rw-r--r-- 1 qyh qyh  12 Mar 25 16:23 test.txt
(END)

```
下面介绍一些管道的妙用和相关的命令
过滤器：
管道的功能经常用来对数据进行复杂的操作，可以把多条命令用管道连接在一起来处理数据，这种方式中使用的命令通常被称为过滤器。比如我们要列出/bin和/usr/bin下的所有可执行程序，排序后进行查看：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /bin /usr/bin |sort|less
```
使用uniq来报告或者忽略重复的行
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /bin /usr/bin |sort|uniq|less
```
只需要在之前命令的基础上加一个uniq，就可以把重复的行去除。如果反过来想看重复的有哪些，使用`uniq -d`即可：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /bin /usr/bin |sort|uniq -d|less
```

统计行数，字数，字节数
命令wc(word count)用于显示包含的行数、字数、字节数。加上参数-l可以只报告行数。
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /bin /usr/bin |sort|uniq |wc
   1317    1316   12672
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /bin /usr/bin |sort|uniq |wc -l
1317
```

打印匹配行
grep命令是一个很常见的命令，在进程管理、文件管理等任务种也经常使用。grep命令的格式是
`grep pattern [file...]`
当grep在文件中遇到pattern的时候，会打印包含该pattern的行，支持单纯的文本匹配和正则表达式匹配。比如我们想查询可执行程序中所有带apt的程序：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /bin /usr/bin |sort|uniq |grep apt
add-apt-repository
apt
apt-add-repository
apt-cache
apt-cdrom
apt-config
apt-extracttemplates
apt-ftparchive
apt-get
apt-key
apt-mark
apt-sortpkgs
captoinfo
debconf-apt-progress
```
grep有两个方便的选项，-i可以忽略大小写。-v进行反选：输出不匹配的选项

打印文件的开头和结尾
使用head和tail。很多时候我们需要查看文件的开头和结尾来确认文件内容。使用`head -n x`来输出文件前x行，`tail -n x`输出文件后x行。

T形管道
有的时候我们既想把输出存储下来，也希望在控制台输出，这时候我们可以使用T形管道——命令名tee,tee会将读取的输入复制到标准输出，并且允许内容从管道传下去，就像一个T形管道。比如我们想把ls的结果保存下来，同时希望用grep进行过滤，可以这样操作：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls /usr/bin | tee ls.txt | grep zip
bunzip2
bzip2
bzip2recover
gpg-zip
gunzip
gzip
zipdetails
qyh@LAPTOP-TRJ8FFIK:~/IO$ head ls.txt -n 10
NF
VGAuthService
X11
[
aa-enabled
aa-exec
add-apt-repository
addpart
addr2line
afm2pl
```
我们同时把结果保存到了ls.txt,并用grep进行了筛选。
### 3.6* 扩展
当我们敲完命令，敲下回车的时候，shell会对我们敲的内容进行“扩展”，这部分内容还是比较复杂的。我在这里仅做一个简要的介绍。
### 3.6.1 路径名称扩展
我们用echo进行实验，在目录下下执行`echo *`，会发生什么呢？直觉上来说，echo应该输出它后面跟着的内容，那么我们应该看到的输出就是"*",而实际上：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo *
hello.txt ls-a.txt ls-out.txt ls.txt new_file.txt test.txt
```
列出的是当前目录下的所有文件?这是因为之前我们提到过的，“*”是一个通配符，它匹配一个或多个字符，所以当我们敲下回车的时候，它就被扩展成了当前目录下与其匹配的文件名：即所有文件。我们可以尝试`echo l*`
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo l*
ls-a.txt ls-out.txt ls.txt
```
果然列出的是所有l开头的字符串。这就是扩展，在我们敲下回车的时候，某些符号会被解释成特殊的含义。比如"~"被解释为用户名
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo ~
/home/qyh
```

### 3.6.2 算数扩展
利用算数扩展，我们可以用shell进行简单的运算，格式为
`$((expression))`
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo $((5+5))
10
```
支持的运算符号包括+,-,*,/,%,**

### 3.6.3 花括号扩展
花括号类似于正则表达式中的[],取内部字符的或运算，且支持字符区间。
比如`{A,B,C}`表示A或B或C,`{A..Z}`则表示A到Z的任意字符。下面用echo实验几个花括号扩展
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo {A..Z}
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo {A{1,2},B{3,4}}
A1 A2 B3 B4
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo {A{1,2}B{3,4}}
{A1B3} {A1B4} {A2B3} {A2B4}
```
花括号表达式经常用来表示一些列文件或者目录。比如创造2020年1月到2021年12月的文件夹
```
mkdir {2020,2021}-{1..12}
```
可以试试这样的表达式会生成什么：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo {2020,2021}-{1..12}
2020-1 2020-2 2020-3 2020-4 2020-5 2020-6 2020-7 2020-8 2020-9 2020-10 2020-11 2020-12 2021-1 2021-2 2021-3 2021-4 2021-5 2021-6 2021-7 2021-8 2021-9 2021-10 2021-11 2021-12
```

### 3.6.4 参数扩展
我们的系统中存放着许多环境变量，我们可以用`$PARAM`来读取这些变量的值，如
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo $USER
qyh
```
可以显示当前用户。

### 3.6.5 命令替换
我们可以把一个命令的输出作为一个扩展来使用，格式为`$(command)`
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ echo $(ls)
hello.txt ls-a.txt ls-out.txt ls.txt new_file.txt test.txt
```

### 3.6.6 引用
并不是所有时候我们都希望参数扩展和单词分割(shell默认用空格符把输入的命令分割，比如现在有一个带空格的目录"my dir"，那么直接用 `cd my dir`试图进入该文件夹时，由于my和dir被视为两个变量，就会发生错误)
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls
 hello.txt   ls-a.txt   ls-out.txt   ls.txt  'my dir'   new_file.txt   test.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ cd my dir
-bash: cd: too many arguments
```
这时我们可以使用双引号，双引号可以避免单词的分割，同时禁止除"$","\","`"外的所有扩展，比如"~","*"都会失去效果。我们使用""就可以进入有空格的文件夹了：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cd "my dir"
qyh@LAPTOP-TRJ8FFIK:~/IO/my dir$
```
但是加上双引号后，算数扩展和参数扩展等依旧有效
```
qyh@LAPTOP-TRJ8FFIK:~/IO/my dir$ echo "$((2+3)) apples"
5 apples
```
更加强大的是单引号''，可以禁止一切扩展，单引号内的字符串直接被当成自身不进行任何扩展。
```
qyh@LAPTOP-TRJ8FFIK:~/IO/my dir$ echo '$((2+3)) apples'
$((2+3)) apples
```

### 小结
现在已经把命令行的基本要素都简要地做了介绍，如果明白了前面的内容，当你到网上查看某些环境配置教程的时候，就不会摸不着头脑地对其复制粘贴了。利用这些基础知识应该可以理解网上大部分关于命令行的操作了，就算不能理解，也可以通过help和man等手段去研究。
这里再补充几个常见的操作，一些同学应早就直到了：
在命令行按方向键上下，可以显示上一条命令和下一条命令。`cd -`可以进入上一个工作目录。通常在命令行里Ctrl+C,Ctrl+v是有别的含义的，复制和粘贴可以直接用鼠标右键进行。
## 4.实用操作 15min 
下面介绍一些所有人都用得到(以后总会用到)的操作，顺便可以帮助理解Linux这个系统。对于每个板块不会太深入地讲解，只会重点讲里面最基础的内容，大家有兴趣可以自己去查找资料做深入的了解。
### 4.1 权限管理
对Windows用户来说，权限管理并不是那么熟悉。只有在安装程序等操作的时候会有提示框让我们进行确认，少部分操作会要求我们使用“管理员权限”。而UNIX在设计之初就是一种多用户的系统，因为在那个时代很少有个人电脑，大家都是共用大型的计算机，所以多用户的设计和权限管理是非常重要的。Linux作为类Unix系统自然也有这样的特性。
很多时候我们可能要用学校或其他单位提供的服务器跑代码等，也有可能在将来我们自己成为了一台服务器的管理员。所以学习权限管理的方法是很重要的
#### 4.1.1 各种类型的用户
我们用之前提到的file命令查看文件`/etc/shadow`的属性，并尝试用用less来查看文件：
```
qyh@LAPTOP-TRJ8FFIK:~/IO/my dir$ file /etc/shadow
/etc/shadow: regular file, no read permission
qyh@LAPTOP-TRJ8FFIK:~/IO/my dir$ less /etc/shadow
/etc/shadow: Permission denied
```
会发现我们并没有权限访问，因为我们在系统中仅仅是一个“普通用户”，没有读取权限。
在UNIX的安全模型中，用户可以拥有文件和目录。当一个文件或者目录归一个用户所有，该用户就拥有对该文件权限的控制权。用户还可以归属于一些群组，用户可以把自己的文件的访问权限授予给特定的群组。
我们可以使用命令id来查看用户身份标识的相关信息。
```
qyh@LAPTOP-TRJ8FFIK:~/IO/my dir$ id
uid=1000(qyh) gid=1000(qyh) groups=1000(qyh),4(adm),20(dialout),24(cdrom),25(floppy),27(sudo),29(audio),30(dip),44(video),46(plugdev),117(netdev),1001(docker)
```

#### 4.1.2 权限与更改权限
对文件和目录的访问权限按 读访问、写访问和执行访问来分。我们用ls -l命令的时候就会显示出一个文件的权限：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l hello.txt
-rw-r--r-- 1 qyh qyh 12 Mar 25 17:04 hello.txt
```
字符"-rw-r--r--"表示了文件的权限。第一个字符"-"表示文件类型，"-"就是普通文件，"d"表示目录。2-4个字符表示当前用户所有者的权限，其中r为读取权限，w为写入权限，x为运行权限(对文件来说是运行，对目录来说是进入的权限)，-为该项权限确实。5-7个字符表示组权限，8-10个字符表示其他用户权限。
下面给出几个文件权限的示例，大家可以看看对应什么权限
`-rwx------` 当前用户拥有该文件的全部权限，而组成员和其他用户没有任何权限
`-rw-r--r--` 当前用户可对当前文件进行读写，组成员和其他用户只能读
`-rwxr-xr-x` 当前用户可对当前用户读写、执行，其他用户和组成员可读可执行
`drwxr-x---` 当前用户可以进入并更改目录，组成员可以进入该目录并查看，但是不能更改。其他用户无权限。

作为文件所有者，我们可以改变文件的权限，一种比较直观的方法是用上面讲的符号来改变，使用命令
`chmod`命令，用u指代当前用户，g表示用户组(文件所属的用户组),o表示其他所有用户，a表示ugo的结合。+表示添加权限，=表示只有指定权限可用，-表示减少权限。权限由r,w,x来指定。如
`chmod u+x`,给当前用户增加执行权限，`chmod o-rw`,禁止其他用户读取和写入，`go=rx`,允许组成员和其他成员读取和执行。
比如我让自己无法访问hello.txt:
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat hello.txt
Hello,world
qyh@LAPTOP-TRJ8FFIK:~/IO$ chmod u-r hello.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ ls -l hello.txt
--w-r--r-- 1 qyh qyh 12 Mar 25 17:04 hello.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat hello.txt
cat: hello.txt: Permission denied
```
再改回来：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ chmod u=rw hello.txt
qyh@LAPTOP-TRJ8FFIK:~/IO$ cat hello.txt
Hello,world
```

#### 4.1.3 更改身份
有三种方法在Linux上转变自己的身份，其中一种是注销再用别的账户登陆，这里就不介绍了。主要介绍获取“超级用户”权限的方式
`su` 以其他用户和组ID的身份来运行shell
`su [-[l]] [user]`
若使用-l选项，那么shell会进入指定用户的登陆界面，也就意味着登陆后会加载对应用户的运行环境，工作目录也会更改为该用户的主目录。-l可以简写为'-'。如果不指定特定的user,默认为超级用户。
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ su -
Password:
Welcome to Ubuntu 20.04.1 LTS (GNU/Linux 4.19.128-microsoft-standard x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Thu Mar 25 21:44:12 CST 2021

  System load:  0.03               Processes:             10
  Usage of /:   1.0% of 250.98GB   Users logged in:       0
  Memory usage: 0%                 IPv4 address for eth0: 172.17.110.55
  Swap usage:   0%

258 updates can be installed immediately.
81 of these updates are security updates.
To see these additional updates run: apt list --upgradable



This message is shown once once a day. To disable it please create the
/root/.hushlogin file.
root@LAPTOP-TRJ8FFIK:~#
```
使用exit可以退出，回到之前的用户。
注意：如果你安装的也是wsl,安装的时候是没有设置root密码的，需要用`sudo passwd root`来设置root密码，才能用`su -`命令。

`sudo` 以另一个用户的身份执行命令
可以说sudo是最常用的命令之一了，它与su命令很类似，但是有一个很重要的功能。就是管理者可以通过配置sudo命令，以一种可控的方式允许普通用户以不同用户的身份执行命令。
直接使用sudo加上自己想要执行的命令后，系统要求输入**当前用户的密码**，验证过后就能获得权限了。利用sudo我们可以访问之前无法访问的文件了：
```
qyh@LAPTOP-TRJ8FFIK:~/IO$ sudo cat /etc/shadow
root:$6$66XtLJ0I.7WJSful$EdBZYmrcOlvG7LaKzTxVrI8x8raZs5K7qXa514vwZ/cHjKNFPChOvMlpPtR2B3.fOqQnwP6Emwke9ZXdDJZYr0:18711:0:99999:7:::
daemon:*:18478:0:99999:7:::
bin:*:18478:0:99999:7:::
sys:*:18478:0:99999:7:::
sync:*:18478:0:99999:7:::
games:*:18478:0:99999:7:::
man:*:18478:0:99999:7:::
lp:*:18478:0:99999:7:::
mail:*:18478:0:99999:7:::
news:*:18478:0:99999:7:::
uucp:*:18478:0:99999:7:::
proxy:*:18478:0:99999:7:::
www-data:*:18478:0:99999:7:::
backup:*:18478:0:99999:7:::
list:*:18478:0:99999:7:::
```
还有命令chown可以更改文件的所有者和所属群组，shgrp可以更改文件所属群组，在这里不展开介绍了。(因为我也没用过，前面说的几个更常用)
### 4.2 进程管理
现代操作系统都是支持多重任务处理的，谁不是挂着腾讯会议然后在一旁打游戏/刷知乎/刷b站呢...多重任务处理实际上是系统快速切换运行中的程序来实现多任务同时进行。Linux内核通过使用进程来管理多重任务。有的时候我们的系统可能出现卡顿或者程序停止响应等情况，这时我们就需要手动对进程进行管理(就像windows下可以开启任务管理器并手动终止进程)
当系统启动的时候，内核会运行一些程序来进行初始化，并且开启一些系统服务，这些系统服务很多都是守护进程，在后台默默做自己的工作。内核会保存每个进程的信息，给每个进程分配一个PID(Process ID),进程ID是按照递增分配的。
#### 4.2.1 查看进程信息
使用`ps`可以查看进程的信息
```
qyh@LAPTOP-TRJ8FFIK:~$ ps
  PID TTY          TIME CMD
   11 pts/0    00:00:00 bash
   83 pts/0    00:00:00 ps
```
默认情况下只会显示和当前终端会话相关的进程信息。第一列是PID,第二列TTY(teletype,电传打字机)代表了进程的控制终端，第三列是运行时间，第四列是对应命令。
使用`ps x`可以显示所有的进程，而不需要关心进程由哪个终端控制。TTY中显示？表示没有控制终端。
```
qyh@LAPTOP-TRJ8FFIK:~$ sudo ps x
[sudo] password for qyh:
  PID TTY      STAT   TIME COMMAND
    1 ?        Sl     0:00 /init
    9 ?        Ss     0:00 /init
   10 ?        S      0:00 /init
   85 pts/0    S+     0:00 sudo ps x
   86 pts/0    R+     0:00 ps x
```
会发现输出结果中有一列叫STAT,显示进程的状态。S是睡眠，R是运行等。
另一个常用的选项是aux,`ps aux`可以显示属于每个用户的进程信息
```
qyh@LAPTOP-TRJ8FFIK:~$ ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.0  0.0    896   576 ?        Sl   09:59   0:00 /init
root         9  0.0  0.0    904    84 ?        Ss   09:59   0:00 /init
root        10  0.0  0.0    904    88 ?        R    09:59   0:00 /init
qyh         11  0.0  0.0  10056  5016 pts/0    Ss   09:59   0:00 -bash
qyh         87  0.0  0.0  10604  3348 pts/0    R+   10:07   0:00 ps aux
```

除了ps之外，我们还可以使用top命令，该命令会显示一个持续更新的进程信息，还包括系统的状态信息。很像windows的任务管理器。它默认3秒更新一次状态
```
top - 10:09:17 up 9 min,  0 users,  load average: 0.00, 0.00, 0.00
Tasks:   5 total,   1 running,   4 sleeping,   0 stopped,   0 zombie
%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
MiB Mem :  12682.7 total,  12538.2 free,     85.7 used,     58.8 buff/cache
MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12419.8 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    1 root      20   0     896    576    512 S   0.0   0.0   0:00.02 init
    9 root      20   0     904     84     20 S   0.0   0.0   0:00.00 init
   10 root      20   0     904     88     20 S   0.0   0.0   0:00.01 init
   11 qyh       20   0   10056   5016   3272 S   0.0   0.0   0:00.08 bash
   88 qyh       20   0   10860   3696   3184 R   0.0   0.0   0:00.00 top
```


#### 4.2.2 中断进程
我编写了一个无尽循环的python程序,保存为test.py：
```python
#! /bin/python3
import time
i=0
while True:
       time.sleep(1)
       i+=1
       print(i)
```
现在我用`python3 test.py`，就可以看到它不断地打印数字，我觉得有些烦想关掉...这时候只需要按`Ctrl-C`就可以告诉程序，你应该拜拜了，然后程序就会停止运行。虽然这样很方便，但是并非所有程序都能这样中断。
```
qyh@LAPTOP-TRJ8FFIK:~$ python3 test.py
1
2
3
4
^CTraceback (most recent call last):
  File "test.py", line 5, in <module>
    time.sleep(1)
KeyboardInterrupt

qyh@LAPTOP-TRJ8FFIK:~$
```

#### 4.2.3 后台运行
有的时候大家想在回寝的路上也能跑程序，并且不想成为学堂路车神，那么学会后台运行是很必要的。一个简单的方法是在命令后面加上“&”字符，shell就会让这个程序在后台运行。我们还是用上面的python程序来看看效果，为了不让其输出影响我们，我们把输出重定向到一个文件里。
```
qyh@LAPTOP-TRJ8FFIK:~$ python3 test.py >> py-out.txt &
[2] 46
```
下面显示的[2] 46表示该程序的作业编号为2，PID是46，我们可以通过ps查看到该程序
```
qyh@LAPTOP-TRJ8FFIK:~$ ps
  PID TTY          TIME CMD
   11 pts/0    00:00:00 bash
   46 pts/0    00:00:00 python3
   47 pts/0    00:00:00 ps
```
还可以使用jobs命令来查看(以作业的形式，看到的会是作业编号)
```
qyh@LAPTOP-TRJ8FFIK:~$ jobs
[2]+  Running                 python3 test.py >> py-out.txt &
```

现在这个程序在后台运行，我们想把它切回到前台，我们只需要使用fg跟上%作业号即可，回到前台后我们就可以用Ctrl-C终止命令了
```
qyh@LAPTOP-TRJ8FFIK:~$ fg %2
python3 test.py >> py-out.txt
^CTraceback (most recent call last):
  File "test.py", line 5, in <module>
    time.sleep(1)
KeyboardInterrupt
```
我们用`cat py-out.txt`看看输出的结果
```
qyh@LAPTOP-TRJ8FFIK:~$ cat py-out.txt
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
...这里省略很多数字
250
```
发现这个程序之前确实一直在后台运行。

#### 4.2.4 暂停
在程序运行的时候，通过Ctrl-Z可以暂停前台进程。我们可以通过jobs查看其作业编号，通过fg %作业号 来恢复进程。或者通过bg %作业号 在后台恢复进程。
```
qyh@LAPTOP-TRJ8FFIK:~$ python3 test.py >>py-out.txt
^Z
[1]+  Stopped                 python3 test.py >> py-out.txt
qyh@LAPTOP-TRJ8FFIK:~$ jobs
[1]+  Stopped                 python3 test.py >> py-out.txt
qyh@LAPTOP-TRJ8FFIK:~$ bg %1
[1]+ python3 test.py >> py-out.txt &
qyh@LAPTOP-TRJ8FFIK:~$ jobs
[1]+  Running                 python3 test.py >> py-out.txt &
qyh@LAPTOP-TRJ8FFIK:~$ fg %1
python3 test.py >> py-out.txt
^CTraceback (most recent call last):
  File "test.py", line 5, in <module>
    time.sleep(1)
KeyboardInterrupt
```

#### 4.2.5 杀死进程
终于要登场了，我们的kill。很多人都见过这个命令,当程序关不掉的时候我们就直接手动杀死。
比如我们在后台运行刚刚的程序，然后通过`kill PID`可以强制其停止。
```
qyh@LAPTOP-TRJ8FFIK:~$ python3 test.py >>py-out.txt &
[1] 54
qyh@LAPTOP-TRJ8FFIK:~$ kill 54
qyh@LAPTOP-TRJ8FFIK:~$ jobs
[1]+  Terminated              python3 test.py >> py-out.txt
```
kill命令本质上是向程序发送了"信号",之前其实我们已经体验过了信号的功能——Ctrl-C和Ctrl-Z都是在发送信号给程序，Ctrl-C发送的是名为INT(Interrupt)的信号，而Ctrl-Z发送的是名为TSTP(Terminal Stop)的信号。程序收到信号以后可以根据信号的类别进行不同的操作。
#### 4.2.6 信号简介
kill的完整用法是`kill [-signal] PID...`，如果没有设置信号，默认发送TERM(Terminate)，当程序还有“活力”来接受信号的时候，程序会停止。不过还有可能，程序已经完全僵死了，它收到TERM这个信号都无法停止自己了，这是非常糟糕的。这时候我们不得不用最终的手段——KILL信号。
通常程序收到TERM这样的信号就会选择死亡了，但是本质上这个“选择死亡”的过程是交给程序自己处理的：程序可以在捕捉到这个信号后保存自己运行的信息，处理好自己的后事，然后再关闭。由于这个过程完全由程序自己决定，所以程序也可以选择不死亡！比如我可以编写一个烦人的程序，在接收到TERM信号后也坚持运行，非常叛逆
```
qyh@LAPTOP-TRJ8FFIK:~$ python3 ignore_signal.py
^C不要停下来啊
^C不要停下来啊
```
该程序代码如下
```python
import signal
import time
def ignore(signum,frame):
    print("不要停下来啊")
signal.signal(signal.SIGINT,ignore)
while True:
    time.sleep(1)
```
这时我们唯一的办法就是杀手锏KILL信号了，这个信号虽说是信号，但是并不会真正意义上地发送到目标程序，目标程序不会捕捉它。它会直接让内核把程序掐断，是非常强硬地终止方式。被KILL终止的程序自然也没有机会保存自己的信息。所以除非万不得已，不要用KILL来终止程序。

每个信号都有一个自己的编号，除了用`kill -KILL PID`这样的方式来发送信号，也可以直接用编号来指代信号。如KILL的编号就是9，`kill -9 PID`就是强行停止程序的命令。
### 4.3 环境管理
环境配置这个词一直让人望而生畏。这里我们就简要了解一些shell的“环境”。环境实际上就是shell储存的大量信息，程序会根据这些储存在环境中的数据来确定我们的配置。环境中的数据就是环境变量，实际上和我们写代码的时候用的变量差不多，通常我们会把重要的环境变量记录在特定的文件里，每次开启系统的时候都会读取这些文件，建立我们的环境。
#### 4.3.1 检查环境
使用`printenv`可以查看环境变量，由于变量比较多，我们可以用less查看
```
qyh@LAPTOP-TRJ8FFIK:~$ printenv |less
```
```
SHELL=/bin/bash
WSL_DISTRO_NAME=Ubuntu-20.04
WT_SESSION=fe49e1d6-d4ed-4764-860d-845f5e84dadc
NAME=LAPTOP-TRJ8FFIK
PWD=/home/qyh
LOGNAME=qyh
HOME=/home/qyh
LANG=C.UTF-8
WSL_INTEROP=/run/WSL/10_interop
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=qyh
SHLVL=0
WSLENV=WT_SESSION::WT_PROFILE_ID
XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
:
```
我们也可以查看单独某个变量的值，如USER
```
qyh@LAPTOP-TRJ8FFIK:~$ printenv USER
qyh
```
当然也可以用之前说过的读取参数的方式来查看
```
qyh@LAPTOP-TRJ8FFIK:~$ echo $USER
qyh
```
环境变量有很多很多，没有办法一一讲解，这里就介绍一个很重要的——PATH
windows用户在配置自己的python等程序时，也经常要修改自己的环境变量，比如把某个程序的bin文件夹添加到PATH中。这个PATH就是系统寻找程序的地方。当我们在命令行敲"python3"的时候，shell就会在PATH这个变量存储的多个目录中寻找，找到了同名的程序就会执行，找不到就会报错。
大家都知道要执行当前文件夹下的文件，比如你编译的C语言程序main,需要输入`./main`，而不能直接输入`main`，就是因为当你直接输入的时候shell会去PATH里面寻找，就找不到你的程序了。只有用`./`告诉shell程序在当前目录下才能正确执行。

#### 4.3.2 建立环境
当用户登陆系统后，bash就会启动并读取一系列启动文件，这些文件定义了所有用户共享的默认环境，接下来bash会读取个人环境中的启动文件，加载个人环境。
我们可以查看用户个人的启动文件`~/.bashrc`
```bash
qyh@LAPTOP-TRJ8FFIK:~$ cat ~/.bashrc
# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
```
这里只截取了一部分，会发现里面有条件语句，有赋值语句，还有一些命令。大家一下子肯定没法全看懂，因为启动文件实际上是shell脚本(没错，shell不仅可以用来交互，还是一个脚本解释器，它也可以写出很多功能强大的脚本)，我肯定没法把这个一下讲清楚...所以大家了解一下就好。
#### 4.3.3 修改环境并激活
如果不会shell脚本的话也很难对环境大改特改...最多只能添加几个新的变量之类的。如果需要修改环境的话，更改个人文件夹下的.bashrc文件就行。然后使用`source .bashrc`就可以重新加载环境。
### 4.4 软件包管理
在最开始的时候有介绍Linux的发行版。决定一个发行版质量的重要因素就是软件包系统和该发行版社区的活力。有许多程序员们在积极维护自己编写的程序，如果想要适应日新月异的程序版本，我们需要软件包管理系统。
早期的Linux上想要安装软件，必须要下载源代码并编译。而现在只需要简单的命令，就能安装想要的程序，还能对安装的程序进行统一的管理。
不同的发行版有着不同的软件包系统，且这些系统之间不兼容!多数发行版采用的就来自于两种软件包技术阵营：Debian的.deb和Red Hat的.rpm技术。其中我们熟知的Ubuntu就属于Debian的阵营，CentOS是Red Hat阵营的。因为我只安装了Ubuntu，所以是以Debian这边的软件包管理来讲解的。
主要用到的命令是apt-get(apt),aptitude。其中apt-get是用于安装、更新、删除等操作的命令，可以完全被apt命令替代。因为apt命令是apt-cache,apt-config和apt-get的整合，所以我们用apt就够了。而aptitude比起apt更擅长依赖问题，当使用aptitude删除掉一个包时，其依赖也会被删除，让系统更加干净。
apt等工具是比较高级的软件包工具，有的时候我们并不是从库中中直接安装，而是从别的网站下载了安装文件后手动安装，这个时候要用到低级工具`dpkg`
#### 4.4.1 查找与安装
每次使用apt(apt-update)命令的时候，都需要先使用`apt update`，这条命令让apt查看软件源，来看看有没有什么新软件或者有没有软件有新版本，会获取当前可以安装的软件的列表。在进行这一步之后，我们可以通过`apt search`(`apt-cache search`)来查找(注意，ubuntu下需要sudo)
```
qyh@LAPTOP-TRJ8FFIK:~$ sudo apt search gcc
Sorting... Done
Full Text Search... Done
arduino-builder/focal 1.3.25-1ubuntu1 amd64
  Command line tool for compiling Arduino sketches

autoconf2.64/focal 2.64+dfsg-1 all
  automatic configure script builder (obsolete version)

autofdo/focal 0.19-2build1 amd64
  AutoFDO Profile Toolchain

binutils-djgpp/focal 2.34-3ubuntu1+1.4 amd64
  Cross-binutils for DOS using DJGPP

binutils-mingw-w64/focal 2.34-5ubuntu1+8.8 all
  Cross-binutils for Win32 and Win64 using MinGW-w64
```
使用命令`apt install name`来安装软件

如果是自己下载的文件，使用`dpkg --install package_file`来安装。
#### 4.4.2 更新
使用`apt update`检查更新后，`apt upgrade`更新所有可以更新的软件包
#### 4.4.3 列出已安装的软件/判断是否安装
使用`dpkg --list`可以显示所有已安装软件。(默认用less显示)
`dpkg --status package_name`来查看一个软件是否安装
`apt show package_name`来查看已安装软件的详细信息、
```
qyh@LAPTOP-TRJ8FFIK:~$ dpkg --status gcc
Package: gcc
Status: install ok installed
Priority: optional
Section: devel
Installed-Size: 50
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Architecture: amd64
Source: gcc-defaults (1.185.1ubuntu2)
Version: 4:9.3.0-1ubuntu2
Provides: c-compiler, gcc-x86-64-linux-gnu (= 4:9.3.0-1ubuntu2)
Depends: cpp (= 4:9.3.0-1ubuntu2), gcc-9 (>= 9.3.0-3~)
Recommends: libc6-dev | libc-dev
Suggests: gcc-multilib, make, manpages-dev, autoconf, automake, libtool, flex, bison, gdb, gcc-doc
Conflicts: gcc-doc (<< 1:2.95.3)
Description: GNU C compiler
 This is the GNU C compiler, a fairly portable optimizing compiler for C.
 .
 This is a dependency package providing the default GNU C compiler.
Original-Maintainer: Debian GCC Maintainers <debian-gcc@lists.debian.org>
```
```
qyh@LAPTOP-TRJ8FFIK:~$ apt show gcc
Package: gcc
Version: 4:9.3.0-1ubuntu2
Priority: optional
Build-Essential: yes
Section: devel
Source: gcc-defaults (1.185.1ubuntu2)
Origin: Ubuntu
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Original-Maintainer: Debian GCC Maintainers <debian-gcc@lists.debian.org>
Bugs: https://bugs.launchpad.net/ubuntu/+filebug
Installed-Size: 51.2 kB
Provides: c-compiler, gcc-x86-64-linux-gnu (= 4:9.3.0-1ubuntu2)
Depends: cpp (= 4:9.3.0-1ubuntu2), gcc-9 (>= 9.3.0-3~)
Recommends: libc6-dev | libc-dev
Suggests: gcc-multilib, make, manpages-dev, autoconf, automake, libtool, flex, bison, gdb, gcc-doc
Conflicts: gcc-doc (<< 1:2.95.3)
Task: ubuntustudio-video, ubuntu-mate-core, ubuntu-mate-desktop
Download-Size: 5208 B
APT-Manual-Installed: yes
APT-Sources: https://mirrors.tuna.tsinghua.edu.cn/ubuntu focal/main amd64 Packages
Description: GNU C compiler
 This is the GNU C compiler, a fairly portable optimizing compiler for C.
 .
 This is a dependency package providing the default GNU C compiler.
```

#### 4.4.3 删除
`apt remove package_name`

### 小结
这一部分就常见的几个任务做了非常简要的介绍，来让大家了解在Linux中完成这些任务的基本逻辑，更加具体的内容还需要大家自己去学习~有了前面那些命令行的基础知识，学起来应该还是不难的。

## 5.运行你的程序 8min
这一节带大家在Linux上运行自己编写的程序（应该很多同学早就已经尝试过了，所以并不会讲特别多）。
### 5.1 编译型程序(C++/C)
这里我们选择用g++来进行编译，我们先准备好一个标准的C++的Hello World程序
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ cat hello.cpp
```
```C++
#include<iostream>
using namespace std;
int main(){
        cout<<"Hello,world"<<endl;
        return 0;
}
```
#### 5.1.1 直接用命令编译
直接使用gcc的命令编译，我们可以用help查看gcc选项，我这里就不看了。使用如下
`g++ [options] file...`
选项`-o`用来指定目标文件的名字。现在我们吧`hello.cpp`编译成`hello`
`gcc hello.cpp -o hello`
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ g++ hello.cpp -o hello
```
编译成功，没有任何输出(所以没有任何问题)
现在文件夹下多了一个叫hello的程序，我们用`./hello`来运行
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ ./hello
Hello,world
```
#### 5.1.2 使用makefile来构建
make是非常强大的命令，一旦你运行了make，它就会找到当前目录下的makefile,并按照你的指示进行构建(当然不限于C/C++,构建LaTeX文档啥的都是可以的，只要你写对了makefile)。makefile本身有很多的功能，包括变量、条件判断、函数等等，需要专门地学习才能上手。所以我仅仅举一个最简单的例子。先来了解一下makefile的规则
```Makefile
target ... : prerequisites ...
    command
    ...
    ...
```
target就是我们的目标文件，prerequisites是这个文件依赖的文件，command是需要执行的命令。当我们运行make不带任何参数的时候，make会去构建makefile中的第一个目标，如果该目标依赖的文件没有被构建或者依赖的文件并不比目标新，则会去构建目标的文件。make会这样一层一层地找依赖关系，直到编译出目标文件。如果中间出现任何错误就会直接退出。来看一个很简单的makefile,我们尝试用g++先编译，再汇编，最后链接。我还使用了一个特殊的目标"clean"，当使用"make clean"的时候会执行里面编写的clean命令。
```
hello: hello.o
	g++ hello.o -o hello
hello.o: hello.s
	g++ -c hello.s -o hello.o
hello.s: 
	g++ -S hello.cpp -o hello.s
clean:
	rm hello.o hello.s hello
```
现在我们执行make,就会先编译出hello.s,然后汇编得到hello.o,最后链接得到hello。
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ make
g++ -S hello.cpp -o hello.s
g++ -c hello.s -o hello.o
g++ hello.o -o hello
```
如果再次使用make:
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ make
make: 'hello' is up to date.
```
由于那些文件都没有更新，所以什么都不会发生。我们使用make clean
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ make clean
rm hello.o hello.s hello
```
之前的产物都消失了。
### 5.2 解释型程序(Python)
现在来讲一下怎么运行解释形语言的脚本，比如python,我们直接使用命令`python3 script.py`就好了。除了这种方法，脚本文件本身是可以被当作可执行文件的。这里就要先介绍一下shebang。再我之前给出的一个python代码中，第一行写了一个神奇的东西
```python
#! /bin/python3
import time
i=0
while True:
    time.sleep(1)
    i+=1
    print(i)
```
`#!/bin/bash`，这个东西被称作shebang(或hashbang)，当文件中存在shebang时，我们执行这个文件，系统会分析#！后面的内容，并将其作为解释器，解释脚本。我们现在创建一个python的helloword，并直接运行
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ cat hello.py
#!/bin/python3
print('Hello,world')
```
```
qyh@LAPTOP-TRJ8FFIK:~/learnLinux$ ./hello.py
Hello,world
```
程序直接显示了其结果。当然也有可能在创建时系统没有给脚本文件足够的权限，这时用chmod进行更改即可。
## 6.其他值得了解的东西
### 6.1 Vim
### 6.2 