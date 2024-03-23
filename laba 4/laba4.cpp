#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

const unsigned int width = 1366;
const unsigned int height = 768;

class mytext {
private:
    sf::Font fonts[4];

    sf::Text m_text;

    sf::Clock clock; 
    sf::Clock clock2;

    std::string m_str;
    std::string output; 
    std::string digits = " 0123456789";
 
    int m_num = 0;
    bool flag;
    bool aud = 1;
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
        
        for (int i = 0; i < 4; i++) {
            if (!fonts[i].loadFromFile(std::string("fonts/font" + std::to_string(i)+ ".ttf"))) {
                std::cout << "font error";
            }
        }
       
       
        sound.setBuffer(audio);
        m_time = t;
        m_str = str;
        m_text.setColor(sf::Color(230, 230, 230, 255));
        m_text.setPosition(m_x, m_y);
        m_text.setFont(fonts[0]);
        m_text.setCharacterSize(50);
        m_dt = m_time / m_str.length();
        clock2.restart();
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
                    m_text.setFont(fonts[m_num % 4]);
                }
                flag = 1;
                m_num++;
            }
        }
        else if (aud) {
            sound.play();
            aud = 0;
            std::cout << clock2.getElapsedTime().asSeconds();
        }
    }
    sf::Text get() {
        return m_text;
    }
};



int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "LABA WORKS!!!");
    window.display();
    mytext text1(std::string("aboba    aboba4565aboba"), 15);
    sf::Clock clock;
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
