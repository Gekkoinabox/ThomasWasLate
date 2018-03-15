#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{

	//Create our sprite by associating the texture with a sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	m_JumpDuration = 0.45f;


} //End function Thomas