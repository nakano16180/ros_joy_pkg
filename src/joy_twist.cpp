#include<ros/ros.h>
#include<sensor_msgs/Joy.h>
#include<geometry_msgs/Twist.h>

using namespace std;

class JoyTwist{
    public:
    JoyTwist(){
        ros::NodeHandle node;          //ノードのハンドルを宣言
        
        joy_sub_ = node.subscribe("joy", 1, &JoyTwist::joyCallback, this);
        twist_pub_ = node.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1);
    }

    void joyCallback(const sensor_msgs::Joy &joy_msg){          //コントローラの指示を受け取る関数
        if(joy_msg.buttons[2] == 1){     //○ボタン
            geometry_msgs::Twist twist;
            twist.linear.x = joy_msg.axes[1]*0.5;     //L stick up or down
            twist.angular.z = joy_msg.axes[0]*1.0;     //L stick right or left
            twist_pub_.publish(twist);
            
        }
        if(joy_msg.buttons[6] == 1){     //L2
            geometry_msgs::Twist twist;
            //twist.linear.x = joy_msg.axes[1]*0.5;     //L stick up or down
            twist.angular.z = joy_msg.buttons[6]*1.0;
            twist_pub_.publish(twist);
            
            //ROS_INFO("L2 buttons is pushed");
        }
        if(joy_msg.buttons[7] == 1){     //R2
            geometry_msgs::Twist twist;
            //twist.linear.x = joy_msg.axes[1]*0.5;     //L stick up or down
            twist.angular.z = joy_msg.buttons[7]*(-1.0);
            twist_pub_.publish(twist);
            
            //ROS_INFO("R2 buttons is pushed");
        }   
    }

private:
    ros::Subscriber joy_sub_;
    ros::Publisher twist_pub_;
};

int main(int argc, char **argv){

    ros::init(argc, argv, "joy_twist");
    JoyTwist joy_twist;
    
    ros::spin();
}

