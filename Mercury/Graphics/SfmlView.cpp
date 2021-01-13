#include "SfmlView.h"
#include <SFML/Graphics.hpp>

namespace merc
{

SfmlView::SfmlView()
{
    
}

SfmlView::~SfmlView()
{
    Close();
}

const std::string& SfmlView::ScanConsole()
{
    sf::Event event{ };
    m_consoleInput.clear();
    Present();
    while(m_window->waitEvent(event))
    {
        if(event.type != sf::Event::TextEntered || event.text.unicode > 128)
            continue;

        if(event.text.unicode != Backspace)
            m_consoleInput.push_back(event.text.unicode);
        else if (!m_consoleInput.empty())
            m_consoleInput.pop_back();

        m_consoleText->setString("Console input: " + m_consoleInput);

        if(event.text.unicode == Enter)
            break;

        Present();
    }

    m_consoleText->setString("Console input: ");
    return m_consoleInput;
}

void SfmlView::Render(const Terrain& terrain)
{

}

void SfmlView::Open()
{
    CreateContext();
    Present();
}

void SfmlView::Close()
{
    m_window->close();
}

void SfmlView::CreateContext()
{
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1200, 800), "Mercury",
        sf::Style::Titlebar | sf::Style::Close);

    m_window->setVerticalSyncEnabled(true);
    m_font = std::make_unique<sf::Font>();
    m_font->loadFromFile("../Resources/sansation.ttf");

    // Create the instructions text
    m_consoleText = std::make_unique<sf::Text>("Console input: ", *m_font, 20);
    m_consoleText->setPosition(80, 755);
    m_consoleText->setFillColor(sf::Color(255, 255, 255));
}

void SfmlView::Present() const
{
    // Clear the window
    m_window->clear(sf::Color(255, 128, 0));

    m_window->draw(*m_consoleText);

    m_window->display();
}

}
