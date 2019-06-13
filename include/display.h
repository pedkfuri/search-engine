#include <iostream>
#include <string>
#include <vector>

#ifndef DISPLAY_HEADER
#define DISPLAY_HEADER

using namespace std;

const int w = 64;

class Display {
	public:
		static string getInput();
		
		static void printResult(vector<string> docs);
		
		static bool menu();
};

#endif //DISPLAY_HEADER
