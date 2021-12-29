# 相机标定

https://github.com/code-iai/iai_kinect2/tree/master/kinect2_calibration

## kinect2标定 Ubuntu16.04 ROS kinetic
https://blog.csdn.net/qingdu007/article/details/79204115
https://www.cnblogs.com/li-yao7758258/p/7445429.html    重点

## Kinect V2 相机标定(光头明明)
https://blog.csdn.net/harrycomeon/article/details/100621013?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162598886416780357225286%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162598886416780357225286&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-4-100621013.pc_search_result_cache&utm_term=iai_kinect2%E7%9B%B8%E6%9C%BA%E6%A0%87%E5%AE%9A&spm=1018.2226.3001.4187

## 重要1111改分辨率
https://blog.csdn.net/qq_40313712/article/details/85231192

## 使用iai_kinect2标定kinectV2相机  改相机参数

https://blog.csdn.net/weixin_38636815/article/details/106692197?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162599212216780261917505%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162599212216780261917505&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-1-106692197.pc_search_result_cache&utm_term=iai_kinect2+++kinect2_viewer&spm=1018.2226.3001.4187

## Ros环境下 kinect标定 -- ROS功能包
https://blog.csdn.net/Siyuada/article/details/78981555







# ros+iai_kinect2标定教程-失败-效果很差-更新和解决办法
https://blog.csdn.net/hehedadaq/article/details/79559310
Kinect2.0相机标定matlab
https://blog.csdn.net/qq_40791099/article/details/106896506?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242

我通常使用0.6到2.5米之间的距离，近中远
用相机拍摄不同角度的彩色图片（正视、俯视、仰视、左倾、右倾），不少于20张
注意：

棋盘尽量覆盖在画面一半
角度越多越好；
棋盘要出现在图像的各个位置；
平面与摄像头平面角度不要超过45°（我自己设置的时候发现角度太斜了红外图像就采集不到了，但是彩色摄像头可以，彩色图片也能采集到，但是不知道放在matlab里能不能识别格子的角点了，所以还是按照大家都这么做的做吧）
参考的一篇博客说距离要2种及以上（我不知道距离远近有什么影响，反正我是照顾到红外相机太远了就采集不到，所以都离得比较近）

## 手眼标定（手眼标定过程）重点看
https://blog.csdn.net/My_Precision/article/details/100064860?utm_medium=distribute.pc_relevant_t0.none-task-blog-2~default~BlogCommendFromMachineLearnPai2~default-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2~default~BlogCommendFromMachineLearnPai2~default-1.control
ROS下kinect2、ur5标定-内外参、配准、手眼标定
https://blog.csdn.net/sinat_23853639/article/details/80276848
KinectV2标定总结

https://blog.csdn.net/qq_34897331/article/details/108078655?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_utm_term-1&spm=1001.2101.3001.4242



## Ubuntu 16.04 中 Kinect 2.0 的 libfreenect2 驱动配置及其图像读取编程实现
https://blog.csdn.net/u012424737/article/details/80609451
## 点云系统的搭建--ROS，OPENNI，PCL1.8
https://blog.csdn.net/harrycomeon/article/details/89685126



## Aubo机器人的ROS环境搭建步骤--重点
https://blog.csdn.net/sinat_38284212/article/details/101626539

## Aubo机器人ROS应用
https://blog.csdn.net/sinat_38284212/article/details/101545844?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control

/opt/ros/kinetic/lib/moveit_ros_move_group/move_group: error while loading shared libraries: libmoveit_robot_trajectory.so.0.9.15: cannot open shared object file: No such file or directory [move_group-6] process has died [pid 3479, exit code 127, cmd /opt/ros/kinetic/lib/moveit_ros_move_group/move_group __name:=move_group __log:=/home/dubq/.ros/log/957a5678-e28f-11e9-99ee-f0def166d64b/move_group-6.log].
错误提示找不到libmoveit_robot_trajectory.so.0.9.15，但是在opt\ros\kinetic\lib目录下可以找到libmoveit_robot_trajectory.so.0.9.17，此问题可能是执行sudo apt upgrade导致的，故重装moveit，即执行：

sudo apt remove ros-kinetic-moveit*
sudo apt install ros-kinetic-moveit


AUBO i5 ros从建模到gazebo仿真-建模
https://blog.csdn.net/haigujiujian/article/details/114977092?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242


在包里面建立以上的文件夹，include 就是存放头文件的，meshes就是存放关节的stl文件以及dae文件，src就是存放源文件，urdf就是存放模型组织文件的

那么urdf中的文件会调用meshes中的模型文件，然后rviz这个文件夹里面就是存放rviz可视化窗口的配置文件。
遨博机器人ROS包aubo_robot 在kinetic版ROS下的编译
https://blog.csdn.net/wxflamy/article/details/79149537
ROS操作系统 | 建立Aubo_Robot通信-资源集合

https://blog.csdn.net/weixin_45843236/article/details/105672726?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162624313016780357217229%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162624313016780357217229&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-1-105672726.pc_search_result_cache&utm_term=aubo_i5%2Fshoulder_joint_position_controller%2Fcommand&spm=1018.2226.3001.4187

[ERROR] [1580993178.194686301, 0.325000000]: GazeboRosControlPlugin missing while using DefaultRobotHWSim, defaults to true.
This setting assumes you have an old package with an old implementation of DefaultRobotHWSim, where the robotNamespace is disregarded and absolute paths are used instead.
If you do not want to fix this issue in an old package just set to true.
https://blog.csdn.net/weixin_44172434/article/details/104202179?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162624729016780366596947%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162624729016780366596947&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-1-104202179.pc_search_result_cache&utm_term=%5BERROR%5D+%5B1626246717.875630069%2C+0.001000000%5D%3A+GazeboRosControlPlugin+missing+%3ClegacyModeNS%3E+while+using+DefaultRobotHWSim%2C+defaults+to+true.+This+setting+assumes+you+have+an+old+package+with+an+old+imp&spm=1018.2226.3001.4187
aubo i5 + realsense D435i识别抓取实践四
https://blog.csdn.net/u014205023/article/details/108769586?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.control

009311765147

