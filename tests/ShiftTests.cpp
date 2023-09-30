#include "catch_amalgamated.hpp"
#include "ciphers.hpp"
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{

TEST_CASE("RequiredShiftTest1", "[RequiredShift]")
{
	const std::string MESSAGE = "GAUL IS DIVIDED INTO THREE PARTS";
	unsigned ENCRYPTION_KEY = 23;
	std::string encrypted = encryptShift(MESSAGE, ENCRYPTION_KEY);
	REQUIRE( encrypted == "DXRI FP AFSFABA FKQL QEOBB MXOQP");
}

TEST_CASE("RequiredShiftTest2", "[RequiredShift]")
{
	const std::string MESSAGE = "DXRI FP AFSFABA FKQL QEOBB MXOQP";
	unsigned ENCRYPTION_KEY = 23;
	std::string decrypted = decryptShift(MESSAGE, ENCRYPTION_KEY);
	REQUIRE( decrypted == "GAUL IS DIVIDED INTO THREE PARTS" );
}


// Strictly speaking, you could fail this test and still get a good grade on the assignment.
// This is provided here to contrast with the required test cases. 
// Remember, you should make your own test cases!
TEST_CASE("ExtraTestCase", "[AdditionalTestCase]")
{
	const std::string MESSAGE = "EYSJ GQ BGTGBCB GLRM RFPCC NYPRQ";
	unsigned ENCRYPTION_KEY = 24;
	std::string decrypted = decryptShift(MESSAGE, ENCRYPTION_KEY);
	REQUIRE( decrypted == "GAUL IS DIVIDED INTO THREE PARTS" );
}





} // end namespace
