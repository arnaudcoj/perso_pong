#ifndef BALL_HPP
#define BALL_HPP

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <cassert>

class Ball : public Entity {

  
  //FIELDS//

public:
  
private:
  sf::Vector2f mDirectionVector;
  float mSpeed;
  
  //METHODS
  
public: 
  Ball(sf::Vector2f position, sf::Vector2f sides = sf::Vector2f(20.f, 20.f));
  virtual void update(sf::Time dt);
  void changeDirection(sf::Vector2f directionVector);
  void accelerate(float acceleration);
  void decelerate(float deceleration);
    
private:
  
};

#endif //BALL_HPP
