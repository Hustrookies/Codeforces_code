//CF_878_E
//data structure
#include<bits/stdc++.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=2e5+10;
int n;
bool is_sam[N];
struct node
{
    int t,id;
    bool operator <(const node &a)const{

        return t>a.t;
    }
};

void solve(){

   memset(is_sam,0,sizeof(is_sam));
   string s[3];
   cin>>s[1]>>s[2];
   int len=s[1].size();
   int dif_num=len;
   for(int i=0;i<len;i++)if(s[1][i]==s[2][i])is_sam[i]=1,dif_num--;
   int t,Q;
   cin>>t>>Q;
   set<int>block_dif,block_same;
   priority_queue<node>q;
   int T=1;
   while(Q--){

    int flag,pos1,pos2;
    cin>>flag;
    if(flag==1){

        cin>>pos1;
        pos1--;
        node tmp;
        if(is_sam[pos1])block_same.insert(pos1);
        else block_dif.insert(pos1);
        tmp.id=pos1,tmp.t=T+t;
        q.push(tmp);
    }else if(flag==2){

        int f1,f2;
        cin>>f1>>pos1>>f2>>pos2;
        pos1--,pos2--;
        swap(s[f1][pos1],s[f2][pos2]);
        if(s[1][pos1]==s[2][pos1]&&!is_sam[pos1]){
            dif_num--;
            is_sam[pos1]=1;
            if(block_dif.find(pos1)!=block_dif.end()){

                block_dif.erase(pos1),block_same.insert(pos1);
            }
        }
        else if(s[1][pos1]!=s[2][pos1]&&is_sam[pos1]) {
            dif_num++;
            is_sam[pos1]=0;
             if(block_same.find(pos1)!=block_same.end()){

                block_same.erase(pos1),block_dif.insert(pos1);
            }
        }
        if(s[1][pos2]==s[2][pos2]&&!is_sam[pos2]){
            dif_num--;
            is_sam[pos2]=1;
            if(block_dif.find(pos2)!=block_dif.end()){

                block_dif.erase(pos2),block_same.insert(pos2);
            }
        }
        else if(s[1][pos2]!=s[2][pos2]&&is_sam[pos2]) {
            dif_num++;
            is_sam[pos2]=0;
             if(block_same.find(pos2)!=block_same.end()){

                block_same.erase(pos2),block_dif.insert(pos2);
            }
        }
    }
    while(!q.empty()&&q.top().t<=T){

        node top=q.top();
        q.pop();
        if(block_dif.find(top.id)!=block_dif.end())block_dif.erase(top.id);
        if(block_same.find(top.id)!=block_same.end())block_same.erase(top.id);
    }
    if(flag==3){
        if(dif_num==(int)block_dif.size())cout<<"Yes"<<endl;
        else cout<<"NO"<<endl;
    }
    T++;
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