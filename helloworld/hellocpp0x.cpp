#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* auto keyword*/
void hello1() {
	vector<string> vec = {"Hello", "world"};
	for (auto e : vec) {
		cout << e << endl;
	}
}

int main(int argc, char **argv) {
	hello1();
	return 0;
}
