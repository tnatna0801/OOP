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


bool make_big_block()
{
	int make = 0;

	srand((unsigned int)time(0));
	
	//블록 종류
	int block_kinds = (rand()%3) + 1; // 1~3
	
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

/*
void make_color_block(vector<block *> v){
	for(auto it = v.begin(); it != v.end(); it++)
	{

	}
}
*/

void move_block()
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
			//cout << "확인" << endl;
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
			}
		}
		else if((char)kInput == 's' || (char)kInput == 'S')
		{
			if(initB->can_down())
			{		
				initB->down();
			}
		}
		else if((char)kInput == 'x' || (char)kInput == 'X')
		{
			if(initB->can_down())
			{	
				initB->down_all();
			}
		}
		else if((char)kInput == 'e' || (char)kInput == 'E')
		{
			initB->rotate();
		}
		tmp->insert(initB->v);
}

int main()
{	

	cout << "***********START Puyo Puyo***********" << endl; 
	
	//객체 생성
	//array_2d *tmp = new array_2d();
	//big_block *initB;
	
	while(true) /////////////////////////////////////나중에 따로 함수 만들 것 : void game()
	{	
		cout << "score : " << tmp->get_score() << endl;
		if(!make_big_block())
		{	
			cout << "더이상 블록을 만들 수 없습니다." << endl;
			break;
		}
		//랜덤 
		/*srand((unsigned int)time(0));

		int block_kinds = 1;//rand() % 3 + 1; //( 0~2 )+ 1 
		//int block_color = rand() % 4 + 1; //( 0~3 )+ 1

		//array_2d *tmp = new array_2d();
		//big_block *bb = new big_block(); 
		if(!(tmp->can_make(block_kinds)))
			break;
		
		//big_block* initB;	
		//점수 
		cout << "score : " << tmp->get_score() << endl;
		
		//블록 생성
		//make_big_block(int type);
		//fold : 3
		int c1 = (rand() % 4) + 1; 
		int c2 = (rand() % 4) + 1;
		int c3 = (rand() % 4) + 1;

		if(block_kinds == 1 && tmp->can_make(1))
		{
			initB = new fold_block(c1, c2, c3);
			tmp->insert(initB->v);
			//bb->v.push_back(fb);
		}
		else if(block_kinds == 2 && tmp->can_make(2))
		{
			initB = new tree_block(c1, c2, c3);
			tmp->insert(initB->v);
			//bb->v.push_back(tb)
		}
		else if(block_kinds == 3 && tmp->can_make(3))
		{
			int c4 = (rand() %4) + 1;
			int c5 = (rand() %4) + 1;
			initB = new cross_block(c1, c2, c3, c4, c5);
			tmp->insert(initB->v);
			//bb->v.push_back()
		}
		else //can_make(1~3) 이 false인 경우 이므로 더이상 블록을 만들 수 없다. 
		{
			cout<< "더이상 블록을 만들 수 없습니다." << endl;
		//	break;
		}
		//tmp->insert(initB->v);
*/
		//생성후에 출력
		tmp->print();
		cout << endl;
		cout << endl;
		while(true)  /////////////////////////////big_block::move(int input)에 구현해야함  
		{
		
			/*	
			int kInput = getch();
			//if ((char)kInput ==  'q')//임시 종료 
			//	break;
			//
				a:좌측으로 한 칸 이동 
				d:우측으로 한 칸 이동
				s: 아래측으로 한 칸 이동
				x: 아래측으로 모두 내리기
				e: 90도 회전 시계방향
			//
			if((char)kInput == 'a' || (char)kInput == 'A')
			{	
				//cout << "확인" << endl;
				if(initB->can_left())
				{	
					initB->left();
					tmp->insert(initB->v);
				}
			}
			else if((char)kInput == 'd' || (char)kInput == 'D')
			{
				//cout << "???" << endl;
				if(initB->can_right())
				{	
					//cout<< "can 통과"<< endl;
					initB->right();
					tmp->insert(initB->v);
				}

			}
			else if((char)kInput == 's' || (char)kInput == 'S')
			{
				if(initB->can_down())
				{		
					cout << "확인" << endl;
					initB->down();
					tmp->insert(initB->v);
				}

			}
			else if((char)kInput == 'x' || (char)kInput == 'X')
			{
				if(initB->can_down())
				{	
					initB->down_all();
					tmp->insert(initB->v);
				}

			}
			else if((char)kInput == 'e' || (char)kInput == 'E')
			{
				initB->rotate();
				cout << "회전이 끝나고 array_2d에 삽입 " << endl;
				tmp->insert(initB->v);
			}
			cout << (char)kInput << "을 입력" << endl; //확인용 
			*/
			move_block();
			
			tmp->print();
			
			if( !initB->can_down() )
				break;
			//if( (char)kInput == 'q')
			//	break;
			
		}//키 입력 
		
		if(initB->down_all())
		{
	
			for(int index = initB->v.size() - 1; index >= 0; index--)
			{
					initB->v[index]->down_all();
					//tmp->insert((*it))
			}
			tmp->insert(initB->v);
		}

		/*
	//	color_block * cb1 = new color_block(initB->v[0]);
	//	color_block * cb2 = new color_block(initB->v[1]);
	//	color_block * cb3 = new color_block(initB->v[2]);
		////////////////////////////////////////////////////////////////////블록 검사 및 삭제 : 총체적 난국 
		////////////////////////////////////////////////////////////////////void boom(int type)을 만들어서 해야할 듯  
		block *b1 = initB->v[0];
		block *b2 = initB->v[1];
		block *b3 = initB->v[2]; // fold, tree
			
		color_block * cb1 = new color_block(b1);
		color_block * cb2 = new color_block(b2);
		color_block * cb3 = new color_block(b3);
		
		
		initB->~big_block();
		b1->find_merge();
		b2->find_merge();
		b3->find_merge();
		int s1 = b1->get_group()->get_set_size();
		int s2 = b2->get_group()->get_set_size();
		int s3 = b2->get_group()->get_set_size();
		//오류 잡기 
		cout << b1->get_color() <<" set : 개수 " << s1 << endl;
		cout << b2->get_color() <<" set : 개수 " << s2 << endl;
		cout << b3->get_color() <<" set : 개수 " << s3 << endl;
		
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
		//폭발 
		//if(s1 >= 4)
		//	array_2d::insert_explosion(b1->get_group());
		//if(s2 >= 4)
		//	array_2d::insert_explosion(b2->get_group());
		//if(s3 >= 4)
		//	array_2d::insert_explosion(b3->get_group());
*/
		
  	}

	//block 낱개로 풀기 
	//initB->~big_block();

	cout<< "***********GAME OVER***********"<<endl;

}

