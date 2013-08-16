/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include "Player.h"

Player::Player( const sf::Texture& image, const sf::FloatRect& position )
	: Character( image, position )
{
	m_speed = 4;
	m_lastMove.x = m_lastMove.y = 0;
}

void Player::HandleMovement( const std::vector< borka::Tile >& lstTiles )
{
	// TODO: Clean this up. Also set up speed to slow down when moving diagonally.

	sf::Vector2f queueMove( 0, 0 );
	m_lastMove.x = m_lastMove.y = 0;

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		queueMove.x = -m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		queueMove.x = m_speed;
	}

	if ( !IsMapCollision( lstTiles, queueMove ) )
	{
		m_lastMove.x = queueMove.x;
		Move( queueMove );
	}

	queueMove = sf::Vector2f( 0, 0 );
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
		m_lastMove.y = queueMove.y;
		Move( queueMove );
	}
}

sf::Vector2f Player::GetLastMove()
{
	return m_lastMove;
}

Behavior Player::GetHorseCommand()
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
	{
		return SIT;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::F ) )
	{
		return FOLLOW_PLAYER;
	}
	else
	{
		return NONE;
	}
}
