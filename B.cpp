#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;
typedef long long ll;
int a,b,c,d,k;
bool p[maxn];
int prime[maxn],top;
int mu[maxn];

void init(){
	memset(p,0,sizeof p);
	memset(mu,0,sizeof mu);
	top=0;
	mu[1]=1;
	for(int i=2;i<maxn;i++){
		if(!p[i]){
			prime[++top]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=top && i*prime[j]<maxn;j++){
			p[i*prime[j]]=1;
			if(i % prime[j] == 0){
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
}

int main(){
	int T;
	init();
	scanf("%d",&T);
	for(int cnt=1;cnt<=T;cnt++){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if(!k){
			printf("Case %d: ",cnt); 
			cout<<0<<endl;
			continue;
		}
		b/=k;d/=k;
		if(b>d) swap(b,d);
		ll res=0,res2=0; 
		for(int i=1;i<=b;i++)
			res += (ll)mu[i]*(b/i)*(d/i);
		for(int i=1;i<=b;i++)
			res2 += (ll)mu[i]*(b/i)*(b/i);
		res -= res2/2;
		printf("Case %d: ",cnt); 
		cout<<res<<endl;
	}
	return 0;
} 
