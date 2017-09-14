#include <bits/stdc++.h>

using namespace std;
const int maxn = 10000005;
typedef long long ll;
int n;
bool p[maxn];
int prime[maxn],top;
int mu[maxn];
ll phi[maxn];
ll sumphi[maxn];

void init(){
	memset(p,0,sizeof p);
	top=0;
	phi[1]=1;
	for(int i=2;i<maxn;i++){
		if(!p[i]){
			prime[++top]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=top;j++){
			if(i*prime[j]>=maxn) break; 
			p[i*prime[j]]=1;
			if(i % prime[j] == 0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
	sumphi[0]=0;
	for(int i=1;i<maxn;i++)
		sumphi[i]=sumphi[i-1]+phi[i];
}

int main(){
	int T;
	init();
	for(;~scanf("%d",&n);){
		ll res = 0;
		for(int i=1;i<=top && prime[i]<=n;i++)
			res += sumphi[n/prime[i]];
		int k;
		for(int i=1;i<=top && prime[i]<=n;i++)
			k=i;
		res = res + res - k;
		printf("%lld\n",res);
	}
	return 0;
} 
