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
#include<map>
#include<sstream>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr;
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		max_num += num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	if (arr[0] != 1) {
		cout << 1;
	}
	else{
		int sum = 1;
		for (int i = 1; i < n; i++) {
			if (sum + 1 < arr[i]) {
				break;
			}
			sum += arr[i];
		}
		cout << sum + 1;
	}
}