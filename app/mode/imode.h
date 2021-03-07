/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include <functional>

namespace merc
{

enum class Mode : unsigned char
{
    Manual,
    Scan,
    Grab,

    Count,
};

class IMode
{
public:
    virtual ~IMode() = default;

    virtual Mode GetMode() const = 0;

    virtual void OnFrame() = 0;

    // TODO:: use boost::signal
    virtual void SetOnStepCallback(std::function<void()>&& callback) = 0;
};

}
