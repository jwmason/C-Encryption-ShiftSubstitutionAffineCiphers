#include <string>
#include <iostream>
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
    // Initialize the substitution map with 26 '-' characters
    substitutionMap = "--------------------------";
    // See if the crib is compatible -> index the message and match the crib length to each possible substring of message
    for (unsigned i = 0; i < (message.length() - crib.length() + 1); i++)
    {
        // initialize looping substring
        std::string message_substring = message.substr(i, crib.length() + i);
        // Make sure first and last letter of substring are not whitespace
        if ((message_substring[0] != ' ') && (message_substring[message_substring.length() - 1] != ' '))
        {
            // Loop through each character in message substring to match shape with crib
            for (unsigned j = 0; j < crib.length(); j++)
            {
                // Check if both are characters
                if (std::isalpha(message_substring[j]) && std::isalpha(crib[j]))
                {
                    // Check if it is empty
                    if (substitutionMap[crib[j] - 'A'] == '-')
                    {
                        bool alrexist{false};
                        // If empty, check it is not a duplicate
                        for (unsigned z = 0; z < substitutionMap.length(); z++) {
                            if (substitutionMap[z] == message_substring[j])
                            {
                                alrexist = true;
                                break;
                            }
                        }
                        // If it is a duplicate, reset
                        if (alrexist) {
                            substitutionMap = "--------------------------";
                            break;
                        }
                        // Else update the substitutionMap
                        else
                        {   
                            substitutionMap[crib[j] - 'A'] = message_substring[j];
                        }
                    }
                    // If the substitution has a duplicate that is the same key and same message char, continue
                    else if (substitutionMap[crib[j] - 'A'] == message_substring[j]) 
                    {
                        continue;
                    }
                    // Reset map if not the same shape
                    else
                    {
                        // std::cout << substitutionMap << '\n';
                        substitutionMap = "--------------------------";
                        break;
                    }
                }
                // Check if both are whitespace
                else if (message_substring[j] == ' ' && crib[j] == ' ')
                {
                    continue;
                }
                // If neither, exit and check next substring
                else
                {
                    substitutionMap = "--------------------------";
                    break;
                }
            }
            // If the map is not empty, return true
            if (substitutionMap != "--------------------------")
            {
                return true;
            }
        }
    }
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