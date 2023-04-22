# GIT  markdown

工具类型：GIT,SVN,CVS,VSS,TFS,Visual Studio Online....

## 分类

本地版本控制：补丁和版本，适合个人

集中版本控制：所有版本数据保存到服务器上，协同开发者从服务器上同步更新或者上传自己的修改。适用于公司，缺点很大，用户需要时常更新和同步数据，服务器故障损失大。因此需要定期备份。代表产品：SVN,CVS,VSS.

分布式版本控制:每个人都与版本信息库同步，存储空间占用大。安全隐患是个人可能泄露机密。不会因为网络和服务器故障而损失。代表产品：GIT

 GIT与SVN区别：

SVN是集中式版本控制系统，版本库是集中放在中央服务器的，而干活的时候，用的都是自己的电脑，所以首先要从中央服务器哪里得到最新的版本，然后干活，干完后，需要把自己做完的活推送到中央服务器。集中式版本控制系统是必须联网才能工作，如果在局域网还可以，带宽够大，速度够快，如果在互联网下，如果网速慢的话，就纳闷了。

Git是分布式版本控制系统，那么它就没有中央服务器的，每个人的电脑就是一个完整的版本库，这样，工作的时候就不需要联网了，因为版本都是在自己的电脑上。既然每个人的电脑都有一个完整的版本库，那多个人如何协作呢？比如说自己在电脑上改了文件A，其他人也在电脑上改了文件A，这时，只需把各自的修改推送给对方，就可以互相看到对方的修改了。

GIT是目前世界上最先进的分布式版本控制系统。



## 历史

linux与BitKeeper终止合作，Linux之父Linus benedict torvaid两周时间开发了GIT系统（免费而且开源）

## 官网进行下载和安装

GIT Bash:Unix和Linux风格的命令行，使用和推荐最多

GIT CMD：windows风格的命令行

GIT GUI：图形界面的Git，不建议初学者使用，尽量先熟悉常用命令。

## GIT基本理论

### 四个工作区域

工作目录，暂存区，资源库，远程的git仓库

*Workspacce:工作区，就是你平时存放项目代码的地方

*Inder/Stage：暂存区，位于.git目录下的index文件，暂存区会记录 git add 添加文件的相关信息（文件名、大小），不保存文件实体，通过 id 指向每个文件的实体。

使用 git status 可以查看暂存区的状态，暂存区标记了当前工作区中那些内容是被 git 管理的，当完成某个需求或者功能后需要提交代码，第一步就是通过 git add 先提交到暂存区。

*Repository：仓库区，安全存放数据的位置，这里有提交的到所有版本的数据。HEAD指向最新放入仓库的版本。

*Remote：远程仓库区，托管代码的服务器，位于托管代码的服务器，远程仓库的内容能够被分布在多个地点的处于协作关系的本地仓库修改。比起本地仓库，远程仓库通常旧一些，因此本地仓库修改完之后需要同步到远程仓库。例如：GitHub，gitee

注意：git是隐藏文件夹需要在Windows中打开权限才能查看。命令学习

cd /                 //切换到根目录
  cd /bin              //切换到根目录下的bin目录
  cd ../               //切换到上一级目录 或者使用命令：cd ..
  cd ~                 //切换到home目录
  cd -                 //切换到上次访问的目录
  cd xx(文件夹名)       //切换到本目录下的名为xx的文件目录，如果目录不存在报错
  cd /xxx/xx/x         //可以输入完整的路径，直接切换到目标目录，输入过程中可以使用tab键快速补全

pwd                 //显示当前目录路径

clear               //清屏命令

ls                   //查看当前目录下的所有目录和文件
  ls -a                //查看当前目录下的所有目录和文件（包括隐藏的文件）
  ls -l                //列表查看当前目录下的所有目录和文件（列表查看，显示更多信息），与命令"ll"效果一样
  ls /bin              //查看指定目录下的所有目录和文件 

touch（加类型）				//在当前目录下新建文件

rm						//移除一个文件

mkdir					//新建文件夹

rm-f					//清理文件夹

mv					//移动目标对象到文件夹中

reset					//重新初始化终端

history						//查看命令历史

help								//帮助

git config--（）--list					//查看配置 

## Git配置文件

#### 所有的配置文件都保存在本地

​     系统配置在GIT的安装目录下

​      个人配置在用户目录内。gitconfig文件中

git config --（） --list					//查看当前用户（）配置 

git config --system--list					//查看系统config的配置 

git config --global  user.name "名字名字" 		//写入config的个人配置

git config --global  user.email "邮箱邮箱" 			//写入个人配置邮箱

##### ”注意空格“

## Git 的工作流程

- 在工作区添加、修改文件；

- 将修改后的文件放入暂存区域；

  git add.

- 将暂存区域的文件提交到本地仓库；

  git commit.

- 将本地仓库的修改推送到远程仓库。

  则git管理的文件有三种状态：已修改（modified）已暂存（staged）已提交（committed）

### GIT项目的搭建

add到commit到push

clone到checkout和pull

一.创建本地仓库：1.创建全新的仓库；2.创建克隆远程的仓库

1.git init

2.git clone  (加网站地址可以去gitee找）

二.实现文件的版本控制

四种状态：

1.Untracked(未跟踪) ：通过git add.

2.Unmodify(已入库未修改):通过修改变成已修改，不然用git rm移出版本库回到上一级

3.Modified(已修改)：通过git add变成暂存，通过git checkout回到上一级，从库中取出文件覆盖当前文件

4

.Staged（暂存状态）：执行git commit同步修改到库中，变为已入库未修改的状态，执行git reset HEAD filename 则取消暂存，文件状态为已修改



git status[文件名字]			//查看指定文件状态

git status							//查看所有文件状态

git add .								//添加所有文件到暂存区

git commit-m“注释消息信息‘   					//提交暂存区中的内容到达本地仓库，-m提交信息



###### 忽略文件

主目录下建立”.gitignore“文件然后用语言进行设置



## 实践时出现的问题

##### The current branch master has no upstream branch.    指没有将本地的分支与远程仓库的分支进行关联



git log命令可以查看版本库中各个版本信息。

git branch 可以看见当前本地分支

通过`git branch -a`查看远程分支，有`master`和`remotes/origin/master`两个

git push --set-upstream origin master 使程序直接上传远程仓库

使用`git push -u origin master`命令上传本地仓库



##### Hi 张洁滨! You've successfully authenticated, but GITEE.COM does not provide shell access. 指git 向仓库推送代码失败。

ssh -T git@gitee.com 查看是否链接成功



#####  ! [rejected]        master -> master (non-fast-forward)    指码云中有的代码会被覆盖，可以强行推上先fetch到本地再merge和push

$ git fetch

$ git merge

3、在使用的时候，`git merge`，又出现了以下的问题

```vbnet
xu:QProj xiaokai$ git merge
fatal: refusing to merge unrelated histories
```

然后继续`git merge`,依然有问题

xu:QProj xiaokai$ git merge
fatal: refusing to merge unrelated histories

对于这个问题。使用`git pull origin master --allow-unrelated-histories`

后继续`git merge`

 `git add .`,`git commit -am "提交信息"`

然后再来一次`git merge`

然后输入`git pull`,显示如下

xu:QProj xiaokai$ git push origin master



#### 验证代码：

cd ~/.ssh

git remote -v 查看远程库的信息

cat ~/.ssh/id_rsa.pub      # 控制台上输出内容

```
ssh -T git@gitee.com
```

首次使用需要确认并添加主机到本机SSH可信列表。

$ pwd     回车之后进行查看当前文件夹位置

`$ ls`     查看当前文件夹都有什么文件

`$ cd ..`     点和cd之间有空格回退到上一级文件夹

`$ mkdir +文件夹名字` 只能新建文件夹

`touch +文件名` 只能新建文件

`$ rm 文件名.文件类型` 删除文件

`$ rm -r 文件夹`删除文件夹 ，注意这个要回到上一级文件夹才可以删。比如我要删除front-end文件夹，front-end在code里边，我就要在code目录下删除。

#### 在管理Git项目上，有两种克隆到本地的方法。

- 直接使用https url克隆到本地
- 使用SSH url克隆到本地

```
~/.ssh` 或者用`~/.ssh ls      观察电脑是否有.ssh文件夹
```

- 如果电脑上**有**，就会显示**bash: /c/Users/…/.ssh: Is a directory**
- 如果电脑上**没有**，那就显示**bash: /c/Users/…/.ssh: No such file or directory**

$ ssh -T git@gitee.com  测试链接

如果看到 **access denied**，者表示拒绝访问，那么你就需要使用 https 去访问。
注意，你是仓库的主人你才能使用SSH连接，如果你不是仓库主人，只是某个项目的成员，那你只能使用HTTPS连接。

$ git remote add + 名字 + 连接地址

添加之后没有任何提示，如果你想确定是否成功了，你可以再输一遍，这时候他会提示你刚才已经设置过了。

名字：你在往远程仓库推送的时候，你会说我要推给谁，总得给它起个名字。（你把孩子送去托儿所，你总得告诉司机是哪个托儿所吧）并且你以后可能会一个**本地仓库连接多个远程仓库**（这是后话），所以必须起名字加以区分。

- $ git remote -v 

- git remote remove + 名字    与某个仓库不链接

- **`git add -A`**，提交**所有变化**

- $ git commit -m "修改注释"

- $ git push -u 仓库名称 分支第一次要-u

- 分支：你现在只有主分支，所以分支直接写master。以后合作项目的时候，成员之间建了不同的分支，你就可以往你自己的分支上推。

- $ git push 名称 分支

- $ git push origin master -f     强制推送，因为报错90%是因为你本地仓库和远程仓库数据发生冲突，使用这个会直接用本地数据覆盖掉远程数据，可能损失数据哦。、

- $ git log 提交记录

- $ git commit --amend -m "修改的内容"

- $ git pull 仓库名称

- git fetch 加名字 加分支 同步本地和远程

- `git branch`命令的`-r`选项，可以用来查看远程分支，`-a`选项查看所有分支

- 可以使用`git merge`命令或者`git rebase`命令，在本地分支上合并远程分支。

- ```
  $ git fetch` + `$ git merge
  ```

**commit message格式**

```text
<type>(<scope>): <subject>
```

**type(必须)**

用于说明git commit的类别，只允许使用下面的标识。

feat：新功能（feature）。

fix/to：修复bug，可以是QA发现的BUG，也可以是研发自己发现的BUG。

- fix：产生diff并自动修复此问题。适合于一次提交直接修复问题
- to：只产生diff不自动修复此问题。适合于多次提交。最终修复问题提交时使用fix

docs：文档（documentation）。

style：格式（不影响代码运行的变动）。

refactor：重构（即不是新增功能，也不是修改bug的代码变动）。

perf：优化相关，比如提升性能、体验。

test：增加测试。

chore：构建过程或辅助工具的变动。

revert：回滚到上一个版本。

merge：代码合并。

sync：同步主线或分支的Bug。

git log后不能退出按q即可

## 版本回退

1.没有add

2.已经add未commit

3.已经commit

```c
git log //查看日志
//情况一使用
git checkout 目录下+文件名
//情况二使用
git checkout commitID 目录下+文件名      //commitID通过git log 查询
//情况三使用
git checkout commitID 目录下+文件名      //commitID通过git log 查询
git reset –hard 版本号//任意版本
git reset –hard HEAD ^   //退到上上个版本:将HEAD^改成HEAD^^, 退到前100个版本：git reset –hard HEAD~100

```

![](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/GZYA_MIJ2ODV2LJVDNRTEK.jpg)



## 分支管理

```c
//分支创建
	git init -b dev       //创建了dev的分支
    git branch        //查看当前分支状况
    git branch cs     //创建了cs的分支
    git branch -m cs abc   //修改了cs名字为abc
//分支删除
        git branch -d abc    //删除abc分支“-D为强制删除不论是否合并过，-d为删除已合并过的分支”
//分支切换
        git checkout abc     //切换到abc的分支目录下
//分支合并
        git merge main      //把main分支与当前分支合并
//分支创建并且切换到分支
        git checkout -b edf    //创建edf分支并且进入edf分支
//推送仓库
        git push github HEAD:github 
 
        
        
```



  

<img src="C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/2-16799135360215.jpg" alt="2" style="zoom:50%;" />

<img src="C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/3-16799135360276.jpg" alt="3"  />



## 远程库的使用

```c


git remote add 名字 仓库网址  //增加多个远程库：
git push gitee main   //推送main分支到gitee
git remote -v //展示操作方法
git remote show //展示当前已关联的远程库
git remote rename 旧名字 新名字  //修改远程仓库名字
git remote add origin XXXX //添加新的远程库
```



## PUSH冲突解决问题

```c
//1.能合并的冲突
git pull  //下拉远程库内容
//蓝色字母表示需要提交修改信息
:wq   //直接提交
//2.不能合并的冲突
    git diff 分支名 文件名   //查看修改内容
    git pull //程序会报错，我们需要手动去解决冲突
    再进行git add .和git commit 和git push
//3.还是不能提交的话
git init                           //初始化仓库
git add .(文件name)                //添加文件到本地 
git commit -m “first commit”      //添加文件描述信息
git remote add origin  远程仓库地址 //链接远程仓库 
git pull origin master           // 把本地仓库的变化连接到远程仓库master
git push -u origin master        //把本地仓库的文件推送到远程仓库master     
```

## merge遇到提交commit信息：          

1. 按键盘字母 i 进入insert模式
2. 修改最上面那行黄色合并信息,可以不修改
3. 按键盘左上角"Esc"
4. 输入":wq",注意是冒号+wq,按回车键即可



## 提交修正

```c
//1.对于提交错误文件的高效率且没有记录的修正
//先修正文件内容
git add .
git commit --amend -m '上次提交信息'    //就不会产生多次记录
//2.对于提交时遗漏文件的高效率且没有记录的修正
git add .
git commit --amend -m '上次提交信息'    //就不会产生多次记录 
//3.长开发周期中的小提交
git add .
git commit --amend -m '上次提交信息n-n' 
```



## 仓库FORK和PR

在GitHub中进行FORK

然后在本地进行git clone 

GitHub仓库地址contrbute中





## ![5](C:/Users/zhangjiejie666/Desktop/star%E9%AA%8C%E6%94%B6/git%E7%AC%94%E8%AE%B0/%E6%96%B0%E5%BB%BA%E6%96%87%E4%BB%B6%E5%A4%B9/5.jpg)

## git pull用法：

git pull命令的作用是：取回远程主机某个分支的更新，再与本地的指定分支合并。

一句话总结git pull和git fetch的区别：git pull = git fetch + git merge

git fetch不会进行合并执行后需要手动执行git merge合并分支，而git pull拉取远程分之后直接与本地分支进行合并。更准确地说，git pull使用给定的参数运行git fetch，并调用git merge将检索到的分支头合并到当前分支中。

基本用法：

git pull <远程主机名> <远程分支名>:<本地分支名>

例如执行下面语句：

git pull origin master

表示将远程origin主机的master分支拉取过来和本地的当前分支进行合并。
