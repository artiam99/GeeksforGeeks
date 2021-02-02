#include<bits/stdc++.h>
using namespace std;

int Partition(int a[] , int l , int r , int x)
{
	for(int i = l; i < r ; i++) 
	if(a[i] == x) 
	{
		swap(a[i] , a[r]);
		
		break;
	}

	int k = l;
	
	for(int i = l ; i < r ; i++)
	if(a[i] <= x)
	{
		swap(a[i] , a[k]);
		
		k++;
	}
	
	swap(a[k] , a[r]);
	
	return k;
}

int Find_Median(int a[] , int n)
{
	sort(a , a + n);
	
	return a[n / 2];
}

int Kth_Smallest(int a[] , int l , int r , int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int n = r - l + 1;
		
		int i, median[(int)ceil(n / 5.0)];
		
		for (i = 0 ; i < n / 5 ; i++)                                 // ---                Dividing the Array int Groups of 5 elements and Finding the Median of each Group.
		median[i] = Find_Median(a + l + i * 5 , 5);                  //    |                
		                                                            //     |                Then Finding the Median of those Median that is Approximate Median.
		if(i * 5 < n)                                              //      |
		{                                                         //       | --- O(n)       So there are at least half of (n / 5) groups where there are 3 elements less than or
			median[i] = Find_Median(a + l + i * 5 , n % 5);      //        |                greater than medofmed i.e. 3 ( 1 / 2 * [n / 5] - 2) >= 3 n / 10 - 6
			                                                    //         |				-2 bcoz one is medofmed  another from last group of size less than 5
			i++;                                               //          |                 
		}                                                     //        ---                 So No of elements that are less than or greater than medofmed is
		                                                     //                             at most n - (3 n / 10 - 6) = 7 n / 10 + 6
		                                                     
		int medOfMed = (i == 1) ? median[i-1] : Kth_Smallest(median , 0 , i - 1 , i / 2);  // T(n / 5)   
                                                                                          //
		int p = Partition(a , l , r , medOfMed);  //  O(n)                                       T(n) = |  O(1)   , n <= 100
                                                                    					//              |  
		if (p - l + 1 == k)                                                            //               |  T(n / 5) + T(7 n / 10 + 6) + O(n)
		return a[p];                                                                  //                =  k * (n / 5) + k * (7 n / 10) + c n  .. Substitution
		                                                                             //                 =  k * (9 n / 10) + c n  <= k n       if  10 c <= k  
		if (p - l + 1 > k)
		return Kth_Smallest(a , l , p - 1 , k);                    //  at most T(7 n / 10 - 6)
                                                                                 
		return Kth_Smallest(a , p + 1 , r , k - (p - l + 1));     //  at most T(7 n / 10 - 6)
	}

	return INT_MAX;
}

int main()
{
	int a[] = {12, 3, 5, 7, 4, 19, 26};
	int n = sizeof(a)/sizeof(a[0]) , k = 3;
	 
	cout << "K'th smallest element is " << Kth_Smallest(a , 0 , n - 1 , k) << endl;
	
	return 0; 
} 

