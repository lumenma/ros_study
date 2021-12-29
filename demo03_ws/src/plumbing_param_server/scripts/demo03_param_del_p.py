#! /usr/bin/env python
# -*- coding:UTF-8 -*-

import rospy

"""
   演示参数删除
        rospy.delete_param("键")
"""

if __name__ == "__main__":
    rospy.init_node("del_param_p")

    try:
        #删除参数
        rospy.delete_param("radius_p")
    except Exception as e:
        rospy.loginfo("被删除的参数不存在")