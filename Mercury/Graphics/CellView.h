/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "World/Terrain/Cell.h"
#include <array>

namespace merc
{

class Cell;
class Robot;

class CellView final : public sf::Drawable
{
    using TCellTextures = std::array<sf::Texture, std::size_t(CellType::Count)>;
public:

    CellView(TCellTextures& cellTextures, sf::Texture& collector, sf::Texture& sapper);
    ~CellView() = default;

    void Initialize(std::size_t x, std::size_t y);

    void Render(const Cell& cell);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    void InitializeShape();

    void RenderRobot(const Robot& robot);
    void RenderCell(const Cell& cell);

    sf::Texture& Texture(CellType type) const;

    TCellTextures& m_cellTextures;

    sf::Texture& m_collector;
    sf::Texture& m_sapper;

    sf::Sprite m_shape;

    std::size_t m_x{ 0 };
    std::size_t m_y{ 0 };
};

}
