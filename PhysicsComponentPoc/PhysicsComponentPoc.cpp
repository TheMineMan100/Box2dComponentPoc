#include <iostream>
#include <string>
#include <vector>
#include <box2d/box2d.h>
#include "PhysicsManager.h"
#include "DynamicBodyComponent.h"
#include "StaticBodyComponent.h"

int main()
{
    PhysicsManager physicsManager;
    b2World& world = physicsManager.getWorldInstance();
    
    DynamicBodyComponent dynamicComponent(10.0f, 30.0f); // Optionally give pixels_per_meter as the third argument
    dynamicComponent.createAsBox(30.0f, 40.0f);

    b2Vec2 firstPoint = b2Vec2(0.0f, 0.0f);
    b2Vec2 secondPoint = b2Vec2(30.0f, 40.0f);
    b2Vec2 thirdPoint = b2Vec2(60.0f, 20.0f);
    std::vector<b2Vec2> point_array = std::vector<b2Vec2>{ firstPoint, secondPoint, thirdPoint };
    StaticBodyComponent polygon(250.0f, 300.0f);
    polygon.createAsPolygon(point_array);

    std::string startY = std::to_string(dynamicComponent.body->GetWorldCenter().y);
    std::cout << "Component y pos: " << startY << std::endl; // Should display the given y value of the component plus half its height

    std::cout << "Hello World!" << std::endl;

    while (true) //fake gameloop, assuming 60 fps
    {
        std::string currentY = std::to_string(dynamicComponent.body->GetWorldCenter().y);
        physicsManager.onUpdate();
        std::cout << "Component y pos: " << currentY << std::endl;
    }
}
