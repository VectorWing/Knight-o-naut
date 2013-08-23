#include "Borka/States/State.h"

#include "Borka/Levels/Level.h"

#include "Character.h"
#include "Player.h"

class DungeonState : public borka::State
{
	public:
    virtual void Setup();
    virtual void Main();

    private:

    Character 	horse;
    Player 		player;

    borka::Level level;

    sf::Sound 		whistle;
    sf::Sound		music;
};
