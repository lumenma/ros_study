#! /usr/bin/env python
#coding:utf-8
import rospy
from geometry_msgs.msg import Twist

"""
    编写 ROS 节点，控制小乌龟画圆

    准备工作:
        发布方:发布速度消息
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点

    实现流程:
        1.导包
        2.初始化 ROS 节点
        3.创建发布者对象
        4.组织数据并发布数据 循环发布运动控制消息

"""


if __name__ == "__main__":

    # 2.初始化 ROS 节点
    rospy.init_node("my_control_p")
    # 3.创建发布者对象
    pub = rospy.Publisher("/turtle1/cmd_vel",Twist,queue_size=10)
    # 4.组织数据并发布数据 循环发布运动控制消息
    #设置发布频率
    rate = rospy.Rate(10)
    #创建速度消息
    twist = Twist()

    twist.linear.x = 0.5
    twist.linear.y = 0
    twist.linear.z = 0

    twist.angular.x = 0
    twist.angular.y = 0
    twist.angular.z = 0.5
    #循环发布
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep()