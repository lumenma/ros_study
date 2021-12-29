#! /usr/bin/env python
# coding=UTF-8

import rospy # 1.导包

if __name__ == "__main__":
     # 2.初始化 ROS 节点
    rospy.init_node("Hello_Vscode_p") 
     #3.日志输出 HelloWorld
    rospy.loginfo("Hello VScode, 我是 Python！")  