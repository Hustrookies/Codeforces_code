//CF_881_E
//DP in tree
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e5+10;
const ll INF=1e18;
ll dp[N];
void solve(){

    int n,Q;
    cin>>n;
    vector<ll>dp(n+1,0);
    vector<int>deg(n+1,0);
    queue<int> q;
    vector<bool> vis(n+1);
    vector<int>G[n+1];
    for(int i=1;i<n;i++){

        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //leaf
    for(int i=2;i<=n;i++){

        if(deg[i]==1) {
            dp[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){

        int fro=q.front();
        vis[fro]=1;
        q.pop();
        for(int i=0;i<G[fro].size();i++){

            if(!vis[G[fro][i]]){

                int fa=G[fro][i];
                dp[fa]+=dp[fro];
                deg[fa]--;
                if(fa>1&&deg[fa]==1)q.push(fa);
                                   
                break;
            }
        }
    }  
    cin>>Q;
    while(Q--){

        int u,v;
        cin>>u>>v;
        ll ans=dp[u]*dp[v];
        cout<<ans<<endl;
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