#include "pch.h"
#include "AudioComponent.h"

XYZEngine::AudioComponent::AudioComponent(GameObject* gameObject)
	: Component(gameObject)
{
	sound = new sf::Sound();
}

XYZEngine::AudioComponent::~AudioComponent()
{
	sound->stop();
	delete sound;
}

void XYZEngine::AudioComponent::Update(float deltaTime)
{
}

void XYZEngine::AudioComponent::Render()
{
}

void XYZEngine::AudioComponent::SetAudio(const sf::SoundBuffer& audio)
{
	sound->setBuffer(audio);
}

void XYZEngine::AudioComponent::SetLoop(bool loop)
{
	sound->setLoop(loop);
}

void XYZEngine::AudioComponent::SetVolume(float volume)
{
	sound->setVolume(volume);
}

void XYZEngine::AudioComponent::Play()
{
	if (sound->getStatus() != sf::SoundSource::Playing)
	{
		sound->play();
	}
}

void XYZEngine::AudioComponent::Stop()
{
	sound->stop();
}

void XYZEngine::AudioComponent::Pause()
{
	sound->pause();
}

void XYZEngine::AudioComponent::Resume()
{
	if (sound->getStatus() != sf::SoundSource::Playing)
	{
		sound->play();
	}
}
