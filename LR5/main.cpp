#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void nA() {
	int n, m;
	cout << "Введите размер матрицы n <= 10 и m <= 10: " << endl;
	cin >> n >> m;
	if (n > 10 || m > 10) {
		cout << "Неверный ввод";	
		return;
	}

	int **A = new int*[n];
	for (int i = 0; i < n; i++) A[i] = new int[m];
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 10 * (j + 1); // получаем 10 20 30 и тд
		}
	}
	
	cout << "Итоговый массив: \n";
	int s = 8;
	int step = 4;

	for (int i = 0; i < n; i++) {
		cout << setw(s) << ' ';
		for (int j = 0; j < m; j++)
			cout << A[i][j] << ' ';
		cout << endl;

		s = s - step;
		if (s == 0 || s == 8) step = -step; // начинаем прибавлять или наоборот отбавлять, если дошли до края
	}

	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;

}



void nB() {
	int n, m, s = 0;
	cout << "Введите размер матрицы n <= 7 и m <= 9: " << endl;
	cin >> n >> m;
	if (n > 7 || m > 9) {
		cout << "Неверный ввод";
		return;
	}
	vector<int> sm;
	int** A = new int* [n];
	for (int i = 0; i < n; i++) A[i] = new int[m];						
	cout << "Введите эл-ты массива: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	cout << "Исходная матрица \n";				
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s += A[i][j];
		}
		sm.push_back(s);
		s = 0;
	}
	cout << "Суммы \n";
	for (int i = 0; i < sm.size(); i++)
		cout << sm[i] << " ";
	cout << endl;

	bool found = false;
	for (int i = 0; i < sm.size(); i++){
		bool is = false;
		for (int j = 0; j < i; j++) {
			if (sm[i] == sm[j]) {				
				is = true;
				break;
			}			
		}
		if (is == true) {
			found = true;
			cout << "Повторяются " << sm[i] << " в массиве на позициях: ";
			vector<int> pos;
			for (int k = 0; k < sm.size(); k++) {
				if (sm[k] == sm[i]) {
					cout << k << " ";
					pos.push_back(k);
				}
			}
			cout << endl;
			for (int p = 1; p < pos.size(); p++) {
				swap(A[pos[0]], A[pos[p]]);
			}
		}
		
	}
	if (found == false) cout << "Повторяющихся сумм нет" << endl;


	cout << "Матрица после перестановок: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;
}


int main() {
	setlocale(0, "russian");
	/*nA();*/
	nB();
	return 0;
}
