/* Author	: Martins Filipe
 * Name		: Header for class Shapes
 * Date		: 2016.11.23
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <SFML/Graphics.hpp>
#include <string>

class Shape
{
public:
	Shape(double x, double y);
	virtual bool isColliding(Shape*)=0;
	virtual void draw(sf::RenderWindow* window) = 0;
	~Shape();
	double GetX();
	double GetY();
	double GetPosition();
protected:
	double x;
	double y;
};

class Circle;

class Rectangle: public Shape
{
public:
	Rectangle(double width, double height, double x, double y);
	~Rectangle();
	bool Rectangle::isColliding(Shape*);
	bool Rectangle::isColliding(Rectangle*);
	bool Rectangle::isColliding(Circle*);
	void Rectangle::draw(sf::RenderWindow*);
	sf::RectangleShape sfmlRect;
	double GetWidth();
	double GetHeight();
private:
	double width;
	double height;
	int rectColorR = 0;
	int rectColorV = 0;
	int rectColorB = 255;
	sf::RectangleShape sfmlRect;
};

class Circle: public Shape
{
public:
	Circle(double r, double x, double y);
	~Circle();
	bool Circle::isColliding(Shape*);
	bool Circle::isColliding(Rectangle*);
	bool Circle::isColliding(Circle*);
	void Circle::draw(sf::RenderWindow*);
	void Circle::move(float deltaX, float deltaY);
	double GetRadius();
private:
	double r;
	int circleColorR = 0;
	int circleColorV = 255;
	int circleColorB = 0;
	sf::CircleShape sfmlCircle;
};

void getRectSfml(sf::RectangleShape*);
void getCircleSfml(sf::CircleShape*);
void defaultColor(Shape*, Shape*);
void collidingColor();

#endif //!SHAPE_H