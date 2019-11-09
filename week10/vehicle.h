#ifndef VEHICLE
#define VEHICLE

#include <iostream>

class vehicle {
protected:
	bool has_name;
	int wheel_number;
	int max_speed;
public:
	vehicle();
	explicit vehicle(int _wheel_number, int _max_speed);
	explicit vehicle(int _wheel_number, int _max_speed, bool _has_name);

	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();
	const char* get_class_name();

	void set_wheel_number(int _wheel_number);
	void set_max_speed(int _max_speed);
	void set_has_name(bool _has_name);
}; 
#endif //
