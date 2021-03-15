#pragma once
#ifndef ADDRESS_HPP
#define ADDRESS_HPP
#include <string>
#include <bitset>
#include <iostream>

class Address 
{
	private:
		long octets[8][4];
		std::string octets_s[8];
	public:
	Address();
	virtual ~Address();
	void hex_to_binary(std::string hex_part);
};


#endif //ADDRESS_HPP