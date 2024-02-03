#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#define Pi = 3.14150

class CrankSlider {
private:
    //Lengths
    float Ground;
    float Input;
    float Rocker;
    // Ground Angle
    float Theta1;
    sf::Vector2f Origin;
    sf::RectangleShape Slider;
    float Ax; float Ay; float Bx; float By;
    // Slider Position [x,y]
    sf::Vertex Joint_A;
    sf::Vertex Joint_B;
    //std::vector<int> Theta2;

public:

    CrankSlider(float ground, float input, float rocker, float theta1, float Ox, float Oy)
    {
        Ground = ground;
        Input = input;
        Rocker = rocker;
        Theta1 = theta1;
        Origin.x = Ox;
        Origin.y = Oy;
        Ax = 0; Ay = 0; Bx = 0; By = 0;

        Slider = sf::RectangleShape(sf::Vector2f(10,30));
        Joint_A = sf::Vertex(sf::Vector2f(Ax, Ay));
        Joint_B = sf::Vertex(sf::Vector2f(Bx, By));
    }

    void Simulate() 
    {
        std::vector<int> theta2;
        std::vector<float>theta3;
        int pi = 3.14159;

        for (int i = 0; i <= 360; i++)
        {
            theta2[i] = i * pi / 180;
            theta3[i] = asin(Input * sin(theta2[i]) / Rocker);
        }

    }

    void Render(sf::RenderWindow& window)
    {
        window.draw();
        window
    }


};




int main()
{
    // Create a render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangle Drawing");

    CrankSlider Linkage1(10, 10, 10, 10, 10, 10);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw();
        window.display();
    }

    return 0;
}
