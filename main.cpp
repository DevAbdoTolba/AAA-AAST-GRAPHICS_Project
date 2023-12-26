  
  #include <windows.h>
  #include <stdio.h>
  #include <iostream>
  #include <GL/glut.h>
  #include <string>
  #include <sstream>
  
  using namespace std;
  
  
  
  
  
    // ==================================================================================================== //
   // ==================================== Function Prototypes ========================================== //
  // ================================================================================================== //
    
    
  void myInit (void);
  void myDisplay(void);
    
  bool checkCollision(float aX, float aY, float aW, float aH, float bX, float bY, float bW, float bH);
  
  void moveBall();
  
  
    // ================================================================================================== //
   // ==================================== Global Variables ============================================ //
  // ================================================================================================== //
  
  
    // ================================================================================================== //
   // ==================================== Main ======================================================== //
  // ================================================================================================== //
  
  int main(int argc, char **argv)
  {
  
      
      glutInit(&argc, argv);  // Initialize GLUT
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowSize(760, 480);
      glutInitWindowPosition(100, 150);
      glutCreateWindow("Brick Breaker Game");
  
      // Register your GLUT callback functions and initialize other settings
      glutDisplayFunc(myDisplay);
      glutSpecialFunc(keyboard);
      glutMouseFunc(mouse);
  
      myInit();  // Initialize your settings
  
      glutMainLoop();  // Enter the GLUT main event loop
  
      return 0;
  
  
  }
  
    // ==================================================================================================== //
   // ==================================== Functions ===================================================== //
  // ==================================================================================================== //
  
  bool checkCollision(float aX, float aY, float aW, float aH, float bX, float bY, float bW, float bH)
  {
      // Check if the bottom of object A is above the top of object B
      if (aY + aH < bY)
          return false;
      // Check if the top of object A is below the bottom of object B
      else if (aY > bY + bH)
          return false;
      // Check if the right side of object A is to the left of the left side of object B
      else if (aX + aW < bX)
          return false;
      // Check if the left side of object A is to the right of the right side of object B
      else if (aX > bX + bW)
          return false;
      // If none of the above conditions are met, the objects are colliding
      else
          return true;
  }
  
  void moveBall(){
      // If the score is greater than or equal to 300, increase the ball's velocity
      if(score >= 300){
          ballVelX = 0.5;
          ballVelY = 0.5;
      }
      // If the score is greater than or equal to 1000, reset the game state and increase the difficulty
      if(score >= 1000){
          // Reset the bar and ball positions
          barX = 200;
          barY = 465;
          ballX = 235;
          ballY = 430;
          // Stop the ball's movement
          ballVelX = 0;
          ballVelY = 0;
          // Reset the bricks
          float brickX = 2, brickY = 2;
          for(int i=0;i<brickAmount;i++){
              // If the bricks reach the end of the row, start a new row
              if(brickX > 450){
                  brickX = 2;
                  brickY += 11;
              }
              // Set the brick's position and dimensions
              bricksArray[i].x = brickX;
              bricksArray[i].y = brickY;
              bricksArray[i].width = 38.66;
              bricksArray[i].height = 10;
              // Make the brick alive
              bricksArray[i].isAlive = true;
              // Move to the next brick position
              brickX += 39.66;
          }
          // Save the previous score
          previousScore = score;
          // Update the highest score if necessary
          if(highestScore < score){
              highestScore = score;
          }
          // Reset the chances and score
          chances = 3;
          score = 0;
          // Reset the flag
          flag2 = false;
          // Pause for 3 seconds
          Sleep(3000);
          // Display the completion message
          completeMessage(flag2);
      }
      // If the score is less than 1000, continue the game
      else{
          // Move the ball horizontally
          ballX += ballVelX;
          // Check for collisions with each brick
          for (int i=0; i<brickAmount; i++){
              if(bricksArray[i].isAlive == true){
                  if(checkCollision(ballX, ballY, ballWH, ballWH, bricksArray[i].x, bricksArray[i].y, bricksArray[i].width, bricksArray[i].height) == true){
                      // If a collision occurs, reverse the ball's horizontal direction and destroy the brick
                      ballVelX = -ballVelX;
                      bricksArray[i].isAlive = false;
                      // Increase the score
                      score += 10;
                      break;
                  }
              }
          }
          // Move the ball vertically
          ballY -= ballVelY;
          // Check for collisions with each brick
          for (int i=0; i<brickAmount; i++){
              if(bricksArray[i].isAlive == true){
                  if(checkCollision(ballX, ballY, ballWH, ballWH, bricksArray[i].x, bricksArray[i].y, bricksArray[i].width, bricksArray[i].height) == true){
                      // If a collision occurs, reverse the ball's vertical direction and destroy the brick
                      ballVelY = -ballVelY;
                      bricksArray[i].isAlive = false;
                      // Increase the score
                      score += 10;
                      break;
                  }
              }
          }
          // If the ball hits the left or right wall, reverse its horizontal direction
          if(ballX < 0){
              ballVelX = -ballVelX;
          }
          else if(ballX+ballWH > 480){
              ballVelX = -ballVelX;
          }
          // If the ball hits the top wall, reverse its vertical direction
          if(ballY < 0){
              ballVelY = -ballVelY;
          }
          // If the ball hits the bottom wall
          else if(ballY+ballWH > 480){
              // If there are no chances left, reset the game state
              if(chances <= 1){
                  // Reset the bar and ball positions
                  barX = 200;
                  barY = 465;
                  ballX = 235;
                  ballY = 430;
                  // Stop the ball's movement
                  ballVelX = 0;
                  ballVelY = 0;
                  // Reset the bricks
                  float brickX = 2, brickY = 2;
                  for(int i=0;i<brickAmount;i++){
                      // If the bricks reach the end of the row, start a new row
                      if(brickX > 450){
                          brickX = 2;
                          brickY += 11;
                      }
                      // Set the brick's position and dimensions
                      bricksArray[i].x = brickX;
                      bricksArray[i].y = brickY;
                      bricksArray[i].width = 38.66;
                      bricksArray[i].height = 10;
                      // Make the brick alive
                      bricksArray[i].isAlive = true;
                      // Move to the next brick position
                      brickX += 39.66;
                  }
                  // Save the previous score
                  previousScore = score;
                  // Update the highest score if necessary
                  if(highestScore < score){
                      highestScore = score;
                  }
                  // Reset the chances and score
                  chances = 3;
                  score = 0;
                  // Reset the flag
                  flag = false;
                  // Pause for 3 seconds
                  Sleep(3000);
                  // Display the message
                  message(flag);
              }
              // If there are chances left, decrease the chances and reset the ball position
              else{
                  chances--;
                  ballX = 235;
                  ballY=430;
                  // If the ball is moving upwards, reverse its direction
                  if(ballVelY < 0){
                      ballVelY = -ballVelY;
                  }
                  // Pause for 3 seconds
                  Sleep(3000);
              }
          }
          // If the ball collides with the bar, reverse its vertical direction
          if(checkCollision(ballX, ballY, ballWH, ballWH, barX, barY, barWidth, barheight) == true){
              ballVelY = -ballVelY;
          }
      }
      // Redraw the display
      glutPostRedisplay();
  }
  
  void myInit (void){
      glClearColor(1.0, 1.0, 1.0, 0.0);
      glColor3f(0.0f, 0.0f, 0.0f);
      glViewport(0, 0, 760, 480);
      glPointSize(4.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(0.0, 760.0, 480.0, 0.0, -1.0, 1.0);
  
  }
  
  void myDisplay(void){
      glClear (GL_COLOR_BUFFER_BIT);
      glColor3f (0.0, 0.0, 0.0);
      //Bar
      glBegin(GL_QUADS);
      glColor3ub(255, 204, 102);
      glVertex2f(barX, barY);
      glVertex2f(barX+barWidth, barY);
      glVertex2f(barX+barWidth, barY+barheight);
      glVertex2f(barX, barY+barheight);
      glEnd();
      //Ball
      glBegin(GL_QUADS);
      glColor3ub(255, 0, 0);
      glVertex2f(ballX, ballY);
      glVertex2f(ballX+ballWH, ballY);
      glVertex2f(ballX+ballWH, ballY+ballWH);
      glVertex2f(ballX, ballY+ballWH);
      glEnd();
  
      //sidebar
      glBegin(GL_QUADS);
      glColor3ub(0, 0, 0);
      glVertex2f(480, 0);
      glVertex2f(480, 480);
      glVertex2f(485, 480);
      glVertex2f(485, 0);
      glEnd();
  
      print(score);
      createBricks();
      message(flag);
      completeMessage(flag2);
  
      glutSwapBuffers();
  }
  
