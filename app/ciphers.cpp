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
    if (message.size() != crib.size())
    {
        return false;  // Message and crib must the same length for decryption.
    }

    // Initialize an empty substitution map of 26 -'s for the alphabet.
    substitutionMap = "--------------------------";
    return false;
}

std::string encryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta)
{
    // initialize encrypted message
    std::string x;
    // loop through each character
    for (char c : message)
    {
        // check to see if character or whitespace
        if (std::isalpha(c))
        {
            // ⍺x + β, modulo 26
            char encryptedChar = 'A' + ((affineAlpha * (c - 'A') + affineBeta) % 26);
            x += encryptedChar;
        }
        else
        {
            // whitespace
            x += c;
        }
    }
    return x;
}

// note: this is the ENCRYPTION key, not the decryption key.
// You are guaranteed that affineAlpha is odd, in the range [1,25], and is not 13.  
std::string decryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta)
{
    // formula for decryption:  x ≡ (inverseAlpha * ((c - 'A') - affineBeta)) % 26
    // initialize decrypted message
    std::string x;
    // Calculate the inverse of affineAlpha
    unsigned inverseAlpha = 1;
    for (int i{1}; i < 26; i++) {
        // checks for the multiplicative inverse of affineAlpha
        if ((affineAlpha * i) % 26 == 1) {
            inverseAlpha = i;
            break;
        }
    }
    // Iterate through each character in the encrypted message
    for (char c : message)
    {
        // check if it's a letter or whitespace
        if (isalpha(c))
        {
            // x ≡ (inverseAlpha * ((c - 'A') - affineBeta)) % 26
            int b = (inverseAlpha * ((c - 'A') - affineBeta + 26)) % 26;
            // Convert back to a character
            char decryptedChar = static_cast<char>('A' + b);
             // Append to decrypted string variable
            x += decryptedChar;
        }
        else
        {
            // whitespace
            x += c;
        }
    }
    return x;
}