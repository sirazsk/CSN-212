#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef pair<int,int> pii;
typedef vector< pair<int,int> > vpi;

const int MAX_N = 20007;

int A[MAX_N];
int temp1[MAX_N];
int temp2[MAX_N];

int lis(int start, int max_length)
{
	int t1, t2;
	int size_b = 0;
	temp2[size_b++] = start;
	for (int i = start+1; i < start+max_length; i++)
	{
		if(A[temp2[size_b-1]] < A[i])
		{
			temp1[i] = temp2[size_b-1];
			temp2[size_b++] = i;
			continue;
		}
		for(t1 = 0, t2 = size_b-1; t1 < t2;)
		{
			int c = (t1+t2)>>1;
			if(A[temp2[c]] < A[i])
			{
				t1=c+1;
			}
			else
			{
				t2=c;
			}
		}
		if(A[i] < A[temp2[t1]])
		{
			if(t1 > 0)
			{
				temp1[i] = temp2[t1-1];
			}
			temp2[t1] = i;
		}	
	}
	return size_b;
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		int n;
		scanf("%d", &n);

		for(int i=0; i < n; i++)
		{
			scanf("%d", &A[i]);
			A[i+n] = A[i];
		}

		vpi v;
		for(int i=0; i < n; ++i)
		v.pb(mp(A[i], i));
		sort(v.begin(), v.end());

		int ans = 1;
		for(int i=0; i < min(150, (int)v.size()); i++)
		{
			ans = max(ans, lis(v[i].S, n));		
		}

		printf("%d\n", ans);
	}
	return 0;
}
