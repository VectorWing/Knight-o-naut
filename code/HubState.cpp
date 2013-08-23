#include "HubState.h"

HubState::HubState( borka::Application* ptrApp,
		borka::ImageManager* ptrImage,
		borka::SoundManager* ptrSound,
		borka::EffectManager* ptrEffect )
		: State( ptrApp, ptrImage, ptrSound, ptrEffect )
{
}

void HubState::Setup()
{
	player.Setup( m_ptrImageManager->GetTexture( "knight.png" ), sf::FloatRect( 1280/2, 720/2, 64, 64 ) );
	player.SetCollisionRegion( sf::FloatRect( 12, 30, 40, 33 ) );

	spaceship.Setup( m_ptrImageManager->GetTexture( "Ship.png" ), sf::FloatRect( 100, 500, 64, 96 ) );

	level.Setup( m_ptrImageManager->GetTexture( "DesertTileset.png" ), borka::HUB );

	footsteps.setBuffer( m_ptrSoundManager->GetSound( "Footsteps.ogg" ) );
	footsteps.setVolume( 25 );

	music.setBuffer( m_ptrSoundManager->GetSound( "AfterTheRain_Moosader.ogg" ) );
	music.setLoop( true );
	music.play();

	m_isDone = false;
}

void HubState::Main()
{
	while ( !m_isDone )
	{
		m_ptrApplication->Update();
		m_ptrEffectManager->Update();
		player.Update();

		Behavior command = player.GetHorseCommand();

		if ( command != NONE )
		{
		}

		player.HandleMovement( level.GetTiles() );

		if ( level.IsTeleport( player ) )
		{
			// Teleport!
			footsteps.play();
			m_nextState = "dungeon";
			m_isDone = true;
			music.stop();
		}

		m_ptrApplication->BeginDraw();
		level.Draw( m_ptrApplication->GetWindow() );
		spaceship.Draw( m_ptrApplication->GetWindow() );
		player.Draw( m_ptrApplication->GetWindow() );
		m_ptrEffectManager->Draw( m_ptrApplication->GetWindow() );
		m_ptrApplication->EndDraw();
    }
}
