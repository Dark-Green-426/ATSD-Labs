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
	srand(time(NULL));
	for (int i = 0; i < Range; i++) {
		Arr[i] = rand();
		Arr[i] *= 0.001;
		if (Arr[i] > 16 && Arr[i] <= 18) {
			Arr[i] *= -1;
		}
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

	for (int i = 0; i < Range; i++) {
		if (Arr[i] < -10) {
			Bukets[0][Count[0]] = Arr[i];
			Count[0]++;
		}
		else if (Arr[i] > -10 && Arr[i] < 10) {
			Bukets[1][Count[1]] = Arr[i];
			Count[1]++;
		}
		else if (Arr[i] > 10) {
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