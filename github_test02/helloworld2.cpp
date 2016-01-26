#include <iostream>

using namespace std;

void repeat(int n)
{
	for (int i = 0; i < n; i++)
		cout << "Hello world!" << endl;
}

int main(int argc, char *argv) {
	cout << "Hello world!" << endl;

	cout << "Hello world 2 !" << endl;

	// task branch

	repeat(20);

	return 0;
}
