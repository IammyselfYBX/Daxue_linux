静态库和共享库

做一个项目 项目文件

我  小黄 小张
a.out -> 主函数 -> 一个主函数 ->我负责主函数

怎么把项目代码交给我？
有一个方案 a.out
打包成一个库文件
"stdio.h" -> printf
          -> scanf
		  
Unix/Linux有，windows
静态库和动态库（共享库）


错误 -> XXXXXXX XXX.dll文件缺失
     -> 动态链接库

	 库文件是.o文件打包的
	  
静态库 -> 代码的归档 -> 在使用的
时候会复制代码到文件中

共享库 -> 吧代码的地址放到目标文件中

静态库优点 -> 独立，在链接后不需要静态库
              源文件
静态库缺点 -> 太占空间，不利于修改和维护

共享库优点 -> 占用空间小，维护和修改方便

共享库缺点 -> 程序运行的时候必须保证共享
库能找到（不独立），速度会稍微慢一点

商业开发中主流使用共享库

printf

使用纯静态库：
 gcc -static .c文件
创建静态库步骤：
1、编写源程序.c文件
2、编译的时候生成.o文件
3、生成静态库.a

ar -r 库文件名称 所有的.o文件
库文件名称有规范：
lib开头   .a结尾，中间放库名
ar -r libmyku.a

静态库链接使用步骤：


1、编写使用程序.c文件，保存退出
2、编写.c文件生成目标文件
gcc -c X.c
3、链接静态库和.o文件,有三种：
     1、强行链接：
	         gcc .o文件 库名称
	 2、双L链接法（重点）
	         gcc .o文件 -l库名 -L库所在目录
	 3、单L链接法
	         gcc .o文件 -l库名称(需要配置环境变量)
	
ldd命令可以查看使用了那些库文件
共享库

export export LD_LIBRARY_PATH=.

共享库创建步骤：
1、写源程序.c文件
2、编写生成.o文件
3、生成共享库文件.so

gcc -shared .o文件 -o.so共享库文件

使用方法和静态库一模一样


gcc -c -fpic day03.c 
-fpic选项出于传统原因而加上

动态链接库 -> 参与执行 但是他自己不能执行

错误处理 

段错误 -> C程序员必备技能 ->错误处理
	 
主流的编程语言（除了C语言）都是用异常机制
处理错误
C语言用的是返回值代表出错
（很单纯，其他语言都直接丢个异常出来，而C
语言是用返回值代表出错）

1 -> 如果返回值类型是int，并且返回值不可能是
     负数，数据会正常返回，返回-1代表出错！
2 -> 如果返回类型是int，并且返回值可能是负数
     返回-1代表出错，0代表正确，数据用指针返
	 回到主函数！
3 -> 如果返回类型是指针，返回NULL代表出错
     其他代表正常（针对指针）
4 -> 如果函数不需要考虑出问题，用void做返回值！

所有C的错误处理都是采用返回值
	以上四点是大多数C程序员的习惯用法！

一个函数返回数据的方法有两种：
1、return 返回-1代表出错！
2、参数中放入一个指针，也可以吧数据带回去

四种错误情况演示：
1、返回两个数的最大值，如果相等返回错误->2
2、返回0-1之间的随机数，如果随机到0，返->1 
   回错误
3、传入一个字符串，如果传入的字符串是->3
   ‘error’，返回错误，如果不是‘error’
   返回原来的字符串
4、打印传入的字符串->4
	 
	 ↑错误处理基础，错误处理函数↓
	 
errno记录错误信息
    -> 错误编号 （int）
	-> 具体信息 （字符类型）
	
	错误处理函数
	-> strerror
	-> perror
	-> printf
strerror() -> 负责传入一个编号，返回具体
              信息（不负责打印，只是一个
              转换函数）
perror()   -> 不用传入错误信息，直接打印
              errno对应信息
printf()   -> %m专门给错误使用的，用来打印
              错误信息			  
	 
要使用reeno这个外部局部变量需要包含头文件
errno.h

要使用错误处理函数还需要包含
string.h头文件
 
	 
C程序员的环境变量和环境表

什么样的类型能把所有环境变量都给存下来

字符串
环境变量存在环境表 
环境表 ->字符指针数组
NULL结束
environ全局变量保存了该数组的首地址


他存放东西的方式是怎样的呢？

环境表是一个二级指针
char* s[5] ->字符指针数组
char** s -> 二级指针
environ就是环境表的首地址
NULL是环境表的结束位置
问：如何编写程序用循环吧环境表里面存放的
环境变量打印出来？
	 
	 
暂停一下！
	 extern
	 
空 = 0； -> 假
	！=NULL 完全没有必要
	 
p++为什么可以？还有就是他这个p++到底移动了
多少？
	 
p++ -> p = p + 1; 
字符指针数组
指针 -> 指针能算加法吗？
     -> 两个指针可以相减吗？
	 -> 指针是存储变量地址的变量
	 -> int i = 10;
	 -> int *pi = &i;
	 -> pi就是指针
	 是普通整形变量
	 *pi和谁等价？
	 *pi = i;
	 &i == pi;
	 
pi + 1效果 ->移动的字节由指向的变量大小决定

pi -> int* -> 4字节
char* -> char的大小
pi -> char** ? 移动几位？
char*的大小？

（*p）++
 p++
sleep函数是延缓程序运行，如sleep（1）；


（*p）++ -> 移动*p的位置，而不是移动p的位置

只增加1个字节！ char  1个字节

写一个循环，吧PWD这个环境变量的值取出来
我不要PWD=这几个字符，而是PWD=后面的字符

提示：比较字符前面N个字符
用strncmp（）

环境表变量是标C的函数，他在头文件stdlib.h中，因此要包含头文件stdlib.h
环境表变量操作函数：
    getenv  ->  返回指向name关联的value的指针（用来获取）
    putenv  ->  将形式为name = value的环境变量放入环境表（用来设置）
	setenv  ->  将name设置成value，第三个参数决定是否替代以后的变量
	unsetenv   ->  删除定义
	clearenv   ->  删除环境表中所有的项
	 
	 
使用：	 
getenv	->  按环境变量的名取得环境变量的值
putenv/setenv   ->  
                区别：
                putenv() -> 参数格式：”name = value“
				setenv() -> 三个参数（分开的）
				putenv() -> 一定会替换掉已经存在的值
				seienv() -> 可以用第三个参数决定是否替换

主函数有第三个参数 -> char** env	
编译没错说明第三个参数的确存在			
主函数第三个参数（）就是环境表
	 
setenv第三个参数，如果是0表示不替换，如果是1表示替换

Unix/Linux内存管理
Unix/Linux -> 重要，但是有点难度

1、内存的分配和回收的相关函数
       |
   STL容器 —> 自动分配和自动回收
       |
   C++语言 -> new分配，delete回收（不是函数）
       |
   C 语言  -> malloc（）  free（）
       |
   unix系统函数 -> sbrk（）  brk（）
       |
   Unix系统函数 -> mmap（）分配 munmap（）回收
-------------------------------------------（应用层）   
   Unix系统调用（内核）  -> kmalloc() vmalloc()
	 
	 
2、 进程的内存空间
    进程和程序的概念
	
malloc（）  free（）
	 
	 
存储位置是不是连续的？
	 
	
malloc是怎么干活的？
malloc -> 33个内存页  

free（pi）
	 
man  函数查询手册使用方法：
man 函数名
	 
unistd.h头文件就是我们Linux或者Unix系统函数的头文件


sbrk（）有两个参数，第二个参数是分配和回收内存的大小（字节）
如果是整数代表 在分配内存，如果是负数代表在回收内存
如果是0不分配也不回收，取当前位置地址
执行完第一次分配后地址在哪里？
地址有没有挨着

sbrk分配的内存字节是连续的，是挨着的
sbrk只有一个内存页

brk（）

一般使用sbrk分配内存，使用brk回收内存

	p + 4   -> 分配了四个字节
	p + 8   -> 分配了四个字节  -> 8个字节
	
	 
	 
mmap和munmap

mmap -> 映射物理内存/文件
	 
这两个函数用到头文件 -> #include <sys/mman.h>
	 
	 
void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
				  
int prod -> 这段内存区的权限
	 
PROT_EXEC  Pages may be executed.

PROT_READ  Pages may be read.

PROT_WRITE Pages may be written.

PROT_NONE  

怎么把宏拼凑在一起
	 
chmod 777 a.out
7 -> 可读可写可执行
100 -> 读权限
010 -> 写权限
001 -> 执行权
位或运算可以用于拼接权限选项

100 | 010 -> 110 
	 
MAP_SHARED
MAP_PRIVATE 
MAP_ANONYMOUS -> 匿名的作用就是告诉mmap函数，我们要映射的是物理内存，不是文件
给不给其他进程访问，私有就是不给访问，共享就是其他进程读可以用	 
	 
MAP_FAILED 
	 
一、文件系统的基本概念
	1、在Unix/Linux系统中，每个文件以一个或多个数据离散的存放在磁盘的块表区（柱面组区）中
	2、一个文件的每个数据块的存储位置保存在I节点（i-node）中
	3、对应系统中多个文件的I节点，保存在磁盘的I节点表中，每个I节点通过一个下标（唯一的表示，类似数组）
	   这个下标叫做I节点号
	4、文件代码清除和所对应的I节点号保存在目录文件中
	5、访问一个文件的过程：文件名到目录文件中到对应I节点号，在根据I节点表中找到每个数据块在磁盘上的存储位置进行访问
	超级块
	
	
广义文件
1) -> 目录文件
2) -> 设备文件
3) -> 控制台 -> /dev/console
4) -> 声卡   -> /dev/audio
5) -> 标准输入输出 -> /dev/tty
6) -> 空设备 -> /dev/null
7) -> 标准出错设备



0标准输入设备
1标准输出设备
2标准出错设备
	
open   ->  打开/创建文件 -> fopen
close  ->  关闭文件      -> fclose
read   ->  读取文件      -> fread
write  ->  写入文件      -> fwrite
lseek  ->  设置/获取读写位置-> fseek/ftell
creat  ->  创建文件

Unix/Linux文件操作函数
fcntl ->  修改文件属性
unlink -> 删除硬链接文件
rmdir  -> 删除空目录
remove  -> 删除硬链接/空目录，相当于合并两个函数
 

	
open    close   creat
#include <fcntl.h>
int open(
  const char *pathname //文件路径
  int flags,           //文件状态
  mode_t mode          //权限模式
  ); 
	 
flags的异或：  
O_RDONLY -> 只读\
                 >只能选一个
O_WRONLY -> 只写/
O_RDWR   -> 读写
O_APPEND -> 追加（不能跟只读或）
O_CREAT  -> 创建，不存在即创建，已存在直接打开，原有内存保留。除非又位或了以下选项↓

O_EXCL   -> 排斥，已存在则失败（为了防止你意外覆盖已有文件）
O_TRUNC  -> 清空 ，已存在则吧原有文件清空

    ↑以上选项只能存在一个，和倒数第三个配合使用

mode：
权限，取值和chmod命令权限参数一致

如果成功返回文件描述符，失败返回-1！
	 

close函数
int close(
   int fd
   );	 
	 
creat函数
int creat(
   const char *pathname,
   mode_t mode
   );	 
open(pathname,O_WRONLY | O_CREAT | O_TRUNC,mode);	 
	 
保护机制
umask 
实际创建文件权限=mode &~ umask
	 
	 
	 
write -> unistd.h
	 
ssize_t write
size_t -> 无符号整形 -> unsigned int
ssize_t -> 整形 -> int
s -> 有符号位 
	 
ssize_t write(
  int fd,//文件描述符
  const void *buf,//缓冲区
  size_t count//期望写入的字节数
  );	 
如果函数执行成功，返回实际写入的字节，失败返回-1，
	 
	 
ssize_t read(
  int fd,//文件描述符
  const void *buf,//缓冲区
  size_t count//期望写入的字节数
  );	 
	 
如果函数执行成功，返回实际写入的字节，失败返回-1， 
	 
写一个文件拷贝程序，带有覆盖检查功能
1、在一个循环中执行，度一块写一块，读完循环结束
2、调用open函数的时候打开目标文件的时候，给他
    O_WRONLY | O_CREAT | O_EXCL
	若目标存在则open失败

	
	 getchar()是标C的函数，用于输入字符串，用法是ch = getchar();
	 
lseek函数
1、每个打开的文件都有一个与之相关的文件位置
2、文件位置通常是一个非负数的整数，用度量从文件头开始计算字节
3、读写操作都从当前文件位置开始，并且根据所读写的字节数，增加文件位置
4、打开一个文件的时候除非定制了O_APPEND，否则文件位置一律设置为0
5、lseek函数仅修改文件表中记录文件位置
6、lseek函数可以将文件位置设置到文件尾之后，在后续操作以后会在文件中形成空洞
	 
#include <sys/types.h>
#include <unistd.h>
off_t lseek(
  int fd,//文件描述符
  off_t offset,//偏移量
  int whence//起始位置
  );
	 
	 
SEEK_SET -> 从文件头
SEEK_CUR -> 当前位置
SEEK_END -> 从文件尾（文件的最后一个字节）
	 
	 
dup和dup2
这两个函数是做文件描述符复制的
1、复制一个已经打开的文件描述符
2、dup函数返回的一定是当前未使用最小的文件描述符
3、dup2函数可以由第二个参数来指定希望复制到文件描述符	 
，若指定的文件描述符已经打开则先关闭它，在复制！
4、所有返回的文件描述符副本，与源文件描述符对应同一个文件表	 
	 
fcntl函数
#include <fcntl.h> 
int fcntl(
   int fd,//文件描述符
   int cmd//控制指令
   ...    //可变参数
   );
	 
1、复制文件描述符 
	int fcntl(oldfd，F_DUPFD,newfd);
复制oldfd为不小于newfd的文件描述符
若newfd文件描述符已用，该函数，就会选择比newfd大的最小未用值

2、获取/设置文件状态标志
获取文件标志用：int fcntl(oldfd，F_GETFL);
拿不到的标志位：O_CREAT/O_EXCL/O_TRUNC
设置标志
int res = fcntl(fd，F_SETFL,flags);
使用非常有限，只能够追加两位，一个是O_APPEND,O_NOBLOCK

3、给文件加锁

文件锁分为两种 -> 两种 -> 读锁/写锁
写锁别的进程写不了，也读不了
读锁能读但是写不了
所以写锁又叫独锁，读锁又叫共享锁
fcntl函数给文件加锁的函数原型
int fcntl(
  int fd,//文件描述符
  F_SETLKW/F_SETLK,
  struct flock *lock
  );
	
	
struct flock{
 short int l_type;   //锁的类型
       //F_RDLCK -> 读锁
	   //F_WRLCK -> 写锁
	   //F_UNLCK -> 解锁
 short int l_whence; //锁区偏移起点
       //SEEK_SET -> 文件头开始偏移
	   //SEEK_CUR -> 文件当前位置开始偏移
	   //SEEK_END -> 文件尾开始偏移
 off_t l_start;      //锁区偏移
       //从l_whence开始偏多少个字节
 off_t l_len;//锁区长度 -> 0
       //写0代表从文件头锁到文件尾
 pid_t l_pid;//加锁进程，加锁是给-1；
       
}；
	
stat函数 -> 获取文件属性
stat/fstat/lstat

int stat(const char *path,//文件路径
         struct stat *buf //文件属性
		 );
//没有文件描述符参数，说明该文件无需打开一个文件
int fstat(int fd,         //文件描述符
          struct stat *buf//文件属性
		  );
int lstat(const char *path,//文件路径
          struct stat *buf //文件属性
		  );//跟stat一样，区别在于lstat不跟踪软连接

struct stat
{
  dev_t st_dev;     //设备ID
  ino_t st_ino;     //i节点号
  mode_t st_mode;   //文件权限和类型
  nlink_t st_nlink; //硬链接数
  uid_t st_uid;     //属主ID
  gid_t st_gid;     //组ID
  dev_t st_rdev;    //特殊设备ID
  off_t st_size;    //文件总字节数
  blksize——t st_blocks; //I/O块字节数
  blkcnt_t st_blocks;   //占用块
  time_t st_atime;  //最后访问时间
  time_t st_mtime;  //最后修改时间
  time_t st_ctime;  //最后状态时间
}
这些类型都是短整形
mode_t st_mode;   //文件权限和类型
（0TTSUGO）	
TT -> 文件类型
S_IFDIR -> 目录
S_IFREG -> 普通文件
S_IFLNK -> 软连接文件
S_IFBLK -> 块设备
S_IFCHR -> 字符设备
S_IFSOCK -> Unix域套接字
S_IFIFO -> 有名管道
全0是目录，1是普通文件，2是软链接，3是块设备
S -> 附加模式
S_ISUID -> 设置用户ID
S_ISGID -> 设置组ID
S_ISVTX -> 粘滞 	
U -> 属主的权限
S_IRUSR -> 属主可读
S_IWUSR -> 属主可写
S_IXUSR -> 属主可执行
G -> 数组的权限
S_IRGRP -> 数组可读
S_IWGRP -> 数组可写
S_IXGRP -> 数组可执行
O -> 其他用户权限
S_IROTH -> 其他人可读
S_IWOTH -> 其他人可写
S_IXOTH -> 其他人可执行
	
常用复制判断文件类型
S_ISDIR(st,st_mode) -> 是否目录
S_ISREG() -> 是否普通文件
S_ISLNK() -> 是否软连接
S_ISBLK() -> 是否块设备
S_ISCHR() -> 是否字符设备
S_ISSOCK() -> 是否Unix域套接字
S_ISFIFO() -> 有名管道

access函数
int access(const char *pathname, int mode);


opendir -> 打开一个目录
readdir -> 读目录内容
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
DIR *fdopendir(int fd);

int readdir(unsigned int fd, struct old_linux_dirent *dirp,
                   unsigned int count);

 struct old_linux_dirent {
               long  d_ino;              /* inode number */
               off_t d_off;              /* offset to this old_linux_dirent */
               unsigned short d_reclen;  /* length of this d_name */
               char  d_name[NAME_MAX+1]; /* filename (null-terminated) */
           }


进程管理

Unix/Linux操作系统如何查看进程？
ps -> 只能查看当前终端启动的进程
ps -aux -> Linux直接支持，而Unix不直接支持！
ps -ef -> Unix/Linux操作系统通用的查看所有进程的命令
whereis ps
	
线程
S->休眠状态
s->代表这个进程有子进程
R->正在运行的进程
Z->僵尸进程 
	
如果进程a启动了进程b，a就叫做b的父进程
b就叫做子进程
有些进程即是父进程又是子进程


a -> b -> c

getpid -> 取当前进程的PID
getppid -> 取父进程PID
getuid/geteuid -> 取当前用户ID（有效用户）


启动子进程的方法
fork -> 子进程  复制父进程 -> 启动子进程
vfork/execl -> 启动全新的子进程

fork函数非常简单，并且相当复杂
pid_t fork(void);
无参，返回PID

fork通过复制父进程创建子进程，那么要复制进程有哪些要复制的？

fork函数只有父进程执行一次，fork之之后代码，父子进程都执行一遍（执行了2次）
fork函数有两次返回，父同时运行，如果子进程先结束，父进程返回子进程的PID，子进程返回0；

fork函数创建子进程的时候，如果父进程有文件件描述符，子进程会不会也复制了？
子进程也会复制文件描述符，但是不复制文件表

父子进程的关系：
fork之后，父子进程同时运行，如果子进程先结束，子进程会给父进程发一个信号
父进程负责回收子进程
fork之后，父子进程同时运行，如果父进程先结束，子进程就变成孤儿进程，会认进
程1（init）位新的父进程，init这个进程也叫做孤儿院
fork之后，父子进程同时运行，如果子进程发信号的时候出了问题，或者父进程没有及时
处理信号，子进程就会变成僵尸进程

父子进程打印不同结果？

fork出错原因：
1、系统进程总数有限额
2、用户进程总数有限额

fork函数存在复制行为

每个进程都有自己的虚拟空间
	
进程结束
exit可以用来结束一个进程
正常结束和非正常结束
正常结束进程的方法：
1、主函数运行return语句
2、函数exit可以终止进程
3、_exit/_Exit可以结束进程
4、最后一个线程结束
5、主线程结束
非正常结束进程的方法：
1、信号被终止
2、线程被其他线程取消

return和exit的区别
return是用来退出函数的，
exit是用来退出进程的

exit/_exit/_Exit的区别

#include<unistd.h>
void _exit(int status);


#include <stdlib.h>
void _Exit(int status);

#include <stdlib.h>
void exit(int status);

exit -> 不会立刻结束进程，他可以调用atexit函数注册过的函数，然后在结束进程
atexit是干啥的呢？
int atexit(void (function)(void));



退出码和进程阻塞

exit(0);

wait函数和waitpid函数
	（殓尸工）
	
#include <sys/tpes.h>
#include <sys/wait.h>
	
pid_t wait(int *status);

pid_t waitpid(pid_t pid, int *status, int options);

pid_t wait(int *status);
会让父进程等待任意子进程的结束（可以是僵尸进程），返回子进程的PID
并且吧子进程的退出信息（退出码和是否正常退出）	
	
*status的参数是几个宏
是否正常退出可以用WIFEXITED(status)判断
退出码用WEXITSTATUS(status)获取


wait和waitpid有何区别？
wait是等待任意一个子进程结束，等待过程父进程必然阻塞
waitpid可以等待指定的子进程结束（也可以任意）等待果子
中，父进程可以阻塞也可以不阻塞
pid_t waitpid(pid_t pid, int *status, int options);

pid的值如下：
-1  -> 等待任意一个子进程的结束
>0  -> 等待特定的子进程结束（子进程PID = pid）
0   -> 等待本进程的子进程结束
<-1 -> 等待进程组ID等于pid绝对值的子进程

WNOHANG 代表非阻塞
正数：等待到结束的子进程PID
0：没有子进程结束自己
-1：出错啦


fork -> 复制父进程，创建子进程
vfork()+execl() -> 创建全新的子进程

vfork不会复制父进程的任何资源，但是会占用父进程的资源运行
导致父进程阻塞

两种情况可以解除阻塞：
exec系列的函数（如execl）

vfork只创建新进程，但是不提供程序
execl只听程序不创建新进程


得出结论：vfork创建出来的子进程一定先于父进程运行
execl：负责启动一个全新的程序
int execl（char *path,char *cmd,...）；
第一个参数是程序所在的路径
第二个参数是执行程序的命令
...代表0-N个任意参数，一般可以跟选项，参数等，最后以NULL结束！

Unix/Linux系统的信号管理

问：程序中如果出现死循环怎么办？
ctrl+c -> 信号

段错误 -> 信号
总线错误 -> 信号
子进程结束 -> 给父进程发信号

什么叫软件中断

中断
中断是程序终止执行现在的代码，转而执行其他代码
软件中断和硬件中断 软件中断的主要方式就是信号！
信号的本质是非负数
每个信号都有一个宏名称，都以SIG开头
比如信号2 -> SIGINT

kill是用来给进程发信号的！
kill -l 可以查看所有信号

关于用0做除数：
整数除以0，会引发浮点数例外，会终止程序！
浮点数除以0，得到的结果是无穷大


用宏名称不能用整数，因为不同系统数字不一样！

信号的异步处理方式。

信号0有特殊用途，本身不带表任何事情，也不回去处理任何事情
用于测试，是否有权发信号

信号是怎么来的？
硬件故障和函数都可能产生信号！

信号的分类：
不可靠信号
  这种信号不支持排队，因此可能丢失，非实时信号，1-31都是不可靠信号
可靠信号
  支持排队，因此不可能丢失，实时信号，34-64都是可靠信号
 
程序收到信号以后的处理方式：
1、默认处理方式，80%都是退出进程！
2、忽略信号，不做任何处理！
3、程序员可以自定义信号处理方式，只需要写一个信号处理函数

△信号9不能被忽略

信号处理的实现步骤：
1、写一个信号处理函数
2、用signal/sigacion注册信号处理方式

#include <signal.h>
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
函数指针的格式：
void （*fa）（int）；

SIG_IGN -> 忽略
SIG_DEF -> 默认处理

ctrl+C -> 信号2
ctrl+\
kill -9 pid

子进程的信号处理
如果子进程是fork创建的，那么子进程完全沿袭父进程对信号处理的方式
vfork+execl创建的子进程，父进程默认子进程也默认，父进程忽略子进程也忽略
父进程自定义函数处理，子进程是默认！

原因：vfork+execl创建的子进程代码区没有父进程的处理函数！

kill函数
发送信号的方法：
1、用键盘发信号
2、出错（部分信号）
3、kill命令发送（全部信号）
4、信号发送函数（这节课内容）

raise() -> 给本进程发任意信号
kill()  -> 给任意进程发任意信号
lalrm() -> 给本进程发送特定信号（闹钟）
sigpueue() -> 给任意进程发任意信号，可以附带额外数据（少用）

#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);


alarm函数

alarm(参数n)  -> n秒之后产生一个闹钟信号：SIGALRM

0代表的是所有的闹钟
在任何情况下之前设置的闹钟都会被取消


信号组->信号集
long long int/sigset_t

1、增加信号
sigaddset()  -> 增加一个信号
sigfillset() -> 放入所有信号（全部增加）
2、删除出
sigdelset()  -> 删除一个信号
sigemptyset()-> 清空信号集
3、查找信号
sigismember()->判断信号是否存在

#include <signal.h>
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);
int sigismember(const sigset_t *set, int signum);
8 * 128 = 1024


set=2 - 放入信号2
set=6 - 放入信号3
set=70 - 放入信号7
set=66 - 删除信号7


信号屏蔽

sigprocmask -> 负责信号屏蔽和接触的！

#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

SIG_BLOCK
   新的加旧的
SIG_UNBLOCK
   旧的减去新的
SIG_SETMASK
   直接替换

参数：
const sigset_t *set代表新的需要屏蔽的信号
sigset_t *oldset用于传出旧的信号屏蔽（不用传出给0）
int how运算方式：
SIG_BLOCK -> 新的+旧的 -> ABC+DEF -> ABCDEF
SIG_UNBLOCK -> 旧的-新的 -> ABC-CDE -> ABC
SIG_SETMASK -> ABC CDE  -> CDE

IPC -> 进程间通讯（两个以上进程数据的互相交换）

1、文件
2、信号
3、管道
4、共享内存
5、消息队列  -> △
6、信号量集（和信号集没有关系）
7、网络（套接字socket）
...

共享内存，消息队列和洗好量集他们遵守相同的规范
叫做XSI IPC

管道：Unix/Linux最古老的IPC方式之一，管道又分为有名管道和无名管道
有名管道可以用于各种IPC，无名管道只能用于fork创建的父子进程之间的IPC

Linux/Unix早起都是以文件作为媒介
管道还不算一般的文件！！

管道的交互媒介是一种特殊的文件：管道文件
管道文件必须使用mkfifo命令或者mkfifo函数才能创建
管道文件的后缀.pipe（翻译就是管道）

echo命令类似于命令行上的printf输出

管道文件挂载上去后制作交互的媒介，不存储数据

编写两个程序，一个发送整数0-99，另一个用来接收
要求：每1秒发送一个



XSI IPC  理论篇
XSI IPC->共享内存，消息队列和信号量集

XSI IPC 遵循相同规范，因此使用方法上很相似

共同的使用方法：
1、创建时都需要使用key，key是一个整数，外部程序使用key来获取内核中IPC的结构
2、key生成有三种方法：
   a、宏IPC_PRIVATE直接做key
   b、定义一个头文件，吧所有的key写在头文件中
   c、函数ftok可以用一个真实存在的目录和一个人工分配的项目ID（0-255）自动生成一个key
3、所有的IPC结构在内核中对应一个唯一的ID，表示每个IPC信号
4、key是用来查找ID的，ID是用来定位IPC结构的！
函数shmget(key,...);,msgget(key,...);可以用key获取ID，后续的代码使用ID
5、创建IPC结构需要提供一个操作函数->msgctl，他至少包含以下功能：
   a、IPC_STAT:取IPC结构的相关属性（查看）
   b、IPC_SET:修改IPC结构的部分属性
   c、IPC_RMID:删除IPC结构
△IPC结构使用完毕一定肯定必须确定能够确保他删除的干干净净，不然就永远在内核里面了！
IPC相关命令：
ipcs:查看IPC结构
ipcrm:删除IPC结构
  
  -a -> 查看所有
  -m -> 共享内存
  -q -> 消息队列
  -s -> 信号量集
删除时，需要指定结构ID

共享内存

使用共享内存的步骤：
1、创建key，可以使用头文件，或者定义ftok函数
2、使用shmget，用key创建/获取共享内存ID
3、shmat（ID）挂载(映射)共享内存
4、正常使用
5、使用shmdt脱接（接触映射）共享内存
6、保证不再使用的时候，可以删除共享内存！shmctl（IPC_RMID);


消息队列
队列由内核负责创建和维护

消息队列的使用步骤：
1、ftok或者头文件定义方式生成key
2、用key创建/获取消息队列的ID
int msgid = msgget
3、放入消息/取出消息
msgsnd  -> 放入，发送消息
msgrcv  -> 取出，接收消息
4、如果确认不再需要使用消息队列，需要删除
msgctl

msgsnd最后一个参数只有两个值，一个是0，另一个是IPC_NOWAIT

int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,
                      int msgflg);

消息类型

消息：
消息分为有类型消息和无类型消息
无类型消息 == 数据，使用任何类型都行
比如：int，double，字符串，结构，联合！
遵守严格先入先出！
有类型消息 == 数据 + 消息类型
必须是结构体

格式如下：
struct 消息名称随便取
{
  long mtype；//第一个成员必须是消息类型
  ...//随便写
}

mtype值，必须大于0

msgsnd发送有类型消息的时候，没有特殊要求
smgrcv接收有类型消息的时候，第四个参数选择要接受的消息类型！

第四个参数的值，可能如下：
 1、整数 接收特定类型的消息
 2、0接收任意类型的消息（先进先出）
 3、负数 接收小鱼等于这个参数绝对值的消息，次序先小后大
 

信号量集
信号量集和信号一点关系都没有，是一个信号的量的数组

信号量 -> 计时器
这个计时器用于控制访问共享内存资源的最大并行进程数

加入信号量3，有5个进程，1先进，结束
234同时上，5在上
这时候就出问题了！！

计时器的工作方式：
1、自增型：开始计数0，来一个自增1，走一个自减1，到计数最大值不允许再来
2、自减型：开始计数就是最大值，来一个自减1，走一个自增1，计数到0不允许再来

使用多个信号有信号集，使用多个信号量，也有信号量集

信号量集其实是进程间的调用，并不是真正的互发数据！

信号量集的编程步骤：
1、使用fotk或者头文件，生成一个key
2、使用semget创建/获取信号量集
3、使用semctl给信号量集中每个信号赋值
4、使用信号量，semop函数
5、如果不咋使用，可以使用semctl函数

semctl初始化信号量集中每个信号量：
int semctl(int semid, int semnum, int cmd, ...);
如果cmd取SETVAL，可以给一个信号量赋值
semnum参数是信号量的下标，第四个参数就是初始值
semctl(semid,0,SETVAL,5);

semop函数中的结构如下：
struct sembuf
{
  unsigned short sem_num; -> 操作信号量的下标
  short sem_op; -> 对信号量操作方式，-1，0，+1
  short sem_flg; -> 计数到0后是否阻塞，为0就阻塞，为IPC_NOWIT就不阻塞
}；


socket -> 网络套接字
TPC UDI
OSI -> 应用层
       表现层
	   会话层
	   传输层
	   网络层
	   数据链路层
	   物理层
TCP/IP模型
协议和协议簇
常见的协议：
TCP -> 传输控制协议 -> 传输层
IP  -> 网络协议     -> 网络层
UDP -> 用户数据协议 -> 传输层
HTTP-> 超文本传输协议->应用层
FTP -> 文件传输协议  ->应用层

关于Socket编程的概念
流
连接
阻塞，非阻塞
同步，异步
IP地址
字节顺序

IP地址：地址是Internet中唯一的地址表示
是一个整数ipv4和ipv6
ipv4就是32位整数
ipv6就是128位整数

192.168.1.1
点分十进制表示法

子网掩码用于区分两个IP是不是在同一子网中


IP+端口 才能够数据交互

端口也是一个整数 short型
0-65535
端口分类：
0-1023：最好不要使用，系统以及使用了其中某些部分
1024-48000：正常使用的端口，很少有部分会被那种的软件使用
48000以后：动态端口，不稳定！

网络编程在C语言中叫做socket

网络编程有很成熟的套路并且Windows也能用！

socket又分为本地通讯和网络通讯

服务器端和客户端
socket编程 编写步骤：
1、创建一个socket，使用函数socket函数

int socket(int domain, int type, int protocol);
返回的是一个叫做socket描述符的东西

int domain参数是域，用来选择协议簇
PF_UNIX PF_LOCAl PF_FILE
这些都代表本地通讯
PF_INET ：IPv4网络通讯
PF_INET6：IPv6网络通讯
注意：PF可以写出AF

int domain用于选择通讯类型
SOCK_STREAM  -> 数据流（TPC）
SOCK_DGRAM   -> 数据报（UDP）

int protocol：已经没有任何意义了，给0

返回值：返回socket描述符，失败返回-1
socket -> 套接字
2、准备通讯地址（搞文件/IP和端口）
有三个通讯地址：
struct sockaddr_in ：不存数据，专门做参数类型
struct sockaddr_un:存储本地通讯数据

本地通讯使用的是一个文件做IPC媒介，因此存储了socket文件名

socket文件，后缀是.sock
#include <sys/un.h>
struct sockaddr_un
{
 int sun_family;//协议簇
 char sun_path[];//文件名（带上路径）
 
}；
#include <sys/in.h>
struct sockaddr_un
{
 int sin_family;//协议簇
 short sin_port;//端口号
 struct in_addr sin_addr;//IP地址
};
3、绑定（描述符通讯地址）
bind(sockfa,sockaddr,szieof(addr));
4、通讯
5、关闭socket描述符

客户端的程序：
步骤与服务器完全一样，除了第三步。第三步把bind换成connect

192.168.1.6

转换IP用函数：inet_addr();
转换端口号用函数：htons（）；
#include <arpa/inet.h>








