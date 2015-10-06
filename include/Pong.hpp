#ifndef PONG_HPP
#define PONG_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Paddle.hpp>
#include <Ball.hpp>
#include <Human.hpp>

class Pong {

  
//FIELDS//

public:
  
private: 
  sf::RenderWindow mWindow;
  static const sf::Time TimePerFrame;
  sf::Font mFont;
  sf::Text mStatisticsText;
  int mStatisticsFramesCounter;
  sf::Time mStatisticsFrameTimer;

  

  Paddle mLeftPaddle;
  Paddle mRightPaddle;
  Ball mBall;
  
//METHODS
  
public: 
  Pong();
  void run();
  
private:
  void update(sf::Time dt);
  void draw();
  void display();
  void updateStatistics(sf::Time elapsedTime);
  void drawStatistics();
  bool handleCollision(Ball& ball, Paddle& paddle);
};
  
#endif //PONG_HPP
