#include "pch.h"
#include "SpriteDirectionComponent.h"

XYZEngine::SpriteDirectionComponent::SpriteDirectionComponent(GameObject* gameObject)
	: Component(gameObject)
{
	input = gameObject->GetComponent<InputComponent>();
	spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
}

void XYZEngine::SpriteDirectionComponent::Update(float deltaTime)
{
	if (input->GetHorizontalAxis() < 0)
	{
		spriteRenderer->FlipX(true);
	}
	if (input->GetHorizontalAxis() > 0)
	{
		spriteRenderer->FlipX(false);
	}
}

void XYZEngine::SpriteDirectionComponent::Render()
{
}
