#include "ros/ros.h"

int main(int argc, char *argv[])
{
    //执行 ros 节点初始化
    ros::init(argc,argv,"hello_node");
    
    //控制台输出 hello world
    ROS_INFO("hello world!");

    return 0;
}
