/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include "Character.h"
#include <iostream>

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
	return false;
}
