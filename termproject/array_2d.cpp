#include "block.h"
#include "color_block.h"
#include "array_2d.h"

//using namespace std;

int array_2d::score = 0; //score은 static 변수로 값을 공유한다. 
block *array_2d::block_array[H][W] = {0};
set<color_block *> array_2d::explosion_s;

//생성자
array_2d::array_2d(){
	
	array_2d::score = 0; //초기화 
	for(int i = 0; i< H; i++)
	{	
		for(int j = 0; j < W; j++)
		{	
			block * zero_b = new block(0);
			zero_b->set_location(j, i);
			array_2d::block_array[i][j] =  zero_b;//new block(0); //0은 비어있는 것
			//array_2d::block_array[i][j]->set_location(j, i); //x, y
		}
	}

	/*{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	*/
	
}

//블록이 생성 가능한지 확인 (type : Tree, Fold, Cross)
bool array_2d::can_make(int type){
	// 1:fold, 2:tree, 3:cross
	if(type == 1)
	{
		if(block_array[1][2]->get_color() != 0 || block_array[1][1]->get_color() != 0)  
			return false;
	}
	else if (type == 2)
	{
		if(block_array[2][2]->get_color() != 0)
			return false;
	}
	else if(type == 3)
	{
		if(block_array[2][2]->get_color() != 0 || block_array[1][1]->get_color() != 0 || block_array[1][3]->get_color() != 0)
			return false;
	}
	return true; //구현 x
}

//작은 블럭 삭제  
void array_2d::delete_block(int x, int y){
	block_array[y][x] = new block(0);
	block_array[y][x]->set_location(x, y);
}

//big_block을 맵에 넣음 ==> insert(int, int, block*) 호출
void array_2d::insert(vector<block *> v){
	for(auto it = v.begin(); it != v.end(); it++)
	{
		insert((*it)->get_x(), (*it)->get_y(), *it);	
	}
	//cout << "됐다" << endl;
}

//big_block의 작은 block들을 맵에 넣음 
void array_2d::insert(int x, int y, block *b){
	block_array[y][x] = b;
	b->set_location(x, y);
}

//get block
//for문을 사용해서 매개변수 x, y와 일치하는 블럭을 가져옴
block * array_2d::get_block(int x, int y){
	if(x < W && x >= 0)
	{
		if(y>=0 && y < H)
		{
			return block_array[y][x];
		}
	} 
	return nullptr;
}

//해당하는 좌표로 이동이 가능한지 확인
bool array_2d::can_move(int x, int y){

	if( x >= 0 && x < W)
	{
		if( y>=0 && y< H)
		{
			if(block_array[y][x]->get_color() == 0)
			{
//				cout << "음수가 나오면 안됨" << x << endl;
				return true;
			}
			return false;
		}
		return false;
	}
	return false;

}

//게임 맵 출력 
void array_2d::print(){
	for(int i = 0; i< H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			std::cout << block_array[i][j]->get_color() << "\t";
			if(j == 4)
				cout << std::endl;
		}
		cout << std::endl;
	}

}

//동시에 여러개 터질 경우 고려
void array_2d::insert_explosion(color_block *group){
//	cout << "insert_explosion" << " "  << group->get_set_size() <<endl;
	array_2d::explosion_s.insert(group);
	//array_2d::remove_explosion(group);
	
	
	//grey를  찾는다. 
	if(group->get_set_size() >= 4) // grey는 옆의 블록이 터지면 터진다. 
	{
		int x;
		int y;
	
		for(auto it = group->s.begin(); it != group->s.end(); it++)
		{
			x = (*it)->get_x();
			y = (*it)->get_y(); 
			if(get_block(x-1, y) != nullptr)
			{
				block * tmp = array_2d::get_block(x-1, y);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
			if(get_block(x+1, y) != nullptr)
			{
				block * tmp = array_2d::get_block(x+1, y);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
			if(get_block(x, y-1) != nullptr)
			{
				block * tmp = array_2d::get_block(x, y-1);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
			if(get_block(x, y+1) != nullptr)
			{
				block * tmp = array_2d::get_block(x, y+1);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
		}	
	}
	/*
	else if(group->get_set_size() == 1) //grey는 옆의 블록이 터지면 같이 터진다. grey옆의 grey인 경우 	
	{	
		auto iterator = group->s.begin();
		if((*iterator)->get_color() ==1)
		{
			int x = (*iterator)->get_x();
			int y = (*iterator)->get_y(); 
			if(get_block(x-1, y) != nullptr)
			{
				block * tmp = array_2d::get_block(x-1, y);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
			if(get_block(x+1, y) != nullptr)
			{
				block * tmp = array_2d::get_block(x+1, y);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
			if(get_block(x, y-1) != nullptr)
			{
				block * tmp = array_2d::get_block(x, y-1);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}
			if(get_block(x, y+1) != nullptr)
			{
				block * tmp = array_2d::get_block(x, y+1);
				if(tmp->get_color() == 1)
				{
					array_2d::insert_explosion(tmp->get_group());
				}
			}

		}	
	}
	*/
}

void array_2d::remove_explosion(color_block *group){
	explosion_s.erase(group);
}

//터트릴 수 있는지 확인
bool array_2d::can_explosion(){
	//int count = 0;
	
	block * boom;
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			//if() color 가 0 이 아닐 때
			boom = array_2d::block_array[i][j]; //->get_group();
			if(boom->get_color() != 0)
			{
				if(boom->get_group()->get_set_size() >= 4)
				{
					return true;
				}
			}
		}
	}
	return false; 
	
	//return true; //구현 x
}


// 블록 검사
// 블록 삭제 
void array_2d::explosion(){
	//delete_block();
	block * boom;
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			boom = array_2d::block_array[i][j]; //->get_group();	
			if(boom->get_color() != 0)
			{
				if(block::can_explosion(boom))
				{
					array_2d::insert_explosion(boom->get_group());
				}
			}
		}
	}
		
	for(auto it = array_2d::explosion_s.begin(); it != array_2d::explosion_s.end(); it++)
	{
		(*it)->explosion();

		array_2d::remove_explosion((*it));
	
	}
		//array_2d::delete_block();
		//array_2d::remove_explosion();
	
	array_2d::score += 1; //explosion_s의 모든 원소들을 explosion했으므로 점수 증가 
}

//score 반환 
int array_2d::get_score(){
	return array_2d::score;
}
/*
void array_2d::set_score(){
	score++;
}

*/
