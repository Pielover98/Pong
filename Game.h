#pragma once
struct Paddle
{
	float xPos = 0, yPos = 0, Size = 0;
	char up, down;
	unsigned color;
};
struct Ball
{
	float bxPos = 0, byPos = 0, xVel = 0, yVel = 0, radius = 0;
	unsigned color;
};
struct Boundary
{
	float xMax = 0, xMin = 0, yMax = 0, yMin = 0;
};

Paddle createPaddle(float xPos, float yPos, float size, char up, char down, unsigned color)
{
	Paddle p;
	p.xPos = xPos;
	p.yPos = yPos;
	p.Size = size;
	p.up = up;
	p.down = down;
	p.color = color;
	return p;
}
Ball createBall(float xpos, float ypos, float radius, float vel, unsigned color)
{
	Ball b;
	b.bxPos = xpos;
	b.byPos = ypos;
	b.xVel = vel;
	b.yVel = vel;
	b.color = color;
	b.radius = radius;
	return b;
}
Boundary createBoundary(float xMax, float xMin, float yMax, float yMin)
{
	Boundary bound;
	bound.xMax = xMax;
	bound.xMin = xMin;
	bound.yMax = yMax;
	bound.yMin = yMin;
	return bound;
}
void updatePaddle(Paddle &p)
{
	if (sfw::getKey(p.up))
	{
		p.yPos += 10;
	}
	if (sfw::getKey(p.down))
	{
		p.yPos -= 10;
	}
	
}

void drawPaddle(const Paddle &p)
{
	sfw::drawLine(p.xPos, p.yPos, p.xPos, p.yPos + p.Size, p.color);
}
void updateBall(Ball &b)
{
	b.byPos += b.xVel;
	b.byPos += b.yVel;
}
void drawBall(const Ball &b)
{
	sfw::drawCircle(b.bxPos, b.byPos, b.radius, 12u, b.color);
}
void updateClampPaddle(Paddle &p, Boundary &bound)
{
	if (p.yPos < bound.yMin)
	{
		p.yPos = bound.yMin;
	}
	if (p.yPos > bound.yMax)
	{
		p.yPos = bound.yMax;
	}
}
void updateClampBall(Ball &b, Boundary &bound)
{
	if (b.byPos < bound.yMin)
	{
		b.yVel *= -1;
	}
	if (b.byPos < bound.yMax)
	{
		b.yVel *= -1;
	}
	if (b.byPos < bound.xMin)
	{
		b.xVel *= -1;
	}
	if (b.byPos < bound.xMax)
	{
		b.xVel *= -1;
	}
}