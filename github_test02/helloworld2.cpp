#include <iostream>

using namespace std;

void repeat(int n)
{
	for (int i = 0; i < n; i++)
		cout << "Hello world!" << endl;
}

int sum(int base, int target) {
	return base + target;
}

void sayHello() {
	cout << "Say Hello !!!" << endl;
}

void printHello() {
	cout << "Hello world!!!!" << endl;
}

int sub(int base, int target) {
	return base - target;
}

int main(int argc, char *argv) {
	cout << "Hello world!" << endl;

	cout << "Hello world 2 !" << endl;

	cout << sum(3, 5) << endl;
	cout << sub(5, 4) << endl;

	repeat(20);

	printHello();

	return 0;
}
