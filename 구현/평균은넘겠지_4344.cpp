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
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		double sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		double avg = sum / (double)n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (avg < arr[i])	cnt++;
		}
		double G_stu = (double)cnt / (double)n * 100;
		cout << fixed;
		cout.precision(3);
		cout << G_stu << '%' << endl;

	}
}