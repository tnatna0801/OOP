//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

//mgr의 object 포인터를 리턴해줌. nullptr일 경우 nullptr을 리턴함
Object* unique_immut::get() const {
	if (this->_mgr == nullptr)
		return nullptr;
	else
		return this->_mgr->ptr;
}

//mgr이 nullptr이 아닌경우 mgr을 delete함
void unique_immut::release(){
	if (this->_mgr != nullptr)
		this->_mgr->~mgr();
}

//사칙연산 : mgr의 val끼리 연산을 한 결과를 새로운 unique_immut에 넣어 리턴 
unique_immut unique_immut::operator+(unique_immut &unique){
	int val = this->_mgr->ptr->get() + unique._mgr->ptr->get();
	this->release(); //사용한 unique_immut들은 모두 release한다. 
	unique.release();
	return unique_immut(new Object(val));
}
unique_immut unique_immut::operator-(unique_immut &unique){
	int val = this->_mgr->ptr->get() - unique._mgr->ptr->get();
	this->release(); //사용한 unique_immut들은 모두 release한다. 
	unique.release();
	return unique_immut(new Object(val));
}
unique_immut unique_immut::operator*(unique_immut &unique){
	int val = this->_mgr->ptr->get() * unique._mgr->ptr->get();
	this->release(); //사용한 unique_immut들은 모두 release한다. 
	unique.release();
	return unique_immut(new Object(val));
}
unique_immut unique_immut::operator/(unique_immut &unique){
	int val = this->_mgr->ptr->get() / unique._mgr->ptr->get();
	this->release(); //사용한 unique_immut들은 모두 release한다. 
	unique.release();
	return unique_immut(new Object(val));
}

// 기존의 mgr을 release하고 새로운 mgr로 대체한다. 
unique_immut& unique_immut::operator=(unique_immut& r){
	if(r._mgr != this->_mgr) { 
		release();
		this->_mgr = r._mgr;
	}
	return *this; //새로운 mgr이 자기자신이면 그대로 return 한다.
}

//mgr에 있는 object 포인터를 리턴
Object* unique_immut::operator->() {
	return this->_mgr->ptr;
}
} // end of namespace ptr
