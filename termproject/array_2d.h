//블록 관리 
// 주로 static으로 구현하여 다른 클래스에서 사용 
#ifndef _ARRAY_2D_H
#define _ARRAY_2D_H

#include <set>
#include <vector>
#include <iostream>
#include "block.h"
#include "big_block.h"
//#include "color_block.h"

#define W 5
#define H 12


class array_2d : public big_block {

protected:
	static block *block_array[H][W];
	static std::set<color_block *> explosion_s; // 터짐 
	static int score;

public:
	//static block *block_array[H][W];
	array_2d();
	bool can_make(int type);
	static void delete_block(int x, int y);
	static void insert(std::vector<block *> v);
	static void insert(int x, int y, block * b);
	static block *get_block(int x, int y);
	static bool can_move(int x, int y);
	void print();
	static void insert_explosion(color_block *group);
	static void remove_explosion(color_block *group);
	static bool can_explosion();
	static void explosion();
	static int get_score();
};
#endif
