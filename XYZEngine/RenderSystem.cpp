#include "pch.h"
#include "RenderSystem.h"

namespace XYZEngine
{
	RenderSystem* RenderSystem::Instance()
	{
		static RenderSystem render;
		return &render;
	}

	void RenderSystem::SetMainWindow(sf::RenderWindow* newWindow)
	{
		window = newWindow;
	}
	sf::RenderWindow& RenderSystem::GetMainWindow() const
	{
		return *window;
	}

	void RenderSystem::Render(const sf::Drawable& drawable)
	{
		window->draw(drawable);
	}
}