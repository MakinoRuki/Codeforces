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
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		int k;
		for (k=2; k<=31; ++k) {
			if (n%((1<<k)-1)==0) {
				break;
			}
		}
		int x = n/((1<<k)-1);
		cout<<x<<endl;
	}
	return 0;
}
