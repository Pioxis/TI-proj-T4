//example IPv6 address 2001:0db8:85a3:0000:0000:8a2e:0370:7334
//If mask /0 then 2^128 = 340282366920938463463374607431768211456 hosts (no mask)
//		First address :: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
//If mask /8 then 2^(128-8)=2^120= 1329227995784915872903807060280344576 hosts
//		First address ff00:: || Last adress ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff
#include "headers/address.hpp"
#include <fstream>
#include <vector>

int main()
	{
		std::ifstream myFile("addresstab.txt");
		std::string tempString2;
		Address tempAddrC;
		bool correct_addr;
		std::vector<Address> wszystkie_adresy;
		int lines = 0;
		while(std::getline(myFile,tempString2))
		{
			tempAddrC.gmfs(tempString2);
			correct_addr = tempAddrC.corrMask();
			while(!correct_addr)
				{
					correct_addr = tempAddrC.corrMask();
				}
			tempAddrC.get_tmp_adr(tempString2);
			wszystkie_adresy.push_back(tempAddrC);
			++lines;
		}
		myFile.clear();
		myFile.seekg(0);
		std::cout << "Ilość linii w pliku: " << lines << std::endl;
		myFile.close();

		for(int i = 0; i<wszystkie_adresy.size(); i++)
			{
				std::cout << i+1 << ". Maska: " << wszystkie_adresy[i].printMask() << std::endl;
			}

		for(auto & i : wszystkie_adresy)
			{
				std::cout << i.addr_ff << std::endl;
				i.dd_is();
				std::cout << "Ilość oktetów po lewej stronie: " << i.widd_left() << std::endl;
			}
		/*
		unsigned long b;
		std::string one_hex = "2a01";
		std::istringstream tempvalue(one_hex);
		tempvalue >> std::hex >> b;
		std::bitset<16> a(b);
		std::cout << "From one string: " << a << std::endl;*/
		return 0;
	}