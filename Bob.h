#pragma once

#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:

	//Constuctor (when an instance of that class is called)
	Bob();

	//THis wil implement the pure virtual function from PlayableCharacter
	bool virtual handleInput();

}; //End class Bob