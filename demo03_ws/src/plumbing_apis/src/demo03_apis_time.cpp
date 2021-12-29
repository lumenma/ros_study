#include "ros/ros.h"

/* 
    需求1: 演示时间相关操作(获取当前时刻 + 设置指定时刻)
    实现:
        1.准备(头文件,节点初始化,Nodehandle创建...)
        2.获取当前时刻
        3.设置指定时间
    需求2: 程序执行中停顿 5 秒
    实现: 
        1.创建持续时间对象
        2.休眠
    需求3:已知程序开始运行的时刻,和程序运行的时间,求运行结束时刻.
    实现:
        1.获取开始执行的时刻
        2.模拟运行时间(N秒)
        3.计算结束时间 = 开始 + 持续时间
    注意:
        1.时刻与持续时间可以执行加减
        2.持续时间之间也可以执行加减
        3.时刻之间可以可以相减,不可以相加
    需求4: 每隔1秒钟,在控制台输出一段文本
    实现;
        策略1:ros::Rate()
        策略2:定时器
    注意:
        创建: nh.createTimer()
        参数1:时间间隔 
        参数2:回调函数(时间事件 TimeEvent)
        参数:是否只执行一次
        参数4:是否自动启动(当设置为false,需要手动调用 timer.start())

        定时器启动后: ros::spin()

 */
    //回调函数
void cb(const ros::TimerEvent& event){
    ROS_INFO("------------");
    ROS_INFO("函数被调用的时刻:%.2f",event.current_real.toSec());
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    // 1.准备(头文件,节点初始化,Nodehandle创建...)
    ros::init(argc,argv,"hello_time");
    ros::NodeHandle nh; //注意:必须.否则会导致时间API调用失败(在NodeHandle会初始化时间操作)
    // 2.获取当前时刻
    //now 函数会将当前时刻封装并返回
    // 当前时间: now 被调用执行的那一刻
    // 参考系 :1970年01月01日 00:00:00
    ros::Time right_now = ros::Time::now();
    ROS_INFO("当前时刻:%.2f",right_now.toSec());
    ROS_INFO("当前时刻:%d",right_now.sec);
    // 3.设置指定时刻
    ros::Time t1(20,312345678);
    ros::Time t2(100.35);
    ROS_INFO("t1 = %.2f",t1.toSec());
    ROS_INFO("t2 = %.2f",t2.toSec());

    //----------------------------------------------------------------------------------------------
    ROS_INFO("--------------------------持续时间--------------------------------------------");

    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠: %.2f",start.toSec());

    //核心
    ros::Duration du(4.5);
    du.sleep(); //休眠

    ros::Time end = ros::Time::now();
    ROS_INFO("休眠结束: %.2f",end.toSec());

    //---------------------------------------------------------------------
    ROS_INFO("----------------------持续时间与时刻运算------------------------------");
    //时刻与持续时间运算
    // 1.获取开始执行的时刻
    ros::Time begin = ros::Time::now();
    // 2.模拟运行时间(N秒)
    ros::Duration du1(5);
    // 3.计算结束时间 = 开始 + 持续时间
    ros::Time stop = begin + du1; //也可以 -
    ROS_INFO("开始时刻: %.2f",begin.toSec());
    ROS_INFO("结束时刻: %.2f",stop.toSec());

    //时刻与时刻运算
    //ros::Time sum = begin + stop; //不可以相加
    ros::Duration du2 = begin - stop;
    ROS_INFO("时刻相减: %.2f",du2.toSec());
    //持续时间与持续时间运算
    ros::Duration du3 = du1 + du2; //0
    ros::Duration du4 = du1 - du2; //10
    ROS_INFO("du1 + du2 =: %.2f",du3.toSec());
    ROS_INFO("du1 - du2 =: %.2f",du4.toSec());

    //---------------------------------------------------------------------
    ROS_INFO("----------------------定时器------------------------------");
    /*
        ros::Timer createTimer(Duration period,      //时间间隔
                         const TimerCallback& callback,  //回调函数
                         bool oneshot = false,         //定时器是否是一次性
                         bool autostart = true)         //定时器是否自动启动
    */
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start(); //手动启动

    ros::spin(); //需要回旋
    return 0;
}
