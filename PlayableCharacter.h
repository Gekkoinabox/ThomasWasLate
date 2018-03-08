#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf; //dont do this noramlly

class PlayableCharacter 
{
protected:

	Sprite m_Sprite;

	//How long does a jump last?
	float m_JumpDuration;

	//is the character currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;

	//Which direction is the character currently moving in?
	bool m_LeftPressed;
	bool m_RightPressed;

	//how long has the jump lasted for?
	float m_TimeThisJump;

	//has the player just initiated jump?
	bool m_JustJumped = false;

//These variables can only be edited and viewed by THIS class, NOT sub classes
private:
	//What is the gravity?
	float m_Gravity;

	//how fast is the character
	float m_Speed = 400.0f;

	//Where is the player?
	Vector2f m_Position;

	//Where are the characters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Left;
	FloatRect m_Right;

//Public functions available to ALL other classes (and this one)
public:

	void spawn(Vector2f startPosition, float gravity);

	//This is a pure virtual function
	//This means this class becomes an abstract class
	//Meaning we cannot create an instance of this class, only sub classes 
	//Sub classes MUST implement this function in order to create instances

	bool virtual handleInput() = 0; // = 0 :this means there will be no implementation in this class

	//THESE ARE ALL GETTERS: GET ER DDOOOOOON

	//Where is the player?
	FloatRect getPosition();

	//A rectangle representing the position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getLeft();
	FloatRect getRight();

	//Get a copy of the sprite
	Sprite getSprite();

	//Make the character stop moving
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	//Where is the center of the character?
	Vector2f getCenter();

	//We will call this function once every frame
	void update(float elaspedTime);

};//end of PlayableCharacter class

