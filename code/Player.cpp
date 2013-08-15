/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include "Player.h"

Player::Player( const sf::Texture& image, const sf::FloatRect& position )
{
	Setup( image, position );
	m_speed = 5;
}

void Player::HandleMovement( const std::vector< borka::Tile >& lstTiles )
{
	bool moved = false;
	sf::Vector2f queueMove;

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		queueMove.x = -m_speed;
		moved = true;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		queueMove.x = m_speed;
		moved = true;
	}

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		queueMove.y = -m_speed;
		moved = true;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		queueMove.y = m_speed;
		moved = true;
	}

	sf::FloatRect adjustedPosition = m_position;
	adjustedPosition.left += queueMove.x;
	adjustedPosition.top += queueMove.y;

	for ( unsigned int i = 0; i < lstTiles.size(); i++ )
	{
		if ( lstTiles[i].IsSolid() && lstTiles[i].IsCollision( adjustedPosition ) )
		{
			moved = false;
		}
	}

	if ( moved )
	{
		Move( queueMove );
	}
}
