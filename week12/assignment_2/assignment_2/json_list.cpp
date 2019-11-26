#include "json_list.h"

//생성자
json_list::json_list(){}

//
json_object* json_list::parse(const char* a, int length){
	
	json_list* list = new json_list();
	if(a[_index] == '[')
		_index++;
	
	while(a[_index] != ']'){
		if(a[_index] == ',' || a[_index] == ' ' || a[_index] == '\n' || a[_index] == '\t')
			_index++;
		else {
			json_object* _value = json_object::parse(a, length);
			list->v.push_back(_value);
			_index++;
		}
	}
	_index++; // ']'
	return list;
}

//return value
json_object* json_list::operator[](int key) const{
	
	if(v.empty() || v.size() <= key)
		return nullptr;
	return v[key];

}

//
json_object::_type json_list::type(){
	return LIST;
}

//
std::string json_list::to_string(){
	std::string result = "[";

	for(auto it = v.begin(); it != v.end(); it++){
		result += (*it)->to_string();
		if(it+1 != v.end())
			result += ",";
	}
	result += "]";
	return result;
}
