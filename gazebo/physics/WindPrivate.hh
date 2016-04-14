/*
 * Copyright (C) 2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_PHYSICS_WINDPRIVATE_HH_
#define _GAZEBO_PHYSICS_WINDPRIVATE_HH_

#include <functional>
#include <boost/shared_ptr.hpp>

#include <ignition/math/Vector3.hh>

#include "gazebo/physics/PhysicsTypes.hh"
#include "gazebo/transport/TransportTypes.hh"

namespace gazebo
{
  namespace physics
  {
    /// \internal
    /// \brief Private data for the Wind class
    class WindPrivate
    {
      /// \brief Pointer to the world.
      public: WorldPtr world;

      /// \brief Node for communication.
      public: transport::NodePtr node;

      /// \brief Response publisher.
      public: transport::PublisherPtr responsePub;

      /// \brief Subscribe to the wind topic.
      public: transport::SubscriberPtr windSub;

      /// \brief Subscribe to the request topic.
      public: transport::SubscriberPtr requestSub;

      /// \brief Wind linear velocity.
      public: ignition::math::Vector3d linearVel;

      /// \brief The function used to to calculate the wind velocity at an
      /// entity's location.
      /// It takes as input a reference to an instance of Wind and a pointer to
      /// an Entity.
      public: std::function< ignition::math::Vector3d (
                  std::shared_ptr<const Wind> &, const Entity *)> linearVelFunc;
    };
  }
}
#endif