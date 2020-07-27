#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 10005
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll l, r;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld%lld",&n,&l,&r);
		ll x = 0LL;
		int i;
		for (i= n-1; i >= 1; --i) {
			if (x + 2LL*i>=l) {
				break;
			}
			x += 2LL*i;
		}
		if (i < 1) {
			cout<<1<<endl;
			continue;
		}
		vector<int> ans;
		ans.clear();
	//	cout<<"x="<<x<<" "<<i<<endl;
		// if (i == n-1) {
		// 	ll det=l-x;
		// 	if (det%2==0) {
		// 		ans.push_back(det/2+1);
		// 		l++;
		// 	}
		// 	det /= 2;
		// 	for (int j = det+1; j<=n-1; ++j) {
		// 		if (l > r) break;
		// 		ans.push_back(1);
		// 		l++;
		// 		if (l>r) break;
		// 		ans.push_back(j+1);
		// 		l++;
		// 	}
		// } else {
		// 	ll det=l-x;
		// 	if (det%2==0) {
		// 		ans.push_back(n);
		// 		l++;
		// 	}
		// 	det/=2;
		// 	int s = n-i;
		// 	for (int j = det+1; j<=i; ++j) {
		// 		if (l>r) break;
		// 		ans.push_back(s+j-1);
		// 		l++;
		// 		if (l>r) break;
		// 		ans.push_back(n);
		// 		l++;
		// 	}
		// }
		int s = n-i;
		ll det=l-x;
		if (det%2==0) {
			ans.push_back(det/2+s);
			l++;
		}
		det/=2;
		for (int j = det+1; j <= i; ++j) {
			if (l>r) break;
			ans.push_back(s);
			l++;
			if (l>r) break;
			ans.push_back(s+j);
			l++;
		}
		int j=i-1;
		while(l <= r && j>=1) {
			if (l > r) break;
			int s = n-j;
			for (int k = 1; k <= j; ++k) {
				if (l>r)break;
				ans.push_back(s);
				l++;
				if (l > r) break;
				ans.push_back(s+k);
				l++;
			}
			j--;
		}
		if (l <= r) {
			ans.push_back(1);
		}
		for (int i = 0; i <ans.size(); ++i) {
			printf("%d", ans[i]);
			if (i < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
