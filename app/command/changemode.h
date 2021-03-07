/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Command/ICommand.h"
#include "Mode/IMode.h"
#include <any>

namespace merc
{

class ChangeMode final : public ICommand
{
public:
    ChangeMode(Mode mode, std::any&& argument);
    virtual ~ChangeMode() = default;

private:
    virtual void Execute(GameInterface& gameInterface) override;

    virtual void Undo(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;

    IMode* CreateByType(GameInterface& gameInterface) const;

    Mode m_mode;
    std::any m_argument;
};

}
