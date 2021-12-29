#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/*
    编写 ROS 节点，控制小乌龟画圆
    需求:发布速度消息

    准备工作:
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建节点句柄
        4.创建发布者对象
        5.发布逻辑 循环发布运动控制消息
        6.spinOnce();
*/

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"my_control");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建发布者对象
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    // 5.发布逻辑 循环发布运动控制消息
    ros::Rate rate(10); //设置发布频率
    //组织被发布消息
    geometry_msgs::Twist twist;
    twist.linear.x = 1.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 0.5;
    //循环发布
    while (ros::ok())
    {
        pub.publish(twist);
        //休眠
        rate.sleep();
        //回头
        // 6.spinOnce();
        ros::spinOnce();
    }
     
    return 0;
}
