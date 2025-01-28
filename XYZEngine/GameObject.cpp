#include "pch.h"
#include "GameObject.h"

namespace XYZEngine
{
	GameObject::GameObject()
	{
		AddComponent<TransformComponent>();
	}

	GameObject::~GameObject()
	{
		for (auto component : components)
		{
			delete component;
		}
		components.clear();
	}

	void GameObject::Update(float deltaTime)
	{
		for (auto& component : components)
		{
			component->Update(deltaTime);
		}
	}
	void GameObject::Render()
	{
		for (auto& component : components)
		{
			component->Render();
		}
	}
}