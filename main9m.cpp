#include <iostream>
#include <D:/uroki/New/SFML-2.4.2/include/SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include <fstream>
#include <list>
#include "map9.h"
#include "Singleton.h"
#include "Enemy.h"

#include <string>
#include <queue>
#include <memory>

int main()
{

    RenderWindow window(sf::VideoMode(800, 800), "Game");

    int TileMap[size_map][size_map] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 7, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 3, 3, 1},
            {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 3, 1},
            {1, 1, 1, 1, 1, 1, 2, 1, 3, 3, 3, 3, 3, 3, 1, 2, 1, 3, 3, 1},
            {1, 1, 3, 3, 1, 1, 2, 1, 3, 3, 3, 3, 3, 3, 1, 2, 1, 3, 3, 1},
            {1, 1, 3, 1, 1, 1, 2, 1, 3, 3, 3, 3, 3, 3, 1, 2, 1, 3, 3, 1},
            {1, 1, 3, 1, 2, 2, 2, 1, 3, 3, 3, 3, 3, 3, 1, 2, 1, 3, 3, 1},
            {1, 1, 3, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1},
            {1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1},
            {1, 1, 1, 1, 2, 2, 2, 1, 1, 8, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1},
            {1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 2, 1, 1, 1},
            {1, 1, 3, 1, 2, 2, 2, 2, 2, 2, 2, 9, 1, 3, 3, 1, 2, 2, 2, 2},
            {1, 1, 3, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 3, 3, 1, 2, 1, 1, 2},
            {1, 1, 3, 3, 1, 2, 1, 3, 1, 1, 1, 2, 1, 3, 3, 1, 2, 2, 2, 2},
            {1, 1, 3, 3, 1, 2, 1, 3, 1, 2, 2, 2, 1, 3, 3, 1, 2, 1, 1, 1},
            {1, 1, 3, 3, 1, 2, 1, 3, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 3, 3},
            {1, 1, 3, 3, 1, 2, 1, 3, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 3, 3},
            {1, 1, 3, 3, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1},
            {1, 1, 1, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

        };

    int **masiv_c = new int *[size_map];
    for (int i = 0; i < size_map; i++)
    {
        masiv_c[i] = new int[size_map];
    }
    for (int i = 0; i < size_map; i++)
    {
        for (int j = 0; j < size_map; j++)
        {
            masiv_c[i][j] = TileMap[i][j];
        }
    }
    // Mapa *kart1 = new Mapa{masiv_c, size_map, size_map};

    Singleton &instance = Singleton::Instance();

    size_t str2 = instance.insert_funk(instance, "pp.png");
    size_t str1 = instance.insert_funk(instance, "Hero.png");

    std::unique_ptr<Mapa> kart = std::unique_ptr<Mapa>(new Mapa(masiv_c, size_map, size_map, str2, instance));
    kart->call_different_funk(kart, str1, instance);
    cout << "  ";
    cout << str1;
    cout << "  ";
    cout << str2;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        kart->draw_all_enemy(kart, window);
    }
    return 0;
}