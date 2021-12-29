#! /usr/bin/env python
# -*- coding:UTF-8 -*-

import rospy
from plumbing_pub_sub.msg import Person

"""
    订阅方:订阅人的消息
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据
        5.spin()
"""
def doPerson(p):
        rospy.loginfo("小伙子的数据:%s, %d, %.2f",p.name, p.age, p.height)
        
if __name__ == "__main__":
        # 2.初始化 ROS 节点:命名(唯一)
        rospy.init_node("daYe")
        # 3.实例化 订阅者 对象
        sub = rospy.Subscriber("jiaoSheTou",Person,doPerson)
        # 4.处理订阅的消息(回调函数)
        # 5.spin()
        rospy.spin()