#include "pch.h"
#include "InputComponent.h"

namespace XYZEngine
{
	InputComponent::InputComponent(GameObject* gameObject) : Component(gameObject) {}

	void InputComponent::Update(float deltaTime)
	{
		verticalAxis = 0.f;
		horizontalAxis = 0.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			verticalAxis += 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			verticalAxis -= 1.0f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			horizontalAxis += 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			horizontalAxis -= 1.0f;
		}
	}
	void InputComponent::Render()
	{

	}

	float InputComponent::GetHorizontalAxis() const
	{
		return horizontalAxis;
	}
	float InputComponent::GetVerticalAxis() const
	{
		return verticalAxis;
	}
}