#include "catch_amalgamated.hpp"
#include "ciphers.hpp"
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{

TEST_CASE("RequiredAffineTest1", "[RequiredAffine]")
{
	const std::string MESSAGE = "AFFINE";
	constexpr unsigned AFFINE_ALPHA = 9;
	constexpr unsigned AFFINE_BETA = 2;
	const std::string CORRECT_ENCRYPTION = "CVVWPM";
	REQUIRE( CORRECT_ENCRYPTION == encryptAffine(MESSAGE, AFFINE_ALPHA, AFFINE_BETA ) );
}


TEST_CASE("RequiredAffineTest2", "[RequiredAffine]")
{
	const std::string MESSAGE = "CVVWPM";
	constexpr unsigned AFFINE_ALPHA = 9;
	constexpr unsigned AFFINE_BETA = 2;
	const std::string CORRECT_DECRYPTION = "AFFINE";
	REQUIRE( CORRECT_DECRYPTION == decryptAffine(MESSAGE, AFFINE_ALPHA, AFFINE_BETA ) );
}



}