cmake_minimum_required(VERSION 3.5)
project(nav2z_client)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(smacc2 REQUIRED)
find_package(std_srvs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(angles REQUIRED)
find_package(yaml_cpp_vendor REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(pluginlib REQUIRED)
find_package(bond REQUIRED)
find_package(slam_toolbox REQUIRED)
find_package(ament_index_cpp REQUIRED)

set(dependencies
  smacc2
  std_srvs
  std_msgs
  nav2_msgs
  tf2
  tf2_ros
  angles
  yaml_cpp_vendor
  tf2_geometry_msgs
  bond
  slam_toolbox
  ament_index_cpp
)

include_directories(include)

add_library(${PROJECT_NAME} SHARED
  src/${PROJECT_NAME}/nav2z_client.cpp
  src/${PROJECT_NAME}/common.cpp

  src/${PROJECT_NAME}/client_behaviors/cb_nav2z_client_behavior_base.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_absolute_rotate.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_rotate_look_at.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_navigate_backward.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_navigate_forward.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_abort_navigation.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_navigate_global_position.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_navigate_next_waypoint.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_navigate_next_waypoint_until_reached.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_navigate_named_waypoint.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_rotate.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_undo_path_backwards.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_wait_pose.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_wait_nav2_nodes.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_pause_slam.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_resume_slam.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_wait_transform.cpp
  src/${PROJECT_NAME}/client_behaviors/cb_seek_waypoint.cpp

  # COMPONENTS
  src/${PROJECT_NAME}/components/costmap_switch/cp_costmap_switch.cpp
  #src/${PROJECT_NAME}/components/odom_tracker/cp_odom_tracker_node.cpp

  src/${PROJECT_NAME}/components/odom_tracker/cp_odom_tracker.cpp
  src/${PROJECT_NAME}/components/planner_switcher/cp_planner_switcher.cpp
  src/${PROJECT_NAME}/components/goal_checker_switcher/cp_goal_checker_switcher.cpp
  src/${PROJECT_NAME}/components/pose/cp_pose.cpp
  src/${PROJECT_NAME}/components/waypoints_navigator/cp_waypoints_event_dispatcher.cpp
  src/${PROJECT_NAME}/components/waypoints_navigator/cp_waypoints_navigator.cpp
  src/${PROJECT_NAME}/components/waypoints_navigator/cp_waypoints_visualizer.cpp
  src/${PROJECT_NAME}/components/amcl/cp_amcl.cpp
  src/${PROJECT_NAME}/components/slam_toolbox/cp_slam_toolbox.cpp
)

ament_target_dependencies(${PROJECT_NAME}
                          ${dependencies})

target_link_libraries(${PROJECT_NAME})

ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${dependencies})

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include/
)

ament_package()
