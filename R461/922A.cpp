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
#include <queue>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
int x,y;
int main() {
	cin>>x>>y;
	if (y==0) {
		cout<<"No"<<endl;
	} else {
		int det=y-1;
		if (det==0) {
			if (x>0) {
				cout<<"No"<<endl;
				return 0;
			}
		}
		if (x<det) {
			cout<<"No"<<endl;
		} else {
			det = x-det;
			if (det%2) {
				cout<<"No"<<endl;
			} else {
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;
}
