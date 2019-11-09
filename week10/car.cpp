#include "car.h"

car::car() : vehicle(){
	car_name = nullptr;
}

car::car(int _wheel_number, int _max_speed) : vehicle(_wheel_number, _max_speed) {
	//부모 생성자를 호출
}

car::car(int _wheel_number, int _max_speed, char* _car_name, bool _has_name) : vehicle(_wheel_number, _max_speed,  _has_name){
	car_name = _car_name;
}

char* car::get_car_name(){
	return this-> car_name;
}

const char* car::get_class_name(){
	const char* class_name = "car";
	return class_name;
}

void car::set_car_name(char* _car_name){
	car_name = _car_name;
}

