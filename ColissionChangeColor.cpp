// ColissionChangeColor.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shape.h"


bool locationAllowed(Shape &shape, int width, int height) {
	double tempX = shape.GetX();
	double tempY = shape.GetY();
	int x = tempX + 1;
	int y = tempY + 1;
	if (x > width || x < 0) {
		return false;
	}
	if (y > height || y < 0) {
		return false;
	}
	return true;
}

int main()
{
	int widthWindow = 500;
	int heightWindow = 500;
<<<<<<< HEAD
=======
	int colorRedR = 255;
	int colorRedV = 0;
	int colorRedB = 0;
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
	double widthRect = 100.0;
	double heightRect = 100.0;
	double rCircle = 50.0;
	double xRect = widthWindow / 2;
	double yRect = widthWindow / 2;
	double xDefault = 0;
	double yDefault = 0;
	float speed = 0.25;

	/*Setting the window*/
<<<<<<< HEAD
	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow),
		"Hunter Square !");

	/*Setting the square*/
	Rectangle* rectPhysiqueShape = new
		Rectangle(widthRect, heightRect, xRect, yRect);

	/*Setting the circle*/
	Circle* circlePhysiqueShape = new
		Circle(rCircle, xDefault, yDefault);
=======
	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "Hunter Square !");

	/*Setting the square*/
	Rectangle* rectPhysiqueShape = new 
		Rectangle(widthRect,heightRect,xRect,yRect);

	/*Setting the circle*/
	Circle* circlePhysiqueShape = new
		Circle(rCircle, xDefault,yDefault);
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c

	while (window.isOpen()) //GameLoop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float deltaX = 0.0f;
		float deltaY = 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			deltaX = 0 - speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			deltaX = speed;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			deltaY = 0 - speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			deltaY = speed;
		}

		if (locationAllowed(*circlePhysiqueShape, widthWindow, heightRect))
		{
			circlePhysiqueShape->move(deltaX, deltaY);
		}
<<<<<<< HEAD

		
		if (circlePhysiqueShape->isColliding(rectPhysiqueShape))
		{
			circlePhysiqueShape->Sprite.setFillColor(sf::Color::Red);
			rectPhysiqueShape->Sprite.setFillColor(sf::Color::Red);
		}
		else
		{
			circlePhysiqueShape->Sprite.setFillColor(sf::Color::Green);
			rectPhysiqueShape->Sprite.setFillColor(sf::Color::Blue);
=======
		
		
		if (circlePhysiqueShape->isColliding(rectPhysiqueShape))
		{
		
		}
		else
		{

>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
		}

		//Setting/Clearing the screen
		window.clear();
<<<<<<< HEAD
		window.draw(circlePhysiqueShape->Sprite);
		window.draw(rectPhysiqueShape->Sprite);
=======
		circlePhysiqueShape->draw(&window);
		rectPhysiqueShape->draw(&window);
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
		window.display();
	}

	//delete zone
	delete rectPhysiqueShape;
	delete circlePhysiqueShape;

	//GameOver
	system("pause");
<<<<<<< HEAD
	return 0;
=======
    return 0;
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
}

