
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <string>
#include <sstream>

using namespace std;

bool checkCollision(float aX, float aY, float aW, float aH, float bX, float bY, float bW, float bH);

void moveBall();


int main(int argc, char **argv)
{

    return 0;
}


bool checkCollision(float aX, float aY, float aW, float aH, float bX, float bY, float bW, float bH)
{
    if (aY + aH < bY)
        return false;
    else if (aY > bY + bH)
        return false;
    else if (aX + aW < bX)
        return false;
    else if (aX > bX + bW)
        return false;
    else
        return true;
}

void moveBall(){
    if(score >= 300){
        ballVelX = 0.5;
        ballVelY = 0.5;
    }
    if(score >= 1000){
        barX = 200;
        barY = 465;
        ballX = 235;
        ballY = 430;
        ballVelX = 0;
        ballVelY = 0;
        float brickX = 2, brickY = 2;
        for(int i=0;i<brickAmount;i++){
            if(brickX > 450){
                brickX = 2;
                brickY += 11;
            }
            bricksArray[i].x = brickX;
            bricksArray[i].y = brickY;
            bricksArray[i].width = 38.66;
            bricksArray[i].height = 10;
            bricksArray[i].isAlive = true;
            brickX += 39.66;
        }
        previousScore = score;
        if(highestScore < score){
            highestScore = score;
        }
        chances = 3;
        score = 0;
        flag2 = false;
        Sleep(3000);
        completeMessage(flag2);
    }
    else{
        ballX += ballVelX;
        for (int i=0; i<brickAmount; i++){
            if(bricksArray[i].isAlive == true){
                if(checkCollision(ballX, ballY, ballWH, ballWH, bricksArray[i].x, bricksArray[i].y, bricksArray[i].width, bricksArray[i].height) == true){
                    ballVelX = -ballVelX;
                    bricksArray[i].isAlive = false;
                    score += 10;
                    break;
                }
            }
        }
        ballY -= ballVelY;
        for (int i=0; i<brickAmount; i++){
            if(bricksArray[i].isAlive == true){
                if(checkCollision(ballX, ballY, ballWH, ballWH, bricksArray[i].x, bricksArray[i].y, bricksArray[i].width, bricksArray[i].height) == true){
                    ballVelY = -ballVelY;
                    bricksArray[i].isAlive = false;
                    score += 10;
                    break;
                }
            }
        }
        if(ballX < 0){
            ballVelX = -ballVelX;
        }
        else if(ballX+ballWH > 480){
            ballVelX = -ballVelX;
        }
        if(ballY < 0){
            ballVelY = -ballVelY;
        }
        else if(ballY+ballWH > 480){
            if(chances <= 1){
                barX = 200;
                barY = 465;
                ballX = 235;
                ballY = 430;
                ballVelX = 0;
                ballVelY = 0;
                float brickX = 2, brickY = 2;
                for(int i=0;i<brickAmount;i++){
                    if(brickX > 450){
                        brickX = 2;
                        brickY += 11;
                    }
                    bricksArray[i].x = brickX;
                    bricksArray[i].y = brickY;
                    bricksArray[i].width = 38.66;
                    bricksArray[i].height = 10;
                    bricksArray[i].isAlive = true;
                    brickX += 39.66;
                }
                previousScore = score;
                if(highestScore < score){
                    highestScore = score;
                }
                chances = 3;
                score = 0;
                flag = false;
                Sleep(3000);
                message(flag);
            }
            else{
                chances--;
                ballX = 235;
                ballY=430;
                if(ballVelY < 0){
                    ballVelY = -ballVelY;
                }
                Sleep(3000);
            }
        }
        if(checkCollision(ballX, ballY, ballWH, ballWH, barX, barY, barWidth, barheight) == true){
            ballVelY = -ballVelY;
        }
    }
    glutPostRedisplay();
}
