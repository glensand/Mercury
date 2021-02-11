/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Command/ManualModeCommand.h"
#include "World/Robot/Robot.h"

namespace merc
{

class Move final : public ManualModeCommand
{
public:
    Move(Direction direction);
    virtual ~Move() = default;

private:
    virtual void ExecuteImpl(GameInterface& gameInterface) override;

    virtual void UndoImpl(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;

    Direction m_direction{ Direction::Up };
};

}
