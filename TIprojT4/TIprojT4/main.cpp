//example IPv6 address 2001:0db8:85a3:0000:0000:8a2e:0370:7334
//If mask /0 then 2^128 = 340282366920938463463374607431768211456 hosts (no mask)
//		First address :: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
//If mask /8 then 2^(128-8)=2^120= 1329227995784915872903807060280344576 hosts
//		First address ff00:: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
#include "headers/address.hpp"

#define HEX_N 16
#define BIN_N 2

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

		for(auto & i : wszystkie_adresy)
		{
			i.split_addr();
			i.dd_is();
			i.widd_left();
			i.widd_right();
			i.str_to_bin();
			i.iMask_to_bMask(i.printMask());
			i.corrSubAddr();
		}
		for( int i = 0; i < wszystkie_adresy.size(); i++)
			{
				std::cout << i + 1 << ". Maska: " << wszystkie_adresy[i].printMask() << std::endl;
				std::cout << "Address: ";
				wszystkie_adresy[i].print_entire_address(HEX_N);
				std::cout << std::endl;
				std::cout << "Mask: ";
				wszystkie_adresy[i].print_mask(HEX_N);
				std::cout << std::endl;
				std::cout << "Subnet: ";
				wszystkie_adresy[i].print_subnet(HEX_N);
				std::cout << std::endl;
			}
		return 0;
	}