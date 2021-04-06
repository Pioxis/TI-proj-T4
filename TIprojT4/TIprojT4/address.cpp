#include "headers/address.hpp"

Address::Address() {}

Address::~Address() = default;

void Address::gmfs(std::string one_line)
	{
		std::string slash = "/";
		std::string s_mask;
		int slashyk = one_line.find_first_of(slash); // Wyszukiwanie slasha i potem wyłuskiwanie maski, która jest za nim

		for( int j = slashyk + 1; j < ((slashyk + 1) + 3); j++ )
			{
				if(one_line[j] != ' ')
						s_mask += one_line[j];
			}
			mask = std::stoi(s_mask); //Wpisanie wartości maski do wartosci obiektu
	}

bool Address::corrMask()
	{
		if( mask < 0 || mask > 128 )
			{
				std::cout << "Maska jest niepoprawna: (" << mask << "), wprowadź poprawną maskę dla adresu: "
				/*<< tutaj wywołanie całego adresu*/<< std::endl;
				std::cout << "Maska musi być w zakresie od 0 do 128" << std::endl;
				std::cin >> mask;
				std::cin.clear();
				std::cout << "Twoja nowa maska: " << mask << std::endl;
				return false;
			}
		else
			{
				//std::cout << "Maska jest poprawna." << std::endl;
				return true;
			}
	}

int Address::printMask() const
	{
		return mask;
	}

void Address::get_tmp_adr(std::string tmp_String_Addr)
	{
		std::string slash = "/";
		std::string s_addr;
		int slash_pos = tmp_String_Addr.find_first_of(slash);
		for(int j = 0; j<slash_pos; j++)
			{
				s_addr += tmp_String_Addr[j];
			}
		addr_ff = std::move(s_addr);
	}

void Address::dd_is()
	{
		for(int i = 0; i < addr_ff.length(); i++)
		{
			if(addr_ff[i] == ':' && addr_ff[i+1] == ':')
				is_dd = true;
		}
	}

int Address::widd_left()
	{
		int oct = 0;
		if(is_dd)
			{
				for(int i = 0; i < addr_ff.length(); i++)
				{
					if(addr_ff[i] == ':' && addr_ff[i+1] != ':')
							oct++;
					else if(addr_ff[i] == ':' && addr_ff[i+1] == ':')
						{
							oct++;
							break;
						}
				}
			}
		else
			{
				for(int i = 0; i < addr_ff.length(); i++)
					{
						if (addr_ff[i] == ':' && addr_ff[i + 1] != ':')
								oct++;
					}
					oct += 1;
			}
		return oct;
	}

int Address::widd_right()
	{

		return 0;
	}

