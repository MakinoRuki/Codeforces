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
#define N 300
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
int getres(int cnt) {
	int pw=0;
	while((1<<pw) < cnt) {
		pw++;
	}
	return pw;
}
int main() {
	cin>>n;
	int ans=0;
	int ans2=1;
	vector<pair<int,int>> ps;
	ps.clear();
	for (int i = 2; i * i <= n; ++i) {
		if (n%i==0) {
			int cnt=0;
			while(n%i==0) {
				cnt++;
				n /= i;
			}
			ans2*=i;
			ps.push_back(make_pair(getres(cnt),cnt));
		}
	}
	if (n>1) {
		ans2*=n;
		ps.push_back(make_pair(0, 1));
	}
	sort(ps.begin(), ps.end());
	if (ps.empty()) {
		cout<<ans2<<" "<<0<<endl;
	} else {
		bool found=false;
		for (int i = 0; i < ps.size(); ++i) {
			int pw = ps[i].first;
			if ((1<<pw) != ps[i].second) {
				found=true;
				break;
			}
		}
		if (!found) {
			ans += ps.back().first;
			if (ps.back().first != ps[0].first) {
				ans++;
			}
		} else {
			ans += ps.back().first+1;
		}
		cout<<ans2<<" "<<ans<<endl;
	}
	return 0;
}
