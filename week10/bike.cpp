#include "bike.h"

bike::bike() : vehicle() {
	bike_name = nullptr;
	bike_number = 0;
}

bike::bike(int _wheel_number, int _max_speed) : vehicle(_wheel_number, _max_speed){
}

bike::bike(int _wheel_number, int _max_speed, char* _bike_name) : vehicle(_wheel_number, _max_speed) {
	bike_name = _bike_name;
}

bike::bike(int _wheel_number, int _max_speed, char* _bike_name, int _bike_number) : vehicle(_wheel_number, _max_speed) {
	bike_name = _bike_name;
	bike_number = _bike_number;
}

bike::bike(int _wheel_number, int _max_speed, char* _bike_name, int _bike_number, bool _has_name) : vehicle(_wheel_number, _max_speed, _has_name){
	bike_name = _bike_name;
	bike_number = _bike_number;
}

int bike::get_bike_number() {
	return this->bike_number;
}

char* bike::get_bike_name() {
	return this->bike_name;
}

const char* bike::get_class_name(){
	const char* class_name = "bike";
	return class_name;
}

void bike::set_bike_name(char* _bike_name){
	bike_name = _bike_name;
}

void bike::set_bike_number(int _bike_number){
	bike_number = _bike_number;
}


