/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/Application.h"
#include "Borka/Level.h"
#include "Borka/ImageManager.h"
#include "Borka/SoundManager.h"
#include "Borka/EffectManager.h"

#include "Player.h"

// Note: Clean up entity stuff... composition instead of inheritance.

int main()
{
	// Temporary - will clean up
    borka::Application application( "Knight-o-naut", sf::Vector2i( 1280, 720 ) );
	borka::ImageManager mgrImages( "assets_images.txt" );
	borka::SoundManager mgrAudio( "assets_audio.txt" );
	borka::EffectManager mgrEffects;

	Character horse( mgrImages.GetTexture( "horse.png" ), sf::FloatRect( 320, 240-64, 64, 64 ) );
	horse.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	Player player( mgrImages.GetTexture( "knight.png" ), sf::FloatRect( 320, 240, 64, 64 ) );
	player.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	borka::Level level( mgrImages.GetTexture( "DesertTileset.png" ) );

	sf::Sound whistle;
	whistle.setBuffer( mgrAudio.GetSound( "whistle.ogg" ) );
	whistle.setVolume( 25 );

	sf::Sound music;
	music.setBuffer( mgrAudio.GetSound( "AfterTheRain_Moosader.ogg" ) );
	music.setLoop( true );
	music.play();

    while ( !application.IsDone() )
    {
		application.Update();
		mgrEffects.Update();
		player.Update();

		Behavior command = player.GetHorseCommand();

		if ( command != NONE )
		{
			mgrEffects.AddEffect( mgrImages.GetTexture( "effects.png" ), sf::Vector2f( player.CenterX() - 16, player.Top() ), borka::UP );
			mgrEffects.AddEffect( mgrImages.GetTexture( "effects.png" ), sf::Vector2f( player.CenterX(), 	player.Top() ), borka::UP );
			mgrEffects.AddEffect( mgrImages.GetTexture( "effects.png" ), sf::Vector2f( player.CenterX() + 16, player.Top() ), borka::UP );
			horse.SetBehavior( command, sf::Vector2f( player.GetPosition().left, player.GetPosition().top ) );
			whistle.setPitch( float(rand() % 150 + 50) / 100 );
			whistle.play();
		}

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )	// Temporary
		{
			level.Setup( mgrImages.GetTexture( "DesertTileset.png" ) );
		}

		player.HandleMovement( level.GetTiles() );
		horse.HandleMovement( level.GetTiles() );

		application.BeginDraw();
		level.Draw( application.GetWindow() );
		horse.Draw( application.GetWindow() );
		player.Draw( application.GetWindow() );
		mgrEffects.Draw( application.GetWindow() );
		application.EndDraw();
    }

    return 0;
}
