#include <string>
#include <fstream>
class Filem {
private:
	std::string filename;
public:
	Filem(std::string filename) {
		this->filename = filename;
	}
	std::string get_datum() {
		std::ifstream ifs(this->filename);
		std::string content((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
		ifs.close();
		return content;
	}
};