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
#include <cmath>
#define N 5002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m,k;
vector<string> seats;
int main() {
	cin>>n>>m>>k;
	seats.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		seats.push_back(s);
	}
	ll ans=0LL;
	if (k==1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (seats[i][j]=='.') {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	if (n==1 && m==1) {
		cout<<0<<endl;
		return 0;
	}
	if (m>1) {
		for (int i = 0; i < n; ++i) {
			int cnt=0;
			for (int j = 0; j < m; ++j) {
				if (seats[i][j]=='.') {
					cnt++;
				} else {
					if (cnt>=k) {
						ans += cnt-k+1;
					}
					cnt=0;
				}
			}
			if (cnt && cnt>=k) {
				ans += cnt-k+1;
			}
		}
	}
	if (n>1) {
		for (int j = 0; j < m; ++j) {
			int cnt=0;
			for (int i = 0; i < n; ++i) {
				if (seats[i][j]=='.') {
					cnt++;
				} else {
					if (cnt>=k) {
						ans += cnt-k+1;
					}
					cnt=0;
				}
			}
			if (cnt && cnt>=k) {
				ans += cnt-k+1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
