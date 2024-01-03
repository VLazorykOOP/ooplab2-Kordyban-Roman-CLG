#include <iostream>
using namespace std;

int m(int a, int b)
{
	int result{ 0 };
	for (int i{ 0 }; i < a; i++) { result += b; }
	return result;
}
int t1() {
	int a{ 1 }, b{ 2 }, c{ 3 }, d{ 4 }, result{ (b << 4 + b + 1) }, tmp{ (a << 6) + (a << 2) };
	cout << ": " << ((m(17, b) + m(3012, a)) >> 5) - m(120, c) + m(127, d) << endl;
}
