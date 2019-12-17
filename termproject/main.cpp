#include "array_2d.h"
#include "block.h"
#include "big_block.h"
#include "color_block.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"

#include <iostream>
#include <ctime>
//#define M_H 12
#include "getch.h"

using namespace std;

//객체 생성
array_2d *tmp = new array_2d();
big_block *initB;

////////big_block 생성
bool make_big_block()
{
	int make = 0;

	srand((unsigned int)time(0));
	
	//블록 종류
	int block_kinds = (rand()%3) + 1; 
	
	if(!(tmp->can_make(block_kinds)))
		return make;


	//각 블록의 색깔 
	int c1 = (rand() % 4) + 1; 
	int c2 = (rand() % 4) + 1;
	int c3 = (rand() % 4) + 1;

	if(block_kinds == 1 && tmp->can_make(1))
	{
		initB = new fold_block(c1, c2, c3);
		make++;
	}
	else if(block_kinds == 2 && tmp->can_make(2))
	{
		initB = new tree_block(c1, c2, c3);
		make++;
	}
	else if(block_kinds == 3 && tmp->can_make(3))
	{
		int c4 = (rand() %4) + 1;
		int c5 = (rand() %4) + 1;
		initB = new cross_block(c1, c2, c3, c4, c5);
		make++;
	}
	tmp->insert(initB->v);
	return make;
}

////유저에게 키 입력을 받고 블록 이동
////can_right()나 can_left()가 가능하더라도 가장 아랫 블록이 can_down이라면 종료 ==> 아래에 닿는 순간 종료 
void move_block()
{
	while(initB->can_down())
	{
		int kInput = getch();
		/*
			a:좌측으로 한 칸 이동 
			d:우측으로 한 칸 이동
			s: 아래측으로 한 칸 이동
			x: 아래측으로 모두 내리기
			e: 90도 회전 시계방향			
		 */
		if((char)kInput == 'a' || (char)kInput == 'A')
		{	
			if(initB->can_left())
			{	
				initB->left();
			}
		}
		else if((char)kInput == 'd' || (char)kInput == 'D')
		{
			if(initB->can_right())
			{	
				initB->right();
				//tmp->insert(initB->v);
			}
		}
		else if((char)kInput == 's' || (char)kInput == 'S')
		{
			if(initB->can_down())
			{		
				initB->down();
				tmp->insert(initB->v);
			}
			else
				break;
		}
		else if((char)kInput == 'x' || (char)kInput == 'X')
		{
			if(initB->can_down())
			{	
				initB->down_all();
				tmp->insert(initB->v);

			}
			else
				break;
		}
		else if((char)kInput == 'e' || (char)kInput == 'E')
		{
			initB->rotate();
		}
		tmp->insert(initB->v);
		cout << endl;
		cout << endl;
		cout << "score : " << tmp->get_score() <<endl;
		tmp->print();
		continue;
	}
}

/*
 void game(){
 	
 
 }

 */

void block_checking(){
	if(initB->v.size() == 3)
	{	
		block *b1 = initB->v[0];
		block *b2 = initB->v[1];
		block *b3 = initB->v[2]; // fold, tree
			
		color_block * cb1 = new color_block(b1);
		color_block * cb2 = new color_block(b2);
		color_block * cb3 = new color_block(b3);

		b1->find_merge();
		b2->find_merge();
		b3->find_merge();
		cout << "big_1 : " << b1->get_color() << "    " << b1->get_group()->get_set_size() << "============"  << endl;
	
	}
	else if(initB->v.size() == 5)
	{
		block *b1 = initB->v[0];
		block *b2 = initB->v[1];
		block *b3 = initB->v[2]; // fold, tree
		block *b4 = initB->v[3];
		block *b5 = initB->v[4];
			
		color_block * cb1 = new color_block(b1);
		color_block * cb2 = new color_block(b2);
		color_block * cb3 = new color_block(b3);
		color_block * cb4 = new color_block(b4);
		color_block * cb5 = new color_block(b5);

		b1->find_merge();
		b2->find_merge();
		b3->find_merge();
		b4->find_merge();
		b5->find_merge();
	}
	initB->~big_block();

	block * new_merge;
	while(array_2d::can_explosion())
	{
		array_2d::explosion();
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j<W; j++)
			{
				new_merge = array_2d::get_block(j, i);
				if(new_merge != nullptr)
				{
					if(new_merge->get_color() != 0)
					{
						new_merge->find_merge();
					}
				}
			}
		}		
	}
} 

int main()
{	
	cout << "***********START Puyo Puyo***********" << endl; 
	
	while(true)
	{	
		cout << "score : " << tmp->get_score() << endl;
		cout << endl;

		if(!make_big_block())
		{	
			cout << "더이상 블록을 만들 수 없습니다." << endl;
			break;
		}

		//생성후에 출력
		tmp->print();
		cout << endl;
		cout << endl;
		
		move_block();// 키입력 while문으로 반복함 
			
		//cout << endl;
		//cout << endl;
		//tmp->print();
		
		//모두 내리기
		for(int index = initB->v.size() - 1; index >= 0; index--)
		{
				initB->v[index]->down_all();
				//tmp->insert((*it))
		}
		tmp->insert(initB->v);

		//블록 검사 및 병합 
		block_checking();		
  	}
	cout<< "score : " << tmp->get_score() << endl;
	cout<< "***********GAME OVER***********"<<endl;
}

