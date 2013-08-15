/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */

#include "Player.h"

Player::Player( const sf::Texture& image, const sf::FloatRect& position )
{
	Setup( image, position );
	m_speed = 5;
}

void Player::HandleMovement()
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
		queueMove.x = m_speed;
		moved = true;
	}

	if ( moved )
	{
		Move( queueMove );
		m_lastMovement = queueMove;
	}
	else
	{
		m_lastMovement = sf::Vector2f( 0, 0 );
	}
}
