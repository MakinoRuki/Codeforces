#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
int t, n;
int a[N];
ll m1[N], m2[N];
int main() {
	cin>>t;
	for (int cas=1;cas  <= t; ++cas) {
		cin>>n;
		ll tot=0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			tot += (ll)a[i];
		}
		ll sum = a[0];
		m1[0] = sum;
		for (int i = 1; i < n; ++i) {
			if (sum < 0) {
				sum = 0;
			}
			sum += (ll)a[i];
			m1[i] = max(m1[i-1], sum);
		}
		sum = a[n-1];
		m2[n-1] = sum;
		for (int i = n-2; i >= 0; --i) {
			if (sum < 0) {
				sum = 0;
			}
			sum += (ll)a[i];
			m2[i] = max(m2[i+1], sum);
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				if (m2[1] >= tot) {
					ok = false;
					break;
				}
			} else if (i == n-1) {
				if (m1[n-2] >= tot) {
					ok = false;
					break;
				}
			} else {
				if (m1[i-1] >= tot || m2[i+1] >= tot) {
					ok = false;
					break;
				}
			}
		}
		if (!ok) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
