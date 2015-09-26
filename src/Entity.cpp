#include <Entity.hpp>

Entity::Entity(sf::Vector2f position, sf::Vector2f sides)
  : mSprite(sides) 
{
  mSprite.setOrigin(sides.x/2, sides.y/2);
  mSprite.setPosition(position);
  mSprite.setFillColor(sf::Color::White);
}

void Entity::draw(sf::RenderTarget& window) {
  window.draw(mSprite);
}
  
void Entity::move(sf::Vector2f& moveVector) {
  mSprite.move(moveVector);
}
