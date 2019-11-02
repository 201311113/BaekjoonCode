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
int arr[26];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[s[0] - 'a']++;
	}
	bool flag = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			cout << (char)(i + 'a');
			flag = 1;
		}
	}
	if (!flag) cout << "PREDAJA";

}