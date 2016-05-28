# cppcmd
parse and assign value from command line parameters

# demo
  ```cpp
  std::string firstValue, secondValue;
  command_parameter commandParameters;
  commandParameters["-f"] = std::make_pair("first value message tip.", &firstValue);
  commandParameters["-s"] = std::make_pair("second value message tip.", &secondValue);
  commandParameters["-h"] = std::make_pair("help message tip", nullptr);

  CmdParamParser::parse(argc, argv, &commandParameters)
  std::cout << firstValue << "," << secondValue;
  ```
