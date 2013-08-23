/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/States/StateManager.h"

#include "Player.h"
#include "DungeonState.h"
#include "HubState.h"

int main()
{
	// Temporary - will clean up
    borka::Application application( "Knight-o-naut", sf::Vector2i( 1280, 720 ) );

    borka::ImageManager 	mgrImages;
	mgrImages.Setup( "assets_images.txt" );
    borka::SoundManager 	mgrAudio;
	mgrAudio.Setup( "assets_audio.txt" );
    borka::EffectManager 	mgrEffects;

	borka::StateManager mgrStates;
	DungeonState dungeonState( &application, &mgrImages, &mgrAudio, &mgrEffects );
	HubState hubState( &application, &mgrImages, &mgrAudio, &mgrEffects );

	mgrStates.AddState( "dungeon", 	&dungeonState );
	mgrStates.AddState( "hub", 		&hubState );
	mgrStates.SetCurrentState( "hub" );

	while ( !application.IsDone() )
    {
		mgrStates.Main();
    }

    return 0;
}
