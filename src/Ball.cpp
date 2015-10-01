#include <Ball.hpp>

Ball::Ball(sf::Vector2f position, sf::Vector2f sides)
  : Entity(position, sides)
  , mDirectionVector(1.f, 1.f)
  , mSpeed(150)
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

void Ball::accelerate(float acceleration) {
  assert(acceleration >= 0.f);
  mSpeed += acceleration;
}

void Ball::decelerate(float deceleration) {
  assert(deceleration <= 0.f);
  mSpeed -= deceleration;
}
