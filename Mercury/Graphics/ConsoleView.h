#pragma once
#include "IView.h"

namespace merc
{

struct GameInterface;

class ConsoleView final : public IView
{
public:
    ConsoleView() = default;
    virtual ~ConsoleView() = default;

    virtual void Render(const Terrain& terrain) override;
};

}
