#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())
#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

int main() {
	freopen("in.in", "w", stdout);
	
	srand(time(0));
	int t = 1000;
	cout<<t<<endl;
	while(t--) {
		int n = 1000000;
		int k = rnd % n + 1;
		cout<<n<<' '<<k<<endl;
	}
	return 0;
}
