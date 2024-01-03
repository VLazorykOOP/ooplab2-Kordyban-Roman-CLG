#include<iostream>
#include<bitset>
using namespace std;

void encode(bitset<24>& data, int* numbers)
{
	int i{ 0 };
	for (; i < 4; i++)
	{
		data[i] = numbers[0] & (1 << i);
	}
	for (; i < 8; i++)
	{
		data[i] = numbers[1] & (1 << i - 4);
	}
	for (; i < 15; i++)
	{
		data[i] = (numbers[2] - 1940) & (1 << i - 8);
	}
	for (; i < 20; i++)
	{
		data[i] = numbers[3] & (1 << i - 15);
	}
	data[i] = numbers[4] & 1;
}

void decode(bitset<24>& data, int* numbers)
{

	return;
}

int t4()
{
	bitset<24> data{ 0 };
	int original[5]{ 9,15,2023,5,1 }, numbers[5];
	for (int i = 0; i < 5; i++) { numbers[i] = original[i]; }
	encode(data, numbers);
	decode(data, numbers);
	for (int i = 0; i < 5; i++) { cout << original[i] << "\t:\t" << numbers[i] << "\t:\t" << endl; }
	for (int i = 0; i < 24; i++) { if (i == 4 || i == 8 || i == 15 || i == 20 || i == 21) { cout << ' '; }cout << int(data[i]); }

}
/*
24
		min		max		bits
a		0		12		4
b		0		9		4
c		1940	2065	7
d		0		31		5
e		0		1		1
 */