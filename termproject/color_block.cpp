#include "color_block.h"
#include "array_2d.h"
#include <algorithm>

using namespace std; //set container
//생성자 
color_block::color_block(block *b){
	this->s.insert(b);
	b->set_group(this);
}

//그룹 
void color_block::insert(set<block *> s){
	for(auto it = s.begin(); it != s.end(); it++)
	{
		this->s.insert((*it));
		(*it)->set_group(this);
	}
}

//get 
set<block *> color_block::get_set(){
	return this->s;
}

//4개이상이면 터트리기 위해서 몇개인지 반환
int color_block::get_set_size(){
	int size = 0;
	
	
	
	for(auto it = s.begin(); it != s.end(); it++)
		{
			size++;
		}
		return size;
	
	//:w
	//	return size;
}

//터트림? 
//color_block이 4개 이상일때 실행됨
void color_block::explosion(){
	int x;
	int y;
	for(auto it = s.begin(); it != s.end(); it++)
	{
		//array_2d::delete_block((*it)->get_x(), (*it)->get_y()); //게임 맵에서 블록 ->
		cout << "color_block explosion " << endl;
		x = (*it)->get_x();
		y = (*it)->get_y();
		(*it)->~block();// 소멸자 호출??
		
		//////모든 블록 아래로 이동 
		block * tmp;
		for(int i = y-1; i >= 0; i--)
		{
			tmp = array_2d::get_block(x, i);
			tmp->down_all();
			array_2d::insert(tmp->get_x(), tmp->get_y(), tmp);
		}
	}
	s.clear();
}
