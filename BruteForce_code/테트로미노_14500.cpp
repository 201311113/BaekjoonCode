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
using namespace std;
int arr[502][502] = { 0, };
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i < N - 1 && j < M - 1) {		// Á¤»ç°¢
				int sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N && j < M - 3) {		//´¯Èù ¸·´ë
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
				if (max < sum) max = sum;
			}
			if (i < N - 3 && j < M) {	//¼¼¿î ¸·´ë
				int sum = arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j] + arr[i][j];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 1 && j > 0) {	//Á¤¹æÇâ »µÅ¥
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 1][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M - 1) {	//90µµ È¸Àü »µÅ¥
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 2) {	//180µµ È¸Àü »µÅ¥
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M && j > 0) {	//270µµ È¸Àü »µÅ¥
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M - 1) {	//½¦¾î¸µ
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 1 && j > 0) {	//90µµ È¸Àü ½¦¾î¸µ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j - 1];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M && j > 0) {	//ÁÂ¿ì´ëÄª ½¦¾î¸µ
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 2) {	//À§¾Æ·¡ ´ëÄª ½¦¾î¸µ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M - 1) {	//¤¡ÀÚ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N && i > 0 && j < M - 2) {	//90µµ È¸Àü ¤¡ÀÚ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M - 1) {	//180µµ È¸Àü ¤¡ÀÚ
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 2) {	//270µµ È¸Àü ¤¡ÀÚ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j < M - 1) {	// ÁÂ¿ì´ëÄª ¤¡ÀÚ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 2) {	//90µµ È¸Àü ÁÂ¿ì´ëÄª ¤¡ÀÚ
				int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
				if (max < sum) max = sum;
			}
			if (i < N - 2 && j > 0 && j < M) {	//180µµ È¸Àü ÁÂ¿ì´ëÄª ¤¡ÀÚ
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
				if (max < sum) max = sum;
			}
			if (i < N - 1 && j < M - 2) {	//270µµ È¸Àü ÁÂ¿ì´ëÄª ¤¡ÀÚ
				int sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (max < sum) max = sum;
			}
		}
	}
	printf("%d", max);
}