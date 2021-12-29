#include "ros/ros.h"
#include "turtlesim/Spawn.h"

/*
    需求:是向服务端发送请求,生成一只小乌龟
    准备工作:
        1.服务话题 /spawn
        2.服务消息类型 turtlesim/Spawn
        3.运行前先启动 turtlesim_node 节点

    实现流程:
        1.包含头文件
          需要包含 turtlesim 包下资源，注意在 package.xml 配置
        2.初始化 ros 节点
        3.创建 ros 节点句柄
        4.创建 service 客户端对象
        5.组织数据并发送
        6.处理响应

*/

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 2.初始化 ros 节点
    ros::init(argc,argv,"service_call");
    // 3.创建 ros 节点句柄
    ros::NodeHandle nh;
    // 4.创建 service 客户端对象
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    // 5.组织数据并发送
    //组织请求数据
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    //5-2发送请求
    //判断服务器状态
    // ros::service::waitForService("/spawn");
    client.waitForExistence();
    bool flag = client.call(spawn); //flag 接受响应状态,响应结果也会被设置成spawn对象
    // 6.处理响应
    if (flag)
    {
        ROS_INFO("乌龟生成成功,新乌龟叫: %s",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("请求失败!!!");
    }
    
    return 0;
}
