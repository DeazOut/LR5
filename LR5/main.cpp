#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void nA() {
	int n, m;
	cout << "������� ������ ������� n <= 10 � m <= 10: " << endl;
	cin >> n >> m;
	if (n > 10 || m > 10) {
		cout << "�������� ����";	
		return;
	}

	int **A = new int*[n];
	for (int i = 0; i < n; i++) A[i] = new int[m];
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 10 * (j + 1); // �������� 10 20 30 � ��
		}
	}
	
	cout << "�������� ������: \n";
	int s = 8;
	int step = 4;

	for (int i = 0; i < n; i++) {
		cout << setw(s) << ' ';
		for (int j = 0; j < m; j++)
			cout << A[i][j] << ' ';
		cout << endl;

		s = s - step;
		if (s == 0 || s == 8) step = -step; // �������� ���������� ��� �������� ���������, ���� ����� �� ����
	}

	for (int i = 0; i < n; i++) delete[] A[i];
	delete[] A;

}



void nB() {
	int n, m, s = 0;
	cout << "������� ������ ������� n <= 7 � m <= 9: " << endl;
	cin >> n >> m;
	if (n > 7 || m > 9) {
		cout << "�������� ����";
		return;
	}
	vector<int> sm;
	int** A = new int* [n];
	for (int i = 0; i < n; i++) A[i] = new int[m];						
	cout << "������� ��-�� �������: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
	cout << "�������� ������� \n";				
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
	cout << "����� \n";
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
			cout << "����������� " << sm[i] << " � ������� �� ��������: ";
			vector<int> pos;
			for (int k = 0; k < sm.size(); k++) {
				if (sm[k] == sm[i]) cout << k << " ";		
				pos.push_back(k);
			}
			cout << endl;
			for (int p = 1; p < pos.size(); p++) {
				swap(A[0], A[pos[p]]);
			}
		}
		
	}
	if (found == false) cout << "������������� ���� ���" << endl;


	cout << "������� ����� ������������: \n";
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