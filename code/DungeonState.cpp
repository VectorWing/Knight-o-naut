#include "DungeonState.h"

#include <iostream>

void DungeonState::Setup()
{
	horse.Setup( m_ptrImageManager->GetTexture( "horse.png" ), sf::FloatRect( 320, 240-64, 64, 64 ) );
	horse.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	player.Setup( m_ptrImageManager->GetTexture( "knight.png" ), sf::FloatRect( 320, 240, 64, 64 ) );
	player.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	level.Setup( m_ptrImageManager->GetTexture( "DesertTileset.png" ) );

	whistle.setBuffer( m_ptrSoundManager->GetSound( "whistle.ogg" ) );
	whistle.setVolume( 25 );

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

		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )	// Temporary
		{
			level.Setup( m_ptrImageManager->GetTexture( "DesertTileset.png" ) );
		}

		player.HandleMovement( level.GetTiles() );
		horse.HandleMovement( level.GetTiles() );

		m_ptrApplication->BeginDraw();
		level.Draw( m_ptrApplication->GetWindow() );
		horse.Draw( m_ptrApplication->GetWindow() );
		player.Draw( m_ptrApplication->GetWindow() );
		m_ptrEffectManager->Draw( m_ptrApplication->GetWindow() );
		m_ptrApplication->EndDraw();
    }
}
