#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {

  //FIELDS//

public:
  
private: 
  sf::RectangleShape mSprite;
  sf::Vector2f mSize;

  //METHODS
  
public: 
  Entity(sf::Vector2f position, sf::Vector2f sides);
  virtual void update(sf::Time dt) = 0;
  void draw(sf::RenderTarget& window);
  void move(sf::Vector2f& moveVector, sf::Time dt);
  sf::Vector2f getPosition();
  sf::Vector2f getSize();
  void setPosition(sf::Vector2f position);
  sf::FloatRect getBoundaries() const;
private:
  
};
  
#endif //ENTITY_HPP
