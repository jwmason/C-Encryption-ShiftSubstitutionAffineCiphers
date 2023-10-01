#include "catch_amalgamated.hpp"
#include "ciphers.hpp"
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{

TEST_CASE("RequiredSubstituteTest1", "[RequiredSubstitute]")
{
	const std::string MESSAGE = "ABCD EFG";
	const std::string CRIB = "GOOD ONE";
	std::string substitutionMap ;
	REQUIRE_FALSE( decryptSubstitution(MESSAGE, CRIB, substitutionMap ) );
	/* If there were a match, it would imply that 'O' in the plaintext 
		were encrypted as 'B' in one spot and 'C' in another and 'E' in yet another.  
		Yet, the spec promised that each letter in the plaintext is consistently
		replaced by a letter to produce the ciphertext message. 
	*/
}

TEST_CASE("RequiredSubstituteTest2", "[RequiredSubstitute]")
{
	const std::string MESSAGE = "HIJK ILM";
	const std::string CRIB = "GOOD ONE";
	std::string substitutionMap ;
	REQUIRE_FALSE( decryptSubstitution(MESSAGE, CRIB, substitutionMap ) );
	/* If this were a match, it would imply that 'O' in the plaintext
		was  encrypted as an 'I' in two places but a 'J' in the other.
	 */
}

TEST_CASE("RequiredSubstituteTest3", "[RequiredSubstitute]")
{
	const std::string MESSAGE = "NQQP RST";
	const std::string CRIB = "GOOD ONE";
	std::string substitutionMap ;
	REQUIRE_FALSE( decryptSubstitution(MESSAGE, CRIB, substitutionMap ) );
	/* If this were a match, it would imply that 'O' in the plaintext
		was  encrypted as a 'Q' in two places but a 'R' in the other.
	 */
}

TEST_CASE("RequiredSubstituteTest4", "[RequiredSubstitute]")
{
	const std::string MESSAGE = "DCCB CBA";
	const std::string CRIB = "GOOD ONE";
	std::string substitutionMap ;
	REQUIRE_FALSE( decryptSubstitution(MESSAGE, CRIB, substitutionMap ) );
	/* If this were a match, it would imply that both 'D' and 'N' in the plaintext 
	   were encrypted as 'B,' despite the spec promising that different letters
	   are not replaced by the same letter. 
	*/
}

TEST_CASE("RequiredSubstituteTest5", "[RequiredSubstitute]")
{
	const std::string MESSAGE = "UWWX WYZ";
	const std::string CRIB =    "GOOD ONE";
	std::string substitutionMap ;
	// For ease of visualization to you the human:
//					     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string CORRECT_DECRYPTION = "---XZ-U------YW-----------";
	REQUIRE( decryptSubstitution(MESSAGE, CRIB, substitutionMap ) );
	REQUIRE( substitutionMap  == CORRECT_DECRYPTION );
}

TEST_CASE("RequiredSubstituteTest6", "[RequiredSubstitute]")
{
	const std::string MESSAGE = "ABCD EFG HIJK ILM NPPQ RST DCCB CBA UWWX WYZ";
	const std::string CRIB = "GOOD ONE";
	std::string substitutionMap ;
	// For ease of visualization to you the human:
//					     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string CORRECT_DECRYPTION = "---XZ-U------YW-----------";
	REQUIRE( decryptSubstitution(MESSAGE, CRIB, substitutionMap ) );
	REQUIRE( substitutionMap  == CORRECT_DECRYPTION) ;
// Note that the message might not make a lot of sense, nor does it have to for this assignment. 

}




} // end namespace
