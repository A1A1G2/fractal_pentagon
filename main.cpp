#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utils/utils.hpp"
#include "fractalPentagon.hpp"
#include "renderer.hpp"

constexpr int screen_width = 1600;
constexpr int screen_height = 1200;

void speedUp(float* period){
    (*period) = (*period) *0.9;
}
void speedDown(float* period){
    (*period) = (*period) *1.1;
}

int main() {
    sf::Clock clock;
    sf::ContextSettings sf_settings;
    sf_settings.antialiasingLevel = 1;

    sf::Color backGrounColor(sf::Color(200,200,200));

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "SFML Text Example");

    //intialize fractal
    fractalPentagon fractal(1000);
    float iterPeriod = 0.001f;

    Renderer renderer(window, fractal);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            switch (event.key.code){
                case sf::Keyboard::Up:
                    speedUp(&iterPeriod);
                    break;
                case sf::Keyboard::Down:
                    speedDown(&iterPeriod);
                    break;
            }
        }

        if (clock.getElapsedTime().asSeconds() > iterPeriod){
            fractal.iterateFractal();
            clock.restart();
        }

        window.clear(backGrounColor);
        renderer.render();
        window.display();
    }

    return 0;
}



