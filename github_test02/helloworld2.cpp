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

int multiply(int base, int target) {
	return base * target;
}

int div(int base, int target) {
	return base / target;
}

void printtest() {
	cout << "test" << endl;
}

void printtest2() {
	cout << "test2" << endl;
}

int main(int argc, char *argv) {
	cout << "Hello world!" << endl;

	cout << "Hello world 2 !" << endl;

	cout << sum(3, 5) << endl;
	cout << sub(5, 4) << endl;
	cout << multiply(10, 3) << endl;
	cout << div(10, 5) << endl;

	repeat(20);

	printHello();

	return 0;
}
