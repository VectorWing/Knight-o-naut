/* Knight-o-naut - Rachel J. Morris - 2013 - License pending - Moosader.com */
#include <iostream>

#include <SFML/Window.hpp>

#include "Borka/Application.h"

int main()
{
    Application application( "Knight-o-naut", sf::Vector2i( 640, 480 ) );

    while ( !application.IsDone() )
    {
		application.Update();

		application.BeginDraw();
		application.EndDraw();
    }

    return 0;
}
