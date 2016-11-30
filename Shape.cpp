/* Author	: Martins Filipe
 * Name		: Class Shapes
 * Date		: 2016.11.23
 */

#include "Shape.h"
#include <cmath>

 /********** - Start zone for Shape - ************/
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

double Shape::GetY()
{
	return this->y;
}

/********** - Start zone for Rectangle - ************/
Rectangle::Rectangle(double width, double height, double x, double y) : Shape(x, y)
{
	this->width = width;
	this->height = height;

	sf::RectangleShape
		Image(sf::Vector2f(width, height));

	this->Sprite = Image;
	Sprite.setPosition(x, y);

	Sprite.setFillColor(sf::Color::Blue);
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

double Rectangle::GetHeight()
{
	return this->height;
}

double Rectangle::GetWidth()
{
	return this->width;
}

/********** - Start zone for Circle - ************/
Circle::Circle(double r, double x, double y) : Shape(x, y)
{
	sf::CircleShape
		Image(r);

	this->Sprite = Image;
	Sprite.setPosition(x, y);

	Sprite.setFillColor(sf::Color::Green);
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
	double circleDistanceX = abs(this->Sprite.getPosition().x - r->Sprite.getPosition().x);
	double circleDistanceY = abs(this->Sprite.getPosition().y - r->Sprite.getPosition().y);

	if (circleDistanceX > (r->GetWidth() / 2.0 + this->r))
	{
		return false;
	}

	if (circleDistanceY > (r->GetHeight() / 2 + this->r))
	{
		return false;
	}
	return true;

	if (circleDistanceX <= (r->GetWidth() / 2))
	{
		return true;
	}

	if (circleDistanceY <= (r->GetHeight() / 2))
	{
		return true;
	}

	double cornerDistance = pow((circleDistanceX - r->GetWidth() / 2.0), 2.0) +
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


void Circle::move(float deltaX, float deltaY)
{
	Sprite.setPosition(sf::Vector2f(Sprite.getPosition().x + deltaX,
		Sprite.getPosition().y + deltaY));
}

double Circle::GetRadius()
{
	return this->r;
}
