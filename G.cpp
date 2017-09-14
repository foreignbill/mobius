#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;
typedef long long ll;
int a,b,c,d,k;
bool p[maxn];
int prime[maxn],top;
int mu[maxn];
int summu[maxn];
template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
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
	summu[0]=0;
	for(int i=1;i<maxn;i++)
		summu[i]=summu[i-1]+mu[i];
}

ll solve(int b,int d,int k){
	b/=k;d/=k;
	if(b>d) swap(b,d);
	ll res=0;
	int la=0;
	for(int i=1;i<=b;i=la+1){
		la=min(b/(b/i),d/(d/i));
		res += (ll)(summu[la]-summu[i-1])*(b/i)*(d/i);
	}
	return res;
} 

int main(){
	int T;
	init();
	read(T);
	for(int cnt=1;cnt<=T;cnt++){
		read(a,b,c);read(d,k);
		if(!k){
			puts("0");
			continue;
		}
		ll res=0;
		res = solve(b,d,k)-solve(a-1,d,k)-solve(b,c-1,k)+solve(a-1,c-1,k);
		printf("%lld\n",res);
	}
	return 0;
} 
