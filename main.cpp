#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "mouse test");
    sf::VertexArray graph(sf::Lines, 320);

    for(size_t i = 0; i < 320; ++i)
    {
        graph[i].position = sf::Vector2f(i*2, 300);
        graph[i].color = sf::Color::Red;
    }

    window.setFramerateLimit(100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(size_t i = 0; i < 319; ++i)
            graph[i].position.y = graph[i+1].position.y;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            graph[319].position.y = 180;
        else graph[319].position.y = 300;
        window.draw(graph);
        window.display();
    }

    return 0;
}
