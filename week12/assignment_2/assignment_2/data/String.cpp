#include "String.h"

#include <iostream>

//생성자
String::String(const std::string& str){
	this->_val = str;
}

//get value
std::string String::val() {
	return this->_val;
}

//set value
void String::set_val(const std::string& str){
	this->_val = str;
}

//pasing
//base : ' or " => 나오면 문자열 종료
json_object* String::parse(const char * a, int length, char base){
	std::string tmp = "";
	//if(a[_index] == '\'' || '\"')
	_index++; // ' or "
	while(_index < length){
		if(base == a[_index]) 
			break;
		tmp += a[_index];
		_index++;
	}
	_index++; // ' or "
	return new String(tmp);
}

//data type return
json_object::_type String::type(){
	return STRING;
}

//string으로 
std::string String::to_string(){
	std::string result = "'" + val() + "'";
	return result;
}
