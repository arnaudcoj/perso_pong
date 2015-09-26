#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <SFML/Graphics.hpp>
#include <Strategy.hpp>

class Human : public Strategy {

  //FIELDS

public:
  
private:
  sf::Keyboard::Key mUpKey;
  sf::Keyboard::Key mDownKey;
  
  //METHODS

public:
  Human(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
  virtual sf::Vector2f getMoveVector();
  void setUpKey(sf::Keyboard::Key upKey);
  void setDownKey(sf::Keyboard::Key downKey);
  //void setKeys(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
  
private:
  bool isValidKey(sf::Keyboard::Key key) const;
};

#endif //HUMAN_HPP
