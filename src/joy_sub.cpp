#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

///メッセージを受信できたら呼ばれる関数

void msgCallback(const geometry_msgs::Twist &cmd_vel_msg){
    ROS_INFO("recieved: %d", cmd_vel_msg);   // 受信したメッセージを表示する関数
}

int main(int argc, char **argv){              // ノードのメイン関数

    ros::init(argc, argv, "joy_sub"); // ノード名の初期化
    ros::NodeHandle nh;                        // ROSシステムとの通信のためのノードのハンドルを宣言

    ros::Subscriber joy_sub = nh.subscribe("cmd_vel", 100, msgCallback);

    ros::spin();

  return 0;
}
