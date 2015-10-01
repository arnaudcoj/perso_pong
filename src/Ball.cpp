#include <Ball.hpp>

Ball::Ball(sf::Vector2f position, sf::Vector2f sides)
  : Entity(position, sides)
  , mDirectionVector(0.2f, 1.f)
  , mSpeed(350)
{
}

void Ball::update(sf::Time dt) {
  sf::Vector2f moveVector(mDirectionVector.x * mSpeed, mDirectionVector.y * mSpeed);
  move(moveVector, dt);
}

void Ball::changeDirection(sf::Vector2f directionVector) {
  assert(directionVector.x >= -1.f && directionVector.x <= 1.f && directionVector.y >= -1.f && directionVector.y <= 1.f);
  mDirectionVector = directionVector;
}

sf::Vector2f Ball::getDirection() {
  return mDirectionVector;
}

void Ball::accelerate(float acceleration) {
  assert(acceleration >= 0.f);
  mSpeed += acceleration;
}

void Ball::decelerate(float deceleration) {
  assert(deceleration <= 0.f);
  mSpeed -= deceleration;
}

void Ball::correctPosition(sf::View worldView) {
  sf::FloatRect viewBoundaries(worldView.getCenter() - worldView.getSize() / 2.f, worldView.getSize());
  
  float halfHeight = getSize().y / 2;
  sf::Vector2f position = getPosition();
  sf::Vector2f direction = getDirection();
  
  if(position.y - halfHeight < viewBoundaries.top) {
    position.y = viewBoundaries.top + halfHeight;
    direction.y = -direction.y;
  }
  
  if(position.y + halfHeight -1 > viewBoundaries.top + viewBoundaries.height - halfHeight) {
    position.y = viewBoundaries.top + viewBoundaries.height - halfHeight;
    direction.y = -direction.y;
  }

  setPosition(position);
  changeDirection(direction);
}
