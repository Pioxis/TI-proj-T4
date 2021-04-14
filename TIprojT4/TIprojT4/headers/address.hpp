#pragma once
#ifndef ADDRESS_HPP
#define ADDRESS_HPP
#include <string>
#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

class Address 
{
	private:
		bool slave;
		int id;
		int master_id;

		bool is_dd = false; //Address with double ":" -> "::"
		int left_segments;
		int right_segments;
		std::string addr_ff; //Address from file
		int mask;
		std::string comment;
		std::vector<std::string> all_segm_str;
		std::bitset<16> binary_seg[8];

	public:
		virtual ~Address();
		bool corrMask();
		void gmfs(std::string one_line); //Get mask from string
		int printMask() const;
		void get_tmp_adr(std::string tmp_String_Addr); //Get temp address from source file to object parameter
		void dd_is(); //Check to IP is address with double ":" -> "::"
		int widd_left(); /*Where is double dot from left side, returns how many octets are before "::".
		If dd_is == false, then going to else with full addr func.*/
		int widd_right(); /*Where is double dot from left side, returns how many octets are after "::".
		Used only when dd_is == true.*/
		void split_addr();
		void str_to_bin(); //String to binary mode in bitset
		void print_entire_address(int opt); //If opt == 16 then address will have hex format.
};

#endif //ADDRESS_HPP