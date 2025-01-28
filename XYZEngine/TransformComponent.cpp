#include "pch.h"
#include "TransformComponent.h"
#include <cmath>
#include <iostream>

namespace XYZEngine
{
	TransformComponent::TransformComponent(GameObject* gameObject) : Component(gameObject) {}

	void TransformComponent::Update(float deltaTime)
	{

	}
	void TransformComponent::Render()
	{

	}

	void TransformComponent::MoveBy(const Vector2Df& offset)
	{
		position.x += offset.x;
		position.y += offset.y;
		isUpdated = false;
	}

	void TransformComponent::RotateBy(float offset)
	{
		rotation = rotation + offset;
		while (rotation >= 360)
		{
			rotation -= 360;
		}
		while (rotation < 0)
		{
			rotation += 360;
		}
		isUpdated = false;
	}

	void TransformComponent::ScaleBy(const Vector2Df& scaleOffset)
	{
		scale.x *= scaleOffset.x;
		scale.y *= scaleOffset.y;
		isUpdated = false;
	}

	const Vector2Df TransformComponent::GetWorldPosition() const
	{
		updateLocalTransform();
		return position;
	}

	const float TransformComponent::GetWorldRotation() const
	{
		updateLocalTransform();
		return rotation;
	}

	const Vector2Df TransformComponent::GetWorldScale() const
	{
		updateLocalTransform();
		return scale;
	}

	const sf::Transform TransformComponent::GetWorldTransform() const
	{
		updateLocalTransform();
		return localTransform;
	}

	void TransformComponent::updateLocalTransform() const
	{
		if (!isUpdated)
		{
			localTransform = createTransform(position, rotation, scale);
			isUpdated = true;
		}
	}
	sf::Transform TransformComponent::createTransform(const Vector2Df& position, float rotation, const Vector2Df& scale) const
	{
		const float angle = rotation * (3.14159265f / 180.f);
		const float cosine = std::cos(angle);
		const float sine = std::sin(angle);
		const float sxc = scale.x * cosine;
		const float syc = scale.y * cosine;
		const float sxs = scale.x * sine;
		const float sys = scale.y * sine;
		const float tx = position.x;
		const float ty = position.y;

		return sf::Transform(sxc, sys, tx,
			-sxs, syc, ty,
			0.f, 0.f, 1.f);
	}
}