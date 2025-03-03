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

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include <tf2_ros/buffer.h>

#include <nav2z_client/components/odom_tracker/cp_odom_tracker.hpp>
#include "cb_nav2z_client_behavior_base.hpp"

namespace cl_nav2z
{
using ::cl_nav2z::odom_tracker::CpOdomTracker;

struct CbUndoPathBackwardsOptions
{
  // the name of the goal checker selected in the navigation2 stack
  std::optional<std::string> goalCheckerId_;

  // the name of the goal checker selected in the navigation2 stack
  std::optional<std::string> undoControllerName_;
};

class CbUndoPathBackwards : public CbNav2ZClientBehaviorBase
{
public:
  CbUndoPathBackwards(std::optional<CbUndoPathBackwardsOptions> options = std::nullopt);

  void onEntry() override;

  void onExit() override;

private:
  std::shared_ptr<tf2_ros::Buffer> listener;

  CpOdomTracker * odomTracker;

  std::optional<CbUndoPathBackwardsOptions> options_;
};
}  // namespace cl_nav2z
