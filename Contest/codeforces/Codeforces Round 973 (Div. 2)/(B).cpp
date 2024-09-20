#include<bits/stdc++.h>

using namespace std;

const int NN = 202020;

int a[NN];

int main() {
    
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        
        long long sum = 0;
        for(int i = 1; i <= n; i++) {
            if(i == n - 1) sum -= a[i];
            else sum += a[i];
        }
        cout<<sum<<endl;
    }
}