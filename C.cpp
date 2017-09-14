#include <bits/stdc++.h>

using namespace std;
const int maxn = 500005;
typedef long long ll;
int a,b,c,d,k;
bool p[maxn];
int prime[maxn],top;
int mu[maxn];
int num[maxn];
ll sum[maxn][20];

void init(){
	memset(p,0,sizeof p);
	memset(mu,0,sizeof mu);
	top=0;
	mu[1]=1;
	num[1]=0;
	for(int i=2;i<maxn;i++){
		if(!p[i]){
			prime[++top]=i;
			mu[i]=-1;
			num[i]=1;
		}
		for(int j=1;j<=top && i*prime[j]<maxn;j++){
			p[i*prime[j]]=1;
			num[i*prime[j]]=num[i]+1;
			if(i % prime[j] == 0){
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for(int i=1;i<maxn;i++)
		for(int j=i;j<maxn;j+=i){
			sum[j][num[i]]+=mu[j/i];
		}
	for(int i=0;i<maxn;i++)
		for(int j=1;j<19;j++)
			sum[i][j]+=sum[i][j-1];
	for(int i=1;i<maxn;i++)
		for(int j=0;j<19;j++)
			sum[i][j]+=sum[i-1][j];
}

int main(){
	int T,n,m,k;
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		k=min(k,18);
		if(n>m) swap(n,m);
		int la=1;
		ll res=0;
		for(int i=1;i<=n;i=la+1){
			la=min(n/(n/i),m/(m/i));
			res += (ll)(sum[la][k]-sum[i-1][k])*(n/i)*(m/i);
		}
		printf("%I64d\n",res);
	}
	return 0;
} 
