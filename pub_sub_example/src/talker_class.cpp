#include "pub_sub_example/talker_class.h"

Talker::Talker(ros::NodeHandle &n): nh_(n){
  std::cout << "constructor" << std::endl;

  talker_class_pub = nh_.advertise<pub_sub_example::TwoInt>("talker_class", 10);
}

Talker::~Talker(){
  std::cout << "destructor" << std::endl;
}

void Talker::publish_msg(){
  msg.arg_one = c1;
  msg.arg_two = c2;
  talker_class_pub.publish(msg);
}
