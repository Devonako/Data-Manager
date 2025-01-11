#include <string>
#define s std::string
#include "Source.h"

class testResult {
public:
	int did_pass;
	s comments;
};

class testResults {
public:
	v<testResult> tRs;
	
};

//size_t contain(s in, s st) {
//	/*if (in.find(st) != std::string::npos) {
//		return true;
//	}
//	return false;*/
//	return in.find(st) != std::string::npos;
//}

testResult test_generate_ccn() {
	var ccn = generate_ccn("-");
	testResult tr;
	if (ccn.length() == 20) {
		tr.did_pass = 1;
	}
	else {
		tr.did_pass = 0;
		tr.comments = "utter failure";
	}
	return tr;
}
#define let auto

testResults runTests() {
	testResults trss;
	let res = test_generate_ccn();
	trss.tRs.push_back(res);
	return trss;
}

void print_test_results(testResult trs) {
	fprintf(stdout, "%s, %s\n\n", trs.did_pass ? " " : "", trs.comments.c_str());
}

void tester() {
	let res = runTests();
	for (let a : res.tRs) {
		
	}
}

void ssdsj() {
	generate_ccn("-");
}
