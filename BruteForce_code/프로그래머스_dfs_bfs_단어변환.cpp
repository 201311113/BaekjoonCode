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
int min_num = 123456789;
bool chk[53];
bool cmp(string tmp, string word) {
	int cnt = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] != word[i]) cnt++;
	}
	if (cnt == 1) return true;
	return false;
}
void dfs(string tmp, string target, int cnt, vector<string>& words) {
	if (tmp == target) {
		if (min_num > cnt) min_num = cnt;
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		if (!chk[i] && cmp(tmp, words[i])) {
			chk[i] = 1;
			dfs(words[i], target, cnt + 1, words);
			chk[i] = 0;
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	dfs(begin, target, 0, words);
	if (min_num == 123456789);
	else answer = min_num;
	return answer;
}