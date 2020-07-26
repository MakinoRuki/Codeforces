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
#define N 105
#define M 20010
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int T, n;
string s;
int main() {
	cin>>T;
	string t = "abacaba";
	for (int cas=1; cas<=T; ++cas) {
		cin>>n>>s;
		string ans="";
		for (int i = 0; i+7 <= n; ++i) {
			int j;
			for (j = 0; j < 7; ++j) {
				if (t[j] == s[i+j]) continue;
				if (s[i+j] == '?') continue;
				break;
			}
			if (j >= 7) {
				string tmp = s;
				for (int k = 0; k < 7; ++k) {
					tmp[i+k] = t[k];
				}
				for (int k = 0; k < n; ++k) {
					if (tmp[k] == '?') tmp[k] = 'z';
				}
			//	if (i==0) cout<<"tmp="<<tmp<<endl;
				int cnt=0;
				for (int k =0; k +7 <= n; ++k) {
					if (tmp.substr(k, 7) == t) {
						cnt++;
					}
				}
				if (cnt==1) {
					ans = tmp;
					break;
				}
			}
		}
		if (ans.empty()) cout<<"No"<<endl;
		else {
			cout<<"Yes"<<endl;
			cout<<ans<<endl;
		}
	}
  return 0;
}
