#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 300005
using namespace std;
typedef long long ll;
int n;
ll h;
int a[N];
int main() {
	cin>>n>>h;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	for (int i = n - 1; i >= 0; --i) {
		vector<int> b;
		b.clear();
		for (int j = 0; j <= i; ++j) {
			b.push_back(a[j]);
		}
		sort(b.begin(), b.end());
		ll tot = 0;
		for (int j = b.size() - 1; j >= 0; j-=2) {
			tot += b[j];
			if (tot > h) break;
		}
		if (tot > h) continue;
		cout<<i+1<<endl;
		break;
	}
	return 0;
}
