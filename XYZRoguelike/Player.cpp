#include "Player.h"
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>

namespace XYZRoguelike
{
	Player::Player()
	{
		gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Player");
		auto playerRenderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();

		playerRenderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureShared("ball"));
		playerRenderer->SetPixelSize(32, 32);

		auto playerCamera = gameObject->AddComponent<XYZEngine::CameraComponent>();
		playerCamera->SetWindow(&XYZEngine::RenderSystem::Instance()->GetMainWindow());
		playerCamera->SetBaseResolution(1280, 720);

		auto playerInput = gameObject->AddComponent<XYZEngine::InputComponent>();

		auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();

		auto collider = gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
	}

	XYZEngine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}