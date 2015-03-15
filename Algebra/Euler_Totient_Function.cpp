//
//  Euler_Totient_Function.cpp
//  O(sqrt(n))
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

//Calculate number of integers in range [1, n], coprime to n
int phi(int n)
{
    int result = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
                n/=i;
            result -= result/i;
        }
    }
    if(n > 1)
    {
        result -= result/n;
    }
    return result;
}

int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    cout<<phi(n)<<"\n";
    return 0;
}

