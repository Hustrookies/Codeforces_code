//CF_881_E
//binary search+ prefix sum
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e5+10;
const ll INF=1e18;
ll dp[N];
void solve(){

   int n,m;
   cin>>n>>m;
   vector<pair<int,int>>seg(m);
   for(int i=0;i<m;i++)cin>>seg[i].first>>seg[i].second;
   int Q;
   cin>>Q;
   vector<int> p(Q);
   for(int i=0;i<Q;i++)cin>>p[i];
   auto check=[&](int mid){

    vector<int>s(n+1);
    for(int i=0;i<mid;i++)s[p[i]]=1;
    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    for(auto [l,r]:seg){

        if(s[r]-s[l-1]>(r-l+1)-(s[r]-s[l-1])) return 1;
    }
    return 0;
   };
   int l = 1, r = Q + 1;
    while(l < r){
        int mid = (l + r) >>1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (r == Q + 1) cout << -1 << endl;
    else cout << r <<endl;


}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}