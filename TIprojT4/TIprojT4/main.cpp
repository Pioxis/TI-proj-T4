//example IPv6 address 2001:0db8:85a3:0000:0000:8a2e:0370:7334
//If mask /0 then 2^128 = 340282366920938463463374607431768211456 hosts (no mask)
//		First address :: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
//If mask /8 then 2^(128-8)=2^120= 1329227995784915872903807060280344576 hosts
//		First address ff00:: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
#include "headers/address.hpp"

int main()
	{
		std::ifstream myFile("addresstab.txt");
		std::string tempString2;
		Address tempAddrC;
		bool correct_addr;
		std::vector<Address> wszystkie_adresy;
		while( std::getline(myFile,tempString2) )
		{
			tempAddrC.gmfs(tempString2);
			correct_addr = tempAddrC.corrMask();
			while(!correct_addr)
			{
				correct_addr = tempAddrC.corrMask();
			}
			tempAddrC.get_tmp_adr(tempString2);
			wszystkie_adresy.push_back(tempAddrC);
		}
		myFile.clear();
		myFile.seekg(0);
		myFile.close();

		for( int i = 0; i < wszystkie_adresy.size(); i++ )
		{
			std::cout << i + 1 << ". Maska: " << wszystkie_adresy[i].printMask() << std::endl;
			wszystkie_adresy[i].split_addr();
			wszystkie_adresy[i].dd_is();
			std::cout << "Ilość oktetów po lewej stronie: " << wszystkie_adresy[i].widd_left() << " || po prawej stronie: " << wszystkie_adresy[i].widd_right() << std::endl;
			wszystkie_adresy[i].str_to_bin();
			wszystkie_adresy[i].print_entire_address(16);
			std::cout << std::endl;
		}

		return 0;
	}