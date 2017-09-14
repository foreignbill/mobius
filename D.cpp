#include <bits/stdc++.h>

using namespace std;
const int maxn = 300005;
const int mod = 1e9+7; 
typedef long long ll;
bool p[maxn];
int prime[maxn],top;
int mu[maxn];
int a[maxn];
ll fac[maxn];
ll inv[maxn];
ll ans[maxn];

ll power(ll a,ll n){
	if(!n) return 1ll;
	ll ret=power(a,n/2);
	ret=ret*ret%mod;
	if(n&1) return ret*a%mod;
	return ret;
}

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
	fac[0]=inv[0]=1;
	for(int i=1;i<maxn;i++){
		fac[i]=fac[i-1]*i%mod;
	} 
	inv[maxn-1]=power(fac[maxn-1],mod-2);
	for(int i=maxn-1;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
}

ll C(ll n,ll m){
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main(){
	int T,n,m,k,x;
	init();
	while(~scanf("%d%d%d",&n,&m,&k)){
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			a[x]++;
		}
		for(int i=m;i>=1;i--){
			ll tot=0;
			for(int j=i;j<=m;j+=i)
				tot+=a[j];
			if(n-tot>k){
				ans[i]=0;
				continue;
			}
			ans[i]=power(m/i,tot-n)*power(m/i-1,k-(n-tot))%mod;
			ans[i]=ans[i]*C(tot,k-(n-tot))%mod;
			for(int j=i+i;j<=m;j+=i)
				ans[i]=(ans[i]-ans[j])%mod;
			ans[i]=(ans[i]+mod)%mod;
		}
		for(int i=1;i<=m;i++)
			printf("%I64d%c",ans[i]," \n"[i==m]);
	}
	return 0;
} 
