#include "ros/ros.h"
#include "std_msgs/String.h"

/*订阅方实现流程:
        1.包含头文件 
          ROS中文本类型--->std_msgs/String.h
        2.初始化 ROS 节点:命名(唯一)
        3.实例化（创建） ROS 句柄
        4.实例化（创建） 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数
*/


void doMsg(const std_msgs::String::ConstPtr &msg)
{
  //设置编码
  setlocale(LC_ALL,"");
    //通过msg获取并操作订阅的数据
    ROS_INFO("翠花订阅的数据:%s",msg->data.c_str());
}
int main(int argc, char  *argv[])
{
    //2.初始化 ROS 节点:命名(唯一)
    ros::init(argc,argv,"cuiHua");
    //3.实例化（创建） ROS 句柄
    ros::NodeHandle nh;
    //4.实例化（创建） 订阅者 对象
    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);
    //5.处理订阅的消息(回调函数)
    ros::spin(); //官方建议,处理回调函数
    ROS_INFO("spin()后的语句");
    
    return 0;
}