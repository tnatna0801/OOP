#include "color_block.h"
#include "block.h"
#include "array_2d.h"
#include "big_block.h"

//int block::color = 0;
block::block(){}

//생성자 
block::block(int color){
	this->color = color;
	this->x = 2;
	this->y = 1;
	this->group = nullptr;
}

//소멸자 
block::~block(){
	array_2d::delete_block(this->x, this->y); // 
	//this->color = 0;
	//this->x = 2;
	//this->y = 1;
	//this->group = nullptr;
}

//get color
int block::get_color(){
	return this->color;
}
void block::set_color(int color){
	this->color = color;
}
//get x좌표 
int block::get_x(){
	return this->x;
}

//get y좌표
int block::get_y(){
	return this->y;
}

//set color block group 
//어떤 그룹에 속했는지
void block::set_group(color_block *group){	
	if(group != nullptr)
		this->group = group;
}

//속한 color_block return
color_block * block::get_group(){
	return this->group;
}

//x, y 좌표 설정
void block::set_location(int x, int y){
	this->x = x;
	this->y = y;
}

//좌측으로 한칸 이동 가능한지 확인
bool block::can_left(){

	if(array_2d::can_move(this->get_x()-1, this->get_y()))
		return true;
	else
		return false;
}
//우측으로 한칸 이동 가능한지 확인
bool block::can_right(){
	if(array_2d::can_move((this->get_x())+1, (this->get_y())))
		return true;
	else
		return false;
}
//아래로 한칸 이동 가능한지 확인
bool block::can_down(){
	if(array_2d::can_move((this->get_x()), (this->get_y())+1))
		return true;
	else
		return false;
}
//오른쪽으로 이동
void block::right(){
	array_2d::delete_block(get_x(), get_y());
	this->set_location(get_x()+1, get_y());	
}
//왼쪽으로 이동
void block::left(){
	array_2d::delete_block(get_x(), get_y());
	this->set_location(get_x()-1, get_y());
	//big_block::min_x = get_x();
	//cout << "변경된 min_x "  << big_block::min_x << endl;
}

void block::down(){
	array_2d::delete_block(get_x(), get_y());
	this->set_location(get_x(), get_y()+1);
}
//한번에 끝까지 아래로 이동
void block::down_all(){
	while(true)
	{
		if(!array_2d::can_move(get_x(), get_y()+1))
			break;
		down();
		//cout << "block의 down_all" << endl;
	//	array_2d::delete_block(get_x(), get_y());
	//	this->set_location(get_x(), get_y() + 1);	
		//cout << this->get_color() <<"1씩 감소" <<get_y() << endl;
	}
	array_2d::insert(get_x(), get_y(), this);
}

//블록끼리 같은 색인지 확인하고 결합할 수 있으면 결합한다. 
bool block::can_merge(block *b){
	//b->
	if(b != nullptr)
	{	
		if(b->get_group() != this->get_group()) // 이미 결합된 경우는 제외 
		{
			if(b->get_color() == this->get_color() && b->get_color() != 1)
				return true; // 구현 x
		}
	}
	return false;
}

//color_block안의 원소(블록)이 4개 이상이면 터트릴 수 있다. 
bool block::can_explosion(block *b){
	if(b->get_group()->get_set_size() >= 4)
	{
		return true;	
	}
	return false;
}

//merge는 color_block끼리 합병 
void block::merge(block *b){

	this->get_group()->color_block::insert(b->get_group()->s);	
}

//블록의 주변 블록들을 살펴 보면서 같은 색의 블록 끼리 결합한다. 
// array_2d::get_block 이용 
void block::find_merge(){
	
	int tmp_x = this->get_x();
	int tmp_y = this->get_y();

	block * l = array_2d::get_block(tmp_x-1, tmp_y);
	block * r = array_2d::get_block(tmp_x+1, tmp_y); 
	block * u = array_2d::get_block(tmp_x, tmp_y-1);
	block * d = array_2d::get_block(tmp_x, tmp_y+1); 

	//좌, 우, 위 

	if(can_merge(l)) 
		merge(l);
	if(can_merge(r))
		merge(r);
	if(can_merge(u))
		merge(u);
	if(can_merge(d))
	{	
		//cout << "한번만 나와야함" <<endl;
			merge(d);
	}
}



