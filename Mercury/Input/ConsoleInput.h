#pragma once

#include "IInput.h"
#include <unordered_map>
#include <functional>

namespace merc
{

enum class CommandType : unsigned char;

class ConsoleInput final : public IInput
{
    using TCreator = std::function<ICommand*()>;
public:
    ConsoleInput();
    ~ConsoleInput();

    virtual void Process() override;

    virtual ICommand* PopCommand() override;

private:

    void InitializeCommandCreators();

    static ICommand* ScanMove();
    static ICommand* ScanMode();
    static ICommand* ScanSapper();

    ICommand* m_command { nullptr };

    std::unordered_map<std::string, TCreator> m_creators;
};

}
