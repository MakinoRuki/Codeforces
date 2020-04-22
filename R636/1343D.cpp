#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n, k;
int a[N];
int BIT[2*N];
int cnt[2*N];
int lowbit(int x) {
	return x&-x;
}
void update(int x,int y) {
	for (int i=x;i<=2*k;i+=lowbit(i))
		BIT[i]+=y;
}
int query(int x) {
	int ans=0;
	for (int i=x;i>0;i-=lowbit(i))
		ans+=BIT[i];
	return ans;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>k;
		for (int i = 1; i <= 2*k; ++i) {
			cnt[i]=0;
			BIT[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n/2; ++i) {
			cnt[a[i]+a[n-i+1]]++;
			int l1 = min(a[i], a[n-i+1])+1;
			int r1 = a[i]+a[n-i+1]-1;
			int r2 = max(a[i], a[n-i+1])+k;
			int l2 = a[i]+a[n-i+1]+1;
			update(l1,1);
			update(r1+1, -1);
			update(l2,1);
			update(r2+1, -1);
		}
	//	cout<<query(2)<<" "<<query(4)<<endl;
		int ans = n;
		for (int i = 2; i <= 2*k; ++i) {
			int res=cnt[i];
			int res2 = query(i);
			ans = min(ans, res2+(n/2-res-res2)*2);
			//cout<<i<<" "<<res2+(n/2-res-res2)*2<<" "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
