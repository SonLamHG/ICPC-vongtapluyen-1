#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
	tree_order_statistics_node_update>  ordered_set;




int dp[200005][19] = {};
int main(){
	int n; cin>>n;
	memset(dp,0x3f, sizeof(dp));
	for(int i=1;i<=n;i++){
		cin>>dp[i][0];
	}
	for(int i = 1;i<18; i++){
		for(int j = 1; j <= n - (1<<i) + 1; j++){
			
			dp[j][i] = min(dp[j][i-1], dp[j + (1<<(i-1))][i-1]);
		}
	}
//	for(int i = 1;i<=n;i++) cout<< dp[i][0]<<" ";
	//cout<<dp[3][2]<<" "<< dp[8- (1<<2)+1][2]<<endl;
	for(int i = 1;i<=n;i++){
		int ans = INT_MIN;
		for(int j = 1;j<=n - i + 1;j++){
			int r = i +j - 1;
			int k = log2(r - j +1);
		//	cout<< j<<" "<<r<<" "<<k<<" "<<min(dp[j][k], dp[r - (1<<k) +1][k])<<endl;
			ans = max(ans,min(dp[j][k], dp[r - (1<<k) +1][k]));
		}
		cout<< ans<<" ";
	}
}