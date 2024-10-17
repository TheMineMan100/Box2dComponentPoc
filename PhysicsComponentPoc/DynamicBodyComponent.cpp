#include "DynamicBodyComponent.h"

b2Body* DynamicBodyComponent::body;
b2World& DynamicBodyComponent::world = Box2dWorld::getWorld();
float DynamicBodyComponent::pixels_per_meter;
float DynamicBodyComponent::x;
float DynamicBodyComponent::y;

DynamicBodyComponent::DynamicBodyComponent(float x, float y, float pixels_per_meter)
{
	DynamicBodyComponent::pixels_per_meter = pixels_per_meter;
	DynamicBodyComponent::x = x;
	DynamicBodyComponent::y = y;
}

void DynamicBodyComponent::createAsBox(float width, float height, bool isSensor, float density, float friction, float restitution, float linearDamping)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set((x + width / 2.0) / pixels_per_meter, (y + height / 2.0) / pixels_per_meter);
	bodyDef.linearDamping = linearDamping;
	DynamicBodyComponent::body = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(width / pixels_per_meter / 2.0, height / pixels_per_meter / 2.0);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.isSensor = isSensor;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	DynamicBodyComponent::body->CreateFixture(&fixtureDef);
}

void DynamicBodyComponent::createAsCircle(float radius, bool isSensor, float density, float friction, float restitution, float linearDamping)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x / pixels_per_meter, y / pixels_per_meter);
	bodyDef.linearDamping = linearDamping;
	DynamicBodyComponent::body = world.CreateBody(&bodyDef);

	b2CircleShape b2shape;
	b2shape.m_radius = radius / pixels_per_meter;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &b2shape;
	fixtureDef.isSensor = isSensor;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	DynamicBodyComponent::body->CreateFixture(&fixtureDef);
}

void DynamicBodyComponent::createAsPolygon(const std::vector<b2Vec2>& point_array, bool isSensor, float density, float friction, float restitution, float linearDamping)
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
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x / pixels_per_meter, y / pixels_per_meter);
	bodyDef.linearDamping = linearDamping;
	DynamicBodyComponent::body = world.CreateBody(&bodyDef);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.isSensor = isSensor;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	DynamicBodyComponent::body->CreateFixture(&fixtureDef);
}

void DynamicBodyComponent::addBoxFixture(float width, float height, bool isSensor, float density, float friction, float restitution, float linearDamping)
{
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(width / pixels_per_meter / 2.0, height / pixels_per_meter / 2.0);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.isSensor = isSensor;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	DynamicBodyComponent::body->CreateFixture(&fixtureDef);
}

void DynamicBodyComponent::addCircleFixture(float radius, bool isSensor, float density, float friction, float restitution, float linearDamping)
{
	b2CircleShape b2shape;
	b2shape.m_radius = radius / pixels_per_meter;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &b2shape;
	fixtureDef.isSensor = isSensor;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	DynamicBodyComponent::body->CreateFixture(&fixtureDef);
}

void DynamicBodyComponent::addPolygonFixture(const std::vector<b2Vec2>& point_array, bool isSensor, float density, float friction, float restitution, float linearDamping)
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
	fixtureDef.isSensor = isSensor;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	DynamicBodyComponent::body->CreateFixture(&fixtureDef);
}
