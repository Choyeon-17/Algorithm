#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;
int n, cntAlpha, mxm;

vector<char[MAX + 1]> words(MAX);
char useAlpha[MAX];
short alphaValue[MAX];
bool check[MAX];

int find(char c)
{
	for (int i = 0; i < cntAlpha; i++)
		if (useAlpha[i] == c)
			return i;
	return -1;
}

void backtracking(int pos)
{
	if (pos == cntAlpha)
	{
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			int cal = 0;
			int len = strlen(words[i]);
			for (int j = 0; j < len; j++)
				cal = (cal * 10) + alphaValue[find(words[i][j])];
			sum += cal;
		}

		if (mxm < sum)
			mxm = sum;
	}

	else
	{
		for (int i = 0; i < cntAlpha; i++)
		{
			if (check[i])
				continue;
			alphaValue[pos] = MAX - i - 1;
			check[i] = true;
			backtracking(pos + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> words[i];

		for (int j = 0; words[i][j] != '\0'; j++)
			if (find(words[i][j]) == -1)
				useAlpha[cntAlpha++] = words[i][j];
	}

	backtracking(0);

	cout << mxm;
	return 0;
}