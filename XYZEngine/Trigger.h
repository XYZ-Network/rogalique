#pragma once

namespace XYZEngine
{
	class ColliderComponent;
	struct Trigger
	{
	public:
		Trigger(ColliderComponent* newFirst, ColliderComponent* newSecond) :
			first(newFirst), second(newSecond) {
		};
	private:
		ColliderComponent* first;
		ColliderComponent* second;
	};
}