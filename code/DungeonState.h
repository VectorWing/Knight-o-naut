#include "Borka/States/State.h"

#include "Borka/Base/Application.h"
#include "Borka/Levels/Level.h"
#include "Borka/Graphics/ImageManager.h"
#include "Borka/Audio/SoundManager.h"
#include "Borka/Graphics/EffectManager.h"

#include "Character.h"
#include "Player.h"

class DungeonState : public borka::State
{
	public:
    virtual void Setup( borka::Application* ptrApp );
    virtual void Main();

    private:
    borka::ImageManager 	mgrImages;
    borka::SoundManager 	mgrAudio;
    borka::EffectManager 	mgrEffects;

    Character 	horse;
    Player 		player;

    borka::Level level;

    sf::Sound 		whistle;
    sf::Sound		music;
};
