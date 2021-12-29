#! /usr/bin/env python
# -*- coding:UTF-8 -*-

import rospy
from std_msgs.msg import String  

"""
    使用 python 实现消息发布
    实现流程:
        1.导包 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 发布者 对象
        4.组织被发布的数据，并编写逻辑发布数据
"""
def cb():
    rospy.loginfo("节点正在被关闭.....")

if __name__ == "__main__":

    # 2.初始化 ROS 节点:命名(唯一)

    """
        作用: ROS初始化

        参数:
            name ---- 设置节点名称的
            argv=None, ----封装节点调用时传递的参数
            anonymous=False,----可以为节点名称生成随机后缀,可以解决重名问题.
        使用:
            1.argv使用
            可以按照ROS中指定的语法格式传参,ROS可以解析并加以使用
            2.anonymous使用
            可以设置为 true ,节点名称可以后缀随机数
    """

    rospy.init_node("sanDai",anonymous = True)  #传入节点名称

    # 3.实例化 发布者 对象;
    """
        内容: latch
            bool 值,默认是False
        作用: 如果设置为True,可以将发布的最后一条消息保存,且后续当新的订阅对象连接时,会将
            该数据发送给订阅者
        使用: latch = True

    """
    # pub = rospy.Publisher("che",String,queue_size=10,latch = True)
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
        #发布数据
        if count <= 10:
            msg.data = "hello"+ str(count)
            pub.publish(msg)
            rospy.loginfo("发布的数据:%s",msg.data)
        else:
            #关闭节点
            rospy.on_shutdown(cb)
            rospy.signal_shutdown("关闭节点")
        rate.sleep()
    rospy.spin() #重要

