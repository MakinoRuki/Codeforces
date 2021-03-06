#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 52
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
int t,n,k;
vector<string> sv;
int main() {
	cin>>n>>k;
	unordered_map<string, int> sm;
	sm.clear();
	sv.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		sm[s] = i;
		sv.push_back(s);
	}
	ll ans=0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			string tmp="";
			for (int p = 0; p < k; ++p) {
				if (sv[i][p] == sv[j][p]) {
					tmp.push_back(sv[i][p]);
				} else {
					if (sv[i][p] != 'S' && sv[j][p] != 'S') {
						tmp.push_back('S');
					} else if (sv[i][p] != 'T' && sv[j][p] != 'T') {
						tmp.push_back('T');
					} else {
						tmp.push_back('E');
					}
				}
			}
			if (sm.find(tmp) != sm.end() && sm[tmp] > i && sm[tmp] > j) {
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
