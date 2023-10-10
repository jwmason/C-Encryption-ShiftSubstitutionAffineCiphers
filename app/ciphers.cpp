#include <string>
#include "ciphers.hpp"


/* 
 * Right now, these functions are stubbed;  that will allow this project
   to compile before you finish everything, and allow you to incrementally
   test your code, but are not expected to return the correct answers.
 */


std::string encryptShift(const std::string &message, unsigned key)
{
    std::string x{""}; // string x to hold decrypted message
    for (char c : message) // loop through all characters in encrypted message
    {
        if (std::isalpha(c)) // check if the character is a letter
        {
            char base{'A'}; // single quotes to show it is a character literal rather than a string literal
            char decryptedChar = static_cast<char>((26 + (c - base + key)) % 26 + base); // (c - base) to find character. + key to find orig position. 
                                                                                         // 26 + and % 26 to handle loop arounds. + base to offset the orig - base.
            x += decryptedChar; // Add decrypted character to x
        }
        else // check for whitespace
        {
            x += ' ';
        }
    }
    return x; // this is a stub
}

std::string decryptShift(const std::string &message, unsigned key)
{
    std::string x{""}; // string x to hold decrypted message
    for (char c : message) // loop through all characters in encrypted message
    {
        if (std::isalpha(c)) // check if the character is a letter
        {
            char base{'A'}; // single quotes to show it is a character literal rather than a string literal
            char decryptedChar = static_cast<char>((26 + (c - base - key)) % 26 + base); // (c - base) to find character. - key to find orig position. 
                                                                                         // 26 + and % 26 to handle loop arounds. + base to offset the orig - base.
            x += decryptedChar; // Add decrypted character to x
        }
        else // check for whitespace
        {
            x += ' ';
        }
    }
    return x; // this is a stub
}



bool decryptSubstitution(const std::string &message, const std::string &crib, std::string &substitutionMap)
{
    if (message.size() != crib.size()) {
        return false;  // Message and crib must be of the same length for decryption.
    }

    // Initialize an empty substitution map of 26 -'s for the alphabet.
    substitutionMap = "--------------------------";
    return false;
}

std::string encryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta)
{
    return message; // this is a stub
}


// note: this is the ENCRYPTION key, not the decryption key.
// You are guaranteed that affineAlpha is odd, in the range [1,25], and is not 13.  
std::string decryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta)
{
    return message; // this is a stub
    
}
