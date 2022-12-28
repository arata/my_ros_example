#include <iostream>

#include "ros/ros.h"
#include "pub_sub_example/TwoInt.h"
#include "pub_sub_example/TwoIntStamp.h"

void callback(const pub_sub_example::TwoInt::ConstPtr& msg){
  std::cout << std::to_string(msg->arg_one) << ", " << std::to_string(msg->arg_two) << std::endl;
  //std::cout << msg->arg_one << ", " << msg->arg_two) << std::endl;
  //std::cout << msg->arg_one << std::endl;
}

void callback_stamp(pub_sub_example::TwoIntStamp msg){
  std::cout << "stamp-> " << msg.header.stamp << ", " << std::to_string(msg.data.arg_one) << ", " << std::to_string(msg.data.arg_two) << std::endl;
}

int main(int argc, char* argv[]){
  std::cout << "start" << std::endl;

  ros::init(argc, argv, "listener_custom");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("talker_custom_msg", 10, callback);
  ros::Subscriber sub_stamp = n.subscribe("talker_custom_msg_stamp", 10, callback_stamp);
  ros::spin();

  return 0;
}
