// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/temperature.hpp>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto nh = rclcpp::Node::make_shared("temperature_sensor_node");
  auto pub = nh->create_publisher<sensor_msgs::msg::Temperature>("/temperature", rclcpp::QoS(1));

  rclcpp::Rate r(10);

  while (rclcpp::ok())
  {
    sensor_msgs::msg::Temperature msg;
    msg.temperature = sin(nh->now().seconds() / 2.0) * 50;
    pub->publish(msg);

    r.sleep();
    rclcpp::spin_some(nh);
  }
}
