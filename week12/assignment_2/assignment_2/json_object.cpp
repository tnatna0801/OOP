#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const std::string& str){
	json_object::_index = 0; // _index 초기화
	return json_object::parse(str.c_str(), str.length());
}

json_object* json_object::parse(const char * a, int length){

	while(_index < length){
	
		if(a[_index] == '{') //dictionary 시작
			 return json_dict::parse(a, length);
		else if (a[_index] == '\'' || a[_index] == '\"') // ' or "
			return String::parse(a, length, a[_index]);
		else if (a[_index] == '\0' || '}' || ')') // 문자열 끝
			return nullptr;
		else if (a[_index] == '[') //list 시작
			return json_list::parse(a, length); 
		else if (a[_index] <= '9' && a[_index] >= '0') // integer 
			return Integer::parse(a, length);
		_index++;
	}
}

