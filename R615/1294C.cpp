#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll n;
vector<pair<int, int>> ps;
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		cin>>n;
		vector<ll> ans;
		ans.clear();
		for (ll i = 2 ; i * i <= n; ++i) {
			if (n % i == 0) {
				ans.push_back(i);
				n /= i;
				break;
			}
		}
		if (ans.empty()) {
			cout<<"NO"<<endl;
			continue;
		}
		for (ll i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				if (i != n/i && i != ans.back() && n/i != ans.back()) {
					ans.push_back(i);
					ans.push_back(n/i);
					break;
				}
			}
		}
		if (ans.size() < 3) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
			cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
		}
	}
	return 0;
}
