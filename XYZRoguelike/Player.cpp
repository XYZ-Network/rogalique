#include "Player.h"

namespace XYZRoguelike
{
	Player::Player()
	{
		gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject();
		auto playerRenderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();

		sf::Texture* newTexture = new sf::Texture();
		if (newTexture->loadFromFile("Resources/Textures/ball.png"))
		{
			newTexture->setSmooth(true);
			playerRenderer->SetTexture(*newTexture);
			playerRenderer->SetPixelSize(32, 32);
		}

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