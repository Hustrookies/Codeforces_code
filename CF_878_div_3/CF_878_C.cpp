//CF_878_C
//math
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
void solve(){

    
   int n,k,q;
   cin>>n>>k>>q;
   vector<int>a(n+1);
   for(int i=1;i<=n;i++)cin>>a[i];
   ll ans=0;
   for(int i=1;i<=n;i++){

    if(a[i]<=q){

        ll len=0;
        while(i<=n&&a[i++]<=q)len++;
        i--;
        if(len>=k)ans+=(len-k+2)*(len-k+1)/2;
    }
   }
   cout<<ans<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}