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

	Character horse( mgrImages.GetTexture( "horse.png" ), sf::FloatRect( 320, 240-64, 64, 64 ) );
	horse.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	Player player( mgrImages.GetTexture( "knight.png" ), sf::FloatRect( 320, 240, 64, 64 ) );
	player.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	borka::Level level( mgrImages.GetTexture( "tileset.png" ) );

    while ( !application.IsDone() )
    {
		application.Update();
		horse.SetBehavior( player.GetHorseCommand(), sf::Vector2f( player.GetPosition().left, player.GetPosition().top ) );

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )	// Temporary
		{
			level.Setup( mgrImages.GetTexture( "tileset.png" ) );
		}

		player.HandleMovement( level.GetTiles() );
		horse.HandleMovement( level.GetTiles() );

		application.BeginDraw();
		level.Draw( application.GetWindow() );
		horse.Draw( application.GetWindow() );
		player.Draw( application.GetWindow() );
		application.EndDraw();
    }

    return 0;
}
