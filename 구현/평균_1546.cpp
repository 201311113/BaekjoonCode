#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<ctime>
#include<set>
#include<sstream>
using namespace std;
int arr[1001];
int main() {
	int n;
	cin >> n;
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max_num < arr[i])	max_num = arr[i];
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double cal_score = (double)arr[i] / (double)max_num * 100;
		sum += cal_score;
	}
	sum /= n;
	string tmp = to_string(sum);
	reverse(tmp.begin(), tmp.end());
	int cnt = 0;
	bool flag = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '0' && !flag) continue;
		else {
			if (tmp[i] == '.') {
				break;
			}
			flag = 1;
			cnt++;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum;

}