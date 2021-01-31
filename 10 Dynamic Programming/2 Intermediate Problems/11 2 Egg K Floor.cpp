#include<bits/stdc++.h>
using namespace std;
int MinimumTrial(int k)
{
	return ceil((-1.0 + sqrt(1 + 8*k))/2.0);// say x is the minimum Number of Trials
}                                          //  2 Cases : 1st Egg breaks the we have (x-1) + 1 = x trials for second Egg 
signed main()                             //             1st Egg doesn't break we wil do the Same thing for higher Floors so we have (x-1) trials
{                                        //    x + (x-1) + (x-2) + ... + 2 + 1 = x * (x + 1) / 2 = k  => x^2 + x - 2*k = 0  =>   x = ceil((-1.0 + sqrt(1 + 8*k))/2.0)
	int Floor = 100;
	
	cout<< MinimumTrial(Floor) <<endl;
    
	return 0;
}

