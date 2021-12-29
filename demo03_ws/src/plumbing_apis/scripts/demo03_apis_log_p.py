#! /usr/bin/env python
# -*- coding:UTF-8 -*-

import rospy

if __name__ == "__main__":
    #演示日志函数
    rospy.init_node("hello_log")

    rospy.logdebug("hello,debug")  #不会输出
    rospy.loginfo("hello,info")  #默认白色字体
    rospy.logwarn("hello,warn")  #默认黄色字体
    rospy.logerr("hello,error")  #默认红色字体
    rospy.logfatal("hello,fatal") #默认红色字体