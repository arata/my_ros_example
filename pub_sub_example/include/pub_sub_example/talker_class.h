#ifndef TALKER_CLASS_H
#define TALKER_CLASS_H

#include "ros/ros.h"
#include "pub_sub_example/TwoInt.h"

class Talker{
 public:
  Talker(ros::NodeHandle &n);
  ~Talker();

  void publish_msg();
  
  int c1 = 0;
  int c2 = 0;

 private:
  ros::NodeHandle nh_;
  ros::Publisher talker_class_pub;

  pub_sub_example::TwoInt msg;

};

#endif
