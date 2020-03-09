#include "Algoritms.h"

using namespace std;

void Algoritms::OpenReadFile(string Name, int Range) {
	ReadFile.open(Name);
	if (ReadFile.is_open()) {
		cout << "Успiшно зчитано з файлу!" << endl;
	}
	else {
		cout << "Помилка! Не зчитано з файлу!" << endl;
		return;
	}
	Arr = new float[Range];
	for (int i = 0; i < Range; i++) {
		ReadFile >> Number;
		Arr[i] = Number;
	}
	ReadFile.close();
}

void Algoritms::GetRandomNumbers(int Range) {
	Arr = new float[Range];
	cout << "Введіть мінімальне число\n";
	cin >> Min;
	cout << "Введіть максимальне число \n";
	cin >> Max;
	int Delta = Max - Min;
	srand(time(NULL));
	for (int i = 0; i < Range; i++) {
		Arr[i] = rand() % Delta + Min ;
		Arr[i] += (rand() % 1000) * 0.001;
 	}
}

void Algoritms::WriteIntoFile(string Name, int Range) {
	WriteFile.open(Name);
	if (WriteFile.is_open()) {
		cout << "Успiшно записано у файл!" << endl;
	}
	else {
		cout << "Помилка при запису в файл!" << endl;
		return;
	}
	int inx = 0;
	while (inx < Range) {
		if (inx % 15 == 0 && inx != 0) {
			WriteFile << '\n';
		}
		WriteFile << Arr[inx] << " ";
		inx++;
	}
	WriteFile.close();
	delete Arr;
}

void Algoritms::ShellSort(int Range, float* Arr) {
	if (Range <= 1) return;
	int Size = Range;
	clock_t Start, Stop;
	Start = clock();
	int Step = Size / 2;
	while (Step > 0) {
		for (int i = 0; i < Size - Step; i++) {
			int j = i;
			while (j >= 0 && Arr[j] > Arr[j + Step])
			{
				swap(Arr[j], Arr[j + Step]);
				j--;
			}
		}
		Step /= 2;
	}
	Stop = clock();
	cout << "Час виконання(Секунд): " << (Stop - Start) / CLK_TCK << "." << (Stop - Start) % CLK_TCK << endl;
}

void Algoritms::ShakerSort(int Range, float* Arr) {
	if (Range <= 1) return;
	int Left = -1;
	int Right = Range - 1;
	bool Boolean = true;
	clock_t Start, Stop;
	Start = clock();
	while (Boolean) {
		Boolean = false;
		Left++;
		for (int i = Left; i < Right; i++) {
			if (Arr[i] > Arr[i + 1]) {
				swap(Arr[i], Arr[i + 1]);
				Boolean = true;
			}
		}
		if (!Boolean) break;
		Right--;
		for (int i = Right; i > Left; i--) {
			if (Arr[i] < Arr[i - 1]) {
				swap(Arr[i], Arr[i - 1]);
			}
		}
	}
	Stop = clock();
	cout << "Час виконання(Секунд): " << (Stop - Start) / CLK_TCK << "." << (Stop - Start) % CLK_TCK << endl;
}

void Algoritms::BucketSort(int Range, float* Arr) {
	float* Bukets[3];
	clock_t Start, Stop;
	int Count[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		Bukets[i] = new float[Range];
	}

	Start = clock();
	int Index = (Max - Min) / 3;

	for (int i = 0; i < Range; i++) {
		if (Arr[i] < Min + Index) {
			Bukets[0][Count[0]] = Arr[i];
			Count[0]++;
		}
		else if (Arr[i] > Min + Index && Arr[i] < Min + 2*Index) {
			Bukets[1][Count[1]] = Arr[i];
			Count[1]++;
		}
		else if (Arr[i] > Min + 2 * Index) {
			Bukets[2][Count[2]] = Arr[i];
			Count[2]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		this->ShellSort(Count[i], Bukets[i]);
		system("cls");
	}

	Stop = clock();
	cout << "Час виконання(Секунд): " << (Stop - Start) / CLK_TCK << "." << (Stop - Start) % CLK_TCK << endl;

	int i = 0;
	for (int j = 0; j < Count[0] && i < Range; j++, i++) {
		Arr[i] = Bukets[0][j];
	}
	for (int k = 0; k < Count[1] && i < Range; k++, i++) {
		Arr[i] = Bukets[1][k];
	}
	for (int r = 0; r < Count[2] && i < Range; r++, i++) {
		Arr[i] = Bukets[2][r];
	}
}

void Algoritms::InputMassive(int Range) {
	Arr = new float[Range];
	for (int i = 0; i < Range; i++) {
		cout << "Введiть [" << i + 1 << "] Елемент:" << endl;
		cin >> Arr[i];
	}
}

void Algoritms::OutPrint(float* Arr, int Range) {
	cout << "Вивести на екран??? 1 - так, 0 - ні" << endl;
	int i;
	cin >> i;
	if (!i) {
		return;
	}
	for (int i = 0; i < Range; i++) {
		cout << Arr[i] << " ";
		if (i % 15 == 0 && i != 0){
			cout << endl;
		}
	}
}