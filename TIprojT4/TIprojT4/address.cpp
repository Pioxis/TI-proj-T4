#include "headers/address.hpp"

void Address::hex_to_binary(std::string hex_part)
{
	long int i = 0;
	
	while(hex_part[i])
	{
		switch(hex_part[i]) // <-- Do skończenia
		{
			case '0':	//0000
				break;
			case '1':	//0001
				break;
			case '2':	//0010
				break;
			case '3':	//0011
				break;
			case '4':	//0100
				break;
			case '5':	//0101
				break;
			case '6':	//0110
				break;
			case '7':	//0111
				break;
			case '8':	//1000
				break;
			case '9':	//1001
				break;
			case 'A':	//1010 -> 10
			case 'a':
				break;
			case 'B':	//1011 -> 11
			case 'b':
				break;
			case 'C':	//1100 -> 12
			case 'c':
				break;
			case 'D':	//1101 -> 13
			case 'd':
				break;
			case 'E':	//1110 -> 14
			case 'e':
				break;
			case 'F':	//1111 -> 15
			case 'f':
				break;
			default:
				std::cout << std::endl << "Error! Invalid hexadecimal digit" <<std::endl;
		}
		i++;
	}
}
