#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			// Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			// Switch between Thomas and Bob camera focus
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				// m_isCharacter1CameraFocus
				m_Character1 = !m_Character1;
			}

			// Switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}

		} // end if keypressed
	} // end while loop for event polling

	//Handle inputs spacific to Thomas
	if (m_Thomas.handleInput())
	{
		//TODO: Play jumping sound
	}

	//Handle inputs spacific to Bob
	if (m_Bob.handleInput())
	{
		//TODO: Play jumping sound
		m_SM.playJump();
	}

} // end input()