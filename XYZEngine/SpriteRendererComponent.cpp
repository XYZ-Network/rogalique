#include "pch.h"
#include "SpriteRendererComponent.h"
#include "TransformComponent.h"
#include "RenderSystem.h"

namespace XYZEngine
{
	SpriteRendererComponent::SpriteRendererComponent(GameObject* gameObject) : Component(gameObject)
	{
		sprite = new sf::Sprite();
		scale = { 1, -1 };
		sprite->setScale({ 1, -1 });
		transform = gameObject->GetComponent<TransformComponent>();
	}
	SpriteRendererComponent::~SpriteRendererComponent()
	{
		if (sprite != nullptr)
		{
			delete sprite;
		}
	}

	void SpriteRendererComponent::Update(float deltaTime)
	{

	}
	void SpriteRendererComponent::Render()
	{
		if (sprite != nullptr)
		{
			sprite->setPosition(Convert<sf::Vector2f, Vector2Df>(transform->GetWorldPosition()));
			sprite->setRotation(transform->GetWorldRotation());

			auto transformScale = Convert<sf::Vector2f, Vector2Df>(transform->GetWorldScale());
			sprite->setScale({ scale.x * transformScale.x, scale.y * transformScale.y });
			RenderSystem::Instance()->Render(*sprite);
		}
	}

	const sf::Sprite* SpriteRendererComponent::GetSprite() const
	{
		return sprite;
	}
	void SpriteRendererComponent::SetTexture(const sf::Texture& newTexture)
	{
		sprite->setTexture(newTexture);
		auto textureSize = sprite->getTexture()->getSize();
		sprite->setOrigin({ 0.5f * textureSize.x, 0.5f * textureSize.y });
	}
	void SpriteRendererComponent::SetPixelSize(int newWidth, int newHeight)
	{
		auto originalSize = sprite->getTexture()->getSize();
		scale = { (float)newWidth / (float)originalSize.x, -(float)newHeight / (float)originalSize.y };
	}

	void SpriteRendererComponent::FlipX(bool flip)
	{
		if (flip != isFlipX)
		{
			scale = { -scale.x, scale.y };
			isFlipX = flip;
		}
	}
	void SpriteRendererComponent::FlipY(bool flip)
	{
		if (flip != isFlipY)
		{
			scale = { scale.x, -scale.y };
			isFlipY = flip;
		}
	}
}