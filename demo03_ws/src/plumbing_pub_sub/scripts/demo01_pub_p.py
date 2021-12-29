#! /usr/bin/env python
# -*- coding:UTF-8 -*-

import os
import sys
import rospy
from std_msgs.msg import String  

# 设置临时环境变量
#路径写死,影响了代码的可移植性
#sys.path.insert(0,"/home/lumenma/demo03_ws/src/plumbing_pub_sub/scripts")
#优化,可以动态获取路径
path = os.path.abspath(".")
sys.path.insert(0,path + "/src/plumbing_pub_sub/scripts")

import tools


"""
    使用 python 实现消息发布
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据
"""

if __name__ == "__main__":

    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("sanDai")  #传入节点名称
    """
        原因:rosrun 执行时,参考路径是工作空间路径,在工作空间下无法查找依赖的模块
        解决:可以声明python的环境变量,当依赖某个模块时,先去指定的环境变量中查找依赖
    """

    # path = os.path.abspath(".")
    # rospy.loginfo("执行时参考的路径: %s",path)
    rospy.loginfo("num = %d",tools.num)
    # 3.实例化 发布者 对象
    pub = rospy.Publisher("che",String,queue_size=10)


    # 4.组织被发布的数据，并编写逻辑发布数据
    #创建数据
    msg = String()
    #指定发布频率
    rate = rospy.Rate(1)
    #设置计数器
    count = 0 
    #使用循环发布数据
    rospy.sleep(3)
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello"+ str(count)
        #发布数据
        pub.publish(msg)
        rospy.loginfo("发布的数据:%s",msg.data)
        rate.sleep()

