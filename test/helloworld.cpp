#include <iostream>

using namespace std;

void printHelloWorld(int count);

int main(int argc, char *argv) {
  cout << "Hello world!" << endl;

  cout << "Hello world2!" << endl;

  for (int i = 0; i < 10; i++) {
	  cout << "Hello world[" << i << "]!!" << endl;
  }
  
  printHelloWorld(3);
  
  return 0;
}

void printHelloWorld(int count) {
  for (int i = 0; i < count; i++) {
    cout << "Hello World!" << endl;
  }
}
