#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
#include  <sstream>

/*  
    实现流程:
        1.包含头文件 
         ROS中文本类型--->std_msgs/String.h
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 节点句柄
        4.实例化 发布者 对象
        5.组织被发布的数据，并编写逻辑发布数据
      
*/

int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"ergouzi");

     //3.实例化 ROS 节点句柄
     ros::NodeHandle nh; //该类封装了 ROS 中的一些常用功能

     //4.实例化 发布者 对象
     ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);

     // 5.组织被发布的数据，并编写逻辑发布数据
     //要求以 10的频率发布数据，并且文本后添加编号
     //先创建被发布的消息
     std_msgs::String msg;
     //发布频率
     ros::Rate rate(1);
     //设置编号
     int count = 0;

     //编写循环，循环中发布数据
     ros::Duration(3.0).sleep();  //延迟第一条数据的发送
     while (ros::ok())
     {
         count++;
         
         //实现字符串拼接数字
         std::stringstream ss;
         ss << "hello---> "<< count;
         //msg.data ="hello";
         msg.data = ss.str();
         pub.publish(msg);
         //添加日志
         ROS_INFO("发布的数据是:%s",ss.str().c_str());
          
        rate.sleep();

         ros::spinOnce(); //循环读取接收的数据，并调用回调函数处理
     }

    return 0;
}