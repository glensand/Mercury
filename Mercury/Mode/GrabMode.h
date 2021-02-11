/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Mode/AutoMode.h"

namespace merc
{

class GrabMode final : public AutoMode
{
public:

    GrabMode(GameInterface& gameInterface);

    virtual ~GrabMode() = default;

    virtual void OnFrame() override;

private:

    void Delouse();
    void ProcessPath(Robot& robot, const std::deque<Direction>& path);
    bool Collect();
    bool Step();
};

}
