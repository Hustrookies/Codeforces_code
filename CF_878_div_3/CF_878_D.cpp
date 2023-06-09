//CF_878_D
//binary search 
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;

int toy[N];
int n;
bool check(int mid){

    int d=toy[1]+mid*2;
    if(d>=toy[n])return 1;
    int pos1=upper_bound(toy+1,toy+n+1,d)-toy;
    d=toy[pos1]+mid*2;
    if(d>=toy[n])return 1;
    int pos2=upper_bound(toy+1,toy+n+1,d)-toy;
    d=toy[pos2]+mid*2;
    if(d>=toy[n])return 1;
    return 0;
}
void solve(){

   cin>>n;
   for(int i=1;i<=n;i++)cin>>toy[i];
   if(n<=3){

    cout<<0<<endl;
    return;
   }
   sort(toy+1,toy+n+1);
   int L=0,R=(toy[n]-toy[1])/2;
   while(L<R){

    int mid=(L+R)>>1;
    if(check(mid))R=mid;
    else L=mid+1;
   }
   cout<<L<<endl;
}

int main(){
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}