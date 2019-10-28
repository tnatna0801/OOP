//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}

//reduce count 1 and if count is 0 delete mgr
void shared_mut::release() {
	_mgr->count -= 1;
	//std::cout << "count: " << _mgr->count << std::endl;
	if (_mgr->count == 0)
		_mgr->~mgr();

} 

//return obj ptr if mgr is nullptr return nullptr 
Object* shared_mut::get() const {
	if (_mgr->ptr == nullptr)
		return nullptr;
	else
		return _mgr->ptr; 
}

//mgr의 count를 리턴
int shared_mut::count() {
	return _mgr->count;
}

//mgr의 count를 1 증가시켜줌
void shared_mut::increase() {
	_mgr->count += 1;
}

//사칙연산 : mgr의 val끼리 연산을 한 결과를 새로운 shared_mut에 넣어 리턴한다.
shared_mut shared_mut::operator+(const shared_mut &shared) {
	int val = this->_mgr->ptr->get() + shared._mgr->ptr->get();
	return shared_mut(new Object(val));
}

shared_mut shared_mut::operator-(const shared_mut &shared) {
	int val = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	return shared_mut(new Object(val));
}
shared_mut shared_mut::operator*(const shared_mut &shared) {
	int val = this->_mgr->ptr->get() * shared._mgr->ptr->get();
	return shared_mut(new Object(val));
}
shared_mut shared_mut::operator/(const shared_mut &shared) {
	int val = this->_mgr->ptr->get() / shared._mgr->ptr->get();
	return shared_mut(new Object(val));
}

//기존의 mgr을 release하고 새로운 mgr로 대체한뒤 increase 한다. 
shared_mut& shared_mut::operator=(const shared_mut &r) {
	release();
	this->_mgr = r._mgr;
	increase();
	return *this;
}

//mgr에 있는 object 포인터를 리턴한다. 
Object* shared_mut::operator->() {
	return this->_mgr->ptr;
}

} // end of namespace ptr
