#! /usr/bin/env python
#coding: utf-8

import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse

"""
    需求:向服务器发送请求,生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.导包
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ros 节点
        3.创建 service 客户端对象
        4.组织数据并发送请求
        5.处理响应结果

"""

if __name__ == "__main__":
    # 2.初始化 ros 节点
    rospy.init_node("service_call_p")
    # 3.创建 service 客户端对象
    client = rospy.ServiceProxy("/spawn",Spawn)
    # 4.组织数据并发送请求
    # 4-1 组织数据
    request = SpawnRequest()
    request.x = 4.5
    request.y = 2.0
    request.theta = -3
    request.name = "turtle2"
    # 4-2判断服务器状态并发送
    client.wait_for_service()
    try:
        response = client.call(request)
        # 5.处理响应结果
        rospy.loginfo("乌龟创建成功!，生成乌龟名字叫:%s",response.name)
    except Exception as e:
        rospy.logerr("请求处理异常")