#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define N 200020
using namespace std;
typedef long long ll;
int t, n,m;
int a[N], p[N], s[N];
int main() {
	cin>>t;
	for (int cas=1;cas <= t; ++cas) {
		cin>>n;
		for (int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		cin>>m;
		for (int i = 0; i < m; ++i) {
			cin>>p[i]>>s[i];
		}
		map<int, int> sp;
		sp.clear();
		for (int i = 0; i < m; ++i) {
			sp[s[i]] = max(sp[s[i]], p[i]);
		}
		auto itr = sp.end();
		itr--;
		while(itr != sp.begin()) {
			itr--;
			auto itr2 = itr;
			itr2++;
			itr->second = max(itr->second, itr2->second);
		}
		int tot=1;
		int cnt=0;
		int maxv = 0;
		int i = 0;
		while(i < n) {
			//cout<<"i="<<i<<endl;
			cnt++;
			maxv = max(maxv, a[i]);
			auto itr = sp.lower_bound(cnt);
			if (itr != sp.end() && itr->second >= maxv) {
				i++;
				continue;
			} else {
				tot++;
				cnt=1;
				maxv = a[i];
				itr = sp.lower_bound(cnt);
				//cout<<"tot="<<tot<<endl;
				if (itr != sp.end() && itr->second >= maxv) {
					i++;
					continue;
				} else {
					break;
				}
			}
		}
		if (i < n) {
			cout<<-1<<endl;
		} else {
			cout<<tot<<endl;
		}
	}
	return 0;
}
