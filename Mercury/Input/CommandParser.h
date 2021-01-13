#pragma once

#include "ICommandParser.h"
#include <unordered_map>
#include <functional>

namespace merc
{

enum class CommandType : unsigned char;

class CommandParser final : public ICommandParser
{
    using TCreator = std::function<ICommand*(std::istream& stream)>;
public:
    CommandParser();
    ~CommandParser();

    virtual ICommand* Parse(std::istream& stream) override;

private:

    void InitializeCommandCreators();

    static ICommand* ParseMove(std::istream& stream);
    static ICommand* ParseMode(std::istream& stream);
    static ICommand* ParseSapper(std::istream& stream);

    std::unordered_map<std::string, TCreator> m_creators;
};

}
