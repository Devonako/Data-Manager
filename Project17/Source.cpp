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
#include <algorithm>
#include "util.h"
// Define "pretty" colors for terminal
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_UNDERLINE "\x1b[4m"
#define ANSI_COLOR_BOLD "\x1b[1m"
#define ANSI_COLOR_ITALIC "\x1b[3m"
using namespace std;
int num_queries = 0;
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
#define triple long double
#define integer int
#define INT int
#define pp poop
#define jameis picksix
#define voi void

#define var auto
#define fn auto

#include "logging.cpp"
logger logg;

voi jameis() {
	console("Wild Jameis throws pick-six, costing his team the game!");
}

#define winston jameis();


#define r result
#define vr v<r>
#define var auto

vs names = {
	"John",
	"Mary",
	 "Jack",
	 "David",
	 "Paul",
	 "Sara",
	 "Duncid",
	 "Tara",
	 "Tate",
	 "Devon",
	 "Kevin",
	 "Allison",
	 "Lisa",
	 "Larry",
	 "Ludwig",
	 "Beethoven",
	 "Marissa",
	 "Kat",
	 "Ronald",
	 "Artemis",
	 "Pat",
	 "Oscar",
	 "Zeus",
	 "Xi",
	 "Yurtseven",
	 "Robert",
	 "Barry",
	 "Karl",
	 "Champ",
	 "Erwin",
	 "Florence",
	 "Gert",
	 "Humberto",
	 "Jose",
	 "Michael",
	 "Nadine",
	 "Holly",
	 "Joe",
	 "Donald",
	 "Jimmy",
	 "Laremy"
	 
};

vs regexes = {
	"\\b(?:4[0-9]{12}(?:[0-9]{3})?|[25][1-7][0-9]{14}|6(?:011|5[0-9][0-9])[0-9]{12}|3[47][0-9]{13}|3(?:0[0-5]|[68][0-9])[0-9]{11}|(?:2131|1800|35\\d{3})\\d{11})\\b",
		 // "Credit Cards
		 "\\b(?:\\d[ -]*?){13,16}\\b",
				// eMAILS
			"\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b",
			"\\b(?:\\+?1[-.\\s]?)?\\(?\\d{3}\\)?[-.\\s]?\\d{3}[-.\\s]?\\d{4}\\b",
			"\\b\\d{3}-\\d{2}-\\d{4}\\b",
			"\\b(?:\\d{1,3}\\.){3}\\d{1,3}\\b",
			"\\b[A-Z]{2}\\d{6,8}\\b",
			"\\b[A-Z]\\d{7}\\b",
			"\\b\\d{9,18}\\b",
			"\\b\\d{1,2}/\\d{1,2}/\\d{2,4}\\b"
			// 
			/*	
			* 
			"Phone Numbers"]
				data_types["Social Security Numbers"] += len(re.findall(r"\b\d{3}-\d{2}-\d{4}\b", file_content))
				data_types["IP Addresses"] += len(re.findall(r"\b(?:\d{1,3}\.){3}\d{1,3}\b", file_content))
				# Add more regex patterns for other data types below(examples provided)
				data_types["Driver's Licenses"] += len(re.findall(r"\b[A-Z]{2}\d{6,8}\b", file_content))  # Example pattern, adjust as needed
				data_types["Passport Numbers"] += len(re.findall(r"\b[A-Z]\d{7}\b", file_content))  # Example pattern, adjust as needed
				data_types["Bank Account Numbers"] += len(re.findall(r"\b\d{9,18}\b", file_content))  # Example pattern, adjust as needed
				data_types["Dates of Birth"] += len(re.findall(r"\b\d{1,2}/\d{1,2}/\d{2,4}\b", file_content))  # Example pattern, adjust as needed*/
			//	# For "Health Records", you'll likely need more sophisticated techniques than basic regex
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

vs states = {
	"Alabama",
	"Arizona",
	"Arkansas",
	"Connecticut",
	"Florida",
	"New York",
	"Texas",
	"California",
	"Oregon",
	"Washington",
	"Idaho",
	"Montana",
	"New Mexico",
	"New Hampshire",
	"Oklahoma",
	"Lousiana",
	"Georgia",
	"South Carolina",
	"North Carolina",
	"Mississippi",
	"Kansas",
	"Michigan",
	"Ohio",
	"Illinois",
	"Tennessee",
	"South Dakota",
	"North Dakota",
	"Kentucky",
	"Maryland",
	"Vermont"
	//"Kentuckyland"
};

vs tools = {
	"screwdriver",
	"hammer",
	"nuts",
	"nail",
	"saw"
};

s generate_tool() {
	s res;
	//srand(time(0));
	return tools.at(rand() % tools.size());
}

//s generate_city () {
//	s res;
//	return res;
//}

s generate_country() {
	s res;
	return res;
}

enum dataActionType
{
	generate,convert, mask, sort, report, govern
};

enum generateDataType {
	name, ssn, email, uuid, tool, state, city, country
};
enum fileType {
	CSV, JSON, XML, YAML, XLS, XLSX, PDF, JPG, DCM, PPT, PPTX, DOC, DOCX, TXT, TSV, PSV, GIF, PNG
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
	generateDataType gend = generateDataType::name;
	std::string name = "default";
	dataTypeType dt = dataTypeType::ASCII;
};

class record {
public:
	std::string data;
	int num;
};

class datum {
public:

	std::string name = "stdout";
	fileType ftype = fileType::CSV;
	v<record> rec;
	v<column> c;
	int remove;
	std::string separator = "\t";
};

class dataAction {
public:
	dataActionType type;
	size_t count = 100;
	generateDataType dd;
	fileType ftype = fileType::CSV;
	std::string input = "stdin";
	std::string output = "stdout";
	datum in;
	datum out;
};


class big_number {
public:
	size_t digits;
	s value;

	fn add(big_number one, big_number two) {
		
	}
};


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
	int pos = len - 1;
	for (; pos >= 0; pos--) {
		ext.push_back(in.at(pos));
	}
	return ext;
}

void print_copyright() {
// #define print(x) var a = x.size(); if ( a < for (var b = 0; (b < 80 - a / 2) {std::cout << " "; } std::cout << x << std::endl;
	s build_tag = "R-010-012325-0900";
	s copyright = build_tag + " Copyright 2024-2025 Devonian Enterprises";
	//print(copyright);
}

std::string truncate_str(s in, size_t len) {
	var s_len = in.length();
	while (s_len > len) {
		s_len -= 1;
		in.pop_back();
	}
	return in;
}

//s tolo(s in) {
//	std::transform(in.begin(), in.end(), in.begin(), tolower);
//	return in;
//}
//
//s tohi(s in) {
//	std::transform(in.begin(), in.end(), in.begin(), toupper);
//	return in;
//}

s replace(s in, s tis, s with) {
	size_t occurences = 0;
	size_t last_index = 0;
	int first = 0;
	s replace;
	while (var a = in.find(tis) != std::string::npos) {
		
		replace += in.substr(last_index, a - last_index);
		first = 1;
		replace += with;
		occurences++;
		last_index = a;
	}
	if (occurences == 0) {
		return in;
	}
	return replace;
}

/*
s dsjhsdj() {

}
*/

s replaceFirst(s in, s tis, s with) {
	s result;
	if (var b = in.find(with) != std::string::npos) {
		for (var a = 0; a < b; a++) {
			result += in.at(a);
		}
		result += with;
		for (var a = b + with.length(); a < in.length() + with.length(); a++) {
			result += in.at(a);
		}
	}
	else {
		return in;
	}
	
}


int compare_char(char one, char two) {
	v<char> ones = { 'a', 'b' };
	long double ll = 1000;
	//long double ll;
	return ll;
}

double proximity(s one, s two) {
	for (char c : one) {
		for (char c2 : two) {
			do
			{
				console9log("aa");
			} while (true);
		}
	}
	return 1.0;
}

/*
dfjhdfj
*/


std::string generate_ccn(std::string sep) {
	s result = "";
	vs types = { "6011", "4491" };
	s type = types.at(rand() % types.size());
	result += type;
	size_t ccn_len = 16;
	int index = type.size();
	// Separator
	while (index < ccn_len + sep.empty() ? 0 : sep.length()) {
		if (index % 4 == 0) {
			index++;
			result += std::to_string(rand() % 10);
		}
		index++;
	}
	return result;
}



std::string generate_number(int digits, int decimals) {
	s result = "";
	for (var a = 0; a < digits; a++) {
		result += std::to_string(rand() % 10);
	}
	if (decimals > 0) {
		result += ".";
	}
	for (var a = 0; a < decimals; a++) {
		result += std::to_string(rand() % 10);
	}
	return result;
}

std::string generate_asc_string(size_t min_length, size_t max_length) {
	s result = "";
	let length = (rand() % (max_length - min_length)) + min_length;
	for (var a = 0; a < length; a++) {
		result += std::to_string(27 + (rand() % 100));
	}
	return result;
}

std::string generate_utf8_string(int min_length, int max_length) {
	s result;
	result = "💩";
	return result;
}

// TODO: Param of dateType
std::string generate_date() {
	s result;
	int month = rand() % 12 + 1;
	result += (month > 9 ? std::to_string(month) : ("0" + std::to_string(month)));
	result += "/";
	int day = rand() % 31 + 1;
	int year = rand() % 124 + 1 + 1900;
	//result += std::to_string
	return result;
}

std::string moneyizer(std::string in, std::string money_sign) {
	return money_sign + in;
}


class governor {
public:
	s his_name;
	s his_royal_governance;
	s user_file;
	char bit_f; // For ?
	char bit_f2;

	void do_govern() {
		if (authenticate() == 0) {
			
		}
		else {
			// print("You are no governor");
			// That's a bad governor
		}
	}

private:

	// Authenticate the royal governor
	int authenticate() {
		if (get_user().compare(his_name) == 0) {
			return 0;
		}
		else { // Anything else?
			return 1;
		}
	}
#define _CRT_SECURE_NO_WARNINGS
	// Get his username
	s get_user() {
		s result;
		char bufferring[2000] = { 0 };
		FILE * f = fopen(user_file.c_str(), "rb");
		if (f) {
			fread(bufferring, 2000, 1, f);
			result = std::string(bufferring);
			result = replace(result, "\r", "");
			result = replace(result, "\n", "");
			result = replace(result, " ", "");
			return result;
		}
		else {
			return result;
		}
	}
};

int validate_license_str(s in) {
	// get current time
	// compare to licensed
	// comapre num queries to licensed
	// Format xxxxxx(garbage) then xx equals month (shift 11) xx equals day (shift 27) xxxx equals year (shift 1219)
	// xxxxxxxxxx (num licensed queries, zero padded)
	// length 6 garbage + 2 + 2 + 4 + 9
	//int month = std::atoi(in.sub)
	// xxxxxx23204000000000002
	if (in.size() < 23) {
		return 0;
	}
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int c_year = 1900 + ltm->tm_year;
	int c_month = 1 + ltm->tm_mon;
	int c_day = ltm->tm_mday;

	int month = std::atoi(in.substr(6, 2).c_str()) - 11;
	int day = std::atoi(in.substr(8, 2).c_str()) - 11;
	int year = std::atoi(in.substr(10, 4).c_str()) - 1219;
	int num_q = std::atoi(in.substr(14, 9).c_str());
	if (year < c_year) {
		return 0;
	}
	if (year == c_year) {
		if (month < c_month) {
			return 0;
		}
		if (month == c_month) {
			if (day < c_day) {
				return 0;
			}
		}
	}
	if (num_q < num_queries) {
		return 0;
	}
	return 1;
}

int validate_license() {
	FILE* f = fopen("license.txt", "rb");
	if (f) {
		char buffer[2000] = { 0 };
		fread(buffer, 2000, 1, f);
		s b_string = s(buffer);
		return validate_license_str(b_string);
	}
	else { // Invalid
		return 0;
	}
}

// 1 -> 1.00
// 2.599 -> 2.60
// 2.555555 -> 2.55555500000
// -1 -> -1.0
// -20.00 -> -20
std::string convert_decimals(std::string in, int decimal_places) {
	size_t l = in.find_first_of('.');
	s result;
	bool was_found = (l == std::string::npos);
	if (was_found) {
		if (decimal_places == 0) {
			return in.substr(0, l - 1);
		}
		int after_dec = in.size() - l;
		
		if (after_dec < decimal_places) {
			// Round it
			// 1.055 -> 1.06
			result += in.substr(0, l - 2);
			result.pop_back();
			int last_number = in.at(l + decimal_places);
		}
		else if (after_dec > decimal_places) {
			// add and expand

			// 1.055 -> 1.0550
			result += in.substr(0, l - 1);
			int diff = after_dec - decimal_places;
			for (int i = 0; i < diff; i++) {
				result += "0";
			}
		}
		else if (after_dec == decimal_places) {
			return in;
		}
	}
	else {
		// 1 -> 1.00
		result += in;
		result += ".";
		for (int i = 0; i < decimal_places; i++) {
			result += "0";
		}
	}
	return result;
}



std::string get_extension(s in) {
	string ext = std::string("");
	size_t len = in.length();
	int pos = len - 1;
	for (; pos >= 0; pos--) {
		if (in[pos] == '.') {
			break;
		}
		ext.push_back(in.at(pos));
	}
	return reverse_str(ext);
}

std::string redact(s in) {
	string ext = "";
	size_t len = in.length();
	int pos = len;
	for (; pos > 0; pos--) {
		ext.push_back('*');
	}
	return ext;
}

std::string redact(s in, size_t start, size_t end) {
	//string ext = "";
	//size_t len = in.length();
	//int pos = 0;
	//for (; pos < end; pos++) {
	//	if (pos >= len) {
	//		break;
	//	}
	//	ext.push_back('*');
	//}
	//return ext;

	string ext = "";
	size_t len = in.length();
	int pos = 0;
	for (; pos < len; pos++) {
		if (pos < end && pos >= start) {
			ext.push_back('*');
		}
		else {
			ext.push_back(in.at(pos));
		}
	}
	return ext;
}

std::string redact(s in, size_t start, size_t end, char redact_char) {
	//string ext = "";
	//size_t len = in.length();
	//int pos = 0;
	//for (; pos < end; pos++) {
	//	if (pos >= len) {
	//		break;
	//	}
	//	ext.push_back('*');
	//}
	//return ext;

	string ext = "";
	size_t len = in.length();
	int pos = 0;
	for (; pos < len; pos++) {
		if (pos < end && pos >= start) {
			ext.push_back(redact_char);
		}
		else {
			ext.push_back(in.at(pos));
		}
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

s generate_city () {
	vector<string> cities = {
		"Dallas",
		"New York City",
		"London",
		"Tokyo",
		"Lagos",
		"Rio de Janeiro",
		"Los Angeles",
		"Houston",
		"Tampa",
		"Miami",
		"Brisbane",
		"Sydney",
		"Atlanta",
		"Portland",
		"Seattle",
		"Paris",
		"Detroit",
		"Melbourne",
		"Tampa",
		"Port Charlotte",
		"Punta Gorda",
		"Murphy",
		"Satellite Beach",
		"Fort Pierce",
		"Daytona Beach",
		"Dublin",
		"Perry",
		"Cochran",
		"Huntsville",
		"Marietta",
		"Montgomery",
		"Galveston",
		"Denver",
		"Mexico City",
		"Tucson",
		"Boise",
		"Salt Lake City",
		"Edmonton",
		"Fairbanks",
		"La Paz",
		"Kota"
};
	return cities.at(rand() % cities.size());
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
		if ((pos = buffer.find(name)) != std::string::npos) {
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
		//a.print();
	}
}



void show_report(vr res) {
	fprintf(stdout, "<!DOCTYPE html> \
		< html lang = \"en\" > \
		<head><meta charset = \"UTF - 8\"> \
		<meta name = \"viewport\" content = \"width = device - width, initial - scale = 1.0\"> \
		<title>Document< / title> \
		< / head> \
		< body>");
	fprintf(stdout, "<table><th> Data Class</th> <th>Data Class</th></");
	for (vv(a) : res) {
		fprintf(stdout, "<tr><td>%s</td><td>%s></td></tr>", a.source, a.dataClass);
	}
}


//s get_buffer() {
//	
//}

// From data parse headers based on file type
void parseData(std::string data, dataAction action) {
	switch (action.in.ftype)
	{
	default:
		break;
	}
	
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
	std::string record_string;
	if (action.out.c.size() > 0) {
		for (; a < action.count; a++) {
			for (var column : action.out.c) {
				switch (column.gend)

				{
				case generateDataType::name:
					record_string += names.at(rand() % names.size());
					break;
				case generateDataType::ssn:
					record_string += generate_ssn();
					break;
				case generateDataType::email:
					//record_string += generate_email()
					break;
				default:
					record_string += generate_asc_string(1, rand() % 50 + 1);
					break;
				}
				record_string += action.out.separator;
			}
			record_string += "\n";
		}
	}
	else if (action.in.c.size() > 0) {
		for (; a < action.count; a++) {
			for (var column : action.in.c) {
				switch (column.gend)

				{
				case generateDataType::name:
					record_string += names.at(rand() % names.size());
					break;
				case generateDataType::ssn:
					record_string += generate_ssn();
					break;
				case generateDataType::email:
					//record_string += generate_email()
					break;
				default:
					record_string += generate_asc_string(1, rand() % 50 + 1);
					break;
				}
				record_string += action.out.separator;
			}
			record_string += "\n";
		}
	}
	if (record_string.size() > 0) {
		
		handleOutput(record_string, action.output, ios::app);
		logg.log_it("Generate to " + action.output + ".");
		//print("Gen -d")
		// Log
	}
	// Os this
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

s replace_with(s input, s replacement, size_t start, size_t end) {
	s output = "";
	// TODO
	size_t replacement_index = 0;
	for (size_t index = 0; index < input.length(); index++) {
		if (index >= start && index <= end) {
			if (replacement.size() >= replacement_index) {
				output += replacement.at(replacement_index);
			}
			else {
				output += input.at(index);
			}
		}
	}
	return output;
}

void handleMask(dataAction action) {
	// Find 
	// // ask opti
	// // Speed
	// // Config
	//iterate_files(action.input);
	var data = get_data(action.input);
	var results = scan_name(data, action.input);
	for (var result : results) {
		data = redact(data, result.start, result.end);
	}
	handleOutput(data, action.output, std::ios::out);
	//redact()
	handleOutput("Masked source " + action.input + " to output " + action.output + ".\n", "log.txt", std::ios::app);
// Make gth
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
			out = out + "\"" + ((action.out.c.size() > 0) ? action.out.c.at(index).name : "Placeholder") + "\": \"" + (action.out.c.size() > index ? action.out.c.at(index).value : ent) + "\",";
			index += 1;
		}
		out += "},";
	}
	else if (action.in.ftype == fileType::CSV && action.out.ftype == fileType::XML) {
		vs res = split(in, ",");
		size_t index = 0;
		out += "<";
		for (var ent : res) {
			out = out + "\"" + (action.out.c.size() > index ? action.out.c.at(index).name : "Placeholder") + "\">" + action.out.c.at(index).value + "</" + (action.out.c.size() > index ? action.out.c.at(index).name : ent) + ">\n";
			index += 1;
		}
		//out += "},";
	}
	else if (action.in.ftype == fileType::CSV && action.out.ftype == fileType::TSV) {
		vs res = split(in, ",");
		size_t index = 0;
		for (var ent : res) {
			out = out + ent + "\t";
		}
		out.pop_back();
		//out += "},";
	}
	else if (action.in.ftype == fileType::CSV && action.out.ftype == fileType::PSV) {
		vs res = split(in, ",");
		size_t index = 0;
		for (var ent : res) {
			out = out + ent + "|";
		}
		out.pop_back();
		//out += "},";
	}
	else if (action.in.ftype == fileType::PSV && action.out.ftype == fileType::TSV) {
		vs res = split(in, "|");
		size_t index = 0;
		for (var ent : res) {
			out = out + ent + "\t";
		}
		out.pop_back();
		//out += "},";
	}
	else if (action.in.ftype == fileType::PSV && action.out.ftype == fileType::CSV) {
		vs res = split(in, "|");
		size_t index = 0;
		for (var ent : res) {
			out = out + ent + ",";
		}
		out.pop_back();
		//out += "},";
	}
	else if (action.in.ftype == fileType::TSV && action.out.ftype == fileType::CSV) {
		vs res = split(in, "\t");
		size_t index = 0;
		for (var ent : res) {
			out = out + ent + ",";
		}
		out.pop_back();
		//out += "},";
	}
	else if (action.in.ftype == fileType::TSV && action.out.ftype == fileType::PSV) {
		vs res = split(in, "\t");
		size_t index = 0;
		for (var ent : res) {
			out = out + ent + "|";
		}
		out.pop_back();
		//out += "},";
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
	s output = "";
	for (var line : res) {
		line_n += 1;
		var liner = convert_line(action, line);
		if (line_n == res.size()) {
			if (action.out.ftype == fileType::JSON) {
				liner.pop_back();
				output += liner;
			}
		}
		else {
			output += liner;
		}
	}
	handleOutput(output, action.output, std::ios::out);
}

void handleReport(dataAction action) {
	std::ifstream ifs(action.input);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	/*
	TODO map columns in to out
	Any data type conversions, function applications
	*/
	handleOutput(content, action.output, std::ios::out);
}
void handleSort(dataAction action) {
	// TODO sorting options
	// Memory, speed, type of sort and keys
	std::ifstream ifs(action.input);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	ifs.close();
	var lines = split(content, "\n");
	std::sort(lines.begin(), lines.end());
	content = "";
	for (var line : lines) {
		content += line;
		content += "\n";
	}
	handleOutput(content, action.output, std::ios::out);
}


void handle_action(v<dataAction> actions) {
	// Todo:
	// 
	
	for (var action : actions) {
		if (action.type == dataActionType::generate) {
			handleGenerate(action);
		}
		else if (action.type == dataActionType::sort) {
			handleSort(action);
		}
		else if (action.type == dataActionType::mask) {
			handleMask(action);
		}
		else if (action.type == dataActionType::convert) {
			handleConvert(action);
		}
		else if (action.type == dataActionType::report) {
			handleReport(action);
		}
		
	}
}

v<string> tokenize(std::string query) {
	// Tokenize 

	// Tokens are separated by spaces

	// Tokens can contain a space if the token is surrounded by angle brackets.
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
void make_me_a_sandwich();

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
	int next_named_dt = 0;
	var token_number = 0;
	if (tokens.size() <= 4) {
		for (var token : tokens) {
			if (token.compare("sandwich") == 0) {
				make_me_a_sandwich();
				break;
			}
		}
	}
	for (var token : tokens) {
		token_number++;
		if (next_name) {
			if (ac.input.empty() && ac.type != dataActionType::generate) {
				ac.input = token;
				if (get_extension(ac.input).compare("csv") == 0) {
					ac.in.ftype = fileType::CSV;
				}
				else if (get_extension(ac.output).compare("psv") == 0) {
					ac.out.ftype = fileType::PSV;
				}
				else if (get_extension(ac.output).compare("tsv") == 0) {
					ac.out.ftype = fileType::TSV;
				}
				else if (get_extension(ac.input).compare("xml") == 0) {
					ac.in.ftype = fileType::XML;
				}
				else if (get_extension(ac.input).compare("json") == 0) {
					ac.in.ftype = fileType::JSON;
				}
				else if (get_extension(ac.input).compare("yaml") == 0) {
					ac.in.ftype = fileType::YAML;
				}
				else if (get_extension(ac.input).compare("pdf") == 0) {
					ac.in.ftype = fileType::PDF;
				}
				else if (get_extension(ac.input).compare("dcm") == 0) {
					ac.in.ftype = fileType::DCM;
				}
				else if (get_extension(ac.input).compare("docx") == 0) {
					ac.in.ftype = fileType::DOCX;
				}
				else if (get_extension(ac.input).compare("xlsx") == 0) {
					ac.in.ftype = fileType::XLSX;
				}
				else if (get_extension(ac.input).compare("pptx") == 0) {
					ac.in.ftype = fileType::PPTX;
				}
				else if (get_extension(ac.input).compare("jpg") == 0) {
					ac.in.ftype = fileType::JPG;
				}
				else if (get_extension(ac.input).compare("doc") == 0) {
					ac.in.ftype = fileType::DOC;
				}
				else if (get_extension(ac.input).compare("ppt") == 0) {
					ac.in.ftype = fileType::PPT;
				}
			}
			else {
				ac.output = token;
				if (get_extension(ac.output).compare("csv") == 0) {
					ac.out.ftype = fileType::CSV;
				}
				if (get_extension(ac.output).compare("psv") == 0) {
					ac.out.ftype = fileType::PSV;
				}
				if (get_extension(ac.output).compare("tsv") == 0) {
					ac.out.ftype = fileType::TSV;
				}
				if (get_extension(ac.output).compare("xml") == 0) {
					ac.out.ftype = fileType::XML;
				}
				if (get_extension(ac.output).compare("json") == 0) {
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
		if (next_named_dt) {
		//
			var size = ac.in.c.size();
			if (size == 0) {

			}
			else if (size > 0) {
				//if (ac.out.)
			}
			next_named_dt = 0;
		}
		if (token.compare("mask") == 0) {
			
			ac.type = dataActionType::mask;
			
		}
		else if (token.compare("named_column") == 0) {
			next_named_column = 1;
		}
		else if (token.compare("nc") == 0) {
			next_named_column = 1;
		}
		else if (token.compare("dt") == 0) {
			next_named_dt = 1;
		}
		else if (token.compare("col") == 0) {
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
		else if (token.compare("conv") == 0) {
			ac.type = dataActionType::convert;
		}
		else if (token.compare("report") == 0) {
			ac.type = dataActionType::report;
		}
		else if (token.compare("rep") == 0) {
			ac.type = dataActionType::report;
		}
		else if (token.compare("sort") == 0) {
			ac.type = dataActionType::sort;
		}
		else if (token.compare("generate") == 0) {
			ac.type = dataActionType::generate;
		}
		else if (token.compare("gen") == 0) {
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
			if (tokens.size() >= token_number + 2) {
				handle_govern(tokens.at(token_number + 1));
			}
			else {
				std::cout << "Ensure a data source is specified to govern in query." << std::endl;
			}
		}
		else if (token.compare("xml") == 0) {
			ac.ftype = fileType::XML;
		}
		else if (token.compare("names") == 0) {
			if (ac.in.c.size() > 0 && ac.out.c.size() == 0) {
				ac.in.c.at(ac.in.c.size() - 1).gend = generateDataType::name;
			}
			else if (ac.out.c.size() > 0) {
				ac.out.c.at(ac.out.c.size() - 1).gend = generateDataType::name;
			}
			else {
				ac.dd = generateDataType::name;
			}
		}

		else if (token.compare("ssn")== 0) {
			if (ac.in.c.size() > 0 && ac.out.c.size() == 0) {
				ac.in.c.at(ac.in.c.size() - 1).gend = generateDataType::ssn;
			}
			else if (ac.out.c.size() > 0) {
				ac.out.c.at(ac.out.c.size() - 1).gend = generateDataType::ssn;
			}
			else {
				ac.dd = generateDataType::ssn;
			}

			//ac.dd = generateDataType::ssn;
		}

		else if (token.compare("email") == 0) {
			if (ac.in.c.size() > 0 && ac.out.c.size() == 0) {
				ac.in.c.at(ac.in.c.size() - 1).gend = generateDataType::email;
			}
			else if (ac.out.c.size() > 0) {
				ac.out.c.at(ac.out.c.size() - 1).gend = generateDataType::email;
			}
			else {
				ac.dd = generateDataType::email;
			}
			//ac.dd = generateDataType::email;
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


#define print(x) console9log(x);
#define pr(x) console9log(x);
#define getin(x)  std::getline(std::cin, x);
#define eq(x, y) x = y;
#define sinit(x) s(x);
#define ifis(x, y, z) if (x.compare(y) == 0) {z}
#define t auto t


void make_me_a_sandwich() {
	s x;
	s in;
	eq(x, "Sure, most certainly.")
	pr(x)
	eq(x, "What toppings though, sir?")
	pr(x)
	getin(in)
		ifis(in, "pepp", {
		pr("Nice choice")
			})
}

void do_something_already() {
	s x = "a";
	
}




void pokemans() {
	// Yes, pokemans
	print("Charmander, bulbasaur, or pikachu?")
		
}

// Get number of queries already used, stored in file when application is not running.
int get_num_queries_used(std::string filename) {
	FILE* f = fopen(filename.c_str(), "rb");
	if (f) {
		char buffer[1000] = { 0 };
		fread(buffer, 1000, 1, f);
		int result = atoi(std::string(buffer).c_str()); // Return value of ATOI
		if (result == 0) {
			return -1;
		}
		else {
			return result;
		}
	}
	else {
		return -1;
	}
}

int update_num_queries_used(std::string filename) {
	FILE* f = fopen(filename.c_str(), "w");
	if (f) {
		char buffer[1000] = { 0 };
		sprintf(buffer, "%d", num_queries);
		fwrite(buffer, 1000, 1, f);
	}
	else {
		return -1;
	}
}

// Main execution
int main(int argc, const char** argv) {

	var a = 0;
	s q = "";

	print_copyright();
#define pause system("wait");

	num_queries = get_num_queries_used("queries.txt.log");
	do {
		var ret = validate_license();
		if (ret == 0) {
			// Bad
			print("No license");
				return 1;
		}
		console9log("Enter query");
		std::getline(std::cin, q); 
		if (q.compare("quit") == 0) {
			break;
		}
		var result = parseQuery(q);
		handle_action(result);
		logg.log_it("Completed query " + q + " .... -> next!");
		num_queries += 1;
		update_num_queries_used("queries.txt.log");
	} while (true);
	return 0;
}