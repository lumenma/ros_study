#! /usr/bin/env python
# -*- coding:UTF-8 -*-

import rospy
from std_msgs.msg import String

"""
   订阅实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 订阅者 对象
        4.处理订阅的消息(回调函数)
        5.spin()
"""
def doMsg(msg):
    rospy.loginfo("我订阅的数据:%s",msg.data)

if __name__ == "__main__":
        # 2.初始化 ROS 节点:命名(唯一)
        rospy.init_node("huaHua")
        # 3.实例化 订阅者 对象
        sub = rospy.Subscriber("fang",String,doMsg,queue_size=10)
        # 4.处理订阅的消息(回调函数)
        # 5.spin()
        rospy.spin()