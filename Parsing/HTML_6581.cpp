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
int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	string s;

	int sum = 0;

	bool sameline = false;

	while (cin >> s)

	{

		if (s == "<br>")

		{

			cout << "\n";

			sum = 0;

		}

		else if (s == "<hr>")

		{

			if (!sum)

			{

				for (int i = 0; i < 80; i++)

					cout << "-";

				cout << "\n";

			}

			else

			{

				sum = 0;

				cout << "\n";

				for (int i = 0; i < 80; i++)

					cout << "-";

				cout << "\n";

			}

		}

		else

		{

			int len = s.length();

			if (!sum)

			{

				sum = len;

				cout << s;

				sameline = true;

			}

			else if (sum + len + 1 <= 80)

			{

				if (sameline)

				{

					cout << " ";

					sum += 1;

				}

				sum += len;

				cout << s;

				if (sum == 80)

				{

					cout << "\n";

					sum = 0;

					sameline = false;

				}

			}

			else

			{

				cout << "\n";

				sum = len;

				sameline = true;

				cout << s;

			}

		}

	}

	return 0;

}