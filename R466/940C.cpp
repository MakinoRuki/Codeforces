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
#define M 20005
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
string s;
int cnt[27];
int main() {
	cin>>n>>k;
	cin>>s;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		cnt[s[i]-'a']++;
	}
	if (k>n) {
		string t=s;
		int i;
		for (i=0;i < 26; ++i) {
			if (cnt[i]) {
				break;
			}
		}
		for (int j = 0; j < k-n; ++j) {
			t.push_back('a'+i);
		}
		cout<<t<<endl;
	} else {
		int i;
		string t=s.substr(0, k);
		for (i = t.size()-1; i >= 0; --i) {
			int j;
			for (j=0; j < 26; ++j) {
				if (j>t[i]-'a' && cnt[j]) {
					break;
				}
			}
			if (j<26) {
				t[i]=j+'a';
				int j2;
				for (j2=0; j2<26; ++j2) {
					if (cnt[j2]) {
						break;
					}
				}
				for (int i2=i+1; i2<t.size(); ++i2) {
					t[i2] = j2+'a';
				}
				break;
			}
		}
		cout<<t<<endl;
	}
	return 0;
}
