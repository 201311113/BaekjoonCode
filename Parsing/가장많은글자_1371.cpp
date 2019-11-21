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
int alpha[27];
int main() {
	string s;
	while (getline(cin, s)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				alpha[s[i] - 'a']++;
			}
		}
	}
	int max_cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (max_cnt < alpha[i]) {
			max_cnt = alpha[i];
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max_cnt == alpha[i]) cout << (char)(i + 'a');
	}

}