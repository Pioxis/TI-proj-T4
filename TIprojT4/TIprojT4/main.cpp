/* Skład sekcji: Piotr Cała, Aleksander Nowak, Mariusz Pawełkiewicz, Patryk Zawadzki, Oskar Czaja */
#include "headers/address.hpp"

#define HEX_N 16 //Just for test of printing binnary representation of addr. For default and full working app HEX_N = 16

int main()
	{
		std::string input_string = "addresstab.txt";
		std::string output_string = "output.txt";
		std::ifstream myFile(input_string);
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
			wszystkie_adresy[i].split_addr();
			wszystkie_adresy[i].dd_is();
			wszystkie_adresy[i].widd_left();
			wszystkie_adresy[i].widd_right();
			wszystkie_adresy[i].str_to_bin();
			wszystkie_adresy[i].iMask_to_bMask(wszystkie_adresy[i].printMask());
			wszystkie_adresy[i].corrSubAddr();
			wszystkie_adresy[i].set_ID(i+1);
			wszystkie_adresy[i].tabs_c();
			wszystkie_adresy[i].set_root();
			if( wszystkie_adresy[i-1].get_tabs() < wszystkie_adresy[i].get_tabs() )
				{
					wszystkie_adresy[i].set_my_master(wszystkie_adresy[i-1].get_ID());
					wszystkie_adresy[i-1].set_master();
				}
			else if( wszystkie_adresy[i-1].get_tabs() == wszystkie_adresy[i].get_tabs() )
				{
					wszystkie_adresy[i].set_my_master(wszystkie_adresy[i-1].get_my_master_ID());
				}
		}
		for( int i = 0; i < wszystkie_adresy.size(); i++ )
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
				std::cout << std::endl << std::endl;
			}
			//Logic
					//Check same addr
			for(int lstr = 0; lstr < wszystkie_adresy.size(); lstr++)
				{
				for (int i = lstr + 1; i < wszystkie_adresy.size(); i++)
					{
					if (wszystkie_adresy[lstr].get_substr() == wszystkie_adresy[i].get_substr())
						{
							std::cout << "Przydzielony adres:" << std::endl << "[" << wszystkie_adresy[lstr].get_ID()
									  << "] ";
							wszystkie_adresy[lstr].print_subnet_only(HEX_N);
							std::cout << std::endl;
							std::cout << "jest taki sam jak: " << std::endl;
							std::cout << "[" << wszystkie_adresy[i].get_ID() << "] ";
							wszystkie_adresy[i].print_subnet_only(HEX_N);
							std::cout << std::endl;
						}
					}
				}
			for(int i = 0; i < wszystkie_adresy.size(); i++)
				{
				for (int j = 0; j < wszystkie_adresy.size(); j++)
					{
						wszystkie_adresy[i].check_submask(wszystkie_adresy[j]);
					}
				}
	//Save to file
	std::ofstream outFile;
	outFile.open(output_string);
	outFile.seekp(0);
	for(auto & x : wszystkie_adresy)
		{
			if(x.get_error_state())
				{
					std::cout << "Popraw plik wejściowy i włącz program ponownie" << std::endl;
					return 0;
				}
			else
				{
					for(int i = 0; i < x.get_tabs(); i++)
						{
							outFile << '\t';
						}
						outFile << x.get_sub_str_hex() << "/" << x.printMask()
						<< " " << x.get_comment() << std::endl;
						outFile.clear();
				}
		}
	outFile.close();
		return 0;
	}