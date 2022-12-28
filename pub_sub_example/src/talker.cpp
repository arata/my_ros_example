#include <iostream>

#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char* argv[]){
  std::cout << "start" << std::endl;
  
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher talker_pub = n.advertise<std_msgs::String>("talker", 10);
  std_msgs::String pub_msg;
  int counter = 0;
  ros::Rate rate(10);
  while (ros::ok()){
    pub_msg.data = "hello " + std::to_string(counter) ;
    talker_pub.publish(pub_msg);
    counter++;
    rate.sleep();
  }
  return 0;
}
