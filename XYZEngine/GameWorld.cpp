#include "pch.h"
#include "GameWorld.h"

namespace XYZEngine
{
	GameWorld* GameWorld::Instance()
	{
		static GameWorld world;
		return &world;
	}

	void GameWorld::Update(float deltaTime)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update(deltaTime);
		}
	}
	void GameWorld::Render()
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Render();
		}
	}
	void GameWorld::LateUpdate()
	{
		for (int i = markedToDestroyGameObjects.size() - 1; i >= 0; i--)
		{
			DestroyGameObjectImmediate(markedToDestroyGameObjects[i]);
		}
	}

	GameObject* GameWorld::CreateGameObject()
	{
		GameObject* newGameObject = new GameObject();
		gameObjects.push_back(newGameObject);
		return newGameObject;
	}
	void GameWorld::DestroyGameObject(GameObject* gameObject)
	{
		markedToDestroyGameObjects.push_back(gameObject);
	}
	void GameWorld::Clear()
	{
		for (int i = gameObjects.size() - 1; i >= 0; i--)
		{
			DestroyGameObjectImmediate(gameObjects[i]);
		}
	}

	void GameWorld::DestroyGameObjectImmediate(GameObject* gameObject)
	{
		gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [gameObject](GameObject* obj) { return obj == gameObject; }), gameObjects.end());
		markedToDestroyGameObjects.erase(std::remove_if(markedToDestroyGameObjects.begin(), markedToDestroyGameObjects.end(), [gameObject](GameObject* obj) { return obj == gameObject; }), markedToDestroyGameObjects.end());

		delete gameObject;
	}
}