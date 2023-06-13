//CF_edu_150_B
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;

void solve(){

   
   int n,fst;
   cin>>n;n--;
   bool flag=true;
   cin>>fst;
   string ans;
   ans.push_back('1');
   int Max=fst;
   while(n--){

    int a;
    cin>>a;
    if(flag){

        if(a>=Max){

            ans.push_back('1');
            Max=a;
            
        }else if(a<=fst){
            
            ans.push_back('1');
            flag=false;
            Max=a;
            
        }else  ans.push_back('0');
        continue;
    }
    if(a<=fst&&a>=Max){

        ans.push_back('1');
        Max=a;
    }
    else ans.push_back('0');
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