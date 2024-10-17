#pragma once
#include <box2d/box2d.h>
#include <vector>
#include "Component.h"
#include "Box2dWorld.h"

class StaticBodyComponent : public Component
{
public:
	static b2Body* body;

	StaticBodyComponent(float x, float y, float pixels_per_meter = 1.0f);

	void createAsBox(float width, float height, bool isSensor = false);
	void createAsCircle(float radius, bool isSensor = false);
	
	// The point_array should define at least 3 points
	// and the points should be defined in a counter-clockwise order
	void createAsPolygon(const std::vector<b2Vec2>& point_array, bool isSensor = false);

	void addBoxFixture(float width, float height, bool isSensor = false);
	void addCircleFixture(float radius, bool isSensor = false);
	void addPolygonFixture(const std::vector<b2Vec2>& point_array, bool isSensor = false);

private:
	static b2World& world;
	static float pixels_per_meter;
	static float x;
	static float y;
};

