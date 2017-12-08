#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

void toUTF(vector <string> word);
long bitMasker(string bin, int size);

int main()
{
	vector <string> words;
	string word;
	while (input >> word) {
		words.push_back(word);
	}
	toUTF(words);
	input.close();
	output.close();
	cin.get();
	return 0;
}


void toUTF(vector <string> word){
	
	for (size_t j = 0; j < word.size(); j++) {
		string temp = "";
		if (j == 0) {
			output << "BOM Defused" << endl;
			for (size_t i = 3; i < word.at(j).size(); ++i)
			{
				bitset<8> set(word.at(j).c_str()[i]);
				temp += set.to_string();
				
			}
			output << "Ux" << uppercase <<hex << bitMasker(temp, word.at(j).size()-3);
		}
		else {
			for (size_t i = 0; i < word.at(j).size(); ++i)
			{
				bitset<8> set(word.at(j).c_str()[i]);
				temp += set.to_string();
				
			}
			output << "Ux" << uppercase << hex << bitMasker(temp, word.at(j).size());
		}
		output << endl;
	}
}


long bitMasker(string bin, int size) {
	string masked;
	long out = 0000;
	switch (size) {
	case 1: for (int i = 1; i < 8; i++) {
				masked += bin[i];
			}
			out = stol(masked, nullptr, 2);
			return out;
	case 2: for (int i = 3; i < 8; i++) {
				masked += bin[i];
			}
			for (int i = 10; i < 16; i++) {
				masked += bin[i];
			}
			out = stol(masked, nullptr, 2);
			return out;
	case 3: for (int i = 4; i < 8; i++) {
				masked += bin[i];
			}
			for (int i = 10; i < 16; i++) {
				masked += bin[i];
			}
			for (int i = 18; i < 24; i++) {
				masked += bin[i];
			}
			out = stol(masked, nullptr, 2);
			return out;
	case 4: for (int i = 4; i < 8; i++) {
				masked += bin[i];
			}
			for (int i = 10; i < 16; i++) {
				masked += bin[i];
			}
			for (int i = 18; i < 24; i++) {
				masked += bin[i];
			}
			for (int i = 26; i < 32; i++) {
				masked += bin[i];
			}
			out = stol(masked, nullptr, 2);
			return out;
	default:
		return out;
		break;
	}
}

