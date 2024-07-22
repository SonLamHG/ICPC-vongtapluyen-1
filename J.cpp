#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int l[n],r[n];
    stack<int> st;

    for(int i=0; i<n; i++){
        while(st.size() && a[i]<=a[st.top()]) st.pop();
        l[i]=-1;
        if(st.size()) l[i]=st.top();
        st.push(i);
    }

    while(st.size()) st.pop();
    for(int i=n-1; i>=0; i--){
        while(st.size() && a[i]<=a[st.top()]) st.pop();
        r[i]=n;
        if(st.size()) r[i]=st.top();
        st.push(i);
    }

    vector<int> ans(n+1,0);
    for(int i=0; i<n; i++){
        int d=r[i]-l[i]-1;
        ans[d]=max(ans[d],a[i]);
    }
    for(int i=n-1; i>0; i--) ans[i]=max(ans[i],ans[i+1]);

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';

    return 0;
}
