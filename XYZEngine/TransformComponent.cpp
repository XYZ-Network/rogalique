#include "pch.h"
#include "TransformComponent.h"

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
	}

	void TransformComponent::ScaleBy(const Vector2Df& scaleOffset)
	{
		scale.x *= scaleOffset.x;
		scale.y *= scaleOffset.y;
	}

	const Vector2Df TransformComponent::GetWorldPosition() const
	{
		return position;
	}

	const float TransformComponent::GetWorldRotation() const
	{
		return rotation;
	}

	const Vector2Df TransformComponent::GetWorldScale() const
	{
		return scale;
	}
}