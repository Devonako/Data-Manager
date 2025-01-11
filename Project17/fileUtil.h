#pragma once
#include <string>
#define s std::string
#define var auto

class filerr {
private:
	std::string name;
	std::string data;
	s get_data(s name) {

	}
public:

	filerr(s name) {
		this->name = name;
		get_data(name);
	}
	s get_line(size_t num) {

	}

	s find_it(s input) {

	}
	
};