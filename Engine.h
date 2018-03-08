#pragma once
#include <sfml/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;
// SARAH NOTE: Don't use "using" in .h files! bad!

class Engine
{
private:
	//The texture holder
	TextureHolder th;
	//SARAH NOTE: Don't name things "th" single letter abbreviations

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	//A regular RenderWindow
	RenderWindow m_Window;

	//The main views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	//Three views for background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	//Sprite and texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Is the game currently playing?
	bool m_Playing = false;

	//Is character 1 or two the current focus?
	bool m_Character1 = true;
	//SARAH NOTE: use enum instead, name better

	//Full or splite screen?
	bool m_SplitScreen = false;

	// Time left in current level?
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	//Private functions for internal use
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	//Constructor
	Engine();
	
	//Run will call all the private functions in a loop
	void run();
};


