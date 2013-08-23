#include "Borka/States/State.h"

#include "Borka/Levels/Level.h"

#include "Character.h"
#include "Player.h"

class DungeonState : public borka::State
{
	public:
	DungeonState( borka::Application* ptrApp,
		borka::ImageManager* ptrImage,
		borka::SoundManager* ptrSound,
		borka::EffectManager* ptrEffect );

    virtual void Setup();
    virtual void Main();

    private:
    Character 	horse;
    Player 		player;

    borka::Level level;

    sf::Sound 		footsteps;
    sf::Sound 		whistle;
    sf::Sound		music;
};
