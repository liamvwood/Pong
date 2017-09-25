#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "cmath"

int main() {

    sf::RenderWindow window(sf::VideoMode(2040,1080,32),"Pong 1.0");
    sf::CircleShape ball, halfCourtCircle;
    sf::RectangleShape paddle1(sf::Vector2f(10,75));
    sf::RectangleShape paddle2(sf::Vector2f(10,75));
    sf::RectangleShape halfCourt(sf::Vector2f(1, window.getSize().y));
    sf::Text score1, score2;

    sf:: Font font;
    font.loadFromFile("OpenSans-Bold.ttf");

    sf::SoundBuffer bufferPaddle1;
    bufferPaddle1.loadFromFile("Beep1.wav");
    sf::SoundBuffer bufferPaddle2;
    bufferPaddle2.loadFromFile("Beep2.wav");
    sf::SoundBuffer bufferCollision;
    bufferCollision.loadFromFile("Beep5.wav");
    sf::Sound soundPaddle1;
    soundPaddle1.setBuffer(bufferPaddle1);
    sf::Sound soundPaddle2;
    soundPaddle2.setBuffer(bufferPaddle2);
    sf::Sound soundCollision;
    soundCollision.setBuffer(bufferCollision);
    sf::Music backgroundMusic;
    if(!backgroundMusic.openFromFile("Centuries_8-Bit.ogg"))
        return EXIT_FAILURE;
    backgroundMusic.setVolume(50);
    backgroundMusic.setLoop(true);

    sf::Text victor1("Player 1 Wins!", font, 64);
    sf::Text victor2("Player 2 Wins!", font, 64);

    victor1.setPosition(window.getSize().x/2 - victor1.getGlobalBounds().width/2,window.getSize().y/3 - victor1.getGlobalBounds().height/2);
    victor2.setPosition(window.getSize().x/2 - victor2.getGlobalBounds().width/2,window.getSize().y/3 - victor2.getGlobalBounds().height/2);

    score1.setFont(font);
    score1.setCharacterSize(32);
    score1.setPosition(window.getSize().x/2 - score1.getCharacterSize()*2, 5);

    score2.setFont(font);
    score2.setCharacterSize(32);
    score2.setPosition(window.getSize().x/2 + 10 + score2.getCharacterSize(), 5);

    halfCourt.setPosition(window.getSize().x/2,0);
    halfCourt.setOutlineColor(sf::Color::White);
    halfCourtCircle.setRadius(50);
    halfCourtCircle.setOutlineColor(sf::Color::White);
    halfCourtCircle.setOutlineThickness(1);
    halfCourtCircle.setFillColor(sf::Color::Black);
    halfCourtCircle.setPosition(window.getSize().x/2 - halfCourtCircle.getRadius(), window.getSize().y/2 - halfCourtCircle.getRadius());

    paddle1.setPosition(0, window.getSize().y/2 - paddle1.getSize().y/2);
    paddle1.setOutlineColor(sf::Color::White);

    paddle2.setPosition(window.getSize().x - paddle1.getSize().x, window.getSize().y/2 - paddle2.getSize().y/2);
    paddle2.setOutlineColor(sf::Color::White);

    ball.setRadius(10);
    ball.setOutlineColor(sf::Color::White);
    ball.setOutlineThickness(3.5);
    ball.setPosition(window.getSize().x/2 - ball.getRadius(), window.getSize().y/2 - ball.getRadius());

    int paddleMover = 1;

    double moverX = 1;
    double moverY = 1;
    int rando = 0;

    bool gamePause = false;
    bool gameOn = true;
    int score1Counter = 0, score2Counter = 0;

    backgroundMusic.play();
    // Game Loop
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        if(!gamePause && gameOn) {
            // Move Right Paddle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && paddle2.getPosition().y >= 0)
                paddle2.setPosition(paddle2.getPosition().x, paddle2.getPosition().y - paddleMover);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                     paddle2.getPosition().y + paddle2.getSize().y <= window.getSize().y)
                paddle2.setPosition(paddle2.getPosition().x, paddle2.getPosition().y + paddleMover);
            // Move Left Paddle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && paddle1.getPosition().y >= 0)
                paddle1.setPosition(paddle1.getPosition().x, paddle1.getPosition().y - paddleMover);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
                     paddle1.getPosition().y + paddle1.getSize().y <= window.getSize().y)
                paddle1.setPosition(paddle1.getPosition().x, paddle1.getPosition().y + paddleMover);
            // Move Ball
            if (ball.getPosition().x + ball.getRadius() * 2 <= window.getSize().x)
                ball.setPosition(ball.getPosition().x + moverX, ball.getPosition().y);
            if (ball.getPosition().y + ball.getRadius() * 2 <= window.getSize().y)
                ball.setPosition(ball.getPosition().x, ball.getPosition().y + moverY);
        }
        // Ball Bounds
        if(ball.getPosition().x  == paddle1.getPosition().x + paddle1.getSize().x && (ball.getPosition().y <= paddle1.getPosition().y + paddle1.getSize().y && ball.getPosition().y + ball.getRadius()*2 >= paddle1.getPosition().y)){
            soundPaddle1.play();
            moverX *= -1;
        } else if(ball.getPosition().x <= 0){
            score2Counter++;
            ball.setPosition(window.getSize().x/2 - ball.getRadius(), window.getSize().y/2 - ball.getRadius());
            moverX *= -1;
        }
        if(ball.getPosition().x + ball.getRadius()*2 == paddle2.getPosition().x && (ball.getPosition().y <= paddle2.getPosition().y + paddle2.getSize().y && ball.getPosition().y + ball.getRadius()*2 >= paddle2.getPosition().y)) {
            soundPaddle2.play();
            moverX *= -1;
        }
        if(ball.getPosition().x + ball.getRadius()*2 >= window.getSize().x){
            score1Counter++;
            ball.setPosition(window.getSize().x/2 - ball.getRadius(), window.getSize().y/2 - ball.getRadius());
            moverX *= -1;
        }
        if (ball.getPosition().y + ball.getRadius() * 2 >= window.getSize().y || ball.getPosition().y <= 0) {
            soundCollision.play();
            moverY *= -1;
        }
        // Update Scores
        score2.setString(std::to_string(score2Counter));
        score1.setString(std::to_string(score1Counter));
        // Check Winning Condition
        if (score1Counter >= 5 || score2Counter >= 5){
            ball.setOutlineColor(sf::Color::Black);
            ball.setFillColor(sf::Color::Black);
            ball.setPosition(window.getSize().x/2 - ball.getRadius(),window.getSize().y/2 - ball.getRadius());
            gameOn = false;
        }
        // Draw To Window
        window.clear(sf::Color::Black);
        window.draw(halfCourt);
        window.draw(halfCourtCircle);
        window.draw(ball);
        window.draw(paddle1);
        window.draw(paddle2);
        window.draw(score1);
        window.draw(score2);
        // Escape Bind
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        // Pause Game Binds
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
            gamePause = true;
            backgroundMusic.pause();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            if(gamePause)
                backgroundMusic.play();
            gamePause = false;
        }
        if(score2Counter == 5)
            window.draw(victor2);
        else if(score1Counter == 5)
            window.draw(victor1);
        window.display();

    }
    return 0;
}
