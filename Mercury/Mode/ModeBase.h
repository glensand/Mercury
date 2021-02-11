/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "IMode.h"

namespace merc
{

struct GameInterface;
class Terrain;

class ModeBase : public IMode
{
public:
    ModeBase(GameInterface& gameInterface, Mode mode);
    virtual ~ModeBase() = default;

    virtual Mode GetMode() const override final;

    virtual void SetOnStepCallback(std::function<void()>&& callback) override final;
protected:

    void Render() const;

    std::function<void()> m_onStepCallback;
    GameInterface& m_gameInterface;
    Mode m_mode;
};

}
