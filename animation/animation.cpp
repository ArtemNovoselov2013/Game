#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>

bool checkHitbox(sf::RectangleShape& obj_1, sf::RectangleShape& obj_2)
{
    int x_1 = obj_1.getPosition().x;
    int y_1 = obj_1.getPosition().y;

    int x_2 = obj_2.getPosition().x;
    int y_2 = obj_2.getPosition().y;

    int width_1 = obj_1.getSize().x;
    int height_1 = obj_1.getSize().y;

    int width_2 = obj_2.getSize().x;
    int height_2 = obj_2.getSize().y;

    if ((x_1 <= x_2 && x_2 <= x_1 + width_1) &&
        (y_1 <= y_2 + height_2 && y_2 + height_2 <= y_1 + height_1))
    {
        return true;
    }

    if ((x_1 <= x_2+width_2 && x_2+width_2 <= x_1 + width_1) &&
        (y_1 <= y_2 + height_2 && y_2 + height_2 <= y_1 + height_1))
    {
        return true;
    }

    return false;
}

int main()
{
    sf::Font font;
    font.loadFromFile("mine_font.otf");

    int x = 800;
    int y = 600;

    sf::RenderWindow window(sf::VideoMode(x,y), "Animation");

    // =========== ТЕКСТУРЫ ============

    // РЫЦАРЬ
    sf::RectangleShape knight(sf::Vector2f(100, 100));

    std::vector<sf::Texture> textures_r;

    sf::Texture kT_r_1;
    kT_r_1.loadFromFile("knight/go_right/1.png");

    sf::Texture kT_r_2;
    kT_r_2.loadFromFile("knight/go_right/2.png");

    sf::Texture kT_r_3;
    kT_r_3.loadFromFile("knight/go_right/3.png");
    
    sf::Texture kT_r_4;
    kT_r_4.loadFromFile("knight/go_right/4.png");

    sf::Texture kT_r_5;
    kT_r_5.loadFromFile("knight/go_right/5.png");

    sf::Texture kT_r_6;
    kT_r_6.loadFromFile("knight/go_right/6.png");

    sf::Texture kT_r_7;
    kT_r_7.loadFromFile("knight/go_right/7.png");

    sf::Texture kT_r_8;
    kT_r_8.loadFromFile("knight/go_right/8.png");

    textures_r.push_back(kT_r_1);
    textures_r.push_back(kT_r_2);
    textures_r.push_back(kT_r_3);
    textures_r.push_back(kT_r_4);
    textures_r.push_back(kT_r_5);
    textures_r.push_back(kT_r_6);
    textures_r.push_back(kT_r_7);
    textures_r.push_back(kT_r_8);
    
    std::vector<sf::Texture> textures_l;

    sf::Texture kT_l_1;
    kT_l_1.loadFromFile("knight/go_left/1.png");

    sf::Texture kT_l_2;
    kT_l_2.loadFromFile("knight/go_left/2.png");

    sf::Texture kT_l_3;
    kT_l_3.loadFromFile("knight/go_left/3.png");

    sf::Texture kT_l_4;
    kT_l_4.loadFromFile("knight/go_left/4.png");

    sf::Texture kT_l_5;
    kT_l_5.loadFromFile("knight/go_left/5.png");

    sf::Texture kT_l_6;
    kT_l_6.loadFromFile("knight/go_left/6.png");

    sf::Texture kT_l_7;
    kT_l_7.loadFromFile("knight/go_left/7.png");

    sf::Texture kT_l_8;
    kT_l_8.loadFromFile("knight/go_left/8.png");

    textures_l.push_back(kT_l_1);
    textures_l.push_back(kT_l_2);
    textures_l.push_back(kT_l_3);
    textures_l.push_back(kT_l_4);
    textures_l.push_back(kT_l_5);
    textures_l.push_back(kT_l_6);
    textures_l.push_back(kT_l_7);
    textures_l.push_back(kT_l_8);

    sf::Texture kD_r;
    kD_r.loadFromFile("knight/down.png");

    // ЗЛОДЕЙ
    sf::RectangleShape enemy(sf::Vector2f(100, 100));

    std::vector<sf::Texture> etextures_r;

    sf::Texture ekT_r_1;
    ekT_r_1.loadFromFile("eknight/go_right/1.png");

    sf::Texture ekT_r_2;
    ekT_r_2.loadFromFile("eknight/go_right/2.png");

    sf::Texture ekT_r_3;
    ekT_r_3.loadFromFile("eknight/go_right/3.png");

    sf::Texture ekT_r_4;
    ekT_r_4.loadFromFile("eknight/go_right/4.png");

    sf::Texture ekT_r_5;
    ekT_r_5.loadFromFile("eknight/go_right/5.png");

    sf::Texture ekT_r_6;
    ekT_r_6.loadFromFile("eknight/go_right/6.png");

    sf::Texture ekT_r_7;
    ekT_r_7.loadFromFile("eknight/go_right/7.png");

    sf::Texture ekT_r_8;
    ekT_r_8.loadFromFile("eknight/go_right/8.png");

    etextures_r.push_back(ekT_r_1);
    etextures_r.push_back(ekT_r_2);
    etextures_r.push_back(ekT_r_3);
    etextures_r.push_back(ekT_r_4);
    etextures_r.push_back(ekT_r_5);
    etextures_r.push_back(ekT_r_6);
    etextures_r.push_back(ekT_r_7);
    etextures_r.push_back(ekT_r_8);

    std::vector<sf::Texture> etextures_l;

    sf::Texture ekT_l_1;
    ekT_l_1.loadFromFile("eknight/go_left/1.png");

    sf::Texture ekT_l_2;
    ekT_l_2.loadFromFile("eknight/go_left/2.png");

    sf::Texture ekT_l_3;
    ekT_l_3.loadFromFile("eknight/go_left/3.png");

    sf::Texture ekT_l_4;
    ekT_l_4.loadFromFile("eknight/go_left/4.png");

    sf::Texture ekT_l_5;
    ekT_l_5.loadFromFile("eknight/go_left/5.png");

    sf::Texture ekT_l_6;
    ekT_l_6.loadFromFile("eknight/go_left/6.png");

    sf::Texture ekT_l_7;
    ekT_l_7.loadFromFile("eknight/go_left/7.png");

    sf::Texture ekT_l_8;
    ekT_l_8.loadFromFile("eknight/go_left/8.png");

    etextures_l.push_back(ekT_l_1);
    etextures_l.push_back(ekT_l_2);
    etextures_l.push_back(ekT_l_3);
    etextures_l.push_back(ekT_l_4);
    etextures_l.push_back(ekT_l_5);
    etextures_l.push_back(ekT_l_6);
    etextures_l.push_back(ekT_l_7);
    etextures_l.push_back(ekT_l_8);

    sf::Texture ekD_r;
    ekD_r.loadFromFile("eknight/down.png");

    enemy.setTexture(&etextures_l[0]);

    // ЗЕМЛЯ
    sf::RectangleShape ground(sf::Vector2f(x, 200));
    ground.setPosition(0, y - 200);
    ground.setFillColor(sf::Color::Green);

    // HP левый
    sf::RectangleShape HP1(sf::Vector2f(100, 25));
    
    std::vector<sf::Texture> HP1textures;

    sf::Texture hp1_1;
    hp1_1.loadFromFile("heart/1.png");

    sf::Texture hp1_2;
    hp1_2.loadFromFile("heart/2.png");

    sf::Texture hp1_3;
    hp1_3.loadFromFile("heart/3.png");

    sf::Texture hp1_4;
    hp1_4.loadFromFile("heart/4.png");

    HP1textures.push_back(hp1_1);

    HP1textures.push_back(hp1_2);

    HP1textures.push_back(hp1_3);

    HP1textures.push_back(hp1_4);


    // HP правый
    sf::RectangleShape HP2(sf::Vector2f(100, 25));
    HP2.setPosition(x - 100, 0);

    std::vector<sf::Texture> HP2textures;

    sf::Texture hp2_1;
    hp2_1.loadFromFile("heart2/1.png");

    sf::Texture hp2_2;
    hp2_2.loadFromFile("heart2/2.png");

    sf::Texture hp2_3;
    hp2_3.loadFromFile("heart2/3.png");

    sf::Texture hp2_4;
    hp2_4.loadFromFile("heart2/4.png");

    HP2textures.push_back(hp2_1);

    HP2textures.push_back(hp2_2);

    HP2textures.push_back(hp2_3);

    HP2textures.push_back(hp2_4);

    // FIREBALL
    sf::RectangleShape FB1(sf::Vector2f(60, 40));
    
    sf::Texture fb1;
    fb1.loadFromFile("fireball/fireball1.png");

    FB1.setTexture(&fb1);
    FB1.setPosition(-50, -50);

    sf::RectangleShape FB2(sf::Vector2f(60, 40));

    sf::Texture fb2;
    fb2.loadFromFile("fireball/fireball2.png");

    FB2.setTexture(&fb2);
    FB2.setPosition(-50, -50);

    // =========== ПЕРЕМЕННЫЕ ============
    
    // Левый
    int kx = 0;
    int ky = y - 300;
    knight.setPosition(kx, ky);

    bool jump = false;
    bool down = false;
    int t = -14;
    int t_n = 0;

    int hp1 = 4;

    // Правый
    int ekx = x/2;
    int eky = y - 300;
    enemy.setPosition(ekx, eky);

    bool ejump = false;
    bool edown = false;
    int et = -14;
    int et_n = 0;

    int hp2 = 4;

    // fireball
    bool fire1 = false;

    bool fire2 = false;

    // =========== ГЛАВНЫЙ ЦИКЛ ============
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ============================== РЫЦАРЬ ==============================

        // Прыжок
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            jump = true;
        }

        if (jump)
        {
            ky = y - 496 + t * t;
            t = t + 1;

            knight.setPosition(kx, ky);
            if (t == 15) {
                jump = false;
                t = -14;
            }
        }


        // Вниз
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            knight.setTexture(&kD_r);
            knight.setPosition(kx, ky+20);
            down = true;
        }

        else
        {
            down = false;
        }

        
        if (down == false)
        { 
            knight.setPosition(kx, ky);

            // Вправо
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                if (kx+2<=x-100)
                    kx = kx + 2;

                knight.setPosition(kx, ky);

                knight.setTexture(&textures_r[t_n]);
                t_n++;
                if (t_n == 8) {
                    t_n = 0;
                }
            }
            else {
                knight.setTexture(&textures_r[0]);
            }

            // Влево
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if (kx-2>=0)
                    kx = kx - 2;
                knight.setPosition(kx, ky);

                knight.setTexture(&textures_l[t_n]);
                t_n++;
                if (t_n == 8) {
                    t_n = 0;
                }
            }
        }

        // ============================== ЗЛОДЕЙ ==============================
        
        // Прыжок
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            ejump = true;
        }

        if (ejump)
        {
            eky = y - 496 + et * et;
            et = et + 1;

            enemy.setPosition(ekx, eky);
            if (et == 15) {
                ejump = false;
                et = -14;
            }
        }


        // Вниз
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            enemy.setTexture(&ekD_r);
            enemy.setPosition(ekx, eky + 20);
            edown = true;
        }

        else
        {
            edown = false;
        }


        if (edown == false)
        {
            enemy.setPosition(ekx, eky);

            // Вправо
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (ekx + 2 <= x - 100)
                    ekx = ekx + 2;

                enemy.setPosition(ekx, eky);

                enemy.setTexture(&etextures_r[et_n]);
                et_n++;
                if (et_n == 8) {
                    et_n = 0;
                }
            }
            else {
                enemy.setTexture(&etextures_l[0]);
            }

            // Влево
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (ekx-2>=0)
                    ekx = ekx - 2;

                enemy.setPosition(ekx, eky);

                enemy.setTexture(&etextures_l[et_n]);
                et_n++;
                if (et_n == 8) {
                    et_n = 0;
                }
            }
        }

        // ============================== FIREBALL ==============================

        //FB1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && fire1==false)
        {
            fire1 = true;
            FB1.setPosition(kx, ky+30);
        }

        if (fire1 == true)
        {
            int fx = FB1.getPosition().x;
            int fy = FB1.getPosition().y;
            FB1.setPosition(fx + 5, fy);
        
            if (fx > x)
            {
                fire1 = false;
                FB1.setPosition(-50, -50);
            }
        }

        if (checkHitbox(enemy, FB1) == true && edown==false)
        {
            hp2 = hp2 - 1;
            fire1 = false;
            FB1.setPosition(-50, -50);
        }

        //FB2
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && fire2 == false)
        {
            fire2 = true;
            FB2.setPosition(ekx, eky + 30);
        }

        if (fire2 == true)
        {
            int fx = FB2.getPosition().x;
            int fy = FB2.getPosition().y;
            FB2.setPosition(fx - 5, fy);

            if (fx < 0)
            {
                fire2 = false;
                FB2.setPosition(-50, -50);
            }
        }

        if (checkHitbox(knight, FB2) == true && down == false)
        {
            hp1 = hp1 - 1;
            fire2 = false;
            FB2.setPosition(-50, -50);
        }

        // ============================== HP ==============================
        
        HP1.setTexture(& HP1textures[hp1 - 1]);

        HP2.setTexture(&HP2textures[hp2 - 1]);

        // Отрисовка
        window.clear();

        if (hp1 <= 0)
        {
            sf::Text wintext;
            wintext.setFont(font);
            wintext.setString("PLAYER 2 WON!");
            wintext.setPosition(250, 50);
            window.draw(wintext);

            HP1.setPosition(-50, -50);

            sf::Texture fall1;
            fall1.loadFromFile("knight/fall.png");
            knight.setTexture(&fall1);
            window.draw(knight);
        }
        else
            window.draw(knight);

        if (hp2 <= 0)
        {
            sf::Text wintext;
            wintext.setFont(font);
            wintext.setString("PLAYER 1 WON!");
            wintext.setPosition(250, 50);
            window.draw(wintext);

            HP2.setPosition(-50, -50);

            sf::Texture fall2;
            fall2.loadFromFile("eknight/fall.png");
            enemy.setTexture(&fall2);
            window.draw(enemy);
        }
        else
            window.draw(enemy);

        window.draw(FB1);
        window.draw(FB2);
        window.draw(ground);
        window.draw(HP1);
        window.draw(HP2);

        window.display();

        if (hp1 <= 0 || hp2 <= 0)
        {
            Sleep(3000);
            window.close();
        }

        Sleep (10);
    }
}