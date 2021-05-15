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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 52
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
string s;
int cnt[12];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		int n = s.size();
		memset(cnt, 0, sizeof(cnt));
		int idx=-1, num = -1;
		for (int i = 0; i < n; ++i) {
			int lb = (i == 0? 1 : 0);
			for (int j = lb; j < s[i]-'0'; ++j) {
				int cnt2[12];
				for (int j2 = 0; j2 < 10; ++j2) {
					cnt2[j2] = cnt[j2];
				}
				cnt2[j]++;
				int rem = n-1-i;
				bool ok = true;
				for (int j2 = 0; j2 <= 9; ++j2) {
					if (cnt2[j2]%2) {
						if (rem <= 0) {
							ok=false;
							break;
						}
						cnt2[j2]++;
						rem--;
					}
				}
				if (ok && rem % 2==0) {
					idx = i;
					num = j;
				}
			}
			cnt[s[i]-'0']++;
		}
		if (idx >= 0) {
		//	cout<<"ok1"<<endl;
			memset(cnt, 0, sizeof(cnt));
			string ans = "";
		//	cout<<"idx="<<idx<<" "<<num<<endl;
			for (int i = 0; i < idx; ++i) {
				ans.push_back(s[i]);
				cnt[s[i]-'0']++;
			}
			ans.push_back(num+'0');
			cnt[num]++;
			int rem = n-1-idx;
			vector<int> ds;
			ds.clear();
			for (int i = 0; i <= 9; ++i) {
				if (cnt[i] % 2) {
					cnt[i]++;
					rem--;
					ds.push_back(i);
				}
			}
			for (int i = 1; i <= rem; ++i) {
				ds.push_back(9);
			}
			sort(ds.begin(), ds.end());
			for (int i = ds.size()-1; i >= 0; --i) {
				ans.push_back(ds[i]+'0');
			}
			cout<<ans<<endl;
		} else {
		//	cout<<"ok2"<<endl;
			n -= 2;
			string ans = "";
			for (int i = 1; i <= n; ++i) {
				ans.push_back('9');
			}
			cout<<ans<<endl;
		}
	}
  return 0;
}
