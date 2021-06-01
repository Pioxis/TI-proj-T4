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
		bool root;
		bool master; //Unused var, for inform in debugging mode
		bool is_dd = false; //Address with double ":" -> "::"
		int id;
		int my_master_id;
		int tabs;
		int left_segments;
		int right_segments;
		int mask;
		std::string addr_ff; //Address from file
		std::string comment;
		std::string subnet_string;
		std::string subnet_string_hex;
		std::bitset<16> binary_seg[8];
		std::bitset<16> bin_mask[8];
		std::bitset<16> sub_addr[8]; //address after correction from normal address to subnet address
		std::vector<std::string> all_segm_str;

	public:
		virtual ~Address(); //Default destructor of object
		bool corrMask(); //Get new from user if mask is not in 0-128 range.
		void gmfs(std::string one_line); //Get mask from string
		int printMask() const; //Print int value of mask
		void get_tmp_adr(std::string tmp_String_Addr); //Get temp address from source file to object parameter
		void dd_is(); //Check to IP is address with double ":" -> "::"
		int widd_left(); /*Where is double dot from left side, returns how many octets are before "::".
		If dd_is == false, then going to else with full addr func.*/
		int widd_right(); /*Where is double dot from left side, returns how many octets are after "::".
		Used when dd_is == true.*/
		void split_addr(); //Split string full addr to hex segments
		void str_to_bin(); //String to binary mode in bitset
		void print_entire_address(int opt); //If opt == 16 then address will have hex format.
		void iMask_to_bMask(int iMask); //Integer mask to bit_set mask. Bitset mask will be used to mask normal address
		void corrSubAddr(); //If addr is not subnet addr then change it to subnet addr
		void print_subnet(int opt); //Printing subnet address and add it to string variable
		void print_subnet_only(int opt); //Same as print_subnet() but without writing to string variable. Just print.
		void print_mask(int opt); //Just print bitset mask
		void set_ID(int pID); //Set parameter ID
		int get_ID() const; //Get parameter ID
		void tabs_c(); //To calcuate tabulators before address
		void set_root(); //To set bool variable root
		int get_tabs() const; //Get value from tabs var for formating end file
		void set_master(); //Set variable master
		void set_my_master(int id_m); //Set variable my_master id
		int get_my_master_ID() const; //Get value of my_master_id
		std::string get_substr(); //Get value of string with subnet address
		void check_submask(Address& prevAddr); //If mask of master is higher then set error true
		bool get_error_state() const; //Get value of bool var
		std::string get_comment() const; //Get value of comment value - string var
		std::string get_sub_str_hex() const; //Get value of subnet address with hex version
	};
#endif //ADDRESS_HPP