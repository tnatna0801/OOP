// fold 모양
//#include "block.h"

#include "big_block.h"

class fold_block : public big_block {
	
	protected:
		static int cnt;
	public:	
		static int get_count();
		fold_block(int c1, int c2, int c3);
		void rotate();
		_type types();


};
