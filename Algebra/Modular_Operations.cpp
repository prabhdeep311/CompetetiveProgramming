//
//  Modular_Operations.cpp
//  Inverse : O(log m)
//
//  Created by Prabhdeep Singh Walia on 15/03/15.
//  Copyright (c) 2015 Prabhdeep Singh Walia. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <list>
#include <fstream>
#include <set>
using namespace std;

#define REP(i,n) for (int i = 1; i <= n; i++)
#define in(i) scanf("%d",&i)
#define out(i) printf("%d\n",i)
#define pii pair<int, int>

typedef long long ll;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

int MOD;

//functions for modular operations
ll M(ll x,ll y)
{
    return (x*y)%MOD;
}
ll A(ll x,ll y)
{
    return (x+y)%MOD;
}
ll mod_pow(ll b,ll e)
{
    if(e==0)    {return 1;}
    else if(e%2==0) {return mod_pow(M(b,b),e/2);}
    else    {return M(b,mod_pow(b,e-1));}
}
ll inv(ll x)
{
    return mod_pow(x,MOD-2);    //using fermat's little theorem x^(p-1)=1 mod p (p is prime)
}
ll D(ll x,ll y)
{
    return M(x,inv(y));
}
 
int main(int argc, const char * argv[])
{
    int a;  //need gcd(a, MOD) = 1
    cin>>a>>MOD;
    cout<<inv(a);
    return 0;
}


