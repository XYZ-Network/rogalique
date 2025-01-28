// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"

using namespace XYZRoguelike;

int main()
{
	XYZEngine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));

	auto player = std::make_shared<Player>();

	XYZEngine::Engine::Instance()->Run();

	return 0;
}
