// 생성된 블록 
// fold_block, tree_block, cross_block이 상속?

#ifndef _BIG_BLOCK_H
#define _BIG_BLOCK_H

#include <vector>
#include "block.h"
#include <iostream>

using namespace std;

class big_block : public block {
	protected:
		enum _type {
			// block kinds
			FOLD,
			TREE,
			CROSS
		};
	
	public:	
		vector<block *> v;
		static int min_x, min_y, max_x, max_y;
	
	public:
	//	vector<block *> v;
		~big_block();
		virtual void rotate();
		bool can_left();
		bool can_right();
		bool can_down();
		void left();
		void right();
		void down();
		void down_all();
		bool move(int input);
		virtual _type types(); // big_block 종류 
};

#endif
