#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int r, c;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int main() {
	cin>>r>>c;
	if (r == 1 && c == 1) cout<<0<<endl;
	else if (r == 1 || c == 1) {
		if (r == 1) {
			for (int i = 1; i <= c; ++i) {
				cout<<i+1;
				if (i == c) cout<<endl;
				else cout<<" ";
			}
		} else if (c == 1) {
			for (int i = 1; i <= r; ++i) {
				cout<<i+1<<endl;
			}
		}
	} else {
    // 直接构造。1->r+c的lcm。
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				cout<<lcm(i, j + r);
				if (j < c) cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
