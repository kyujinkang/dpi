#include <iostream>

using namespace std;

void printHelloWorld();

int main(int argc, char *argv) {
  cout << "Hello world!" << endl;

  cout << "Hello world2!" << endl;

  for (int i = 0; i < 10; i++) {
	  cout << "Hello world[" << i << "]!!" << endl;
  }
  
  printHelloWorld();
  
  return 0;
}

void printHelloWorld() {
  cout << "Hello World!" << endl;
}
