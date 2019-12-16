// big_block 이 쪼개지고 color_block에 같은 색끼리 결합됨 

#ifndef _COLOR_BLOCK_H
#define _COLOR_BLOCK_H

#include "block.h"
#include <set>

using namespace std;

//class block;
class color_block : public block {

	public: 	
		set<block *> s;
	public: 
		color_block(block * b);
		void insert(std::set<block *> s);
		std::set<block *> get_set();
		int get_set_size();
		void explosion();
};

#endif
