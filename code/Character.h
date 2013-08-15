/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#ifndef _CHARACTER
#define _CHARACTER

#include "Borka/BaseEntity.h"

class Character : public borka::BaseEntity
{
	public:
	virtual void HandleMovement() = 0;

	protected:
};

#endif
