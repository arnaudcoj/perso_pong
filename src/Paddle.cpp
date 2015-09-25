#include <Paddle.hpp>

Paddle::Paddle(sf::Vector2f position, sf::Vector2f sides)
  : Entity(position, sides)
{
}

bool Paddle::touchesTheBall(Ball& ball) const {
  return false; // to be implemented
}

void Paddle::update(sf::Time dt) {
  //to be implemented 
}
