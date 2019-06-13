#include "../include/display.h"

string Display::getInput() {
	string input;
	getline(cin, input);
	return input;
}

void Display::printResult(vector<string> docs) {
	int a, b;

	for (b = 0; b < docs.size(); b++) {
		cout << " " << b + 1 << ". " << docs[b];
		for (a = 0; a < w - docs[b].size() - 6; a++) cout << " ";
		cout << " " << endl;
	}
}

bool Display::menu() {
	cout << "Fazer outra consulta [s/n]? ";

	char c;
	cin.clear();
	cin >> c;

	if (c == 's') {
		return true;
	} else {
		return false;
	}
}