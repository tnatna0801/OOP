
#include "vehicle.h"

class car : public vehicle {
private:
	char* car_name;
public: 
	car();
	explicit car(int _wheel_number, int _max_speed);
	explicit car(int _wheel_number, int _max_speed, char* _car_name, bool _has_name);

	char* get_car_name();
	const char* get_class_name();
	void set_car_name(char* _car_name);
};

