#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Algoritms {
public:
	float* Arr;
	float Number;
	int Range;

	ifstream ReadFile;
	ofstream WriteFile;
	string Name;

	void OpenReadFile(string Name, int Range);
	void GetRandomNumbers(int Range);
	void WriteIntoFile(string Name, int Range);
	void ShellSort(int Range, float* Arr);
	void ShakerSort(int Range, float* Arr);
	void BucketSort(int Range, float* Arr);
	void InputMassive(int Range);
};