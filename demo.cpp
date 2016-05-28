#include <iostream>

#include "cmdparamdef.h"
#include "cmdparamparser.h"

int main(int argc, char *argv[])
{
    std::string firstValue, secondValue;

    command_parameter commandParameters;
    commandParameters["-f"] = std::make_pair("first value message tip.", &firstValue);
    commandParameters["-s"] = std::make_pair("second value message tip.", &secondValue);
    commandParameters["-h"] = std::make_pair("help message tip", nullptr);

    if (! CmdParamParser::parse(argc, argv, &commandParameters)) {
        return false;
    }

    return 0;
}

