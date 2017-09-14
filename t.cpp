#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int mod=1000000007;
const int maxn=10000005;
bool check[maxn];          //用于打表记录的中间量
LL sumPhi[maxn];           //前i个的欧拉函数和
int cnt,phi[maxn],prime[maxn];  //素数个数，欧拉表，素数表
//素数表是第几个素数是什么，欧拉表是i的欧拉是phi[i];
void init(int n){               //素数+欧拉表
    phi[1]=1;
    cnt=0;
    for(int i=2;i<=n;i++){
        if(!check[i]){
            phi[i]=i-1;
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>n)break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    sumPhi[0]=0;
    for(int i=1;i<=n;i++) sumPhi[i]=(sumPhi[i-1]+phi[i]);
}

int main(){
    int n;
    while(cin>>n){
        LL ans=0;
        init(n);
        for(int i=0;i<cnt;i++){
            ans+=sumPhi[n/prime[i]];
        }
        cout<<2*ans-cnt<<endl;
    }
    return 0;
}
