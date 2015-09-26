#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <SFML/Graphics.hpp>

class Strategy {

  //FIELDS
public:

private:

  //METHODS

public:
  virtual sf::Vector2f getMoveVector() = 0;
  
  
private:

  
};

#endif //STRATEGY_HPP
