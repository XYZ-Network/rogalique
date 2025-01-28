#include "pch.h"
#include "Component.h"
#include <iostream>

namespace XYZEngine
{
	Component::Component(GameObject* gameObject) : gameObject(gameObject) {}
	Component::~Component()
	{
		std::cout << "Deleted component: " << this << std::endl;
	}
	GameObject* Component::GetGameObject()
	{
		return gameObject;
	}
}