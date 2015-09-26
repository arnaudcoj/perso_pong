#include <Paddle.hpp>

Paddle::Paddle(sf::Vector2f position, sf::Vector2f sides, Human strategy)
  : Entity(position, sides)
  , mStrategy(strategy)
{
}

bool Paddle::touchesTheBall(Ball& ball) const {
  return false; // to be implemented
}

void Paddle::update(sf::Time dt) {
  sf::Vector2f moveVector = mStrategy.getMoveVector();
  move(moveVector);
}
