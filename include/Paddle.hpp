#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Ball.hpp>
#include <Entity.hpp>

class Paddle : public Entity {

  //FIELDS//

public:
  
private: 
  //METHODS
  
public: 
  Paddle(sf::Vector2f position, sf::Vector2f sides = sf::Vector2f(30.f, 100.f));
  bool touchesTheBall(Ball& ball) const;
  virtual void update(sf::Time dt);
  
private:
  
};
  

#endif //PADDLE_HPP
