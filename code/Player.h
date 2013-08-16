/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#ifndef _PLAYER
#define _PLAYER

#include "Character.h"
#include "Borka/Tile.h"

class Player : public Character
{
	public:
	Player( const sf::Texture& image, const sf::FloatRect& position );
	virtual void HandleMovement( const std::vector< borka::Tile >& lstTiles );
	Behavior GetHorseCommand();

	void Update();

	sf::Vector2f GetLastMove();

	protected:
	sf::Vector2f 	m_lastMove;
	float 			m_commandTimeout;
};

#endif
