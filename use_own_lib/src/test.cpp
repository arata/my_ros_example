#include <iostream>
#include "ros/ros.h"

#include "extra_ros_lib/create_ros_msg.h"

int main(int argc, char* argv[]){
  std::cout << "start" << std::endl;

  ros::init(argc, argv, "test_my_lib");
  ros::NodeHandle n;

  ros::Publisher talker_lib_pub = n.advertise<std_msgs::String>("talker_lib", 10);

  CreateMsg create_msg;
  std_msgs::String strmsg = create_msg.packString("hello");
  geometry_msgs::Pose posemsg = create_msg.packPose(1.0,1.0,1.0,1.0,1.0,1.0,1.0);

  ros::Rate rate(10);
  while (ros::ok){
    talker_lib_pub.publish(strmsg);
    rate.sleep();
  }

  return 0;
}
