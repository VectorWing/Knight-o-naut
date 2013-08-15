/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#ifndef _CHARACTER
#define _CHARACTER

#include "Borka/BaseEntity.h"

class Character : public borka::BaseEntity
{
	public:
	virtual void HandleMovement() = 0;
	void CorrectMovement();

	protected:
	float m_speed;
	sf::Vector2f m_lastMovement;
};

#endif
