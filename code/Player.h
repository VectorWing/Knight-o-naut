/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#ifndef _PLAYER
#define _PLAYER

#include "Character.h"

class Player : public Character
{
	public:
	Player( const sf::Texture& image, const sf::FloatRect& position );
	virtual void HandleMovement();

	protected:
};

#endif
