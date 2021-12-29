#include "ros/ros.h"

int main(int argc, char *argv[])
{
    //乱码解决
    //setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "zh_CN.utf8");
    //执行节点初始化
    ros::init(argc,argv,"HelloVSCode");

    //输出日志
    ROS_INFO("hello,哈哈哈");
    
    return 0;
}