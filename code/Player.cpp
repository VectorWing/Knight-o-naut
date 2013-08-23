/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include "Player.h"

Player::Player() { ; }

Player::Player( const sf::Texture& image, const sf::FloatRect& position )
{
	Setup( image, position );
}

void Player::Setup( const sf::Texture& image, const sf::FloatRect& position )
{
	Character::Setup( image, position );
	m_speed = 4;
	m_lastMove.x = m_lastMove.y = 0;
	m_commandTimeout = 0;
}

void Player::Update()
{
	if ( m_commandTimeout > 0 )
	{
		m_commandTimeout -= 1.0f;
	}
}

void Player::HandleMovement( const std::vector< borka::Tile >& lstTiles )
{
	// TODO: Clean this up. Also set up speed to slow down when moving diagonally.

	sf::Vector2f queueMove( 0, 0 );
	m_lastMove.x = m_lastMove.y = 0;

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
	{
		queueMove.x = -m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
	{
		queueMove.x = m_speed;
	}

	if ( !IsMapCollision( lstTiles, queueMove ) )
	{
		m_lastMove.x = queueMove.x;
		Move( queueMove );
	}

	queueMove = sf::Vector2f( 0, 0 );
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
	{
		queueMove.y = -m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) || sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
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
	if ( m_commandTimeout <= 0 )
	{
		if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Q ) )
		{
			m_commandTimeout = 10.0f;
			return SIT;
		}
		else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::E ) )
		{
			m_commandTimeout = 50.0f;
			return GOAL;
		}
	}
	return NONE;
}
