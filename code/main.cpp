/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/Application.h"
#include "Borka/Level.h"

#include "Character.h"

int main()
{
    borka::Application application( "Knight-o-naut", sf::Vector2i( 1280, 720 ) );

	// Temporary
	sf::Texture imgTileset;
	if ( !imgTileset.loadFromFile( "assets/graphics/tileset.png" ) )
	{
		std::cerr << "Error loading tileset" << std::endl;
	}

	sf::Texture imgPlayer;
	if ( !imgPlayer.loadFromFile( "assets/graphics/knight.png" ) )
	{
		std::cerr << "Error loading knight" << std::endl;
	}

	Character player;
	player.Setup( imgPlayer, sf::FloatRect( 320, 240, 64, 64 ) );

	borka::Level level;
	level.Setup( imgTileset );

    while ( !application.IsDone() )
    {
		application.Update();

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
		{
			level.Setup( imgTileset );
		}

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
		{
			player.Move( -5, 0 );
		}
		else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
		{
			player.Move( 5, 0 );
		}

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
		{
			player.Move( 0, -5 );
		}
		else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
		{
			player.Move( 0, 5 );
		}

		application.BeginDraw();
		level.Draw( application.GetWindow() );
		player.Draw( application.GetWindow() );
		application.EndDraw();
    }

    return 0;
}
