#include "ros/ros.h"
#include "std_msgs/String.h"

/*
    需求: 演示不同类型的话题名称设置
         设置话题名称与命名空间

*/

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"hello");
    // ros::NodeHandle nh;

    //核心:设置不同类型的话题
    // rosrun rename02_topic topic_name __ns:=xxx
    //1.全局----话题名称需要以 / 开头(也可以设置自己的命名空间),这种情况下和节点(命名空间以及名称)没有关系
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);

    //2.相对----非 / 开头
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);

    //3.私有---需要创建特定 NodeHandle nh("~")
    ros::NodeHandle nh("~");
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",1000);


    //注意:如果私有的NH创建的话题以 / 开头(全局话题),生成的话题是全局非私有
    //全局话题优先级更高
    ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",1000);

    while (ros::ok())
    {
        /* code */
    }
    
    return 0;
}
