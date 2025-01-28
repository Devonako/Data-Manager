#include <string>
#include <fstream>
#include <iostream>
#include "util.h"
#include <algorithm>

class Filem {
private:
	std::string filename;
public:
	// Initialize
	Filem(std::string filename) {
		this->filename = filename;
	}
	// Get contents
	std::string get_datum() {
		std::ifstream ifs(this->filename);
		std::string content((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
		ifs.close();
		return content;
	}
	// Delete
	int del() {
		return remove(this->filename.c_str());
	}

	// Move / renane
	int move (std::string res) {
		int ret = rename(this->filename.c_str(), res.c_str());
		this->filename = res;
		return ret;
	}

	int encrypt() {
		std::string in = get_datum();
		std::string result;
		for (char c : in) {
			result += (c - 10);
		}
		std::ofstream MyFile(this->filename, std::ios::out);

		// Write to the file
		MyFile << result << "\n";

		// Close the file
		MyFile.close();
	}

	int decrypt() {
		std::string in = get_datum();
		std::string result;
		for (char c : in) {
			result += (c + 10);
		}
		std::ofstream MyFile(this->filename, std::ios::out);

		// Write to the file
		MyFile << result << "\n";

		// Close the file
		MyFile.close();
	}
	int sort() {
		std::string in = get_datum();
#define vs std::vector<std::string>
#define var auto
		vs res = split(in, "\n");
		std::sort(res.begin(), res.end());
		std::string content = "";
		for (var line : res) {
			content += line;
			content += "\n";
		}
		std::ofstream MyFile(this->filename, std::ios::out);

		// Write to the file
		MyFile << content << "\n";

		// Close the file
		MyFile.close();
	}

}; 