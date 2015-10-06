#include <Pong.hpp>

const sf::Time Pong::TimePerFrame = sf::seconds(1.f/60.f);

int main () {
  try{
    Pong game;
    game.run();
  } catch (std::exception& e) {
    std::cout << "\nEXCEPTION : " << e.what() << std::endl;
  }
}

Pong::Pong()
  : mWindow(sf::VideoMode(800, 600), "Pong", sf::Style::Titlebar | sf::Style::Close)
  , mFont()
  , mStatisticsText()
  , mStatisticsFramesCounter(0)
  , mStatisticsFrameTimer()
  , mLeftPaddle(sf::Vector2f(mWindow.getSize().x * 0.1, mWindow.getSize().y * 0.5), sf::Vector2f(mWindow.getSize().x * 0.03, mWindow.getSize().y * 0.2), Human(sf::Keyboard::A, sf::Keyboard::Q))
  , mRightPaddle(sf::Vector2f(mWindow.getSize().x * 0.9, mWindow.getSize().y * 0.5), sf::Vector2f(mWindow.getSize().x * 0.03, mWindow.getSize().y * 0.2), Human(sf::Keyboard::Up, sf::Keyboard::Down))
  , mBall(sf::Vector2f(mWindow.getSize().x * 0.5, mWindow.getSize().y * 0.5), sf::Vector2f(mWindow.getSize().y * 0.02, mWindow.getSize().y * 0.02))
{
  mFont.loadFromFile("resources/Vdj.ttf");
  mStatisticsText.setPosition(5.f, 5.f);
  mStatisticsText.setCharacterSize(10u);
  mStatisticsText.setFont(mFont);
}

void Pong::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen()) {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;
    sf::sleep(TimePerFrame);
    while (timeSinceLastUpdate > TimePerFrame)
      {
	timeSinceLastUpdate -= TimePerFrame;
	update(TimePerFrame);
      }

    updateStatistics(elapsedTime);
    
    draw();
    drawStatistics();
    display();
  }
}

void Pong::update(sf::Time dt) {
  sf::Event event;
  while (mWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	mWindow.close();
    }

  if(!handleCollision(mBall, mLeftPaddle))
    mLeftPaddle.update(dt);
  mLeftPaddle.correctPaddlePosition(mWindow.getDefaultView());

  if(!handleCollision(mBall, mRightPaddle))
    mRightPaddle.update(dt);
  mRightPaddle.correctPaddlePosition(mWindow.getDefaultView());
  
  mBall.update(dt);
  mBall.correctPosition(mWindow.getDefaultView());
}


void Pong::draw() {
  mWindow.clear();

  mBall.draw(mWindow);
  mLeftPaddle.draw(mWindow);
  mRightPaddle.draw(mWindow);
  
}

void Pong::display() {
  mWindow.display();
}

void Pong::drawStatistics() {
  mWindow.draw(mStatisticsText);
}

void Pong::updateStatistics(sf::Time elapsedTime) {
  mStatisticsFramesCounter++;
  mStatisticsFrameTimer += elapsedTime;

  if(mStatisticsFrameTimer >= sf::seconds(1)) {
    mStatisticsText.setString(std::to_string(mStatisticsFramesCounter) + "fps");
    mStatisticsFrameTimer -= sf::seconds(1);
    mStatisticsFramesCounter = 0;
  }
}

bool Pong::handleCollision(Ball& ball, Paddle& paddle) {
  sf::FloatRect ballBounds = ball.getBoundaries();
  sf::FloatRect paddleBounds = paddle.getBoundaries();
  if(ballBounds.intersects(paddleBounds)) {
    sf::Vector2f ballPosition = ball.getPosition();
    sf::Vector2f ballDirection = ball.getDirection();
    if(ballPosition.x <= paddleBounds.left || ballPosition.x >= paddleBounds.left + paddleBounds.width)
      ballDirection.x = -ballDirection.x;
    if(ballPosition.y <= paddleBounds.top || ballPosition.y >= paddleBounds.top + paddleBounds.height)
      ballDirection.y = -ballDirection.y;
    ball.changeDirection(ballDirection);
    return true;
  }
  return false;
}
