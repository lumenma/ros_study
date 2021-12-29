#! /usr/bin/env python
#coding: utf-8

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("hello")

    """
        需求: 实现不同类型的话题设置
    """
    # rosrun rename02_topic topic_name_p.py __ns:=xxx
    # 1.全局
    # pub = rospy.Publisher("/chatter",String,queue_size=10)
    # pub = rospy.Publisher("/yyy/chatter",String,queue_size=10)
    # 2.相对
    # pub = rospy.Publisher("chatter",String,queue_size=10)
    # pub = rospy.Publisher("yyy/chatter",String,queue_size=10)
    # 3.私有
    # pub = rospy.Publisher("~chatter",String,queue_size=10) #/xxx/hello/chatter
    pub = rospy.Publisher("~yyy/chatter",String,queue_size=10)  #/xxx/hello/yyy/chatterss

    while not rospy.is_shutdown():
        pass
