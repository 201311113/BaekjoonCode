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
int main() {
	int t;
	scanf("%d\n", &t);
	string end_sentence = "what does the fox say?";
	while (t--) {
		string record;
		getline(cin, record);
		vector<string> records;
		vector<string> not_fox;
		string tmp = "";
		for (int i = 0; i < record.size(); i++) {
			if (record[i] == ' ') {
				records.push_back(tmp);
				tmp = "";
				continue;
			}
			tmp += record[i];
		}
		records.push_back(tmp);
		while (1) {
			string other_animal;
			getline(cin, other_animal);
			if (other_animal == end_sentence) break;
			for (int i = other_animal.size() - 1; i >= 0; i--) {
				if (other_animal[i] == ' ') {
					not_fox.push_back(other_animal.substr(i + 1));
					break;
				}
			}
		}

		for (int i = 0; i < records.size(); i++) {
			bool flag = 0;
			for (int j = 0; j < not_fox.size(); j++) {
				if (records[i] == not_fox[j]) {
					flag = 1;
					break;
				}
			}
			if (!flag) cout << records[i] << " ";
		}
	}
}