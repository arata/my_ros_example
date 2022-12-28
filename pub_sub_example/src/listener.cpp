#include <iostream>

#include "ros/ros.h"
#include "std_msgs/String.h"

/*
void callback(const std_msgs::String::ConstPtr& msg){
  std::cout << msg->data << std::endl;
}
*/

void callback(std_msgs::String msg){
  std::cout << msg.data << std::endl;
}

int main(int argc, char* argv[]){
  std::cout << "start" << std::endl;
  
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("talker", 10, callback);
  ros::spin();

  return 0;
}
