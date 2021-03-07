#include "terrainview.h"
#include "world/terrain/terrain.h"

namespace
{
// TODO:: move out (config)
constexpr std::size_t ViewWidth{ 800 }; // pixels
constexpr std::size_t ViewHeight{ 800 }; // pixels

constexpr std::size_t CellCountX{ 20 };
constexpr std::size_t CellCountY{ 20 };
}

namespace merc
{

TerrainView::TerrainView(std::size_t x, std::size_t y)
    : m_x(x)
    , m_y(y)
{
    InitializeTextures();
    InitializeCells();
}

void TerrainView::SetCenter(std::size_t shiftX, std::size_t shiftY)
{
    m_centerX = shiftX;
    m_centerY = shiftY;
}

void TerrainView::Render(const Terrain& terrain)
{
    // TODO:: compute center more accurate
    const auto lastCellX = std::min(terrain.GetSizeX(), m_centerX + CellCountX / 2);
    const auto lastCellY = std::min(terrain.GetSizeY(), m_centerY + CellCountY / 2);

    const auto initialiX = CellCountX > lastCellX ? 0 : lastCellX - CellCountX;
    auto cellX = initialiX;
    auto cellY = CellCountY > lastCellY ? 0 : lastCellY - CellCountY;

    auto&& cellRobot = terrain.GetCell(m_centerX, m_centerY);

    for(auto&& viewRow : m_mapView)
    {
        for(auto&& view : viewRow)
        {
            const auto& cell = terrain.GetCell(cellX, cellY);
            view.Render(cell);
            ++cellX;
        }
        ++cellY;
        cellX = initialiX;
    }
}

void TerrainView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto&& cellRow : m_mapView)
    {
        for(auto&& cellView : cellRow)
        {
            cellView.draw(target, states);
        }
    }
}

void TerrainView::InitializeTextures()
{
    Texture(CellType::Bomb).loadFromFile("../Resources/bomb.png");
    Texture(CellType::Rock).loadFromFile("../Resources/rock.png");
    Texture(CellType::Apple).loadFromFile("../Resources/apple.png");
    Texture(CellType::Empty).loadFromFile("../Resources/empty.png");
    Texture(CellType::Unknown).loadFromFile("../Resources/unknown.png");

    m_collector.loadFromFile("../Resources/collector.png");
    m_sapper.loadFromFile("../Resources/sapper.png");
}

void TerrainView::InitializeCells()
{
    constexpr auto stepX = ViewWidth / CellCountX;
    constexpr auto stepY = ViewHeight / CellCountY;

    m_mapView = TMap(CellCountY, std::vector<CellView>(CellCountX, 
        CellView(m_cellTextures, m_collector, m_sapper))
    );

    std::size_t curX = { m_x };
    std::size_t curY = { m_y };
    for(auto&& row : m_mapView)
    {
        for(auto&& cell : row)
        {
            cell.Initialize(curX, curY);
            curX += stepX;
        }
        curY += stepY;
        curX = m_x;
    }
}

sf::Texture& TerrainView::Texture(CellType type)
{
    return m_cellTextures[std::size_t(type)];
}

}
