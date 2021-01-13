#pragma once
#include "IView.h"
#include <memory>
#include <thread>
#include <atomic>

namespace sf
{
class RenderWindow;
class Text;
class Font;
}

namespace merc
{

struct GameInterface;

class SfmlView final : public IView
{
public:
    SfmlView();
    virtual ~SfmlView();

    virtual const std::string& ScanConsole() override;

    virtual void Render(const Terrain& terrain) override;

    virtual void Open() override;

    virtual void Close() override;
private:

    void CreateContext();
    void Present() const;

    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<sf::Text> m_consoleText;
    std::unique_ptr<sf::Font> m_font;

    std::string m_consoleInput;

    enum ConsoleCommand : unsigned char
    {
        Backspace = 8,
        Enter = 13,

        Count,
    };
};

}
