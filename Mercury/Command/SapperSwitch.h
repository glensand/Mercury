/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Command/ICommand.h"

namespace merc
{

class SapperSwitch final : public ICommand
{
public:
    SapperSwitch(bool on);
    virtual ~SapperSwitch() = default;

private:
    virtual void Execute(GameInterface& gameInterface) override;

    virtual void Undo(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;

    bool m_sapperOn;
};

}
