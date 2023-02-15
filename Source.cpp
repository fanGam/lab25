#include <iostream>
#include "Header.h"

using namespace std;

void main() {
	string Inp = "-";
	while (Inp != "0") {
		cout << "Type what do you need!" << endl;
		cout << "1 - ListWork42" << endl;
		cout << "2 - ListWork43" << endl;
		cout << "3 - ListWork63" << endl;
		cout << "0 - Exit" << endl;
		cout << "-> ";
		cin >> Inp;
		if (Inp == "1") {
			ListWork42();
		}
		else if (Inp == "2") {
			ListWork43();
		}
		else if (Inp == "3") {
			ListWork63();
		}
		else if (Inp != "0") {
			cout << "Error! Type again!" << endl;
		}
	}
}