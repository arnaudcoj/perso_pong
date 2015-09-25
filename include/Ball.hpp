#ifndef BALL_HPP
#define BALL_HPP

#include <Entity.hpp>
#include <SFML/Graphics.hpp>

class Ball : public Entity {

  
  //FIELDS//

public:
  
private:
  
  //METHODS
  
public: 
  Ball(sf::Vector2f position, sf::Vector2f sides = sf::Vector2f(20.f, 20.f));
  virtual void update(sf::Time dt);
  
private:
  
};

#endif //BALL_HPP
