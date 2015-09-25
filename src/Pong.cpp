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
  : mWindow(sf::VideoMode(800, 600), "SFML works!", sf::Style::Titlebar | sf::Style::Close)
  , mFont()
  , mStatisticsText()
  , mStatisticsFramesCounter(0)
  , mStatisticsFrameTimer()
  , mLeftPaddle(sf::Vector2f(mWindow.getSize().x * 0.1, mWindow.getSize().y * 0.5), sf::Vector2f(mWindow.getSize().x * 0.03, mWindow.getSize().y * 0.2))
  , mRightPaddle(sf::Vector2f(mWindow.getSize().x * 0.9, mWindow.getSize().y * 0.5), sf::Vector2f(mWindow.getSize().x * 0.03, mWindow.getSize().y * 0.2))
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

      mBall.update(dt);
      mLeftPaddle.update(dt);
      mRightPaddle.update(dt);
    }
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
