#include "parserConfig.h"
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <string>
#include <stdexcept>
#include <memory>

namespace merc
{

ParserConfig::ParserConfig(std::string_view configName)
    : m_configName(configName)
{

}

ParserConfig::TCommandNameParserMap ParserConfig::LoadCommands() const
{
    rapidjson::Document config;
    
    FILE* fp = nullptr;
    fopen_s(&fp, m_configName.c_str(), "rb");

    if (fp == nullptr)
        throw std::runtime_error("Could not open file, file name: " + m_configName);

    std::unique_ptr<char[]> bufferDeleter(new char[65536]);
    auto* readBuffer = bufferDeleter.get();

    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    config.ParseStream(is);

    if (config.HasParseError() || !config.IsObject())
        throw std::runtime_error("Could not parse config, error code: " + std::to_string(config.GetParseError()) + " "
        + std::to_string(config.GetErrorOffset()));

    auto&& parsers = config["Parsers"].GetArray();
    
    TCommandNameParserMap result;
    for (auto&& commandParser : parsers)
    {
        auto&& commandName = commandParser["Command"].GetString();
        auto&& parserName = commandParser["Parser"].GetString();

        result.emplace(commandName, parserName);
    }

    return result;
}

}
