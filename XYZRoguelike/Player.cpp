#include "Player.h"
#include <ResourceSystem.h>

namespace XYZRoguelike
{
	Player::Player()
	{
		gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject();
		auto playerRenderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();

		playerRenderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureShared("ball"));
		playerRenderer->SetPixelSize(32, 32);

		auto playerCamera = gameObject->AddComponent<XYZEngine::CameraComponent>();
		playerCamera->SetWindow(&XYZEngine::RenderSystem::Instance()->GetMainWindow());
		playerCamera->SetBaseResolution(1280, 720);

		auto playerInput = gameObject->AddComponent<XYZEngine::InputComponent>();
	}

	XYZEngine::GameObject* Player::GetGameObject()
	{
		return gameObject;
	}
}