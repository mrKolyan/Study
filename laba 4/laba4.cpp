#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

const unsigned int width = 1366;
const unsigned int height = 768;

class mytext {
private:
    sf::Font font1;
    sf::Font font2;
    sf::Font font3;
    sf::Font font4;
    sf::Text m_text;

    sf::Clock clock; 

    std::string m_str;
    std::string output; 
    std::string digits = " 0123456789";
 
    int m_num = 0;
    bool flag;
    bool aud = 0;
    float m_time;
    float m_x = 50;
    float m_y = 350;
    float m_dt;
    
    sf::SoundBuffer audio;
    sf::Sound sound;
public:
    mytext() = default;
    mytext(std::string str, float t) {
        setup(str,t);
    }
    int setup(std::string str, float t) {
        if (!font1.loadFromFile("fonts/arial.ttf")) {
            std::cout << "font error1";
            return 0;
        }
        if (!font2.loadFromFile("fonts/Gabriola.ttf")) {
            std::cout << "font error2";
            return 0;
        }
        if (!font3.loadFromFile("fonts/impact.ttf")) {
            std::cout << "font error3";
            return 0;
        }
        if (!font4.loadFromFile("fonts/courbd.ttf")) {
            std::cout << "font error4";
            return 0;
        }
        if (!audio.loadFromFile("sound/applause.wav")) {
            std::cout << "audio error";
            return -1;
        }
        sound.setBuffer(audio);
        m_time = t;
        m_str = str;
        m_text.setColor(sf::Color(230, 230, 230, 255));
        m_text.setPosition(m_x, m_y);
        m_text.setFont(font1);
        m_text.setCharacterSize(50);
        m_dt = m_time / m_str.length();
        return 1;
    }
    void verbAnimationText() {
        flag = 1;
        if (output.length() < m_str.length()) {
            if (clock.getElapsedTime().asSeconds() > m_dt) {
                output.append(std::string(1, m_str[m_num]));
                clock.restart();
                m_text.setString(output);
                for (int i = 0; i < 10; i++) {
                    if (m_str[m_num] == digits[i])
                        flag = 0;
                }
                if (flag) {
                    switch ((m_num + 17) % 4) {
                    case 0:
                        m_text.setFont(font1);
                        break;
                    case 1:
                        m_text.setFont(font2);
                        break;
                    case 2:
                        m_text.setFont(font3);
                        break;
                    case 3:
                        m_text.setFont(font4);
                        break;
                    }
                }
                flag = 1;
                m_num++;
            }
        }
        else if (aud) {
            sound.play();
            aud = 0;
        }
    }
    sf::Text get() {
        return m_text;
    }
};



int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(width, height), "LABA WORKS!!!");
    window.display();
    mytext text1(std::string("aboba    aboba4565aboba"), 10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color());
        
        text1.verbAnimationText();
        window.draw(text1.get());

        window.display();
        } 
    return 0;
}
