#include "Borka/States/State.h"
#include "Borka/Levels/Level.h"

#include "Player.h"

class HubState : public borka::State
{
	public:
	HubState( borka::Application* ptrApp,
		borka::ImageManager* ptrImage,
		borka::SoundManager* ptrSound,
		borka::EffectManager* ptrEffect );

    virtual void Setup();
    virtual void Main();

    private:
    Player 		player;
    Character 	spaceship;

    borka::Level level;

    sf::Sound 		footsteps;
    sf::Sound 		music;
};
