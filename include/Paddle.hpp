#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Ball.hpp>
#include <Entity.hpp>
#include <Strategy.hpp>
#include <Human.hpp>

class Paddle : public Entity{

  //FIELDS//

public:
  
private: 
  //METHODS
  
public: 
  Paddle(sf::Vector2f position, sf::Vector2f sides, Human strategy);
  bool touchesTheBall(Ball& ball) const;
  virtual void update(sf::Time dt);
  
private:
  Human mStrategy;
};
  

#endif //PADDLE_HPP
