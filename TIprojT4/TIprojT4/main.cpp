//example IPv6 address 2001:0db8:85a3:0000:0000:8a2e:0370:7334
//If mask /0 then 2^128 = 340282366920938463463374607431768211456 hosts (no mask)
//		First address :: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
//If mask /8 then 2^(128-8)=2^120= 1329227995784915872903807060280344576 hosts
//		First address ff00:: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff



#include "headers/address.hpp"

//using namespace std;

int main()
{
	std::string full_address1("2a01:1d8:2:280::/58");
	std::bitset<16> bitset1(std::string("1110"));
	std::bitset<16> bitset2(45035);
	std::cout << bitset1 << std::endl;
	std::cout << bitset2 << std::endl;
	std::cout << std::hex << bitset2.to_ulong() << std::endl;
	std::cout << full_address1 << std::endl;
	std::cout << std::dec << full_address1.size() << std::endl;
	return 0;
}