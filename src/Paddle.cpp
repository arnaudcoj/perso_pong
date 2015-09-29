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
  move(moveVector, dt);
}

void Paddle::correctPaddlePosition(sf::View worldView) {
  sf::FloatRect viewBoundaries(worldView.getCenter() - worldView.getSize() / 2.f, worldView.getSize());
  
  float halfHeight = getSize().y / 2;
  sf::Vector2f position = getPosition();

  position.y = std::max(position.y - halfHeight, viewBoundaries.top);
  position.y = std::min(position.y + halfHeight, viewBoundaries.top + viewBoundaries.height - halfHeight);

  setPosition(position);
}
