#include <fstream>

void GenerateMap(size_t w, size_t h, std::ostream& file)
{
    file << h << " " << w << std::endl;

    for (std::size_t r = 0; r < h; r++) 
    {
        for (std::size_t c = 0; c < w; c++) 
        {
            int type = std::rand() % 10;

            if (type == 2) 
                file << "b";
            else if (type == 6) 
                file << "#";
            else if (type == 8) 
                file << "a";
            else 
                file << "*";
        }
        file << std::endl;
    }
}

int main()
{
    constexpr std::size_t sizeX{ 1000 };
    constexpr std::size_t sizeY{ 1000 };

    std::ofstream out("map.map");

    GenerateMap(sizeX, sizeY, out);

    out.close();

    return 0;
}