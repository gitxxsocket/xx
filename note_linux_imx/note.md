
{
    "cmake.generator": "MinGW Makefiles"
}

pacman -S mingw-w64-x86_64-cmake



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

M3jKfi74CtCd7b9
Qb9YQS45gDDxWd7

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


pacman -Sy 同步软件包数据库，然后再输入 pacman -Su 更新软件包，期间 msys2 提示你输入 y 之后会关闭，重新打开 再输入一遍 pacman -Su 即可。

安装并配置 Clang
安装 Clang 和 LLVM
打开 msys2 ，输入 pacman -S mingw64/mingw-w64-x86_64-make mingw64/mingw-w64-x86_64-gdb mingw64/mingw-w64-x86_64-clang
git@github.com:gitxxsocket/CmakeCreateSo.git
