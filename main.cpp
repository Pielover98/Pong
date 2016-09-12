
#include "sfwdraw.h"
#include "Game.h"

void main()
{
	sfw::initContext(800, 600, "Xavier Pong!");

	unsigned r = sfw::loadTextureMap("./res/Background.png");


	Paddle p1 = createPaddle( 10, 300, 60, 'W','S', CYAN);
	Paddle p2 = createPaddle(790, 300, 60, 'I', 'K', RED);
	Ball ball = createBall(450, 250, 6, 3, GREEN);
	Boundary boundP = createBoundary(500, 1, 410, 1);
	Boundary boundB = createBoundary(800, 1, 600, 1);


	while (sfw::stepContext())
	{
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0);
		updatePaddle(p1);
		updatePaddle(p2);
		updateBall(ball);
		drawBall(ball);
		updateClampBall(ball, boundB);
		updateClampPaddle(p1, boundP);
		updateClampPaddle(p2, boundP);
		drawPaddle(p1);
		drawPaddle(p2);
	}

	sfw::termContext();
}
/*
void main()
{
	
	sfw::initContext(800, 600, "NSFW Draw");
	unsigned r = sfw::loadTextureMap("./res/Frank.jpg");
	sfw::setBackgroundColor(BLACK);

	float xPos = 5, yPos = 350, xSize = 100, ySize = 100;
	float xPosP2 = 795, yPosP2 = 350, xSizeP2 = 100, ySizeP2 = 100;

	while (sfw::stepContext())
	{
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0);
		sfw::drawLine(xPos, yPos, xPos, yPos + ySize, BLACK);

		if (sfw::getKey('W'))
		{
			yPos += 10;
		}
		if (sfw::getKey('S'))
		{
			yPos -= 10;
		}
		if (yPos < 0)
		{
			yPos = 0;
		}
		if (yPos > 500)
		{
			yPos = 500;
		}
		sfw::drawLine(xPosP2, yPosP2, xPosP2, yPosP2 + ySizeP2, BLACK);

		if (sfw::getKey('I'))
		{
			yPosP2 += 10;
		}
		if (sfw::getKey('K'))
		{
			yPosP2 -= 10;
		}
		if (yPosP2 < 0)
		{
			yPosP2 = 0;
		}
		if (yPosP2 > 500)
		{
			yPosP2 = 500;
		}
	}
}
*/
