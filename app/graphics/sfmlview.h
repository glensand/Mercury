/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "iview.h"
#include <memory>
#include <chrono>

namespace sf
{
class RenderWindow;
class Text;
class Font;
}

namespace merc
{

class TerrainView;

class SfmlView final : public IView
{
public:
    SfmlView();
    virtual ~SfmlView();

    virtual const std::string& ScanConsole() override;

    virtual void Render(const Player& player) override;

    virtual void Present() override;

    virtual void Open() override;

    virtual void Close() override;
private:

    void CreateContext();

    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<sf::Text> m_consoleText;
    std::unique_ptr<sf::Text> m_score;
    std::unique_ptr<sf::Font> m_font;
    std::unique_ptr<TerrainView> m_terrain;

    std::string m_consoleInput;

    enum ConsoleCommand : unsigned char
    {
        Backspace = 8,
        Enter = 13,

        Count,
    };

    std::chrono::steady_clock::time_point m_lastPresent;
};

}
