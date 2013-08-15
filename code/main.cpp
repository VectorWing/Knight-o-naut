/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/Application.h"
#include "Borka/Level.h"
#include "Borka/ImageManager.h"

#include "Player.h"

int main()
{
    borka::Application application( "Knight-o-naut", sf::Vector2i( 1280, 720 ) );
	borka::ImageManager mgrImages( "assets_images.txt" );

	Player player( mgrImages.GetTexture( "knight.png" ), sf::FloatRect( 320, 240, 64, 64 ) );

	borka::Level level( mgrImages.GetTexture( "tileset.png" ) );

    while ( !application.IsDone() )
    {
		application.Update();

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )	// Temporary
		{
			level.Setup( mgrImages.GetTexture( "tileset.png" ) );
		}

		if ( level.IsCollision( player ) )
		{
			player.CorrectMovement();
		}

		player.HandleMovement();

		application.BeginDraw();
		level.Draw( application.GetWindow() );
		player.Draw( application.GetWindow() );
		application.EndDraw();
    }

    return 0;
}
