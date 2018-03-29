#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"

using namespace sf;
// SARAH NOTE: Don't use "using" in .h files! bad!

class Engine
{
private:
	// The Texture Holder
	TextureHolder th;
	// SARAH NOTE: DON'T NAME THINGS "th" (single letter abbreviations)

	//Our playable characters, thomas and his friend bob
	Thomas m_Thomas;
	Bob m_Bob;

	//A class to manage the levels
	LevelManager m_LM;

	//Sound manager
	SoundManager m_SM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Sprite and texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or two the current focus?
	bool m_Character1 = true;
	// SARAH NOTE: use enum instead, name better

	// Full or split screen?
	bool m_SplitScreen = false;

	// Time left in current level?
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	// The vertex array for the level tiles
	VertexArray m_VALevel;
	//The 2D array with the map for the level (data) (0-3)
	//a pointer to a point (aka 2D Array)
	int** m_ArrayLevel = NULL;
	//texture for the level tiles
	Texture m_TextureTiles;

	// Private functions for internal use
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

	//load a new level
	void loadLevel();

	//Detect collisions
	//POLYMORPHISM
	bool detectCollisions(PlayableCharacter& character);

	//Make a vector of the best places to emit sounds from
	void populateEmitters(vector<Vector2f>&vSoundEmitter, int** arrayLevel);

	//a list (Vector) of Vector2f to contain the fire emitter locations
	vector<Vector2f> m_FireEmitters;

public:
	// Constructor
	Engine();

	// Run wil call all the private functions in a loop
	void run();
};
