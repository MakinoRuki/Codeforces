#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int x[N], y[N];
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>x[i]>>y[i];
	}
	if (n % 2) {
		cout<<"NO"<<endl;
	} else {
		int X = x[0]+x[n/2];
		int Y = y[0]+y[n/2];
		int i;
		for (i = 0; i < n/2; ++i) {
			if ((x[i]+x[i+n/2] != X) || (y[i]+y[i+n/2] != Y)) {
				break;
			}
		}
		if (i >= n/2) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
