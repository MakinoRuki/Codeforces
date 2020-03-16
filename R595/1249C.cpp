#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int q;
ll n;
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		vector<int> ds;
		ds.clear();
		ll m = n;
		while(m) {
			ds.push_back(m%3);
			m /= 3;
		}
		int idx=-1;
		for (int i = 0; i < ds.size(); ++i) {
			if (ds[i] == 2) idx=i;
		}
		if (idx == -1) {
			cout<<n<<endl;
		} else {
			int j=idx+1;
			for (; j < ds.size(); ++j) {
				if (ds[j] == 0) break;
			}
			if (j >= ds.size()) ds.push_back(1);
			else ds[j] = 1;
			for (int k = j-1; k >= 0; --k) {
				ds[k] = 0;
			}
			ll pw = 1LL;
			ll res = 0;
			for (int i = 0; i < ds.size(); ++i) {
				if (ds[i]) res += pw;
				pw *= 3;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}
