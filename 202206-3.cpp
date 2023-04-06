
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
//#define endl '\n'
typedef long long ll;
const int N=1e5+10;
int n,q;
string S;
int ls(int x) {return x<<1;}
int rs(int x){return x<<1|1;}
struct node{

    bool is_sort;
    int state;
};
node tree[N<<2];
bool check(int s1,int s2){

    //s1变为最高位之后都是1
    for(int i=25;i>=0;i--){

        if(s1&(1<<i)){

            s1=(1<<i)-1;
            break;
        }
    }
    if((s1&s2)==0) return 1;
    return 0;
}
void push_up(int p){

    tree[p].state=tree[ls(p)].state|tree[rs(p)].state;
    if(tree[ls(p)].is_sort&&tree[rs(p)].is_sort&&check(tree[ls(p)].state,tree[rs(p)].state))
     tree[p].is_sort=1;
    else tree[p].is_sort=0;
}
void build(int p,int pl,int pr){

    if(pl==pr) {

        tree[p].state=(1<<(S[pl-1]-'a'));
        tree[p].is_sort=1;
        return;
    }
    //递归建立子区间
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    //子区间建立完成，向上传递
    push_up(p);
}
void update(int pos,int p,int pl,int pr,char c){

    if(pl==pos&&pr==pos){

        tree[p].state=(1<<(c-'a'));
        return;
    }
    //递归修改子区间
    int mid=(pl+pr)>>1;
    if(pos<=mid) update(pos,ls(p),pl,mid,c);
    else update(pos,rs(p),mid+1,pr,c);
    //子区间修改完毕，向上传递
    push_up(p);
}
bool query_sort(int L,int R,int p,int pl,int pr){
    if(pl>=L&&R>=pr){

        return tree[p].is_sort;
    }
     bool ans=1;
    int mid=(pl+pr)>>1;
    if(L<=mid) ans*=query_sort( L, R, ls(p), pl,mid);
    if(R>mid) ans*=query_sort(L,R,rs(p),mid+1,pr);
    return ans;
    // if(ans&&check(tree[ls(p)].state,tree[rs(p)].state)){
    //     return 1;
    // }
    // else return 0;
}


int query_state(int L,int R,int p,int pl,int pr){

    if(pl>=L&&R>=pr){

        return tree[p].state;
    }
    int state=0;
    int mid=(pl+pr)>>1;
    if(L<=mid) state|=query_state(L,R,ls(p),pl,mid);
    if(R>mid) state|=query_state(L,R,rs(p),mid+1,pr);
    return state;
}

void solve(){

    
    cin>>n>>S>>q;
    build(1,1,n);
    while(q--){

        int op;
        int x,l,r;
        char c;
        cin>>op;
        if(op==1){

            // cin>>x>>c;
            // update(x,1,1,n,c);
            cin>>l>>r;
            cout<<query_sort(l,r,1,1,n)<<endl;
        }else{

           
            cin>>l>>r;
            if(l==r) {
                cout<<"Yes"<<endl;
                continue;
            }
             //满足有序
            if(query_sort(l,r,1,1,n)){

                if(l==1&&r==n) cout<<"Yes"<<endl;
                else{
                    //用state辅助判断； 
                    int state=query_state(l,r,1,1,n);
                    //cout<<state<<endl;
                    //去掉最高位和最低为
                    int high=0,low=0;
                    for(int i=0;i<26;i++){

                        if(state&(1<<i)){

                           low=i;
                            break;
                        }
                    }
                    for(int i=25;i>=0;i--){

                        if(state&(1<<i)){

                            high=i;
                            break;
                        }
                    }
                     //cout<<state<<endl;
                    // int s1=0,s2=0;
                    // if(l>1) s1=query_state(1,l-1,1,1,n);
                    // if(r<n) s2=query_state(r+1,n,1,1,n);
                    // if((s1&state)==0&&(s2&state)==0)
                    //     cout<<"Yes"<<endl;
                    // else cout<<"No"<<endl;
                    state=(1<<high)-(1<<low+1);
                    int s1=0,s2=0;
                    if(l>1) s1=query_state(1,l-1,1,1,n);
                    if(r<n) s2=query_state(r+1,n,1,1,n);
                    if((s1&state)==0&&(s2&state)==0)
                        cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }

                
            }
            else cout<<"No"<<endl;
        }
    }   
}

int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(nullptr);
	cout.tie(0);
	int t=1;
	while(t--) solve();
}
