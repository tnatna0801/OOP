#include "Integer.h"

//생성자
Integer::Integer(int value){
	this->_val = value;
}

//get value
int Integer::val(){
	return this->_val;
}

//set value
void Integer::set_val(const int& value){
	this->_val = value;
}

//parsing
//문자열 값을 숫자가 아닌 값이 올 때 까지 char 배열에 저장하다가 이외의 값이 오면 다음 index에 '\0'을 저장하여 문자열을 끝낸 후 atoi를 사용
json_object* Integer::parse(const char * a, int length){
	char tmp[] = "";
	int i = 0;
	while(a[_index] >= '0' && a[_index] <= '9'){ //숫자가 아닌 값이 올때까지 반복 
		//if(a[_index] != " ") //띄어쓰기 제거 
		tmp[i] = a[_index++];
		i++;
	}

	tmp[++i] = '\0';

	return new Integer(std::atoi(tmp));

}

//data type return 
json_object::_type Integer::type(){
	return INT;
}

std::string Integer::to_string(){
	return std::to_string(val());
}

