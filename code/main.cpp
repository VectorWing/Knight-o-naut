/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/States/StateManager.h"

#include "Player.h"
#include "DungeonState.h"

// Note: Clean up entity stuff... composition instead of inheritance.

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
	DungeonState dungeonState;
	dungeonState.Link( &application, &mgrImages, &mgrAudio, &mgrEffects );

	mgrStates.AddState( "dungeon", &dungeonState );
	mgrStates.SetCurrentState( "dungeon" );
	mgrStates.Setup();

	while ( !application.IsDone() )
    {
		mgrStates.Main();
    }

    return 0;
}
