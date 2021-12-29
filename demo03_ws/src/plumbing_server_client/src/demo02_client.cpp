#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

/*
     客户端实现:提交两个整数,并处理响应的结果

        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 节点句柄
        4.创建一个客户端对象
        5.回调函数处理请求并产生响应
    实现参数的动态提交
       1.格式:rosrun xxxxxxx   xxxxxx  12 34
       2.节点执行时,需要获取命令中的参数,并组织进 request
    问题:
        如果先启动客户端,那么会请求异常
    需求:
        如果先启动客户端,不要直接抛出异常,而是挂起,等服务器启动后,再正常请求.
    解决:
        在ROS中内置了相关函数,这些函数可以让客户端启动后挂起,等待服务器启动.
        client.waitForExistence();
        ros::service::waitForService("服务话题");
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //优化实现,获取命令中的参数
    if (argc != 3){
        ROS_INFO("提交的参数个数不对.");
        return 1;
    }
    
    // 2.初始化 ROS 节点
    ros::init(argc,argv,"daBao");
    // 3.创建 ROS 节点句柄
    ros::NodeHandle nh;
    // 4.创建一个客户端对象
    ros::ServiceClient client=nh.serviceClient<plumbing_server_client::Addints>("addints");
    // 5.提交请求并产生响应
    plumbing_server_client::Addints ai;
    //5-1 组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    //5-2处理响应
    //调用判断服务器状态的函数
    //函数1
    // client.waitForExistence();
    ros::service::waitForService("addints");
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("响应成功!");
        //获取结果
        ROS_INFO("响应结果 = %d",ai.response.sum);
    }else{
        ROS_INFO("处理失败....");
    }
    
    return 0;
}