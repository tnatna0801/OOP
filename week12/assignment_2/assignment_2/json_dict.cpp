#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"

//생성자
json_dict::json_dict(){}

//set dictionary
void json_dict::put(json_object* key, json_object* val){
	int check = find(key);
	if(check == -1) 
		v.push_back(std::make_pair(key, val));
	else // vector에 이미 key와 동일한 key가 존재함 
		v[check] = std::make_pair(key, val); // 새로운 val로 초기화 
}

//find index
int json_dict::find (json_object* key){
	
	std::string tmp = key->to_string();
	int index = 0;

	for(auto it = v.begin(); it != v.end(); it++){
		if((it -> first -> to_string()).compare(tmp) == 0)
			return index;
		index++;
	}
	return -1; //찾지 못하면 -1 return
}

//
json_object* json_dict::parse(const char * a, int length){
	json_dict* dict = new json_dict();
	if (a[_index] == '{')
		_index++; // a[_index] = '{'
	while(_index < length){	
		if(a[_index] == ',' || a[_index] == ' ' || a[_index] == '\n' || a[_index] == '\t'){
			_index++;
			continue;
		}
		json_object* key; // key 값은 dict와 list를 제외한 값만 취급
		if(a[_index] == '\'' || '\"')
			key = String::parse(a, length, a[_index]);
		else if(a[_index] <= '9' && a[_index] >= '0')
			key = Integer::parse(a, length);
		if(a[_index] == ' ')
			_index++;
		json_object* val = json_object::parse(a, length);	
		
		dict->put(key, val);
		if(a[_index] == '}')
			break;
		//if( a[_index] == ',' || a[_index] == ' ')
		_index++;

	}
	_index++; // a[_index] = '}'
	return dict;
}

json_object* json_dict::operator[](json_object* key) const{
	
	if(key->type() == INT){
		return json_dict::operator[](atoi(key->to_string().c_str()));
	}
	else{ // key가 string일 경우 
		return json_dict::operator[](key->to_string());
	}
	return nullptr;
}

json_object* json_dict::operator[](const std::string& key) const{
	//vector을 탐색해서 key와 일치하는 value를 반환한다. 
	for(auto it = v.begin(); it != v.end(); it++){
		if(it->first->type() == STRING){
			if(it->first->to_string().compare(key) == 0)
				return it->second;
		}
	}
	return nullptr;
}

json_object* json_dict::operator[](int key) const{
	for(auto it = v.begin(); it != v.end(); it++){
		if(it->first->type() == INT){
			if(it->first->to_string().compare(std::to_string(key)) == 0)
				return it->second;
		}
	}
	return nullptr;
}

//type return
json_object::_type json_dict::type(){
	return DICT;
}

//string 으로 반환 
std::string json_dict::to_string(){
	std::string result = "{";
	// 'key' : 'value'
	for(auto it = v.begin(); it != v.end(); it++){
		result += it->first->to_string() + ": " + it->second->to_string();
		if(it+1 != v.end()){
			result += ", ";
		}
	}
	result += "}";
	return result;
}
