#include "extra_ros_lib/create_ros_msg.h"

CreateMsg::CreateMsg(){
  std::cout << "constructor" << std::endl;
  
}

CreateMsg::~CreateMsg(){
  std::cout << "destructor" << std::endl;
}

std_msgs::String CreateMsg::packString(std::string str){
  std_msgs::String msg;
  msg.data = str;
  return msg;
}

geometry_msgs::Pose CreateMsg::packPose(float x, float y, float z,
                                        float qx, float qy, float qz, float qw){
  geometry_msgs::Pose msg;
  msg.position.x = x;
  msg.position.y = y;
  msg.position.z = z;
  msg.orientation.x = qx;
  msg.orientation.y = qy;
  msg.orientation.z = qz;
  msg.orientation.w = qw;

  return msg;
}
