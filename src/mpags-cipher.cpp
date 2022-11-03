#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"

std::string transformChar(const char in);
bool processCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFileName,
                        std::string& outputFileName, 
                        const std::string& inputText_Cipher,
                        const std::string& key,
                        const bool& encrypt);

std::string runCaesarCipher( const std::string& inputText_Cipher,
const size_t key, const bool encrypt );

int main(int argc, char* argv[])
{

    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    //const std::size_t nCmdLineArgs{cmdLineArgs.size()};
    bool helpRequested{false};
    bool versionRequested{false}; 
    std::string inputFile{""}; 
    std::string outputFile{""};

    std::string inputText_Cipher{""};
    std::string key{""};
    bool encrypt{true};

    if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, inputText_Cipher, key, encrypt))
    {
        return 1;
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }
    //char inputChar {'x'};
    // Initialise variables
    std::string inputText;

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    if (!inputFile.empty()) {

        std::string name {inputFile};
        std::ifstream in_file {name};
        bool ok_to_read = in_file.good();
        if (ok_to_read == true){
            char inputChar {'x'};
            while (in_file >> inputChar) {
                inputText += transformChar(inputChar);
            }
        }
        else if(!ok_to_read){
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }
    }
    else {
            char inputChar{'x'};
            while (std::cin >> inputChar) {
                inputText += transformChar(inputChar);
            }
    }



    if (!outputFile.empty()) {
        std::string name2 {outputFile};
        std::ofstream out_file {name2, std::ios::app};
        bool ok_to_write2 = out_file.good();
        if (ok_to_write2 == true){
            out_file << inputText << std::endl;
        }
        else if (!ok_to_write2){
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }
    }
    else {
        std::cout << inputText << std::endl;
    }
    
    //std::cout << "Do you want to encrypt? Write 1 for encrypt and 0 for decrypt" << std::endl;
    //std::cin >> encrypt;
    runCaesarCipher(inputText_Cipher, std::stoul(key), encrypt);
    return 0;
}
