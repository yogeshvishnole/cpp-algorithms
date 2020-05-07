#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int med(int a, int b, int c)
{
	int A[] = { a,b,c };
	int n = sizeof(A) / sizeof(A[0]);
	sort(A, A + n);
	return A[1];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		vector<int> vec;
		vec.reserve(N);
		for (int i = 0; i < N; i++)
		{
			cin >> vec[i];
		}
		for (int i = 0; i < (N - 2); i++)
		{
			int median = med(vec[i],vec[i + 1], vec[i + 2]);
			if (median == vec[i])
				vec.erase(vec.begin() + i);
			else if (median == vec[i + 1])
				vec.erase(vec.begin() + i + 1);
			else
				vec.erase(vec.begin() + i + 2);
		}
		cout << vec[0] << " " << vec[1] << endl;
	}
}
