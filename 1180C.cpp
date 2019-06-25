#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define N 300010
using namespace std;
typedef long long ll;
int n, q;
int a[N];
int ansa[N], ansb[N];
int main() {
	cin>>n>>q;
	deque<int> dq;
	dq.clear();
	int maxv = -1;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		dq.push_back(a[i]);
		maxv = max(maxv, a[i]);
	}
	int cnt=1;
	int b[N];
	while(true) {
		int v = dq.front();
		if (v == maxv) {
			for (int i = 0; i < n; ++i) {
				b[i] = dq.front();
				dq.pop_front();
			}
			break;
		}
		dq.pop_front();
		int v2 = dq.front();
		dq.pop_front();
		ansa[cnt] = v;
		ansb[cnt] = v2;
		dq.push_front(max(v, v2));
		dq.push_back(min(v, v2));
		cnt++;
	}
	cnt--;
	for (int i = 0; i < q; ++i) {
		ll qi;
		cin>>qi;
		if (qi <= cnt) {
			cout<<ansa[qi]<<" "<<ansb[qi]<<endl;
		} else {
			ll ri = (qi - cnt) % (n-1);
			ri = (ri - 1 + n-1)%(n-1);
			cout<<b[0]<<" "<<b[ri + 1]<<endl;
		}
	}
	return 0;
}
