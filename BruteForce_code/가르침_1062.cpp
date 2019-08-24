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
using namespace std;
int N, K;
vector<string> word;
bool alpha[26];
int max_cnt = 0;
void BT(int al, int cnt) {
	if (cnt == K) {	//배울수 있는 최대한 배우고 단어 탐색
		int possible_cnt = 0;
		for (int i = 0; i < word.size(); i++) {
			bool flag = 1;
			for (int j = 0; j < word[i].size(); j++) {
				if (!alpha[word[i][j] - 'a']) {
					flag = 0;
					break;
				}
			}
			if (flag) possible_cnt++;
		}
		max_cnt = max(max_cnt, possible_cnt);
		return;
	}
	for (int i = al; i < 26; i++) {
		if (alpha[i] == 0) {
			alpha[i] = 1;
			BT(i, cnt + 1);
			alpha[i] = 0;
		}
	}

}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int s_size = s.size() - 8;
		s = s.substr(4, s_size);
		word.push_back(s);
	}
	if (K == 26) {
		cout << N;
		return 0;
	}

	alpha['a' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['i' - 'a'] = 1;
	alpha['c' - 'a'] = 1;
	K -= 5;
	BT(0, 0);
	cout << max_cnt;
}