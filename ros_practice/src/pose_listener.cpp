#include "ros/ros.h"
#include "turtlesim/Pose.h"

void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("Turtle1 pose: x:%0.6f, y:%0.6f, theta:%0.6f, linear_v:%0.6f, angular_v:%0.6f", msg->x, msg->y, msg->theta, msg->linear_velocity, msg->angular_velocity);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/turtle1/pose", 1000, poseCallback);

  ros::spin();

  return 0;
}
