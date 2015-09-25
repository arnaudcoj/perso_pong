#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {

  //FIELDS//

public:
  
private: 
  sf::Vector2f mPosition;
  sf::RectangleShape mSprite;
  //METHODS
  
public: 
  Entity(sf::Vector2f position, sf::Vector2f sides);
  virtual void update(sf::Time dt) = 0;
  void draw(sf::RenderTarget& window);
  
private:
  
};
  
#endif //ENTITY_HPP
