/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#ifndef _CHARACTER
#define _CHARACTER

#include "Borka/Entities/BaseEntity.h"
#include "Borka/Levels/Tile.h"
#include "Borka/Levels/Level.h"

enum Behavior { NONE, SIT, GOAL, FOLLOW_PLAYER };

class Character : public borka::BaseEntity
{
	public:
	Character();
	Character( const sf::Texture& image, const sf::FloatRect& position );

	void Setup( const sf::Texture& image, const sf::FloatRect& position );
	void RandomCoordinates();
	void PlaceNear( const Character& item, borka::Level& level );

	bool IsMapCollision( const std::vector< borka::Tile >& lstTiles, const sf::Vector2f& queueMove );
	virtual void HandleMovement( const std::vector< borka::Tile >& lstTiles );

	void SetBehavior( Behavior behavior );
	void SetBehavior( Behavior behavior, const sf::Vector2f goal );
	void SetSpeed( float speed );

    virtual void Draw( sf::RenderWindow& window );

	protected:
	float 			m_speed;
	sf::Vector2f 	m_lastMovement;
	sf::Vector2f 	m_goal;
	Behavior 		m_behavior;
};

#endif
