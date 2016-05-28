#ifndef CMDPARAMPARSER_H
#define CMDPARAMPARSER_H

#include <string>
#include <map>

#include "cmdparamdef.h"

/*!
 * \brief The CommandParamParser class
 *
 * use to parse and assign value from command line parameters
 */
class CmdParamParser{
public:
    /*!
     * \brief parse by params
     * \param argc
     * \param argv
     * \param params    try to assign value to params'value by params's key
     * \return
     *
     * program name would be return by 'params["program_name"].first', use getProgressNameBy(params);
     */
    static bool parse(int argc, char *argv[], command_parameter* params);
    /*!
     * \brief get progress name by CommandParameter
     * \param params
     * \return progress name
     *
     * must call parse(argc, argv, 'params') function first,
     * and then use 'params' as function parameter to call getProgressNameBy('params')
     */
    static std::string getProgressNameBy(const command_parameter& params);

private:
    const static std::string progressNameKey;
};

#endif // CMDPARAMPARSER_H
