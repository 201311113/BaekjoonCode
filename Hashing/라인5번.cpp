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
map<string, bool> m;
bool cmp(const pair<string, int> &a, const pair<string, int> &b) {	// document들을 정렬하기 위해만든 cmp함수 태그값이 같은게 있으면 이름순으로 정렬
	if (a.second == b.second) return a < b;
	return a.second > b.second;
}
vector<string> cal(vector<vector<string>> dataSource, vector<string> tags) {
	for (int i = 0; i < tags.size(); i++) {//맵에 tag들 저장
		m.insert({ tags[i], 1 });
	}
	vector<string> ans;
	vector<pair<string,int>> doc;
	for (int i = 0; i < dataSource.size(); i++) {	// 있는 태그값 계산해서 doc 벡터에 저장
		int tmp = 0;
		for (int j = 1; j < dataSource[i].size(); j++) {
			if (m[dataSource[i][j]]) {
				tmp++;
			}
		}
		doc.push_back({ dataSource[i][0], tmp});// 0번째가 doc이름이니까
	}
	sort(doc.begin(), doc.end(), cmp);
	int cnt = 0;
	for (int i = 0; i < doc.size(); i++) {
		if (cnt == 10) break;
		if (doc[i].second == 0) continue;
		ans.push_back(doc[i].first);
		cnt++;
	}
	return ans;
}
int main() {
	vector<string> tags;
	vector<vector<string>> dataSource;
	while (1) {
		string s;
		cin >> s;
		if (s == "end") {
			break;
		}
		vector<string> tmp;
		tmp.push_back(s);
		while (1) {
			string ss;
			cin >> ss;
			if (ss == "end") break;
			tmp.push_back(ss);
		}
		dataSource.push_back(tmp);
	}
	while (1) {
		string s;
		cin >> s;
		if (s == "end") break;
		tags.push_back(s);
	}
	vector<string> ans = cal(dataSource, tags);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<<" ";
	}
}
//doc1 t1 t2 t3 end
//doc2 t0 t2 t3 end
//doc3 t1 t6 t7 end
//doc4 t1 t2 t4 end
//doc5 t6 t100 t8 end
//end
//t1 t2 t3 end
