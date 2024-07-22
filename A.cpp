#include<bits/stdc++.h>
#define ll long long
#define onbit(n, i) (n|(1<<i))
#define checkbit(n, i) ((n>>i)%2)
#define fullbit(i) ((1<<i)-1)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define all(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 01
#endif

void solve()
{
	string s;
	cin>>s;
	vector<int> diff(s.size()+2, 0);
	int m;
	cin>>m;
	for(int q=1;q<=m;q++)
	{
		int r;
		cin>>r;
		diff[r]++;
		diff[s.size()-r+2]--;
	}
	for(int i=1;i<=s.size();i++) 
		diff[i] += diff[i-1];
	debug(diff);
	debug(s);
	for(int i=1;i<=s.size()/2;i++)
		if(diff[i]%2==1) swap(s[i-1], s[s.size()-i]);
	cout<<s<<endl;
}

int main()
{
  #ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
  #else
	#endif
//	int t;
//	cin>>t;
//	while(t--)
		solve();
	return 0;
}
