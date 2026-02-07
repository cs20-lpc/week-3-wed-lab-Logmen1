// TO DO: Implement the driver main() function to test your code.
#include <iostream>
#include <string>
#include "Multitest.hpp"

using namespace std;

int main() {
	LinkedList<string> shoes;
	string s[5] = { "Boots", "Tennis Shoes", "High Heels","Cleats", "Flip Flops" };
	cout << "creating list...\n";
	shoes.append(s[0]);
	shoes.append(s[1]);
	shoes.append(s[2]);
	shoes.append(s[3]);
	shoes.append(s[4]);
	cout << "list created.\nlist size:" << shoes.getLength() << "\nList contents:\n";
	for (int x = 0; x < shoes.getLength(); x++) {
		cout << shoes.getElement(x) << endl;
	}
	string st;
	cout << "try appending\n";
	cout << "enter a shoe type\n";
	cin >> st;
	shoes.append(st);
	cout << "new contents of list:\n";
	for (int x = 0; x < shoes.getLength(); x++) {
		cout << shoes.getElement(x) << endl;
	}
	int t;
	cout << "try replace\n";
	cout << "enter position to replace\n";
	cin >> t;
	cout << "now enter shoe\n";
	cin >> st;
	shoes.replace(t - 1, st);
	cout << "new contents of list:\n";
	for (int x = 0; x < shoes.getLength(); x++) {
		cout << shoes.getElement(x) << endl;
	}
	cout << "now replace an impossible position\n";
	cout << "enter position to replace\n";
	cin >> t;
	cout << "now enter shoe\n";
	cin >> st;
	try {
		shoes.replace(t - 1, st);
	}
	catch (string mess) {
		cout << mess << endl;
	}
	cout << "contents of list:\n";
	for (int x = 0; x < shoes.getLength(); x++) {
		cout << shoes.getElement(x) << endl;
	}
	cout << "thank you for testing, shutting down list...\n";
	cout << "clearing list...\n";
	shoes.clear();
	cout << "done! goodbye!";

	return 0;
}
