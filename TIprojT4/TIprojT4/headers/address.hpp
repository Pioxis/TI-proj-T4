#pragma once
#ifndef ADDRESS_HPP
#define ADDRESS_HPP
#include <string>
#include <bitset>
#include <iostream>
#include <sstream>
#include <utility>

class Address 
{
	private:
		int id;
		int master_id;
		bool is_dd = false; //Address with double ":" -> "::"
		//std::string addr_ff; //Address from file
		std::bitset<16> binary_octets[8];
		std::string octets_s[8];
		int mask = 0;
	public:
		std::string addr_ff; //Address from file
		Address();
		virtual ~Address();
		bool corrMask();
		void gmfs(std::string one_line); //Get mask from string
		int printMask() const;
		void get_tmp_adr(std::string tmp_String_Addr); //Get temp address from source file to object parameter
		void dd_is(); //Check to IP is address with double ":" -> "::"
		int widd_left(); //Where is double dot from left side, returns how many octets are before "::"
		int widd_right(); //Where is double dot from left side, returns how many octets are after "::"
};


#endif //ADDRESS_HPP