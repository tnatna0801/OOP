#include "array_2d.h"
#include "big_block.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"

using namespace std;


int big_block::min_x = 0;
int big_block::min_y = 0;
int big_block::max_x = 0;
int big_block::max_y = 0;
/*
vector<block *> big_block::v;
*/
//소멸자 
big_block::~big_block(){
	
	v.erase(v.begin(), v.end());
	
	min_x = 0;
	min_y = 0;
	max_x = 0;
	max_y = 0;

}

//overriding
void big_block::rotate(){
}

bool big_block::can_left(){
	int check= 0;
	int dif_x = (this->max_x) - (this->min_x);
	int dif_y = (this->max_y) - (this->min_y);
//	cout << dif_x << "   " << dif_y << endl;
	//fold : v[0], v[1] 확인 
	//tree : v[0], v[1], v[2] 확인
	//cross :v[0], v[1], v[4] 확인

	if(v[0]->can_left())// && v[1]->can_left())
		check++;
	
	switch(dif_x)
	{
		case 0: // tree
			if(tree_block::get_count() == 0) // 가로
			{
				if(check==1)
					return true;
				else
					break;
			}
			else if(tree_block::get_count() == 1)
			{	
				if(v[1]->can_left()&&v[2]->can_left())
					check++;
				if(check == 2)
					return true;
				else
					break;
			}
			break;
		case 1: // fold
			if(fold_block::get_count() == 0 || fold_block::get_count() == 1)//array_2d::can_move(x2, y2-1) || array_2d::can_move(x1+1, y1))
			{	
//				cout << "2번째 블록   " <<  v[1]->get_color() << endl;
				if(v[1]->can_left())
					check++;
				else
					break;
			}
			else if(fold_block::get_count() == 2 || fold_block::get_count() == 3)//array_2d::can_move(x2, y2+1) || array_2d::can_move(x1, y1+1))
			{
//				cout << "left:  3-4번째 모양" << v[2]->get_color() << endl; 
				if(v[2]->can_left())
					check++;
				else
					break;
			}

			if(check == 2)
				return true;	
			break;
		case 2: // cross
			if(v[1]->can_left() && v[4]->can_left())
				check++;
			if(check == 2)
				return true;
			break;
	}
	
	return false;
}


bool big_block::can_right(){
	int check = 0; // 우측 으로 갈 수 있는지 확인  
	int dif_x = (this->max_x) - (this->min_x);
	//fold : v[0], v[2] 확인
	//tree : v[0], v[1], v[2] 확인
	//cross :v[0], v[3], v[4] 확인

	switch(dif_x)
	{
		case 0: // tree
			if(tree_block::get_count() == 0)
			{
				if(v[0]->can_right() && v[1]->can_right() && v[2]->can_right())
					check++;
			}
			else if(tree_block::get_count() == 1)
			{
				if(v[2]->can_right())
					check++;
			}
			if(check == 1)
				return true;
			break;
		case 1: // fold
			if(fold_block::get_count() == 0 || fold_block::get_count() == 1)
			{
				if(v[0]->can_right() && v[2]->can_right())
					check++;
			}
			else if(fold_block::get_count() == 2 || fold_block::get_count() == 3)
			{
				if(v[1]->can_right() && v[2]->can_right())
					check++;
			}
			if(check == 1)
				return true;
			break;
		case 2: // cross
			if(v[0]->can_right() && v[3]->can_right() && v[4]->can_right())
				check++;
			//cout<<"check_2"<<check<<endl;
			if(check==1)
				return true;
			break;
	}
	return false;

}

bool big_block::can_down(){
	int check = 0; // 아래로 갈 수 있는지 확인  
	int dif_x = (this->max_x) - (this->min_x); //종류 구분용

	//fold : v[1], v[2] 확인
	//tree : v[2] 확인
	//cross :v[1], v[3], v[4] 확인

//	cout << "v[3]" << v[2]->get_color() << endl;
	switch(dif_x)
	{
		case 0: // tree
			//회전해서 나오는 모양 ---
			if(tree_block::get_count() == 0) // 세로
			{
				if(v[2]->can_down())
					check++;
			}
			else if(tree_block::get_count() == 1) // 가로
			{
				if(v[0]->can_down() && v[1]->can_down() && v[2]->can_down())
					check++;
			}
			if(check == 1)
				return true;
			break;
		case 1: // fold
			//회전해서 나오는 모양 다 고려함  
			if(v[2]->can_down())
			{
				check++;
			}
			if(fold_block::get_count() == 2 || fold_block::get_count() == 3) //array_2d::can_move(x2, y2-1) || array_2d::can_move(x1+1, y1))
			{	
				if(check ==1)
					return true;
			}
			else if(fold_block::get_count() == 0 || fold_block::get_count() == 1)//array_2d::can_move(x2, y2+1) || array_2d::can_move(x1, y1+1))
			{
				if(v[1]->can_down())
					check++;
				if(check==2)
					return true;
			}
			break;
		case 2: // cross
			if(v[4]->can_down() && v[3]->can_down() && v[1]->can_down())
				check++;
			if(check == 1)
				return true;
			break;
	}
		
	return false;

}

void big_block::left(){

	for(auto it = v.begin(); it != v.end(); it++)
	{
		(*it)->left();
	}
}

void big_block::right(){
	for(auto it = v.begin(); it != v.end(); it++)
	{
		(*it)->right();
	}
}

//왜 bool일까?/////////////////////////////////////////////////////////////수정
void big_block::down(){
	
	for(auto it = v.begin(); it != v.end(); it++)
	{
		(*it)->down();
	}
	
}
////////////////////////////////////////////////////////////////////////////////수정 
void big_block::down_all(){
	while(can_down())
	{
		for(auto it = v.begin(); it != v.end(); it++)
		{
			(*it)->down();
		}
	}
}

//유저가 입력한 키값을 받아서 move 
bool big_block::move(int input){
	/*
	1 : 좌측
	2 : 우측 
	3 : 아래
	4 : 한꺼번에 아래 
	5 : 회전 
	 */
	switch(input)
	{
		case 1:
			if(this->can_left())
			{
				this->left();
			}
			break;
		case 2:
			if(this->can_right())
			{
				this->right();
			}
			break;
		case 3:
			if(this->can_down())
			{
				this->down();
			}
			break;
		case 4:
			if(this->can_down())
			{
				this->down_all();
			}
	}


}

big_block::_type big_block::types(){};
