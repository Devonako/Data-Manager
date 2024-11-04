/*
Data Manager - 

Performs data management operations.
Sort, mask, synthesize, convert, etc.
*/
// Include
#include <string>
#include <filesystem>
#include <vector>
#include <iostream>
#include <regex>
#include <fstream>
using namespace std;
#define s string
#define fs filesystem
#define v vector
#define vs v<s>
#define vv(x) auto x
#define console(x) std::cout << x << "\n";
#define console9log(x) std::cout << x << "\n";
#define add push_back

vs names = {
	"a",
	"b"
};

vs regexes = {
	"\\b(?:4[0-9]{12}(?:[0-9]{3})?|[25][1-7][0-9]{14}|6(?:011|5[0-9][0-9])[0-9]{12}|3[47][0-9]{13}|3(?:0[0-5]|[68][0-9])[0-9]{11}|(?:2131|1800|35\\d{3})\\d{11})\\b"
};

class result {
public:
	 int start;
	 int end;
	 s dataClass;
	 s source;

	 void print() {
		 printf("Start: %d, End: %d Class: %s Source: %s", start, end, dataClass.c_str(), source.c_str());
	 }
};

enum dataActionType
{
	generate,convert, mask, sort
};

enum generateDataType {
	name, ssn
};
enum fileType {
	CSV, JSON, XML
};

class dataAction {
public:
	dataActionType type;
	int count;
	generateDataType dd;
	fileType ftype;
	
};


enum dataTypeType {
	UTF8, NUMERIC, ASCII, DATE, TIME, TIMESTAMP
};

class dataType {

};

class column {
	std::string value;
	int position;
};

class record {
	std::string data;
};



#define r result
#define vr v<r>
#define var auto
size_t contain(s in, s st) {
	/*if (in.find(st) != std::string::npos) {
		return true;
	}
	return false;*/
	return in.find(st);
}

v<result> scan_name(s buffer, s source) {
	v<result> results;
	size_t pos = 0;
	for (auto name : names) {
		if ((pos = contain(buffer, name)) != std::string::npos) {
			result re;
			re.start = pos;
			re.end = pos + name.length();
			re.dataClass = "Names";
			re.source = source;
			results.push_back(re);
		}
	}
	return results;
}

//v<result> scan_regexes(s buffer, s source) {
//	v<result> results;
//	size_t pos = 0;
//	for (auto regex : regexes) {
//		if (std::regex::) {
//			result re;
//			re.start = pos;
//			re.end = pos + name.length();
//			re.dataClass = "Pattern";
//			re.source = source;
//			results.push_back(re);
//		}
//	}
//	return results;
//}

void print_results(vr res) {
	for (vv(a) : res) {
		a.print();
	}
}


/*
void show_report(vr res) {
	fprintf(stdout, "<!DOCTYPE html> \
		< html lang = "en" > \
		<head><meta charset = "UTF-8">
		<meta name = "viewport" content = "width=device-width, initial-scale=1.0">
		<title>Document< / title>
		< / head>
		< body>")
	for (vv(a) : res) {

	}
}
*/

//s get_buffer() {
//	
//}

void handleOutput(std::string data, std::string fileName) {
	// Create and open a text file
	ofstream MyFile(fileName);

	// Write to the file
	MyFile << data;

	// Close the file
	MyFile.close();
}

void handleGenerate(dataAction action) {
	var a = 0;
	if (action.dd == generateDataType::name) {
		for (; a < action.count; a++) {
			handleOutput(names.at(rand() % names.size()), "output.csv");
		}
	}
}

void handleConvert(dataAction action) {

}

void handle_action(v<dataAction> actions) {
	for (var action : actions) {
		if (action.type == dataActionType::generate) {
			handleGenerate(action);
		}
		else if (action.type == dataActionType::sort) {
			
		}
		else if (action.type == dataActionType::mask) {

		}
		else if (action.type == dataActionType::convert) {

		}
	}
}

v<string> tokenize(std::string query) {
	s a = "";
	vs tokens;
	for (char c : query) {
		if (c == ' ') {
			tokens.add(a);
			a.clear();
		}
		else {
			a.push_back(tolower(c));
		}
	}
	return tokens;
}

v<dataAction> parseQuery (std::string query) {
	vs tokens = tokenize(query);
	v<dataAction> actions;
	dataAction ac;
	for (var token : tokens) {
		if (token.compare("mask")) {
			
			ac.type = dataActionType::mask;
			
		}
		else if (token.compare("convert") == 0) {
			ac.type = dataActionType::convert;
		}
		else if (token.compare("sort") == 0) {
			ac.type = dataActionType::sort;
		}
		else if (token.compare("generate") == 0) {
			ac.type = dataActionType::generate;
		}
		else if (token.compare("csv") == 0) {
			ac.ftype = fileType::CSV;
		}
		else if (token.compare("json") == 0) {
			ac.ftype = fileType::JSON;
		}
		else if (token.compare("xml") == 0) {
			ac.ftype = fileType::XML;
		}

		else if (token.compare("and") == 0) {
			actions.push_back(ac);
		}
		else if (var rows = atoi(token.c_str()) > 0) {
			ac.count = rows;
		}
		else if 
	}
	actions.push_back(ac);
}

void iterate_files(std::string dir) {
	std::string path = dir;
	for (const auto& entry : fs::recursive_directory_iterator(path)) {
		
		if (entry.is_regular_file()) {
			var pa = entry.path().c_str();
		}
	}
}

// Main ecevution
int main(int argc, const char** argv) {
	var a = 0;
	console9log(a);
	do {
		console9log("Enter query");
		
	} while (true);
	print_results(scan_name("a sandwich.", "made up"));
}