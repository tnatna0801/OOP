// tree 

#include "big_block.h"

class tree_block : public big_block {

	protected:
		static int cnt;
	public:
		static int get_count();
		tree_block(int c1, int c2, int c3);
		void rotate();
		_type types();

};
