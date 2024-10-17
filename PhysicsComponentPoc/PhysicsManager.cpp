#include "PhysicsManager.h"

b2World& PhysicsManager::getWorldInstance()
{
    return _world;
}

void PhysicsManager::onUpdate(float timeStep, int32 velocityIterations, int32 positionIterations)
{
    _world.Step(timeStep, velocityIterations, positionIterations);
}
