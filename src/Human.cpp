#include <Human.hpp>


Human::Human(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
  : mUpKey(upKey)
  , mDownKey(downKey) {
}

sf::Vector2f Human::getMoveVector() {
  sf::Vector2f moveVector(0.f, 0.f);
  if(sf::Keyboard::isKeyPressed(mUpKey))
    moveVector.y += 5;
  if(sf::Keyboard::isKeyPressed(mDownKey))
    moveVector.y -= 5;
  return moveVector;
}

void Human::setUpKey(sf::Keyboard::Key upKey) {
  if(isValidKey(upKey))
    mUpKey = upKey;
}

void Human::setDownKey(sf::Keyboard::Key downKey) {
  if(isValidKey(downKey))
    mUpKey = downKey;
}

bool Human::isValidKey(sf::Keyboard::Key key) const {
  return true; //to be implemented
}
