#include "pub_sub_example/talker_class.h"

int main(int argc, char* argv[]){
  std::cout << "start program" << std::endl;

  ros::init(argc, argv, "talker_class");
  ros::NodeHandle n;
  
  Talker talker(n);

  ros::Rate rate(10);
  while (ros::ok()){
    talker.publish_msg();
    talker.c1++;
    talker.c2++;
    rate.sleep();
  }
  
  // ros::spin();
  
  return 0;
}
