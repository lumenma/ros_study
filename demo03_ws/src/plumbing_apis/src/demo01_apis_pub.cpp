#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
#include  <sstream>

/*  
    实现流程:
        1.包含头文件 
         ROS中文本类型--->std_msgs/String.h
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 节点句柄
        4.实例化 发布者 对象
        5.组织被发布的数据，并编写逻辑发布数据
      
*/

int main(int argc, char *argv[])
{
    //设置编码
    setlocale(LC_ALL,"");
    // 2.初始化 ROS 节点:命名(唯一)

  /**  ROS初始化函数。
 *
 * 该函数可以解析并使用节点启动时传入的参数(通过参数设置节点名称、命名空间...) 
 *
 * 该函数有多个重载版本，如果使用NodeHandle建议调用该版本。 
 *
 * \param argc 参数个数
 * \param argv 参数列表
 * \param name 节点名称，需要保证其唯一性，不允许包含命名空间
 * \param options 节点启动选项，被封装进了ros::init_options
 * 使用:
 * 1.argc 与 argv 的使用
 * 如果按照ROS中特定格式传入实参,那麽ROS可以加以使用,比如用来设置全局参数,给节点重命名.
 * 2.options的使用
 * 节点名称需要保证唯一,会导致一个问题:同一节点不能重复启动.
 * ROS 中当有重名的节点启动时,之前的节点会被关闭,
 * 需求:特定场景下,需要一个节点多次启动且能正常运行,怎麽办.
 * 解决:设置启动项:ros::init_options::AnonymousName
 *      当创建ROS节点时,会在用户自定义的节点名称后缀随机数,从而避免重名问题.
 */


    ros::init(argc,argv,"ergouzi",ros::init_options::AnonymousName);

     //3.实例化 ROS 节点句柄
     ros::NodeHandle nh; //该类封装了 ROS 中的一些常用功能

     //4.实例化 发布者 对象
    /*
        作用:创建发布者对象
        模板:被发布的消息类型
        参数:
            1.话题名称
            2.队列长度
            3.latch(可选)如果设置为true,会保存发布方的最后一条消息,并且新的订阅对象连接到发布方时,发布方会将这条消息发送给订阅者
        使用:
            latch 设置为 true 的作用?
            以静态地图发布为例,方案一:可以使用固定频率发送地图数据,但是效率低；方案2;可以将地图发布对象的 latch 设置为 true ,并且发布方只发送一次数据,每当订阅者连接时,
            将地图数据发送给订阅者(只发送一次),这样就提高了数据的发送效率.

    */  
     ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10,true);

     // 5.组织被发布的数据，并编写逻辑发布数据
     //要求以 10的频率发布数据，并且文本后添加编号
     //先创建被发布的消息
     std_msgs::String msg;
     //发布频率
     ros::Rate rate(1);
     //设置编号
     int count = 0;

     //编写循环，循环中发布数据
     ros::Duration(3.0).sleep();  //延迟第一条数据的发送
     while (ros::ok())
     {
        //如果计数器 >= 50,那麽关闭节点
        if (count >= 50)
        {
            ros::shutdown();
        }
         
         count++;
         
         //实现字符串拼接数字
         std::stringstream ss;
         ss << "hello---> "<< count;
         //msg.data ="hello";
         msg.data = ss.str();

        //  if (count <= 10)
        //  {
        //     pub.publish(msg);
        //     //添加日志
        //     ROS_INFO("发布的数据是:%s",ss.str().c_str());
        //  }
        
        pub.publish(msg);
        //添加日志
        ROS_INFO("发布的数据是:%s",ss.str().c_str());

        rate.sleep();
         ros::spinOnce(); //循环读取接收的数据，并调用回调函数处理
         ROS_INFO("一轮回调执行完毕.....");
     }

    return 0;
}