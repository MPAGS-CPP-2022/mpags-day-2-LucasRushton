#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

std::string runCaesarCipher( const std::string& inputText_Cipher,
const size_t key, const bool encrypt );

#endif // MPAGSCIPHER_CAESARCIPHER_HPP