#include "sfmlview.h"
#include <SFML/Graphics.hpp>
#include "graphics/TerrainView.h"
#include "app/gameinterface.h"
#include "Player/player.h"
#include "world/robot/robot.h"
#include "world/iworld.h"

#include <thread>

namespace
{
constexpr std::size_t MovesPerSecond{ 3 };
constexpr std::size_t FrameTime{ 1000  / MovesPerSecond };
}

namespace
{
// TODO:: move out (config)
constexpr std::size_t TerrainPositionX{ 100 };
constexpr std::size_t TerrainPositionY{ 10 };
}


namespace merc
{

SfmlView::SfmlView()
{
    m_lastPresent = std::chrono::steady_clock::now();
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
            m_consoleInput.push_back(char(event.text.unicode));
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

void SfmlView::Render(const Player& player)
{
    const auto [positionX, positionY] = player.GetCollector().GetPosition();
    m_terrain->SetCenter(positionX, positionY);
    m_terrain->Render(player.GetExploredTerrain());

    m_score->setString("Score: " + std::to_string(player.GetCollector().GetScore()));
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
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 900), "Mercury",
        sf::Style::Titlebar | sf::Style::Close);

    m_window->setVerticalSyncEnabled(true);
    m_font = std::make_unique<sf::Font>();
    m_font->loadFromFile("../Resources/sansation.ttf");

    // Create the instructions text
    m_consoleText = std::make_unique<sf::Text>("Console input: ", *m_font, 20);
    m_consoleText->setPosition(80, 835);
    m_consoleText->setFillColor(sf::Color(255, 255, 255));

    m_score = std::make_unique<sf::Text>("Score: 0", *m_font, 20);
    m_score->setPosition(80, 865);
    m_score->setFillColor(sf::Color(255, 255, 255));

    m_terrain = std::make_unique<TerrainView>(TerrainPositionX, TerrainPositionY);
}

void SfmlView::Present()
{
    m_window->clear(sf::Color(255, 128, 0));

    m_window->draw(*m_consoleText);
    m_window->draw(*m_score);

    m_window->draw(*m_terrain);

    m_window->display();

    const auto now = std::chrono::steady_clock::now();
    const auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_lastPresent);
    if (frameTime.count() < FrameTime)
    {
        const auto sleepTime = FrameTime - frameTime.count();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    }
    m_lastPresent = now;
}

}
