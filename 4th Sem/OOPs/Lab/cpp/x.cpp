#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cstdint>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    intmax_t a,b,c,ans;
    cin>>a>>b>>c;
    //unsigned long long int ans;
    ans=((int)(0.5*c*a))%1000000007;
    ans+=((int)(0.5*c*b))%1000000007;
    cout<<ans%1000000007;
    return 0;
}