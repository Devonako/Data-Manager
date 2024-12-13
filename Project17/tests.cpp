#include <string>
#define s std::string

class testResult {
	int did_pass;
	s comments;
};

class testResults {
	
};

size_t contain(s in, s st) {
	/*if (in.find(st) != std::string::npos) {
		return true;
	}
	return false;*/
	return in.find(st) != std::string::npos;
}

void ssdsj() {

}
