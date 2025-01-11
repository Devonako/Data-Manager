#pragma once
#include <string>
#include <vector>
#include <iostream>
#define s std::string
#define v std::vector
#include<memory>
#include <cstdlib>

class potato {
public:
	
	potato() {
		int a = 0;
		a + 1;
		void* ad;
		ad = malloc(27);
		memcpy(ad, "sdss", 4);
		
	}
};

int asff() {

}


int equ(s in, s two) {
	return in.compare(two) == 0;
}





class lint {
public: 
	int in1;
	int in2;
	potato p;
	lint() {
		
	}
};

class governance_result {
public:
	int aaa;
};

class gov_quality {
public:
	
};

class gov_fun {
private:
	int asww;
	void output(s in) {
		std::cout << in << "\n";
	}
	s input(s prompt) {
		s res;
		std::getline(std::cin, res);
		return res;
	}
public:
	governance_result governance() {
		governance_result gr;
		// pinrt "who is the governor

		// 
		output("Who is the governor?");
		s gov = input("Enter the name.");
		if (equ("gov", gov)) {
			output("You are the governror.");
		}
	}

	void governance_quality(s in) {
		//g et in

		// 
	}

	void ssjkf() {

	}

	
};