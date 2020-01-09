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
typedef long long ll;
int main() {
	vector<int> mushroom;
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		mushroom.push_back(n);
	}
	int sum = 0;
	bool flag = 0;
	for (int i = 0; i < 10; i++) {
		sum += mushroom[i];
		if (sum >= 100) {
			flag = 1;
			int a, b;
			a = sum - 100;
			b = 100 - (sum - mushroom[i]);
			if (a > b) sum -= mushroom[i];
			break;
		}
	}
	cout << sum;
}