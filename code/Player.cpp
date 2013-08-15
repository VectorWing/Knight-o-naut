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
	sf::Vector2f queueMove;

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		queueMove.x = -m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		queueMove.x = m_speed;
	}

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		queueMove.y = -m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		queueMove.y = m_speed;
	}

	if ( !IsMapCollision( lstTiles, queueMove ) )
	{
		Move( queueMove );
	}
}
