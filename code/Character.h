/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#ifndef _CHARACTER
#define _CHARACTER

#include "Borka/BaseEntity.h"
#include "Borka/Tile.h"

class Character : public borka::BaseEntity
{
	public:
	bool IsMapCollision( const std::vector< borka::Tile >& lstTiles, const sf::Vector2f& queueMove );

	protected:
	float m_speed;
	sf::Vector2f m_lastMovement;
};

#endif
