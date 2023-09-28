
#include <string>
#include "ciphers.hpp"


/* 
 * Right now, these functions are stubbed;  that will allow this project
   to compile before you finish everything, and allow you to incrementally
   test your code, but are not expected to return the correct answers.
 */


std::string encryptShift(const std::string &message, unsigned key)
{
    return message; // this is a stub
}

std::string decryptShift(const std::string &message, unsigned key)
{

    return message; // this is a stub
}



bool decryptSubstitution(const std::string &message, const std::string & crib, std::string &decryption)
{
    return false; // this is a stub
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
