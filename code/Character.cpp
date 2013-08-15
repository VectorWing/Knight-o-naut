/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include "Character.h"
#include <iostream>

void Character::CorrectMovement()
{
	std::cout << "Correct movement" << std::endl;
	std::cout << "Last movement: " << m_lastMovement.x << ", " << m_lastMovement.y << std::endl;
	// Undo movement
	Move( -m_lastMovement.x, -m_lastMovement.y );
}
