#pragma once

#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:

	//Constuctor (when an instance of that class is called)
	Thomas();

	//THis wil implement the pure virtual function from PlayableCharacter
	bool virtual handleInput();

}; //End class Thomas