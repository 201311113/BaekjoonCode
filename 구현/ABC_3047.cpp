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
int arr[3];
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	string s;
	cin >> s;
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'A') {
			cout << arr[0] << " ";
		}
		else if (s[i] == 'B') {
			cout << arr[1] << " ";
		}
		else if (s[i] == 'C') {
			cout << arr[2] << " ";
		}
	}
}
