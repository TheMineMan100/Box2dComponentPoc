#pragma once
#include <box2d/box2d.h>
#include "Box2dWorld.h"

class PhysicsManager
{
public:
	b2World& getWorldInstance();

	void onUpdate(float timeStep = 1.0 / 60, int32 velocityIterations = int32(8), int32 positionIterations = int32(3));
private:
	b2World& _world = Box2dWorld::getWorld();
};
