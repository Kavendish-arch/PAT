/**
    C++接口安装
    采用源码编译的安装方式
    首先，安装一些依赖，根据自己的情况选择，如果不知道自己安装了那些依赖，就都输入一遍，如果已经安装系统会自动跳过，不会重复安装
    sudo apt-get install build-essential
    sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
    sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
    下载安装包、然后，将压缩包解压，我下载我是opencv3.4.3版本，所以最后解压出来的文件夹就是opencv-3.4.3，接着，先用命令行进入该文件夹，然后执行命令，如下所示：
    cd opencv-3.3.0 && ls
    mkdir build && cd build    //建立build 文件夹
    cmake ..			       //cmake编译 上级目录中的Cmakefile文件
    Ls && make -j7	           //make编译
    make install		       //安装
    #安装完成
*/

/**
Python 接口安装
有以下几种方法。具体操作如下：
方法一（推荐）：利用pip安装opencv-python
在安装之前，如果你之前安装过旧版本的opencv，那么就先将其删除，再进行下面的安装过程。
在pip中可以方便快速的安装opencv-python和opencv-contrib-python，只需要输入两条指令即可：
$ pip install opencv-python #安装opencv
$ pip install opencv-contrib-python #安装opencv的contrib扩展包
常见问题：
opencv-python和opencv-contrib-python是否必须要同时安装？
答：不需要，他们分别可以独自运行，但是一般情况下，都会将两个包都装上
报错显示pip找不到包？
答：这种请看多半是因为pip比较旧，这时只需要输入下面的指令更新以下pip就行了
$ pip install --upgrade pip$ pip install wheel #如果确定已经安装了wheel就不用执行这条指令
安装过程遇到错误提示？
答：确保你已经删除了旧版本的opencv python捆绑包

方法二:利用conda安装opencv
利用conda安装opencv，这种方法相较于pip安装方法来说，可以自由选择opencv的版本，使用面更广，
但是缺点是不能安装opencv-contrib。具体操作如下：
首先，可以查询一下conda里面可以安装的opencv：
conda search opencv
然后，根据你想要安装的opencv版本（以3.1.0为例），输入以下指令即可：
conda install opencv=3.1.0
以上两种opencv的安装方法可以满足大部分人的基本需求，
但是，如果你既想要自定义选择opencv的版本，又想要安装opencv-contrib扩展库，
那么可以采用源码编译的方式安装，这也是opencv官方推荐的安装方式。
 */

/**
方法三：源码编译安装opencv和contrib
首先，更新以下系统：
$ sudo apt-get update
$ sudo apt-get upgrade
接着，安装需要的编译工具
$ sudo apt-get install build-essential cmake pkg-config
然后，安装相应的依赖包
$sudo apt-get install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev
$sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
$ sudo apt-get install libxvidcore-dev libx264-dev
$ sudo apt-get install libgtk-3-dev
$ sudo apt-get install libatlas-base-dev gfortran

在Github的opencv项目主页下载你需要的版本，注意contrib的版本和opencv的版本要一致。
opencv源码下址：
https://github.com/opencv/opencv/releases
contrib源码下载地址：
https://github.com/opencv/opencv_contrib/releases

下载好opencv的源码压缩包以后，将其解压，然后，进入到opencv的文件夹中（这里我以opencv3.1.0为例）：
（注意，如果下面的指令报错，就将所有-D后面的空格删除）
$ cd ~/opencv-3.1.0/
$ mkdir build
$ cd build
$ cmake -D CMAKE_BUILD_TYPE=RELEASE \
        -D CMAKE_INSTALL_PREFIX=/usr/local \ 
#这里是opencv的安装路径，建议不要修改，就采用默认的安装路径即可    
-D INSTALL_PYTHON_EXAMPLES=ON \    
-D INSTALL_C_EXAMPLES=OFF \    
-D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib-3.1.0/modules \    
-D PYTHON_EXECUTABLE=~/.pyenv/bin/python \ 
#这是要用来编译的python路径    
-D BUILD_EXAMPLES=ON ..  
# 我在编译例子时遇到错误，把它改为OFF通过
上边的参数配置中，有几处是需要根据你自己电脑上的路径来设置的：
CMAKE_INSTALL_PREFIX：opencv的安装路径，可以自己设置，但建议就用默认路径
OPENCV_EXTRA_MODULES_PATH：contrib文件夹的所在路径，取决于你刚刚下载的contrib压缩包解压后的文件位置
PYTHON_EXECUTABLE：用来进行编译的python路径，如果你不知道自己所有python的路径的话，
可以利用指令which python来查询
完成cmake的配置后，利用make指令进行编译：
$ make
然后在进行安装
$ sudo make install
$ sudo ldconfig
最后，建立软连接
$ ln -s /usr/local/lib/python2.7/site-packages/cv2.so cv2.so

首先介绍一下我的安装环境：
本人这台机器是core I5 7200U，Nvidia 930MX，标准的笔记本配置，系统是Windows 10 64位，
CMake3.7.2，Visual Studio 2015（MSVC1900）。因为个人原因需要用到Python和CUDA，
本博文同时也会提供CUDA和Python的安装过程。

第一步，打开OpenCV官网（www.opencv.org），然后点击导航栏上的Releases，进入到OpenCV的下载界面如下：
Documentation是描述OpenCV当前版本的文档，对我们理解源码和使用sdk都有一定的帮助；
被矩形框标记的就是我们需要的源码了，点击后会直接下载对应的源码包
（从跳转链接来看，是从GitHub上下载的）。
接下来的几个pack就是官方分别在Windows、iOS、Android三个平台下编译好的安装包
（安装包的使用和在三个平台下安装应用程序是一样的，安装过程实际上就是解压过程，
解压后会有两个目录，一个是存放源码的，一个是存放SDK的）。
不过作为一个爱折腾的程序员，肯定想是从源码编译得到SDK，
而且如果你想和一些外部库（例如CUDA、Python、Java等）联合使用的话，\
肯定要源码编译，而且从自己机器上编译的是最适合自己机器的。

下载好源码后，解压到自己想要的目录下（我的目录是D:\Final Program\opencv-3.4.0），目录自己随意选择就好，但是注意路径中最好不要含有中文。解压后的内容如下：


使用过CMake的朋友在看到CMakeLists.txt文件时，就明白了，我们需要使用CMake工具才能得到我们想要的VS解决方案文件或工程文件，才能编译我们想要的SDK，所以我们需要下载CMake工具，这里提供一个下载的链接（https://cmake.org/files/），里面提供从0.5版本到最新的3.10，我这里使用的是3.7.2，这个版本没有多大的要求，但是不同的版本，当你点击configure之后，可能有个别选项不一致。
因为我个人需要用到CUDA和Python，
所以这里描述下CUDA和Python的安装过程：
CUDA：首先访问这个链接（https://developer.nvidia.com/cuda-downloads），
选择自己想要的版本，下载安装包然后安装即可，安装过程和安装Nvidia驱动差不多，
但是时间更长，安装完成后，大约需要4-5个G的空间。

Python：我这里使用的是Python3.2，访问链接（https://www.python.org/download/releases/3.2/）
这里值得注意的一点是不仅要下载msi的安装文件还需要下载对应的PDB，
否则OpenCV的Python部分的DEBUG会编译不过。另外如果你要编译64位的OpenCV，那么你的Python请选择64位。

所有的准备工作都完成了，现在开始使用CMake配置工程了，首先打开CMake，
然后配置源码目录和将要生成VS工程存放目录（推荐不要放在源码目录，保持源码不被污染），我的配置如下：

然后点击Configure，在这个过程中会下载ippicv和ffmpeg，中途不能断网，
否则会重新下载，这里提供OpenCV3.4对应的文件（http://download.csdn.net/download/hzgloveyd/10200165）。

如果你的Python没在环境变量中，那么你需要手动设置对应选项

然后点击Configure直到你的选项框中没有红色为止，然后点击Generate按钮生成VS工程即可。
到最后一步了，打开解决方案，在你配置的build目录里找到OpenCV.sln，双击运行。
然后点击生成按钮的皮生成，在对话框里先选中矩形框标记的1，点击生成按钮，当完成以后，再点击矩形框标记的2，
点击生成即可，你需要的SDK就在你build目录下的install目录里面
*/