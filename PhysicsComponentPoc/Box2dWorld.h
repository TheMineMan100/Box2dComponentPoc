#ifndef Box2dWorld_h
#define Box2dWorld_h

#pragma once
#include <box2d/box2d.h>

class Box2dWorld
{
public:
	static Box2dWorld& getInstance() { return instance; }
	static b2World& getWorld() { return _world; }

	Box2dWorld(const Box2dWorld&) = delete;
	Box2dWorld(Box2dWorld&&) = delete;
	Box2dWorld& operator=(const Box2dWorld&) = delete;
	Box2dWorld& operator=(Box2dWorld&&) = delete;
private:
	static Box2dWorld instance;
	static b2World _world;

	Box2dWorld() {}
};

#endif // !Box2dWorld.h

