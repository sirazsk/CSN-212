#include <iostream>
#include <vector>
using namespace std;

class ZigZag {
	public:
		int longestZigZag(vector<int> s)
		{
			if(s.size() == 1) return 1;
			
			vector<int> k(s.size()-1);
			for(int i = 1;i < s.size();i++)
			{
				k[i-1] = s[i]-s[i-1];
			}

			int l = 0;
			while(l < k.size() && k[l] == 0)
			{
				l++;
			}
			
			if(l == k.size()) return 1;
			int max = 2;
			int curr = k[l];
			for(int i = l+1;i < k.size();i++)
			{
				if(k[i]*curr < 0)
				{
					curr = k[i];
					max++;
				}
			}
			
			return max;
		}
};
