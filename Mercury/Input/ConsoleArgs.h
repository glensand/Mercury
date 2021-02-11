/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

namespace merc
{

class ConsoleArgs final
{
public:
    ConsoleArgs(int argc, char** argv);

    const char* GetArg(unsigned index) const;

private:
    unsigned m_argsCount;
    char** m_args;
};

}
