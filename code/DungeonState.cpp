#include "DungeonState.h"

#include <iostream>


DungeonState::DungeonState( borka::Application* ptrApp,
	borka::ImageManager* ptrImage,
	borka::SoundManager* ptrSound,
	borka::EffectManager* ptrEffect )
	: State( ptrApp, ptrImage, ptrSound, ptrEffect )
{
}

void DungeonState::Setup()
{
	horse.Setup( m_ptrImageManager->GetTexture( "horse.png" ), sf::FloatRect( 320, 240-64, 64, 64 ) );
	horse.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	player.Setup( m_ptrImageManager->GetTexture( "knight.png" ), sf::FloatRect( 320, 240, 64, 64 ) );
	player.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	level.Setup( m_ptrImageManager->GetTexture( "DesertTileset.png" ) );

	// Generate new coordinates while you're colliding with stuff.
	while ( level.IsCollision( player ) )
	{
		player.RandomCoordinates();
	}

	while ( level.IsCollision( horse ) )
	{
		horse.RandomCoordinates();
	}

	whistle.setBuffer( m_ptrSoundManager->GetSound( "whistle.ogg" ) );
	whistle.setVolume( 25 );

	footsteps.setBuffer( m_ptrSoundManager->GetSound( "Footsteps.ogg" ) );
	footsteps.setVolume( 25 );
	footsteps.play();

	music.setBuffer( m_ptrSoundManager->GetSound( "AfterTheRain_Moosader.ogg" ) );
	music.setLoop( true );
	music.play();

	m_isDone = false;
}

void DungeonState::Main()
{
	while ( !m_isDone )
	{
		m_ptrApplication->Update();
		m_ptrEffectManager->Update();
		player.Update();

		Behavior command = player.GetHorseCommand();

		if ( command != NONE )
		{
			m_ptrEffectManager->AddEffect( m_ptrImageManager->GetTexture( "effects.png" ), sf::Vector2f( player.CenterX() - 16, player.Top() ), borka::UP );
			m_ptrEffectManager->AddEffect( m_ptrImageManager->GetTexture( "effects.png" ), sf::Vector2f( player.CenterX(), 	player.Top() ), borka::UP );
			m_ptrEffectManager->AddEffect( m_ptrImageManager->GetTexture( "effects.png" ), sf::Vector2f( player.CenterX() + 16, player.Top() ), borka::UP );

			horse.SetBehavior( command, sf::Vector2f( player.GetPosition().left, player.GetPosition().top ) );
			whistle.setPitch( float(rand() % 150 + 50) / 100 );
			whistle.play();
		}

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )	// Back to HUB
		{
			m_nextState = "hub";
			m_isDone = true;
			music.stop();
		}

		player.HandleMovement( level.GetTiles() );
		horse.HandleMovement( level.GetTiles() );

		if ( level.IsTeleport( player ) )
		{
			// Teleport!
//			m_nextState = "dungeon";
//			m_isDone = true;
			music.stop();
			Setup();
		}

		m_ptrApplication->BeginDraw();
		level.Draw( m_ptrApplication->GetWindow() );
		horse.Draw( m_ptrApplication->GetWindow() );
		player.Draw( m_ptrApplication->GetWindow() );
		m_ptrEffectManager->Draw( m_ptrApplication->GetWindow() );
		m_ptrApplication->EndDraw();
    }
}
