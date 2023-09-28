#ifndef __CIPHERS_PROJECT_ZERO

#define __CIPHERS_PROJECT_ZERO

#include <string>


// do not change below this line, except those below the "TODO" line (below)


std::string encryptShift(const std::string &message, unsigned key);

// note: key is the ENCRYPTION key, not the decryption key.
std::string decryptShift(const std::string &message, unsigned key);




// "Accept no Substitute"

bool decryptSubstitution(const std::string &message, const std::string & crib, std::string &decryption);
// from the old version of the project, this was "decrypt," with the message replacing cipherstream and the decryption being what would have been output.



// affine

std::string encryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta);
// the encryption function is x -> affineAlpha * x + affineBeta (mod 26)


// note: this is the ENCRYPTION key, not the decryption key.
// You are guaranteed that affineAlpha is odd, in the range [1,25], and is not 13.  
std::string decryptAffine(const std::string &message, unsigned affineAlpha, unsigned affineBeta);






// do not change above this line; 


#endif

