#pragma once
#include <eng.hpp>

class TestGame : public eng::Game
{
    public:
	TestGame()
	    : eng::Game("Hello test game")
	{
	    eng::AssetManager::LoadShader("./testvert.glsl", "./testfrag.glsl", "test");
	    eng::Shader* s = eng::AssetManager::GetShader("test");
	    s->Use();
	}
};
