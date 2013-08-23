/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include "Character.h"
#include <iostream>

Character::Character( const sf::Texture& image, const sf::FloatRect& position )
{
	Setup( image, position );
	m_speed = 2;
}

bool Character::IsMapCollision( const std::vector< borka::Tile >& lstTiles, const sf::Vector2f& queueMove )
{
	borka::BaseEntity adjusted;
	adjusted.SetPosition( m_position );
	adjusted.Move( queueMove.x, queueMove.y );
	adjusted.SetCollisionRegion( m_collisionRegion );

	for ( unsigned int i = 0; i < lstTiles.size(); i++ )
	{
		if ( lstTiles[i].IsSolid() && lstTiles[i].IsCollision( adjusted ) )
		{
			return true;
		}
	}

	// Collision with side of screen
	if ( adjusted.IsCollision( sf::FloatRect( 0, 		0, 		1280, 	64 ) ) ||		// Top
		 adjusted.IsCollision( sf::FloatRect( 0, 		720-64, 1280, 	64 ) ) ||		// Bottom
		 adjusted.IsCollision( sf::FloatRect( 0, 		0, 		64, 	720 ) ) ||		// Left
		 adjusted.IsCollision( sf::FloatRect( 1280-64, 	0, 		64, 	720 ) ) )		// Right
	{
		return true;
	}

	return false;
}

void Character::HandleMovement( const std::vector< borka::Tile >& lstTiles )
{
	// TODO: Clean this up. Also set up speed to slow down when moving diagonally.
	sf::Vector2f queueMove( 0, 0 );

	if ( m_behavior == GOAL )
	{
		if ( m_goal.x < m_position.left )
		{
			queueMove.x = -m_speed;
		}
		else if ( m_goal.x > m_position.left )
		{
			queueMove.x = m_speed;
		}

		if ( m_goal.y < m_position.top )
		{
			queueMove.y = -m_speed;
		}
		else if ( m_goal.y > m_position.top )
		{
			queueMove.y = m_speed;
		}

		if ( !IsMapCollision( lstTiles, queueMove ) )
		{
			Move( queueMove );
		}

		// Note: This might not happen due to floating points.
		// Add a "range".
		if ( m_position.left == m_goal.x && m_position.top == m_goal.y )
		{
			m_behavior = NONE;
		}
	}
}

void Character::SetBehavior( Behavior behavior )
{
	m_behavior = ( behavior == NONE ) ? m_behavior : behavior;
}

void Character::SetBehavior( Behavior behavior, const sf::Vector2f goal )
{
	m_goal = goal;
	SetBehavior( behavior );
}

void Character::SetSpeed( float speed )
{
	m_speed = speed;
}

void Character::Draw( sf::RenderWindow& window )
{
	// Draw goal
	// TODO: This is bad because it will draw over other characters
	// and any enemies with a "goal" will have this display too.
	if ( m_behavior == GOAL )
	{
		sf::CircleShape circle;
		circle.setFillColor( sf::Color( 100, 200, 50, 200 ) );
		circle.setPosition( sf::Vector2f( m_goal.x - 10 + 32, m_goal.y - 10 + 32 ) );
		circle.setRadius( 20 );
		circle.setOutlineColor( sf::Color( 0, 0, 0 ) );
		circle.setOutlineThickness( 3 );
		window.draw( circle );
	}

	BaseEntity::Draw( window );
}
