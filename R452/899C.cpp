#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 60
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int main() {
	cin>>n;
	if (n%4==0 || n%4==3) {
		cout<<0<<endl;
	} else {
		cout<<1<<endl;
	}
	vector<int> v1,v2;
	v1.clear();
	v2.clear();
	bool f=false;
	int r=n%4;
	for (int i = n; i > r; i-=2) {
		if (i==1) {
			v1.push_back(i);
		} else {
			if (!f) {
				v1.push_back(i);
				v2.push_back(i-1);
			} else {
				v2.push_back(i);
				v1.push_back(i-1);
			}
		}
		f= !f;
	}
	if (r==1) {
		v1.push_back(1);
	} else if (r==2) {
		v1.push_back(1);
		v2.push_back(2);
	} else if (r==3) {
		v1.push_back(1);
		v1.push_back(2);
	}
	printf("%d", (int)v1.size());
	for (int i = 0; i < v1.size(); ++i) {
		printf(" %d", v1[i]);
	}
	cout<<endl;
	return 0;
}
