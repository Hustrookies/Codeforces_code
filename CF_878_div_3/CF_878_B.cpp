//CF_878_B
//bitmask
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;

void solve(){

   ll n,k;
   cin>>n>>k;
   if(k>=32)cout<<n+1<<endl;
   else{

    ll Max=pow(2,k)-1;
    if(Max>=n)cout<<n+1<<endl;
    else cout<<Max+1<<endl;
   }
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}