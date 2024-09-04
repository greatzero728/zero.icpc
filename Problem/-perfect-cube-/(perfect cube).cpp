#include<bits/stdc++.h>

using namespace std;

bool isPerfectCube(long long x) {
	long long y = cbrt(x);
	for(int i = 2; i--; ) if(y * y * y == x) {
		return true;
	}
	return false;
}

int main() {
	
	cout<<isPerfectCube(27)<<endl;
	return 0;
}
