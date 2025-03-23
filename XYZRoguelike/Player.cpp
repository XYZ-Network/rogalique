#include "Player.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <MovementComponent.h>
#include <SpriteDirectionComponent.h>
#include <SpriteMovementAnimationComponent.h>

namespace XYZRoguelike
{
	Player::Player(const XYZEngine::Vector2Df& position)
	{
		gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Player");
		auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
		transform->SetWorldPosition(position);

		auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
		renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("player", 0));
		renderer->SetPixelSize(100, 100);

		auto camera = gameObject->AddComponent<XYZEngine::CameraComponent>();
		camera->SetWindow(&XYZEngine::RenderSystem::Instance()->GetMainWindow());
		camera->SetBaseResolution(1280, 720);

		auto input = gameObject->AddComponent<XYZEngine::InputComponent>();

		auto movement = gameObject->AddComponent<XYZEngine::MovementComponent>();
		movement->SetSpeed(400.f);

		auto spriteDirection = gameObject->AddComponent<XYZEngine::SpriteDirectionComponent>();

		auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
		rigidbody->SetKinematic(false);

		auto collider = gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();

		auto animator = gameObject->AddComponent<XYZEngine::SpriteMovementAnimationComponent>();
		animator->Initialize("player", 6.f);
	}

	XYZEngine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}