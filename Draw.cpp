#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	//erase the last frame
	m_Window.clear(Color::White);

	//Single screen
	if (!m_SplitScreen)
	{
		//switch to the background view
		m_Window.setView(m_BGMainView);
		//Draw
		m_Window.draw(m_BackgroundSprite);
		//Set Main View
		m_Window.setView(m_MainView);
		//TODO: Draw all the stuff

	}//end single screen
	//Splitscreen
	else
	{
		//Draw Thomas's side of the screen first
		//switch to background view first
		m_Window.setView(m_BGLeftView);
		//Switch to the main view for left
		m_Window.draw(m_BackgroundSprite);
		//Draw the left view
		m_Window.setView(m_LeftView);


		//Draw Bob's side of the screen first
		//switch to background view first
		m_Window.setView(m_BGRightView);
		//Switch to the main view for left
		m_Window.draw(m_BackgroundSprite);
		//Draw the left view
		m_Window.setView(m_RightView);
	}//End splitscreen

	//Draw Hud
	//Switch to hud
	m_Window.setView(m_HudView);
	//TODO: Draw hud

	//Show everything we have just drawn
	m_Window.display();
}//End of draw funtion