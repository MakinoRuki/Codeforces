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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		cin>>s;
		if (n%k != 0) {
			puts("-1");
		} else {
			int cnt[26];
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n; ++i) {
				cnt[s[i]-'a']++;
			}
			int i;
			for (i = 0; i < 26; ++i) {
				if (cnt[i] % k) {
					break;
				}
			}
			if (i >= 26) {
				cout<<s<<endl;
				continue;
			}
			bool found=false;
			for (int i = n-1; i >= 0; --i) {
				for (int j = s[i]-'a'+1; j < 26; ++j) {
					cnt[s[i]-'a']--;
					cnt[j]++;
					int tot=0;
					for (int j2 = 0; j2 < 26; ++j2) {
						if (cnt[j2]%k) tot += k-cnt[j2]%k;
					}
					if (tot <= n-1-i && (n-1-i-tot) % k == 0) {
						s[i] = 'a'+j;
						s = s.substr(0, i+1);
						vector<int> cs;
						cs.clear();
						for (int j2 = 0; j2 < 26; ++j2) {
							if (cnt[j2]%k) {
								for (int j3 = 1; j3 <= k-cnt[j2]%k; ++j3) {
									cs.push_back(j2);
								}
							}
						}
						while(cs.size() < n-1-i) {
							cs.push_back(0);
						}
						sort(cs.begin(), cs.end());
						for (auto c : cs) {
							s.push_back(c + 'a');
						}
						cout<<s<<endl;
						found=true;
						break;
					} else {
						cnt[j]--;
						cnt[s[i]-'a']++;
					}
				}
				if (found) break;
				cnt[s[i]-'a']--;
			}
			//cout<<s<<endl;
		}
	}
  return 0;
}
