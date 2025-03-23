#include "Music.h"

Music::Music(const std::string& soundName)
{
	auto gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Music: " + soundName);
	auto music = gameObject->AddComponent<XYZEngine::AudioComponent>();
	music->SetAudio(*XYZEngine::ResourceSystem::Instance()->GetSound(soundName));
	music->SetLoop(true);
	music->Play();
}
