#include "headers/address.hpp"

Address::~Address() = default;

void Address::gmfs(std::string one_line)
	{
		std::string slash = "/";
		std::string s_mask;
		int slashyk = one_line.find_first_of(slash); //Wyszukiwanie slasha i potem wyłuskiwanie maski, która jest za nim
		int j;
		for( j = slashyk + 1; j < ((slashyk + 1) + 3); j++ )
		{
			if(one_line[j] != ' ')
				s_mask += one_line[j];
		}
			mask = std::stoi(s_mask); //Wpisanie wartości maski do wartosci obiektu
		std::string temp_comm;
		for (int k = j; k<one_line.length(); k++)
			{
				if(one_line[k] != '\n')
					temp_comm += one_line[k];
			}
			comment = temp_comm;
	}

bool Address::corrMask()
	{
		if( mask < 0 || mask > 128 )
		{
			std::cout << "Maska jest niepoprawna: (" << mask << "), wprowadź poprawną maskę dla adresu: ";
			//print_entire_address();
			std::cout << addr_ff<< std::endl;
			std::cout << "Maska musi być w zakresie od 0 do 128" << std::endl;
			std::cin >> mask;
			std::cin.clear();
			std::cout << "Twoja nowa maska: " << mask << std::endl;
			return false;
		}
		else
		{
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
					if(oct > 0)
					{
						oct++;
					}
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
		left_segments = oct;
		return oct;
	}

int Address::widd_right()
	{
		int oct = 0;
		if(is_dd)
		{
			for( int i = addr_ff.length(); i > 0; i--)
			{
				if( addr_ff[i] == ':' && addr_ff[i-1] != ':' )
				{
					oct++;
				}
				else if ( addr_ff[i] == ':' && addr_ff[i-1] == ':')
				{
					if(oct > 0)
					{
						oct++;
					}
					break;
				}
			}
		}
		right_segments = oct;
		return oct;
	}

void Address::split_addr()
	{
		std::string segment;
		std::string temp_Str_addr = addr_ff;
		temp_Str_addr.erase(remove(temp_Str_addr.begin(), temp_Str_addr.end(), '\t'),
							temp_Str_addr.end()); //remove TAB from string

		std::stringstream temp_Str_addr2;
		temp_Str_addr2.str(temp_Str_addr);
		while (std::getline(temp_Str_addr2, segment, ':')) //Split stringstream to segments of IPv6 addr
		{
			if(!segment.empty())
			{
				all_segm_str.push_back(segment);
			}
		}
	}

void Address::str_to_bin()
	{
		std::string view_str;
		unsigned long b = 0;
		unsigned long g = 0;
		std::istringstream tempvalue;
		std::istringstream tempvalue_r;
	//left side
		if(left_segments > 0)
		{
			for (int j = 0; j < left_segments; j++)
			{
				tempvalue.str(all_segm_str[j]);
				tempvalue >> std::hex >> b;
				std::bitset<16> temp_seg_bin(b);
				binary_seg[j] = temp_seg_bin;
				tempvalue.clear();
				tempvalue_r.clear();
			}
		}
	//right side
		if(right_segments > 0)
		{
			int all_seg_count = left_segments+right_segments;
			for (int r = 7; r >= 8 - right_segments; r--)
			{
				tempvalue_r.str(all_segm_str[all_seg_count-1]);
				tempvalue_r >> std::hex >> g;
				std::bitset<16> temp_seg_bin2(g);
				binary_seg[r] = temp_seg_bin2;
				tempvalue.clear();
				tempvalue_r.clear();
				all_seg_count--;
			}
		}
	}

void Address::print_entire_address(int opt)
	{
	if(opt == 16)
		{
		int max_seg = sizeof(binary_seg) / sizeof(binary_seg[0]);
		for (int i = 0; i < max_seg; i++)
			{
			std::cout.fill('0');
			std::cout.width(4);
			std::cout << std::hex << binary_seg[i].to_ulong();
			if (i != max_seg - 1)
				std::cout << ":";
			}
		std::cout << std::dec << "/" << mask;
		}
	else
		{
		int max_seg = sizeof(binary_seg) / sizeof(binary_seg[0]);
		for (int i = 0; i < max_seg; i++)
			{
			//std::cout.fill('0');
			//std::cout.width(4);
			std::cout << /*std::hex <<*/ binary_seg[i]/*.to_ulong()*/;
			if (i != max_seg - 1)
				std::cout << ":";
			}
		std::cout /*<< std::dec*/ << "/" << mask;
		}
	}
