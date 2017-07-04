// recursiveIntToHex.cpp
// Adam Flammino 7/3 SDEV 345
// Recursively converts ints to hex

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>


class NumberConverter {
private:
	std::string out;
public:
	// converts int to hex
	void intToHex(int num) {
		int temp = num % 16;
		num /= 16;
		
		switch (temp) {
		case 10:
			out = "A" + out;
			break;
		case 11:
			out = "B" + out;
			break;
		case 12:
			out = "C" + out;
			break;
		case 13:
			out = "D" + out;
			break;
		case 14:
			out = "E" + out;
			break;
		case 15:
			out = "F" + out;
			break;
		default:
			out = std::to_string(temp) + out;
		}
		if (num > 0) {
			intToHex(num);
		}
	}

	// gets output value
	std::string getNum() {
		return out;
	}
	// Prevents output from accumulating
	void clearOut() {
		out = "";
	}
};

int main()
{
	std::vector<int> ints;
	std::vector<int> absInts;
	std::string sign = "";
	std::string output;
	ints.push_back(18);
	ints.push_back(-434);
	ints.push_back(67);
	ints.push_back(0);
	for (int i = 0; i < ints.size(); i++) {
		absInts.push_back(abs(ints[i])); // Use vector of abs rather than raw values to avoid having to deal with misplaced "-"
	}
	NumberConverter nc;
	for (int i = 0; i < absInts.size(); i++) {
		if (ints[i] != absInts[i]) {
			sign = "-";
		}
		else {
			sign = "";
		}
		nc.intToHex(absInts[i]);
		std::cout << ints[i] << " in hex is " << sign << nc.getNum() << std::endl;
		nc.clearOut();
	}
    return 0;
}


