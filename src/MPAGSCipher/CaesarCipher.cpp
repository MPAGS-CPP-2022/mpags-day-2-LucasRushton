#include <cctype>
#include <iostream>
#include <string>
#include <vector>

// Our project headers

std::string runCaesarCipher( const std::string& inputText_Cipher,
const size_t key, const bool encrypt )
{
    std::string message;
    char ch;
    int i;
    //std::cout << encrypt << std::endl;
    if (encrypt == true)
    {
        message = inputText_Cipher;

        //std::cout << "Enter a message to encrypt: ";
        ///std::cin >> message;
        //std::cout << "Enter key: ";
        //std::cin >> key;
        for(i = 0; message[i] != '\0'; ++i)
        {
            // Loop through characters of message
            ch = message[i];
            // Check if character is above 'a' and below 'z' in alphabet
            if(ch >= 'a' && ch <= 'z')
            {
                ch += key;
                // If the character + key means that the alphabet needs to be wrapped around i.e. ch > 'z'
                // then we need this if statement
                if(ch > 'z')
                {
                    ch += - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }
            // Also need to do the same for capital letters
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch += key;
                if(ch > 'Z')
                {
                    ch += - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }
        std::cout << "Encrypted message: " << message << std::endl;
    }
    else if (encrypt == false)
    {
        message = inputText_Cipher;
        //std::cout << "HELLO I'M HERE" << std::endl;
        //char ch_decrypt;
        //int i_decrypt;
        //std::cout << "Enter a message to decrypt: " << std::endl;
        ///std::cin >> message;
        //std::cout << "Enter key: ";
        //std::cin >> key_decrypt;
        for(i = 0; message[i] != '\0'; ++i)
        {
            //std::cout << "Loop through characters of message:" << i_decrypt << std::endl;
            ch = message[i];
            if(ch >= 'a' && ch <= 'z')
            {
                ch -= key;
                if(ch < 'a')
                {
                    ch += 'z' - 'a' + 1;
                }
                message[i] = ch;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                ch -= key;
                if(ch < 'A')
                {
                    ch += 'Z' - 'A' + 1;
                }
                message[i] = ch;
            }
        }
        std::cout << "Decrypted message: " << message << std::endl;
        
    }
    else
    {
        std::cout << "User did not specify whether to encrypt or decrypt! Please try again" << std::endl;
    }
    //std::cout << message << std::endl;
    return message;
}