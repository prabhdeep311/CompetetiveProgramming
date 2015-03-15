//
//  Binary_Exponentiation.cpp
//  O(log(n))
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
const ll MOD = 1000000007;
const int maxn=1e+5;
typedef vector<vector<ll> > matrix;

int bin_pow(int a, int n)
{
    if(n == 0)    return 1;
    if(n%2 == 1)
    {
        return a*bin_pow(a, n-1);
    }
    else
    {
        int ret = bin_pow(a, n/2);
        return ret*ret;
    }
}

int main(int argc, const char * argv[])
{
    int a, n;
    cin>>a>>n;
    cout<<bin_pow(a, n)<<"\n";
    return 0;
}

