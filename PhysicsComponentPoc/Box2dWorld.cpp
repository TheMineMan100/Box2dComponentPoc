#include "Box2dWorld.h"

Box2dWorld Box2dWorld::instance;
b2World Box2dWorld::_world(b2Vec2(0.0f, 9.8f));
