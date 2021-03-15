//example IPv6 address 2001:0db8:85a3:0000:0000:8a2e:0370:7334
//If mask /0 then 2^128 = 340282366920938463463374607431768211456 hosts (no mask)
//		First address :: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
//If mask /8 then 2^(128-8)=2^120= 1329227995784915872903807060280344576 hosts
//		First address ff00:: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff



#include "headers/address.hpp"
using namespace std;

int main()
{
	string addresses("2a01:1d8:2:280::/58");
	bitset<16> bitset1(string("1011"));
	bitset<16> bitset2(45035);
	cout << bitset1 << endl;
	cout << bitset2 << endl;
	cout << hex << bitset2.to_ulong() << endl;
	return 0;
}