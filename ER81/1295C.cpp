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
#define N 200005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int T;
string s,t;
int main() {
	cin>>T;
	for (int cas=1; cas<=T; ++cas) {
		cin>>s>>t;
		map<int, set<int>> pos;
		pos.clear();
		for (int i = 0; i < s.size(); ++i) {
			pos[s[i]-'a'].insert(i);
		}
		int pre=-1;
		bool ok = true;
		for (int i = 0; i < t.size(); ++i) {
			if (pos.find(t[i]-'a') == pos.end()) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout<<-1<<endl;
		} else {
			int ans=1;
			for (int i = 0; i < t.size(); ++i) {
				auto itr = pos[t[i]-'a'].upper_bound(pre);
				if (itr == pos[t[i]-'a'].end()) {
					ans++;
					pre = -1;
				}
				itr = pos[t[i]-'a'].upper_bound(pre);
				pre = *itr;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
