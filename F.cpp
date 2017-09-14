#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;
typedef long long ll;
int n,m;
bool p[maxn];
int prime[maxn],top;
int mu[maxn];
ll phi[maxn];

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
}

int main(){
	int T;
	init();
	for(;~scanf("%d%d",&n,&m);){
		if(n>m) swap(n,m);
		ll res = 0;
		for(int i=1;i<=n;i++)
			res += (ll)phi[i]*(n/i)*(m/i);
		res += res;
		res -= (ll)n*m;
		cout<<res<<endl;
	}
	return 0;
} 
