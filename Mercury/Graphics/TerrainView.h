#pragma once

#include <SFML/Graphics.hpp>
#include "Graphics/CellView.h"

#include <vector>

namespace merc
{

class Terrain;

class TerrainView final : public sf::Drawable
{
    using TCellTextures = std::array<sf::Texture, std::size_t(CellType::Count)>;
    using TMap = std::vector<std::vector<CellView>>;
public:

    TerrainView(std::size_t x, std::size_t y);
    ~TerrainView() = default;

    void SetCenter(std::size_t shiftX, std::size_t shiftY);

    void Render(const Terrain& terrain);

    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:

    void InitializeTextures();
    void InitializeCells();

    sf::Texture& Texture(CellType type);

    std::size_t m_centerX{ 0 };
    std::size_t m_centerY{ 0 };

    std::size_t m_x{ 0 };
    std::size_t m_y{ 0 };

    TCellTextures m_cellTextures;
    sf::Texture m_sapper;
    sf::Texture m_collector;

    TMap m_mapView;
};

}
