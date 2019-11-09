
#include "vehicle.h"

class bike : public vehicle {
private:
	char* bike_name;
	int bike_number;
public:
	bike();
	explicit bike(int _wheel_number, int _max_speed);
	explicit bike(int _wheel_number, int _max_speed, char* _bike_name);
	explicit bike(int _wheel_number, int _max_spedd, char* _bike_name, int bike_number);
	explicit bike(int _wheel_number, int _max_speed, char* _bike_name, int _bike_number, bool _has_name);

	int get_bike_number();
	char* get_bike_name();
	const char* get_class_name();

	void set_bike_name(char* _bike_name);
	void set_bike_number(int _bike_number);
};
