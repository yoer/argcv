#include "cmdparamparser.h"

#include <iostream>
#include <algorithm>

const std::string CmdParamParser::progressNameKey = "program_name";

bool CmdParamParser::parse(int argc, char *argv[], command_parameter *params)
{
    if (2 == argc) {    //  user ask for helps
        auto helpKey = argv[1];
        auto findParam = params->find(helpKey);
        if (findParam == params->end()) {
            std::cout << helpKey << " is not a valid key" ;
        } else {
            std::cout << findParam->second.first << std::endl;
        }
        return false;
    }

    if ((1 == argc)
            || (argc %2 != 1)) {   //  not valid
        std::cout << "Usage is :" << std::endl;
        std::for_each(params->begin(), params->end(),
                      [](std::pair<std::string,
                      std::pair<std::string, std::string*> > value){
            if ("-h" == value.first.substr(0, sizeof("-h"))) {
                return;   //  filter help info
            }
            std::cout << value.first << " " <<  value.second.first << std::endl;
        });
        std::cout << std::endl;
        return false;
    }

    for (int paramIdx = 1; paramIdx < argc; ++paramIdx) {
        auto curKey = argv[paramIdx];

        if (paramIdx+1 == argc) {
            std::cout << "unvalid param" << curKey;
            break;
        }

        auto findParam = params->find(curKey);
        if (findParam == params->end()) {
            std::cout << curKey << " is not a needed argument.";
            ++paramIdx; //  filter current parameter's value
            continue;
        }

        if (nullptr != findParam->second.second) {
            *(findParam->second.second) = argv[++paramIdx];
        }
    }

    (*params)[CmdParamParser::progressNameKey] = std::make_pair(argv[0], nullptr);

    return true;
}

std::string CmdParamParser::getProgressNameBy(const command_parameter &params)
{
    auto findParam = params.find(CmdParamParser::progressNameKey);
    if (findParam == params.end()) {
        return "";
    }

    return findParam->second.first;
}
