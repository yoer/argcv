#ifndef CMDPARAMDEF
#define CMDPARAMDEF

#include <string>
#include <map>

/*!
 * \brief Command Parameter, define a parameters of command line
 * Usage:
 *
 * std:string value1, value2;
 * command_parameters parameters;
 * parameters["-key1"] = std::make_pair("<first key's message>", &(value1));
 * parameters["-key2"] = std::make_pair("<second key's message>", &(value2));
 */

typedef std::string parameter_key;
typedef std::string parameter_message;
typedef std::string* parameter_value_pointer;
typedef std::pair<parameter_message, parameter_value_pointer> parameter_info;
typedef std::map<parameter_key, parameter_info> command_parameter;

#endif // CMDPARAMDEF

