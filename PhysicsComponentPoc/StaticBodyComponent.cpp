#include "StaticBodyComponent.h"

b2Body* StaticBodyComponent::body;
b2World& StaticBodyComponent::world = Box2dWorld::getWorld();
float StaticBodyComponent::pixels_per_meter;
float StaticBodyComponent::x;
float StaticBodyComponent::y;

StaticBodyComponent::StaticBodyComponent(float x, float y, float pixels_per_meter)
{
	StaticBodyComponent::pixels_per_meter = pixels_per_meter;
	StaticBodyComponent::x = x;
	StaticBodyComponent::y = y;
}

void StaticBodyComponent::createAsBox(float width, float height, bool isSensor)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set((x + width / 2.0) / pixels_per_meter, (y + height / 2.0) / pixels_per_meter);
	StaticBodyComponent::body = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(width / pixels_per_meter / 2.0, height / pixels_per_meter / 2.0);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	StaticBodyComponent::body->CreateFixture(&fixtureDef);
}

void StaticBodyComponent::createAsCircle(float radius, bool isSensor)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x / pixels_per_meter, y / pixels_per_meter);
	StaticBodyComponent::body = world.CreateBody(&bodyDef);

	b2CircleShape b2shape;
	b2shape.m_radius = radius / pixels_per_meter;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &b2shape;

	StaticBodyComponent::body->CreateFixture(&fixtureDef);
}

void StaticBodyComponent::createAsPolygon(const std::vector<b2Vec2>& point_array, bool isSensor)
{
	float n = point_array.size();
	b2Vec2* vertices = new b2Vec2[n];
	for (int i = 0; i < n; i++)
	{
		vertices[i].Set(point_array[i].x / pixels_per_meter, point_array[i].y / pixels_per_meter);
	}

	b2PolygonShape polygonShape;
	polygonShape.Set(vertices, n);

	delete[] vertices;

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x / pixels_per_meter, y / pixels_per_meter);
	StaticBodyComponent::body = world.CreateBody(&bodyDef);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;

	StaticBodyComponent::body->CreateFixture(&fixtureDef);
}

void StaticBodyComponent::addBoxFixture(float width, float height, bool isSensor)
{
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(width / pixels_per_meter / 2.0, height / pixels_per_meter / 2.0);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	StaticBodyComponent::body->CreateFixture(&fixtureDef);
}

void StaticBodyComponent::addCircleFixture(float radius, bool isSensor)
{
	b2CircleShape b2shape;
	b2shape.m_radius = radius / pixels_per_meter;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &b2shape;

	StaticBodyComponent::body->CreateFixture(&fixtureDef);
}

void StaticBodyComponent::addPolygonFixture(const std::vector<b2Vec2>& point_array, bool isSensor)
{
	float n = point_array.size();
	b2Vec2* vertices = new b2Vec2[n];
	for (int i = 0; i < n; i++)
	{
		vertices[i].Set(point_array[i].x / pixels_per_meter, point_array[i].y / pixels_per_meter);
	}

	b2PolygonShape polygonShape;
	polygonShape.Set(vertices, n);

	delete[] vertices;
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;

	StaticBodyComponent::body->CreateFixture(&fixtureDef);
}
