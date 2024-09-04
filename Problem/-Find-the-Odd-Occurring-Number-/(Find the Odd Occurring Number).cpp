#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using pii = pair<int, int>;

int findOdd(vector<int> arr) {
	map<int, int> num;
	for(int x : arr) num[x]++;
	for(pii p : num) if(p.y & 1) return p.x;
	return -1;
}

int main() {
	
	vector<int> vec = {7, 2, 2, 3, 3, 3, 4, 4, 4};
	cout<<findOdd(vec)<<endl;
	return 0;
}
