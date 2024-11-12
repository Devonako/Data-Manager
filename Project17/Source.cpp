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
#include "util.h"
using namespace std;
#define s string
#define fs filesystem
#define v vector
#define vs v<s>
#define vv(x) auto x
#define console(x) std::cout << x << "\n";
#define console9log(x) std::cout << x << "\n";
#define add push_back
#define let auto
#define fn auto

vs names = {
	"John",
	"Mary",
	 "Jack",
	 "David",
	 "Paul"
};

vs regexes = {
	"\\b(?:4[0-9]{12}(?:[0-9]{3})?|[25][1-7][0-9]{14}|6(?:011|5[0-9][0-9])[0-9]{12}|3[47][0-9]{13}|3(?:0[0-5]|[68][0-9])[0-9]{11}|(?:2131|1800|35\\d{3})\\d{11})\\b"
};


//fn get_regex(int index) {
//	let x = 0;
//	for (; x < regexes.size(); x++) {
//		if (index == x) {
//			return re
//		}
//	}
//}

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
	generate,convert, mask, sort, report
};

enum generateDataType {
	name, ssn, email
};
enum fileType {
	CSV, JSON, XML
};
enum dataTypeType {
	UTF8, NUMERIC, ASCII, DATE, TIME, TIMESTAMP
};

class dataType {

};

class column {
public:
	std::string value;
	int position;
	generateDataType gend;
	std::string name;
};

class record {
public:
	std::string data;
	int num;
};

class datum {
public:

	std::string name;
	fileType ftype;
	v<record> r;
	v<column> c;
	int remove;
};

class dataAction {
public:
	dataActionType type;
	size_t count;
	generateDataType dd;
	fileType ftype;
	std::string input;
	std::string output;
	datum in;
	datum out;
};





#define r result
#define vr v<r>
#define var auto
size_t contain(s in, s st) {
	/*if (in.find(st) != std::string::npos) {
		return true;
	}
	return false;*/
	return in.find(st) != std::string::npos;
}

std::string reverse_str(s in) {
	string ext = "";
	size_t len = in.length();
	int pos = len;
	for (; pos >= 0; pos--) {
		ext += in[pos];
	}
	return ext;
}

std::string get_extension(s in) {
	string ext = "";
	size_t len = in.length();
	int pos = len;
	for (; pos >= 0; pos--) {
		if (in[pos] == '.') {
			break;
		}
		ext += in[pos];
	}
	return ext;
}

std::string redact(s in) {
	string ext = "";
	size_t len = in.length();
	int pos = len;
	for (; pos >= 0; pos--) {
		ext += "*";
	}
	return ext;
}

std::string generate_email(std::vector<string> prefix, std:: string domain) {
	s email;
	s at = "@";
	for (var prefix_part : prefix) {
		email = email + prefix_part;
	}
	email = email + at + domain;
	return email;
}

std::string generate_ssn() {
	s ssn;
	for (var a = 0; a < 3; a++) {
		ssn += std::to_string(rand() % 9 + 1);
	}
	ssn += "-";
	for (var a = 0; a < 2; a++) {
		ssn += std::to_string(rand() % 9 + 1);
	}
	ssn += "-";
	for (var a = 0; a < 3; a++) {
		ssn += std::to_string(rand() % 9 + 1);
	}
	return ssn;
}



// Pseudo
std::string generate_name() {
	return names.at(rand() % names.size());
}

s generate_city{
	vector<string> cities = {
		"Dallas",
		"New York City",
		"London",
		"Tokyo",
		"Lagos",
		"Rio de Janeiro",
		"Los Angeles"
};

}

std::string encrypt(s in) {
	s result;
	for (char c : in) {
		result += (c * 27 % 127);
	}
	return result;
}

std::string get_data(std::string fileName) {
	std::ifstream ifs(fileName);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	return content;
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
void iterate_files(dataAction action) {
	std::string path = action.input;
	for (const auto& entry : fs::recursive_directory_iterator(path)) {

		if (entry.is_regular_file()) {
			var pa = entry.path().c_str();
			std::ifstream t(entry.path().generic_string());
			/*std::stringstream buffer;
			buffer << t.rdbuf();
			scan_name(, entry.path().generic_string())*/
		}
	}
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

void parseData(std::string data) {

}

void handleOutput(std::string data, std::string fileName, int mode) {
	// Create and open a text file
	if (fileName.compare("stdout") == 0) {
			fprintf(stdout, "%s\n", data.c_str());
	}
	else
	{
		ofstream MyFile(fileName, mode);

		// Write to the file
		MyFile << data << "\n";

		// Close the file
		MyFile.close();
	}
	
}

void handleGenerate(dataAction action) {
	var a = 0;
	if (action.dd == generateDataType::name) {
		for (; a < action.count; a++) {
			
			handleOutput(names.at(rand() % names.size()), action.output, ios::app);
			

		}
		// log
		handleOutput("Generated name to file " + action.output + ".\n", "log.txt", std::ios::app);
	}
	if (action.dd == generateDataType::ssn ) {
		for (; a < action.count; a++) {

			handleOutput(generate_ssn(), action.output, std::ios::app);


		}
		// log
		handleOutput("Generated ssn to file " + action.output + ".\n", "log.txt", std::ios::app);
	}
}

void handleMask(dataAction action) {
	//iterate_files(action.input);
}

// CSV
// name, ssn
// JSON
// {"name": "John", "ssn": "444-44-4444"}
std::string convert_line(dataAction action, std::string in) {
	s out = "";
	if (action.in.ftype == fileType::CSV && action.out.ftype == fileType::JSON) {
		vs res = split(in, ",");
		size_t index = 0;
		out += "{";
		for (var ent : res) {
			out = out + "\"" + action.out.c.at(index).name + "\": \"" + action.out.c.at(index).value + "\",";
			index += 1;
		}
		out += "},";
	}
	return out;
}

void handleConvert(dataAction action) {
	std::ifstream ifs(action.input);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	vs res = split(content, "\n");
	size_t size = res.size();
	size_t line_n = 0;
	for (var line : res) {
		line_n += 1;
		var liner = convert_line(action, line);
		if (line_n == res.size()) {
			if (action.out.ftype == fileType::JSON) {
				liner.pop_back();
			}
		}
	}
}

void handleReport(dataAction action) {
	std::ifstream ifs(action.input);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	handleOutput(content, action.output, std::ios::out);
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
		else if (action.type == dataActionType::report) {
			handleReport(action);
		}
	}
}

v<string> tokenize(std::string query) {
	s a = "";
	vs tokens;
	var left_token = 0;
	var right_token = 0;
	for (char c : query) {
		if (c == '{') {
			left_token = 1;
			continue;
		}
		if (c == '}') {
			left_token = 0;
			tokens.add(a);
			a.clear();
		}
		if (c == ' ' && ! left_token) {
			tokens.add(a);
			a.clear();
		}
		else {
			a.push_back(tolower(c));
		}
	}
	tokens.add(a);
	return tokens;
}

// Handle the webquery
// HTtplib

 // #include "Header1.h"


void h_web(s qu) {
	/*httplib::Client cli("http://google.com?q=" + qu);

	auto res = cli.Get("/");
	if (res && res->status == 200) {
		std::cout << res->body << std::endl;
	}
	else {
		std::cout << "Request failed" << std::endl;
	}*/

	return;
}
// Govern the data


// Get  a hold on the data
// Identify it
// Qu is the source
void handle_govern(s qu) {
	get_data(qu);
}

// Generate 10 names
// Convert XML to JSON
// Convert a.xml to b.json
// Mask
// Sort
// Generate 10 names to CSV file
// 

// Wbquery


v<dataAction> parseQuery (std::string query) {
	// Idea: Leniency in token interpretation
	// Idea: Handle tokens with spaces (surround with parens)
	// 
	vs tokens = tokenize(query);
	v<dataAction> actions;
	dataAction ac;
	ac.input = "";
	ac.output = "";
	int rows = 0;
	int next_name = 0;
	int next_named_column = 0;
	var token_number = 0;
	for (var token : tokens) {
		token_number++;
		if (next_name) {
			if (ac.input.empty() && ac.type != dataActionType::generate) {
				ac.input = token;
				if (get_extension(ac.input).compare("csv") == 0) {
					ac.in.ftype = fileType::CSV;
				}
				if (get_extension(ac.input).compare("xml") == 0) {
					ac.in.ftype = fileType::XML;
				}
				if (get_extension(ac.input).compare("JSON") == 0) {
					ac.in.ftype = fileType::JSON;
				}
			}
			else {
				ac.output = token;
				if (get_extension(ac.output).compare("csv") == 0) {
					ac.out.ftype = fileType::CSV;
				}
				if (get_extension(ac.output).compare("xml") == 0) {
					ac.out.ftype = fileType::XML;
				}
				if (get_extension(ac.output).compare("JSON") == 0) {
					ac.out.ftype = fileType::JSON;
				}
			}
			next_name = 0;
			continue;
		}
		if (next_named_column) {
			if (ac.out.name.length() > 0) {
				column c;
				c.position = ac.out.c.size() + 1;
				c.name = token;
				
				ac.out.c.push_back(c);
			}
			else {
				ac.in.name = token;
				column c;
				c.position = ac.in.c.size() + 1;
				c.name = token;

				ac.in.c.push_back(c);
			}
			next_named_column = 0;
		}
		if (token.compare("mask") == 0) {
			
			ac.type = dataActionType::mask;
			
		}
		else if (token.compare("named_column") == 0) {
			next_named_column = 1;
		}
		else if (token.compare("file") == 0) {
			next_name = 1;
		}
		else if (token.compare("source") == 0) {
			next_name = 1;
		}
		else if (token.compare("target") == 0) {
			next_name = 1;
		}
		else if (token.compare("convert") == 0) {
			ac.type = dataActionType::convert;
		}
		else if (token.compare("report") == 0) {
			ac.type = dataActionType::report;
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
		else if (token.compare("webquery") == 0) {
			s webquery = "";
			var ind = token_number;
			for (; ind < tokens.size(); ind++) {
				webquery = webquery +  tokens.at(ind);
			}
			h_web(webquery);
			break;
		}
		else if (token.compare("govern") == 0) {

		}
		else if (token.compare("xml") == 0) {
			ac.ftype = fileType::XML;
		}
		else if (token.compare("names") == 0) {
			ac.dd = generateDataType::name;
		}

		else if (token.compare("ssn")== 0) {
			ac.dd = generateDataType::ssn;
		}

		else if (token.compare("email") == 0) {
			ac.dd = generateDataType::email;
		}

		else if (token.compare("and") == 0) {
			actions.push_back(ac);
		}
		else if ((rows = atoi(token.c_str())) > 0) {
			ac.count = rows;
		}
		// else if 
	}
	actions.push_back(ac);
	return actions;
}




// Main ecevution
int main(int argc, const char** argv) {
	/*console("test");
	console(encrypt("test"));
	return 0;*/

	var a = 0;
	s q = "";
	//nsole9log(a);
	do {
		console9log("Enter query");
		std::getline(std::cin, q); 
		var result = parseQuery(q);
		handle_action(result);
	} while (true);
	print_results(scan_name("a sandwich.", "made up"));
}