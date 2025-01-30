#include "DeveloperLevel.h"

using namespace XYZEngine;

namespace XYZRoguelike
{
	void DeveloperLevel::Start()
	{
		player = std::make_shared<Player>();
	}
	void DeveloperLevel::Restart()
	{
		Stop();
		Start();
	}
	void DeveloperLevel::Stop() 
	{
		GameWorld::Instance()->Clear();
	}
}