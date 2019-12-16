//#include "big_block.h"
//#include "block.h"
#include "cross_block.h"

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5){
	//block 낱개 생성
	block *b1 = new block(c1);
	b1->set_location(b1->get_x(), b1->get_y()-1);
	
	block *b2 = new block(c2);
	b2->set_location(b2->get_x()-1, b2->get_y());
	
	block *b3 = new block(c3);
	//b3->set_location(b3->get_x(), b3->get_y()-1);
	
	block *b4 = new block(c4);
	b4->set_location(b4->get_x() + 1, b4->get_y());
	
	block *b5 = new block(c5);
	b5->set_location(b5->get_x(), b5->get_y() + 1);

	//big_block으로 묶음
	big_block::v.push_back(b1);
	big_block::v.push_back(b2);
	big_block::v.push_back(b3);
	big_block::v.push_back(b4);
	big_block::v.push_back(b5);

	big_block::min_x = 1;
	big_block::min_y = 0;
	big_block::max_x = 3;
	big_block::max_y = 2;

}

//시계방향
void cross_block::rotate(){
 	//cout << "??????" << endl;	
	int tmp = big_block::v[0]->get_color();
	big_block::v[0]->set_color(big_block::v[1]->get_color());
	big_block::v[1]->set_color(big_block::v[4]->get_color());
	big_block::v[4]->set_color(big_block::v[3]->get_color());
	big_block::v[3]->set_color(tmp);

}


big_block::_type cross_block::types(){
	return CROSS;
}

