#include "tree_block.h"
#include "array_2d.h"

int tree_block::cnt = 0;
//생성자
tree_block::tree_block(int c1, int c2, int c3){
	//block 낱개 생성 
	block *b1 = new block(c1);
	b1->set_location(b1->get_x(), b1->get_y() - 1);
	block *b2 = new block(c2);//default
	block *b3 = new block(c3);
	b3->set_location(b3->get_x(), b3->get_y() + 1);
	
	//big_block올 묵음 
	//big_block 클래스의 v 
	big_block::v.push_back(b1);
	big_block::v.push_back(b2);
	big_block::v.push_back(b3);

	big_block::min_x = 2;
	big_block::min_y = 0;
	big_block::max_x = 2;
	big_block::max_y = 2;
	cnt = 0;
}

void tree_block::rotate(){
	int x1 = v[0]->get_x();
	int x2 = v[2]->get_x();
	int y1 = v[0]->get_y();
	int y2 = v[2]->get_y();

	if(v[1]->get_y() < y2) // 세로 
	{	
		if(array_2d::can_move(x1 + 1, y1 + 1) && array_2d::can_move(x2 - 1, y2 - 1))
		{
			v[0]->set_location(x1 + 1, y1 + 1);
			v[2]->set_location(x2 - 1, y2 - 1);

			block * tmp = v[0];
			v[0] = v[2];
			v[2] = tmp;
			cnt = 1;
		}
	}
	else // --- 가로
	{
	//	cout << "ㄱ가로 " << endl;
		if(array_2d::can_move(x1+1, y1-1) && array_2d::can_move(x2-1, y2+1))
		{
			v[0]->set_location(x1 + 1, y1-1);
			v[2]->set_location(x2-1, y2+1);
			cnt = 0;
		}
	
	}
	
	array_2d::delete_block(x1, y1);
	array_2d::delete_block(x2, y2);
}

big_block::_type tree_block::types(){
	return TREE;
}

int tree_block::get_count(){
	return cnt;
}
