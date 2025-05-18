#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

//Chess pieces png download:   https://commons.wikimedia.org/wiki/Category:SVG_chess_pieces
/*Todo
*Mouse input
* Custom Classes (pieces)
* sound
*/


void DrawChessBoard(sf::RenderWindow& window);



int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    //sf::RenderWindow window(desktop , "SFML works!", sf::State::Fullscreen);//Fullscreen
    sf::RenderWindow window(desktop, "SFML works!");
    window.setFramerateLimit(10);

    //Main Loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                std::cout << "new width: " << resized->size.x << std::endl;
                std::cout << "new height: " << resized->size.y << std::endl;
            }
        }

        window.clear();
        //window.clear(sf::Color::Black);  // Clear the whole window
        DrawChessBoard(window);
        window.display();

    }
    return 0;
}
    //Define



void DrawChessBoard(sf::RenderWindow& window) {
    //Initialize
    const int BoardSize = 8;
    float TileSize;
    float PosY;
    float PosX; 
    float SmallSize; //smaller window size

    //Define
    PosY = 0.f; //Supposed to start at y=0

    //Calculate TileSize
    sf::Vector2u windowSize = window.getSize();
    //Which Side is smaller?
    if (windowSize.y <= windowSize.x)
        SmallSize = windowSize.y;
    else
        SmallSize = windowSize.x;

    TileSize = SmallSize/ static_cast<float>(BoardSize);

    //shapes
    sf::RectangleShape square(sf::Vector2f({ TileSize, TileSize }));


    //drawing the board//
    for (int row = 0; row < BoardSize; ++row) {
        PosX = (windowSize.x - (TileSize * BoardSize)) / 2.f; // Reset to center horizontally
        for (int col = 0; col < BoardSize; ++col) {

            square.setPosition({ PosX,PosY });//setposition
            if ((row + col) % 2 == 0)//set color
                square.setFillColor(sf::Color::White);
            else
                square.setFillColor(sf::Color(118, 150, 86));

            window.draw(square);
            PosX += TileSize;   //move it accordingly on the x coordinate
        }
        PosY += TileSize; // Move to the next row
    }

    //////////////////////////////////////////
    std::cout << "Width: " << windowSize.x << std::endl;
    std::cout << "Height:" << windowSize.y << std::endl;
    std::cout << "TileSize:" << TileSize << std::endl;
}