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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
string s;
int x;
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		scanf("%d", &x);
		int n = s.size();
		for (int i = 1; i <= n; ++i) {
			ans[i] = -1;
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (s[i-1] == '0') {
				if (i-x>=1) {
					if (ans[i-x] < 0) {
						ans[i-x] = 0;
					} else {
						if (ans[i-x] != 0) {
							ok=false;
							break;
						}
					}
				}
				if (i+x<=n) {
					if (ans[i+x] < 0) {
						ans[i+x] = 0;
					} else {
						if (ans[i+x] != 0) {
							ok=false;
							break;
						}
					}
				}
			} else {
				if (i-x<1 && i+x>n) {
					ok=false;
					break;
				} else if (i-x<1 && i+x<=n) {
					if (ans[i+x] == 0) {
						ok = false;
						break;
					}
				} else if (i-x>=1 && i+x>n) {
					if (ans[i-x] == 0) {
						ok = false;
						break;
					}
				} else {
					if (ans[i+x] == 0 && ans[i-x] == 0) {
						ok = false;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (ans[i] < 0) {
				ans[i] = 1;
			}
		}
		// for (int i = 1; i <= n; ++i) {
		// 	cout<<"i="<<i<<" "<<ans[i]<<endl;
		// }
		// cout<<"ok="<<ok<<endl;
		for (int i = 1; i <= n; ++i) {
		//	cout<<"i2="<<i<<endl;
			if (s[i-1] == '0') {
				if (i-x>=1 && ans[i-x]==1) {
					ok=false;
					break;
				}
				if (i+x<=n && ans[i+x] == 1) {
					ok = false;
					break;
				}
			} else {
			//	cout<<i-x<<" "<<ans[i-x]<<endl;
				if (i-x<1 && i+x>n) {
					ok=false;
					break;
				} else if (i-x>=1 && ans[i-x]==1) {
				//	cout<<"ok!!"<<endl;
					continue;
				} else if (i+x<=n && ans[i+x] == 1) {
					continue;
				} else {
					ok=false;
					break;
				}
			}
		//	cout<<"i2="<<i<<endl;
		}
		if (!ok) {
			cout<<-1<<endl;
		} else {
			string ans2 = "";
			for (int i = 1; i <= n; ++i) {
				ans2.push_back('0'+ans[i]);
			}
			cout<<ans2<<endl;
		}
	}
	return 0;
}
