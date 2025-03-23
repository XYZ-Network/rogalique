#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"
#include "Vector.h"

namespace XYZRoguelike
{
	class Player
	{
	public:
		Player(const XYZEngine::Vector2Df& position);
		XYZEngine::GameObject* GetGameObject();
	private:
		XYZEngine::GameObject* gameObject;
	};
}