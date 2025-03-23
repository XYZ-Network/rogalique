#pragma once

#include <GameObject.h>
#include <GameWorld.h>
#include <AudioComponent.h>
#include <ResourceSystem.h>

class Music
{
public:
	Music(const std::string& soundName);
private:
	XYZEngine::GameObject* gameObject;
};

