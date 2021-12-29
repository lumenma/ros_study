#! /usr/bin/env python
# -*- coding:UTF-8 -*-
import rospy
from plumbing_pub_sub.msg import Person
"""
    发布方:发布人的消息
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据
"""
if __name__ == "__main__":
    # 2.初始化 ROS 节点:命名(唯一)
    rospy.init_node("daMa")
    # 3.实例化 发布者 对象
    pub = rospy.Publisher("jiaoSheTou",Person,queue_size=10)
    # 4.组织被发布的数据，并编写逻辑发布数据
    #4-1.创建Person数据
    p = Person()
    p.name = "奥特曼"
    p.age = 8
    p.height = 1.85
    #4-2.创建 Rate 对象
    rate = rospy.Rate(1)
    #4-3.循环发布数据
    while not rospy.is_shutdown():
        pub.publish(p)  #发布消息
        rospy.loginfo("发布的消息:%s, %d, %.2f",p.name, p.age, p.height)
        rate.sleep()  #休眠