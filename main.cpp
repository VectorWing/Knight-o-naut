/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/Application.h"
#include "Borka/Level.h"

int main()
{
    borka::Application application( "Knight-o-naut", sf::Vector2i( 1280, 720 ) );

	// Temporary
	sf::Texture tileset;
	if ( !tileset.loadFromFile( "assets/graphics/tileset.png" ) )
	{
		std::cerr << "Error loading tileset" << std::endl;
	}

	sf::Texture player;
	if ( !player.loadFromFile( "assets/graphics/knight.png" ) )
	{
		std::cerr << "Error loading knight" << std::endl;
	}

	borka::Level level;
	level.Setup( tileset );

    while ( !application.IsDone() )
    {
		application.Update();

		application.BeginDraw();
		level.Draw( application.GetWindow() );
		application.EndDraw();
    }

    return 0;
}
