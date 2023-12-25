
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <string>
#include <sstream>

using namespace std;

bool checkCollision(float aX, float aY, float aW, float aH, float bX, float bY, float bW, float bH);

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