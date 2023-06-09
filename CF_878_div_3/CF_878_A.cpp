//CF_878_A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

void solve(){

    string s,ans;
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++){

        char tmp=s[i];
        ans.push_back(tmp);
        i++;
        while(s[i]!=tmp)i++;
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