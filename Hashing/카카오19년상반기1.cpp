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
vector<string> cal(vector<string> record) {
	vector<string> ans;
	map<string, string> m;
	map<string, string> mm;
	vector<pair<string, string>> tans;
	for (int i = 0; i < record.size(); i++) {
		string ord="", id="", nick="";
		int tmp = 0;
		for (int j = 0; j < record[i].size(); j++) {
			if (record[i][j] == ' ') {
				tmp++;
				continue;
			}
			if (tmp == 0) ord += record[i][j];
			else if (tmp == 1) id += record[i][j];
			else if (tmp == 2) nick += record[i][j];
		}
		if (ord == "Enter") {
			if (m.find(id) == m.end()) {//없을때
				m.insert({ id,nick });
				if (mm.find(id) != mm.end()) {
					mm[id] = nick;
				}
				else {
					mm.insert({ id,nick });
				}
				tans.push_back({ "enter",id });
			}
			else {
				mm[id] = nick;
			}
		}
		else if (ord == "Leave") {
			tans.push_back({ "leave", id });
			m.erase(id);

		}
		else if (ord == "Change") {
			mm[id] = nick;
		}
	}
	cout << mm["uid4567"] << endl;
	for (int i = 0; i < tans.size(); i++) {
		string s="";
		s += mm[tans[i].second];
		if (tans[i].first == "enter") {
			s += "님이 들어왔습니다.";
		}
		else if (tans[i].first == "leave") {
			s += "님이 나갔습니다.";
		}
		ans.push_back(s);
	}
	return ans;
}
int main() {
	vector<string> arr;
	arr.push_back("Enter uid1234 Muzi");
	arr.push_back("Enter uid4567 Prodo");
	arr.push_back("Leave uid1234");
	arr.push_back("Enter uid1234 Prodo");
	arr.push_back("Change uid4567 Ryan");
	vector<string> ans = cal(arr);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}