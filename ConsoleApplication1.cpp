#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

static int cor = 0;

void printMatrix(const vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void clear(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
	matrixA.clear();
	matrixB.clear();
	cout << "All previous input are deleted." << endl;
}

void getHelp() {
	cout << "Each roll's length of matrix must euqal.\nIn order to add or minus two matrixs, the row and roll of two matrixs must be equal";
	cout << "Here is the instruction of this software:" << endl;
	cout << "Click 1 Addition" << endl;
	cout << "Click 2 Substraction" << endl;
	cout << "Click 3 Multiplcation" << endl;
	cout << "Click 7 to delete previous input."<<endl;
	cout << "Click any other button to Divsion" << endl;
}

vector<vector<int>> MtxClac(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, int& func) {
	vector<vector<int>> ans(matrixA);
	for (int i = 0; i < matrixA.size() - 1; i++) {
		if (matrixA[i].size() != matrixA[i + 1].size()) {
			ans.clear();
			return ans;
		}

	}
	for (int i = 0; i < matrixB.size() - 1; i++) {
		if (matrixB[i].size() != matrixB[i + 1].size()) {
			ans.clear();
			return ans;
		}

	}
	switch (func) {
	case 1:
		if (matrixA.size() != matrixB.size()) {
			ans.clear();
			return ans;
		}
		for (int i = 0; i < matrixA.size() - 1; i++) {
			if (matrixA[i].size() != matrixB[i].size()) {
				ans.clear();
				return ans;
			}

		}
		for (int i = 0; i < matrixA.size(); i++) {
			for (int j = 0; j < matrixA[0].size(); j++) {
				ans[i][j] += matrixB[i][j];
			}
		}
		break;
	case 2:
		if (matrixA.size() != matrixB.size()) {
			ans.clear();
			return ans;
		}
		for (int i = 0; i < matrixA.size() - 1; i++) {
			if (matrixA[i].size() != matrixB[i].size()) {
				ans.clear();
				return ans;
			}

		}
		for (int i = 0; i < matrixA.size(); i++) {
			for (int j = 0; j < matrixA[0].size(); j++) {
				ans[i][j] -= matrixB[i][j];
			}
		}
		break;
	case 3: 
		if (matrixA.size() != matrixB[0].size()) {
			ans.clear();
			return ans;
		}
		for (int i = 0; i < matrixA.size(); ++i) {
			for (int j = 0; j < matrixB[0].size(); ++j) {
				ans[i][j] = 0;
				for (int k = 0; k < matrixA[0].size(); ++k) {
					ans[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
		

		break;


	}
	return ans;
}

int main() {
    vector<vector<int>> ans;
	vector<vector<int>> matrix1;
	vector<vector<int>> matrix2;
	int status = NULL;

	while (true) {
		bool UI = true;
		while (UI) {
		cout << "Welcome to martix calculator, this software allow you to do some claculation for two martix.\nClick any other bottoms to start.\nClick 9 exiting." << endl;
		cout << "If you want to get help, click '0'\n";
		cin >> status;
		switch (status) {
		case 9:
			cout << "Exit....";
			return 0;
		case 0:
			getHelp();
			break;
		case 7:
			clear(matrix1, matrix2);
		default:
			UI = false;
			break;
		}
	}



		int rows1, cols1;
		cout << "Enter the number of rows of the first two-dimensional vector (matrix): ";
		cin >> rows1;
		cout << "Enter the number of columns for the first two-dimensional vector (matrix): ";
		cin >> cols1;
		cout << "Enter the elements of the first two-dimensional vector (matrix) by row:" << endl;
		for (int i = 0; i < rows1; ++i) {
			vector<int> row;
			cout<<"row "<<i<<endl;
			for (int j = 0; j < cols1; ++j) {
				int element;
				cin >> element;
				row.push_back(element);
			}
			matrix1.push_back(row);
		}
		int rows2, cols2;
		cout << "Enter the number of rows of the second two-dimensional vector (matrix): ";
		cin >> rows2;
		cout << "Enter the number of columns of the second two-dimensional vector (matrix) : ";
		cin >> cols2;
		cout << "Enter the elements of the second two-dimensional vector (matrix) by row:" << endl;
		for (int i = 0; i < rows2; ++i) {
			vector<int> row;
			cout<<"row "<<i<<endl;
			for (int j = 0; j < cols2; ++j) {
				int element;
				cin >> element;
				row.push_back(element);
			}
			matrix2.push_back(row);
		}
		cout<<"which function you want to use?"<<endl;
		cin>>status;
		switch(status){
			case 1:
				ans = MtxClac(matrix1,matrix2,status);
				if (ans.empty()) {
					cout << "Invaild input, try again.\n";
					break;
				}
				cout << "A:\n";
				printMatrix(matrix1);
				cout << endl;
				cout << "B:\n";
				printMatrix(matrix2);
				cout << endl;
				cout << "A+B:\n";
				printMatrix(ans);
				break;
			case 2:
				ans = MtxClac(matrix1, matrix2, status);
				if (ans.empty()) {
					cout << "Invaild input, try again.\n";
					break;
				}
				cout << "A:\n";
				printMatrix(matrix1);
				cout << endl;
				cout << "B:\n";
				printMatrix(matrix2);
				cout << endl;
				cout << "A-B:\n";
				printMatrix(ans);
				break;
			case 3:
				ans = MtxClac(matrix1, matrix2, status);
				if (ans.empty()) {
					cout << "Invaild input, try again.\n";
					break;
				}
				cout << "A:\n";
				printMatrix(matrix1);
				cout << endl;
				cout << "B:\n";
				printMatrix(matrix2);
				cout << endl;
				cout << "A*B:\n";
				printMatrix(ans);
				break;
			default:
				ans = MtxClac(matrix1, matrix2, status);
				if (ans.empty()) {
					cout << "Invaild input, try again.\n";
					break;
				}
				cout << "A:\n";
				printMatrix(matrix1);
				cout << endl;
				cout << "B:\n";
				printMatrix(matrix2);
				cout << endl;
				cout << "A/B:\n";
				printMatrix(ans);
				break;
		}

		

	}

	return 0;
}


