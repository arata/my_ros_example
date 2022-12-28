#include <iostream>

#include "ros/ros.h"
#include "pub_sub_example/TwoInt.h"
#include "pub_sub_example/TwoIntStamp.h"

int main(int argc, char* argv[]){
  std::cout << "start" << std::endl;
  
  ros::init(argc, argv, "talker_custom");
  ros::NodeHandle n;

  ros::Publisher talker_pub = n.advertise<pub_sub_example::TwoInt>("talker_custom_msg", 10);
  ros::Publisher talker_stamp_pub = n.advertise<pub_sub_example::TwoIntStamp>("talker_custom_msg_stamp", 10);

  pub_sub_example::TwoInt pub_msg;
  pub_sub_example::TwoIntStamp pub_msg_stamp;

  int c1 = 0;
  int c2 = 100;

  ros::Rate rate(10);
  while (ros::ok()){
    pub_msg.arg_one = c1;
    pub_msg.arg_two = c2;
    talker_pub.publish(pub_msg);

    pub_msg_stamp.header.stamp = ros::Time::now();
    pub_msg_stamp.data = pub_msg;
    talker_stamp_pub.publish(pub_msg_stamp);

    c1++;
    c2++;
    rate.sleep();
  }
  return 0;
}
