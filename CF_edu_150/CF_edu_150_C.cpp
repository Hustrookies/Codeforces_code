//CF_edu_150_C
//DF+brute force
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
const ll INF=1e18;
int p[10]={1,10,100,1000,10000};

ll get_ans(string s){

    string r;
    int len=s.size();
    char tmp=s.back();
    for(int i=len-1;i>=0;i--){

        r.push_back(tmp);
        if(s[i]>tmp)tmp=s[i];
    }
    reverse(r.begin(),r.end());
    ll ret=0;
    for(int i=0;i<len;i++){

        if(s[i]>=r[i])ret+=p[s[i]-'A'];
        else ret-=p[s[i]-'A'];
    }
    return ret;
}
void solve(){

   string S;
   cin>>S;
   vector<vector<int>>pos(10);
   for(int i=0;i<(int)S.size();i++)pos[S[i]-'A'].push_back(i);
   ll ans=-INF;
   for(int i='A';i<='E';i++){

    if(pos[i-'A'].empty())continue;
    string tmp1(S),tmp2(S);
    for(int j='A';j<='E';j++){
        tmp1[pos[i-'A'][0]]=j;
        ans=max(ans,get_ans(tmp1));
        tmp2[pos[i-'A'].back()]=j;
        ans=max(ans,get_ans(tmp2));
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