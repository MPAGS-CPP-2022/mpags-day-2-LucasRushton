#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <vector>
#include <string>

bool processCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFileName,
                        std::string& outputFileName,
                        std::string& inputText_Cipher,
                        std::string& key,
                        bool& encrypt);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP