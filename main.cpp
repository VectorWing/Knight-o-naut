/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/Application.h"
#include "Borka/Level.h"

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
	sf::Sprite player;
	player.setTexture( imgPlayer );
	player.setPosition( 320, 240 );

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
			player.move( -5, 0 );
		}
		else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
		{
			player.move( 5, 0 );
		}

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
		{
			player.move( 0, -5 );
		}
		else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
		{
			player.move( 0, 5 );
		}

		application.BeginDraw();
		level.Draw( application.GetWindow() );
		application.GetWindow().draw( player );
		application.EndDraw();
    }

    return 0;
}
