/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */

#include "Player.h"

void Player::HandleMovement()
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		Move( -5, 0 );
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		Move( 5, 0 );
	}

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		Move( 0, -5 );
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		Move( 0, 5 );
	}
}
