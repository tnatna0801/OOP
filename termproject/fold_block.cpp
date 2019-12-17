#include <iostream>
#include <algorithm>
#include "array_2d.h"
#include "big_block.h"
#include "fold_block.h"

int fold_block::cnt = 0;
//생성자
fold_block::fold_block(int c1, int c2, int c3){
	//block 낱개 생성 
	block *b1 = new block(c1);
	b1->set_location(b1->get_x(), b1->get_y()-1);
	block *b2 = new block(c2);
	b2->set_location(b2->get_x()-1, b2->get_y());
	block *b3 = new block(c3);
	//b3->set_location(b3->get_x()-1, b3->get_y());
	
	//big_block으로 묶음 
	big_block::v.push_back(b1);
	big_block::v.push_back(b2);
	big_block::v.push_back(b3);
	
	big_block::min_x = std::min({b1->get_x(), b2->get_x(), b3->get_x()});
	big_block::min_y = std::min({b1->get_y(), b2->get_y(), b3->get_y()});
	big_block::max_x = std::max({b1->get_x(), b2->get_x(), b3->get_x()});
	big_block::max_y = std::max({b1->get_y(), b2->get_y(), b3->get_y()});

	cnt = 0;
	//std::cout << v[1]->get_color() << "   fold" << std::endl;
}

//회전 
void fold_block::rotate(){
	cout << "회전 " << endl;
	int x1 = v[0]->get_x();
	int y1 = v[0]->get_y();

	int x2 = v[1]->get_x();
	int y2 = v[1]->get_y();
	
	int x3 = v[2]->get_x();
	int y3 = v[2]->get_y();

	if(cnt == 0)
	{
		v[0]->set_location(x1, y1+1);
		v[1]->set_location(x2, y2-1);
		v[2]->set_location(x3-1, y3);

		block * tmp = v[0];
		v[0] = v[1];
		v[1] = v[2];
		v[2] = tmp;
		cnt = 1;
	}
	else if(cnt == 1) // 180 ㄴ
	{
		array_2d::delete_block(x3, y3);
		v[0]->set_location(x1+1, y1);
		v[1]->set_location(x2, y2-1);
		v[2]->set_location(x3-1, y3);

		block * tmp = v[0];
		v[0] = v[1];
		v[1] = tmp;
		cnt = 2;

	}
	else if(cnt == 2)//array_2d::can_move(x2, y2+1)) // 270 
	{
		array_2d::delete_block(x3, y3);
		v[0]->set_location(x1+1, y1);
		v[1]->set_location(x2, y2+1);
		v[2]->set_location(x3, y3-1);

		block * tmp = v[0];
		v[0] = v[2];
		v[2] = v[1];
		v[1] = tmp;
		cnt = 3;

	}
	else if(cnt == 3)//array_2d::can_move(x1, y+1)) // 360
	{
		v[0]->set_location(x1+1, y1);
		v[1]->set_location(x2, y2+1);
		v[2]->set_location(x3-1, y3);
		
		block * tmp = v[1];
		v[1] = v[2];
		v[2] = tmp;
		cnt = 0;

	}
	array_2d::delete_block(x1, y1);
	array_2d::delete_block(x2, y2);
	array_2d::delete_block(x3, x3);
}

int fold_block::get_count(){
	return fold_block::cnt;
}

//종류 
big_block::_type fold_block::types(){
	return FOLD;
}

