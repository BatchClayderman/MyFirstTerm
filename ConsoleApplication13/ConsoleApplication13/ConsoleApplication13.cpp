#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int factorial(int n) {//阶乘
	int temp = 1;
	for (int i = 1; i <= n; i++) {
		temp *= i;
	}
	return temp;
}
int pd(int* array, int len) {//逆序对的奇偶性判断
	int temp = 0;
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[i]) {
				temp++;
			}
		}
	}
	if (temp % 2 == 0) {
		return 1;
	}
	else {
		return -1;
	}
}
int main() {
	int n;
	cout << "请输入n：" << endl;
	cin >> n;
	vector< vector< int > > det(n, vector<int>(n));//利用vector新建二维数组，即行列式
	vector<vector<int > > t(factorial(n), vector<int>(n));//记录排列
	vector<int> jo(factorial(n));//奇偶性
	int* pl = new int[n];//排列的临时存放
	for (int i = 0; i < n; i++) {
		pl[i] = i + 1;//初始化为1，2....,n
	}
	//int k = 0;
	/*for (int i = 0; i < factorial(n); i++) {
		for (int j = 0; j < n; j++) {
			cout << t[i][j] << ' ';
		}
		cout << endl;
	}*/
	int j = 0;
	do {
		int* temp = new int[n];
		for (int i = 0; i < n; i++) {
			temp[i] = pl[i];
			t[j][i] = pl[i];
			//cout << t[j][i] << ' ';
		}
		//cout << endl;
		jo[j] = pd(temp, n);
		//cout << jo[j] << endl;
		j++;
		//k++;
		delete[] temp;
	} while (next_permutation(pl, pl + n));//全排列
	for (int i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << "请输入det(" << i + 1 << ")" << "(" << j + 1 << ")" << endl;
			cin >> det[i][j];
		}
	}
	int answer = 0;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << det[i][j] << ' ';
		}
		cout << endl;
	}*/
	cout << endl;
	for (int i = 0; i < factorial(n); i++) {
		//cout << jo[i] << endl;
		int temp = 1;
		for (j = 0; j < n; j++) {
			int l = t[i][j];
			/*cout << l << ' ';
			cout << det[j][l-1] << ' ';*/
			temp *= det[j][l - 1];
		}
		temp *= jo[i];
		//cout << endl;
		answer += temp;
	}
	cout << "det等于" << answer;
	delete[] pl;
	return 0;
}