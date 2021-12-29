#include "ros/ros.h"
#include "plumbing_server_client/Addints.h"

/*
     服务端实现:解析客户端提交的数据,并运算再产生响应
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 节点句柄
        4.创建 服务 对象
        5.回调函数处理请求并产生响应
        6.由于请求有多个，需要调用 ros::spin()
*/

bool doNums(plumbing_server_client::Addints::Request &request,
            plumbing_server_client::Addints::Response &response)
{
 
    //1.处理请求
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("收到的请求数据为:num1 = %d, num2 = %d",num1, num2);

    //2.组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和的结果: sum = %d ",sum);

    return true;
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
     // 2.初始化 ROS 节点
    ros::init(argc,argv,"heiShui");  //节点名称需要保证统一
     // 3.创建 ROS 节点句柄
    ros::NodeHandle nh;
     // 4.创建 服务 对象
    ros::ServiceServer server = nh.advertiseService("addints",doNums);
     ROS_INFO("服务器端启动");
     // 5.回调函数处理请求并产生响应

     // 6.由于请求有多个，需要调用 ros::spin()
    ros::spin();
    return 0;
}