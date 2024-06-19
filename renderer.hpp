
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "fractalPentagon.hpp"

class Renderer{
public:
    explicit
    Renderer(sf::RenderTarget& window_, fractalPentagon& fractal_)
        : window{window_}
        , fractal{fractal_}{
            width = window.getSize().x;
            height = window.getSize().y;
        }
    Renderer(sf::RenderTarget& window_, fractalPentagon& fractal, int width_, int height_)
        : window{window_}
        , fractal{fractal}
        , width{width_}
        , height{height_}
    {}

    void render(){
        show_fractal();
    }

    void drawThickLine(sf::Vector2f point1, sf::Vector2f point2, float thickness, sf::Color color) {
        float length = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
        float angle = atan2(point2.y - point1.y, point2.x - point1.x) * 180 / M_PI;

        sf::RectangleShape line(sf::Vector2f(length, thickness));
        line.setPosition(point1);
        line.setRotation(angle);
        line.setFillColor(color);

        window.draw(line);
    }

    void show_fractal(){
        for (auto& point : fractal.corners){
            sf::CircleShape pointShape(10);
            pointShape.setFillColor(sf::Color::Black);
            pointShape.setPosition(point.x + 300, point.y);
            window.draw(pointShape);
        }

        for (auto& point : fractal.fractalPoints){
            sf::CircleShape pointShape(2);
            pointShape.setFillColor(sf::Color::Black);
            pointShape.setPosition(point.x + 300, point.y);
            window.draw(pointShape);
        }

        sf::CircleShape pointShape(12);
        pointShape.setFillColor(sf::Color::Green);
        pointShape.setPosition(fractal.currentPoint.x + 300, fractal.currentPoint.y);
        window.draw(pointShape);

        sf::CircleShape pointShape2(12);
        pointShape2.setFillColor(sf::Color::Yellow);
        pointShape2.setPosition(fractal.secondPoint.x + 300, fractal.secondPoint.y);
        window.draw(pointShape2);

        auto& line = fractal.line;
        drawThickLine(sf::Vector2f(line.first.x + 300, line.first.y), sf::Vector2f(line.second.x + 300, line.second.y), 5, sf::Color::Blue);

    }

    void render_text(const std::string& text, int size, int x, int y, std::string& font_path, sf::Color color){
        sf::Text sf_text;
        sf::Font font;
        if(!font.loadFromFile(font_path)){
            std::cerr << "Error loading font" << std::endl;
            return;
        }
        sf_text.setFont(font);
        sf_text.setString(text);
        sf_text.setCharacterSize(size);
        sf_text.setFillColor(color);
        sf_text.setPosition(x, y);
        window.draw(sf_text);
    }

    void setWidth(int width_){
        width = width_;
    }
    void setHeight(int height_){
        height = height_;
    }
    [[nodiscard]]
    int getWidth() const{
        return width;
    }
    [[nodiscard]]
    int getHeight() const{
        return height;
    }


private:
    int width = 800;
    int height = 600;
    fractalPentagon& fractal;
    sf::RenderTarget& window;
};
