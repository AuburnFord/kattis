#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2000001;

// semiclosed form for cardinality of powerset of multiset = *= (m+1) // m = multiplicity of num_i

ll all_factors[MAX];
ll prime_factors[MAX];

void fastint(int& num) {
    char c = getchar();
    num = 0;
    for(; c>47&&c<58; c=getchar()) num = num*10+c-48;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < MAX; i++) all_factors[i] = 1;
    for(int i = 0; i < MAX; i++) prime_factors[i] = 0;

    for(ll n = 2; n < MAX; n++) {
        if(!prime_factors[n]) { 
            for(ll i = n+n; i < MAX; i+=n) {
                prime_factors[i]+=1;
                ll count = 0;
                ll num = i;
                while(num%n==0) {
                    num/=n;
                    count++;    
                }
                all_factors[i] *= (1+count);
            }
        }
        
    }
    
    int cases, query;
    fastint(cases);
    while(cases--) {
        fastint(query);
        cout << all_factors[query] - prime_factors[query] << "\n"; 
    }
    return 0;
}
