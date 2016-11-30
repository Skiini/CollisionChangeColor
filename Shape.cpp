/* Author	: Martins Filipe
 * Name		: Class Shapes
 * Date		: 2016.11.23
 */

#include "Shape.h"
#include <cmath>

<<<<<<< HEAD
 /********** - Start zone for Shape - ************/
=======
/********** - Start zone for Shape - ************/
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
Shape::Shape(double x, double y)
{
	this->x = x;
	this->y = y;
}

Shape::~Shape()
{

}

double Shape::GetPosition()
{
	return this->x, this->y;
}

double Shape::GetX()
{
	return this->x;
}

<<<<<<< HEAD
double Shape::GetY()
=======
double Shape::GetY() 
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
{
	return this->y;
}

/********** - Start zone for Rectangle - ************/
<<<<<<< HEAD
Rectangle::Rectangle(double width, double height, double x, double y) : Shape(x, y)
{
	this->width = width;
	this->height = height;

	sf::RectangleShape
		Image(sf::Vector2f(width, height));

	this->Sprite = Image;
	Sprite.setPosition(x, y);

	Sprite.setFillColor(sf::Color::Blue);
=======
Rectangle::Rectangle(double width, double height, double x, double y) : Shape(x,y)
{
	this->width = width;
	this->height = height;
	sfmlRect=sf::RectangleShape(sf::Vector2f(width,height));
	sfmlRect.setPosition(sf::Vector2f(x, y));
	sfmlRect.setOrigin(sf::Vector2f(width/2, height/2));
	sfmlRect.setFillColor(sf::Color::Blue);
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
}

Rectangle::~Rectangle()
{

}

bool Rectangle::isColliding(Shape* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return isColliding(r);
	}

	Circle* c = dynamic_cast <Circle*> (s);
	if (c != NULL)
	{
		return isColliding(c);
	}
}

bool Rectangle::isColliding(Rectangle* r)
{
	if ((this->x + this->width) < r->x || x > (r->x + r->width))
	{
		return false;
	}

	if ((this->y + this->height) < r->y || (r->y + r->height) < this->y)
	{
		return false;
	}

	return true;
}

bool Rectangle::isColliding(Circle* c)
{
	return c->isColliding(this);
}

<<<<<<< HEAD
=======
void Rectangle::draw(sf::RenderWindow* window)
{
	window->draw(sfmlRect);
}

>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
double Rectangle::GetHeight()
{
	return this->height;
}

double Rectangle::GetWidth()
{
	return this->width;
}

/********** - Start zone for Circle - ************/
<<<<<<< HEAD
Circle::Circle(double r, double x, double y) : Shape(x, y)
{
	sf::CircleShape
		Image(r);

	this->Sprite = Image;
	Sprite.setPosition(x, y);

	Sprite.setFillColor(sf::Color::Green);
=======
Circle::Circle(double r, double x, double y) : Shape(x,y)
{
	this->r = r;
	sfmlCircle=sf::CircleShape(r);
	sfmlCircle.setPosition(sf::Vector2f(x, y));
	sfmlCircle.setFillColor(sf::Color::Green);
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
}

Circle::~Circle()
{

}

bool Circle::isColliding(Shape* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return isColliding(r);
	}

	Circle* c = dynamic_cast <Circle*> (s);
	if (c != NULL)
	{
		return isColliding(c);
	}
}

bool Circle::isColliding(Rectangle* r)
{
<<<<<<< HEAD
	double circleDistanceX = abs(this->Sprite.getPosition().x - r->Sprite.getPosition().x);
	double circleDistanceY = abs(this->Sprite.getPosition().y - r->Sprite.getPosition().y);

	if (circleDistanceX > (r->GetWidth() / 2.0 + this->r))
=======
	double circleDistanceX = abs(this->x - r->GetX());
	double circleDistanceY = abs(this->y - r->GetY());

	if (circleDistanceX > (r->GetWidth()/2.0 + this->GetRadius()))
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
	{
		return false;
	}

<<<<<<< HEAD
	if (circleDistanceY > (r->GetHeight() / 2 + this->r))
	{
		return false;
	}
	return true;

	if (circleDistanceX <= (r->GetWidth() / 2))
=======
	if (circleDistanceY > (r->GetHeight() / 2 + this->GetRadius()))
	{
		return false;
	}

	if (circleDistanceX <= (r->GetWidth()/2))
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
	{
		return true;
	}

	if (circleDistanceY <= (r->GetHeight() / 2))
	{
		return true;
	}

<<<<<<< HEAD
	double cornerDistance = pow((circleDistanceX - r->GetWidth() / 2.0), 2.0) +
=======
	double cornerDistance =  pow((circleDistanceX - r->GetWidth() / 2.0),2.0) +
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
		pow((circleDistanceY - r->GetHeight() / 2.0), 2.0);
}

bool Circle::isColliding(Circle* c)
{
	double tempR;
	double tempX;
	double tempY;
	tempR = this->r + c->GetRadius();
	tempX = this->x - c->GetX();
	tempY = this->y - c->GetY();

	if (tempX < tempR)
	{
		return true;
	}

	if (tempY < tempR)
	{
		return true;
	}
}

<<<<<<< HEAD

void Circle::move(float deltaX, float deltaY)
{
	Sprite.setPosition(sf::Vector2f(Sprite.getPosition().x + deltaX,
		Sprite.getPosition().y + deltaY));
=======
void Circle::draw(sf::RenderWindow* window)
{
	window->draw(sfmlCircle);
}

void Circle::move(float deltaX,float deltaY)
{
	sfmlCircle.setPosition(sf::Vector2f(sfmlCircle.getPosition().x + deltaX,
		sfmlCircle.getPosition().y + deltaY));
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
}

double Circle::GetRadius()
{
	return this->r;
}
<<<<<<< HEAD
=======

void getRectSfml(sf::RectangleShape*)
{
	return sfmlRe
}

void defaultColor(Shape* r, Shape* c)
{
	r->
	sfmlRect.setFillColor(sf::Color::Red);
}

void defaultColor()
{
	sfmlRect.setFillColor(sf::Color::Red);
}
>>>>>>> f3da85220086665d93e2e34b24a6dbf30925517c
