#ifndef CREATE_ROS_MSG_H
#define CREATE_ROS_MSG_H

#include <iostream>
#include <string>
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"

class CreateMsg{
 public:
  CreateMsg();
  ~CreateMsg();
  std_msgs::String packString(std::string str);
  geometry_msgs::Pose packPose(float x, float y, float z, float qx, float qy, float qz, float qw);
 private:

};

#endif
