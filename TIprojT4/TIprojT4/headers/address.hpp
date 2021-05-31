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
#include <iomanip>

class Address 
{
	private:
		bool error = false;
		int id;
		bool root;
		bool master;
		int my_master_id;
		int tabs;

		bool is_dd = false; //Address with double ":" -> "::"
		int left_segments;
		int right_segments;
		std::string addr_ff; //Address from file
		int mask;
		std::string comment;
		std::vector<std::string> all_segm_str;
		std::bitset<16> binary_seg[8];
		std::bitset<16> bin_mask[8];
		std::bitset<16> sub_addr[8]; //address after correction from normal address to subnet address
		std::string subnet_string;
		std::string subnet_string_hex;

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
		Used when dd_is == true.*/
		void split_addr();
		void str_to_bin(); //String to binary mode in bitset
		void print_entire_address(int opt); //If opt == 16 then address will have hex format.
		void iMask_to_bMask(int iMask);
		void corrSubAddr(); //If addr is not subnet addr then change it to subnet addr
		void print_subnet(int opt);
		void print_mask(int opt);
		void set_ID(int pID);
		int get_ID() const;
		void tabs_c();
		void set_root();
		int get_tabs() const;
		void set_master();
		void set_my_master(int id_m);
		int get_my_master_ID() const;
		std::string get_substr();
		void check_submask(Address& prevAddr);
		bool get_error_state() const;
		std::string get_comment() const;
		std::string get_sub_str_hex() const;

	};
#endif //ADDRESS_HPP