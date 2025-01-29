#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "GameObject.h"
#include "Vector.h"

namespace XYZEngine
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void MoveBy(const Vector2Df& offset);
		void RotateBy(float offset);
		void ScaleBy(const Vector2Df& scaleOffset);

		const Vector2Df GetWorldPosition() const;
		const float GetWorldRotation() const;
		const Vector2Df GetWorldScale() const;

	private:
		mutable Vector2Df position = { 0, 0 };
		mutable float rotation = 0.f;
		mutable Vector2Df scale = { 1, 1 };
	};
}