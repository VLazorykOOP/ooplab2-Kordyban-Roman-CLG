#include<iostream>
#include<string>
#include<bitset>
#include<fstream>
using namespace std;

void shuffle(bitset<16>* data)
{
	srand(time(0));
	for (int i = 64 - 1; i > 0; i--)
	{
		int j = std::rand() % (i + 1);
		swap(data[i], data[j]);
	}
}

void encode(string text, bitset<16>* data)
{
	for (int i = 0; i < text.size(); i++)
	{
		data[i][6] = i % 2;
		data[i][15] = text[i] % 2;
		for (int j = 0; j <= 5; j++) { data[i][j] = i & (1 << j); }
		for (int j = 7; j <= 14; j++) { data[i][j] = text[i] & (1 << j - 7); }
	}
}

void decode(string& text, bitset<16>* data)
{
	for (int i = 0; i < 64; i++) { text.push_back('\0'); }
	for (int i = 0; i < text.size(); i++)
	{
		int position = 0, symbol = 0;
		for (int j = 0; j <= 5; j++) { if (data[i][j]) { position |= (1 << j); } }
		for (int j = 7; j <= 14; j++) { if (data[i][j]) { symbol |= (1 << j - 7); } }
		text[position] = symbol;
		cout << position << '\t' << char(symbol) << '\t' << data[i].to_string() << endl;
	}
}

void f_read(bitset<16>* data)
{
	string bits;
	ifstream file("data.bin");
	getline(file, bits);
	file.close();
	for (int i = 0; i < 64; i++) { for (int j = 0; j < 16; j++) { data[i][j] = (bits[i * 16 + j] - '0'); } }
}

void f_write(bitset<16>* data)
{
	string bits;
	for (int i = 0; i < 64; i++) { for (int j = 0; j < 16; j++) { bits.push_back(data[i][j] + '0'); } }
	ofstream file("data.bin");
	file << bits;
	file.close();
}

void t2()
{
	bitset<16> data[64];
	for (int i = 0; i < 64; i++) { data[i].reset(); }
	string text;
	//text = "Romaaaan s1gma";
	if (text == "")
	{
		f_read(data);
		decode(text, data);
		cout << text << endl;
	}
	else
	{
		for (int i = text.size() - 1; i >= 0; i--) { if (text[i] == ' ') { text[i] = '_'; } }
		for (; text.size() > 64;) { text.pop_back(); }
		for (; text.size() < 64;) { text.push_back('_'); }

		encode(text, data);
		shuffle(data);
		f_write(data);
	}
}
