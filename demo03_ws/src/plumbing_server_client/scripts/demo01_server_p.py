#! /usr/bin/env python
#coding:utf-8

import rospy
from plumbing_server_client.srv import Addints,AddintsRequest,AddintsResponse
# from plumbing_server_client.srv import *
"""
    服务器端实现:解析客户端请求,产生响应.
        
        1.导包
        2.初始化 ROS 节点
        3.创建服务端对象
        4.回调函数处理逻辑请求并产生响应
        5.spin() 函数

"""
# 参数:封装了请求数据
# 返回值:响应数据
def doNum(request):
    # 1.解析提交的两个整数
    num1 = request.num1
    num2 = request.num2
    # 2.求和
    sum = num1 + num2
    # 3.将结果封装进响应
    response = AddintsResponse()
    response.sum = sum

    rospy.loginfo("服务器解析的数据num1 = %d, mum2 = %d, 响应的结果: sum = %d",num1,num2,sum)

    return response

if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("heiShui")
    # 3.创建服务端对象
    server = rospy.Service("addInts",Addints,doNum)
    rospy.loginfo("服务器已经启动了")
    # 4.回调函数处理逻辑请求并产生响应
    # 5.spin() 函数
    rospy.spin()