#include<bits/stdc++.h>
using namespace std;
struct suf
{
    int ind;
    int rank[2];
};
static bool comp(suf s1 , suf s2)
{
    if(s1.rank[0] == s2.rank[0])
    return (s1.rank[1] < s2.rank[1]);

    return (s1.rank[0] < s2.rank[0]);
}
void countsort(suf a[] , int n , int r)
{   
    int C[n+1];  memset(C , 0 , sizeof(C));

    for(int i = 0 ; i < n ; i++)
    C[a[i].rank[r]]++;

    for(int i = 1 ; i < n+1 ; i++)
    C[i] += C[i-1];

    suf b[n];

    for(int i = n-1 ; i >= 0 ; i--)
    {
        b[C[a[i].rank[r]] - 1] = a[i];

        C[a[i].rank[r]]--;
    }

    for(int i = 0 ; i < n ; i++)
    a[i] = b[i];
}
void radixsort(suf a[] , int n)
{
    countsort(a , n , 1);
    countsort(a , n , 0);
}
int* Construct(string &s , int n)
{
    suf Arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        Arr[i].ind = i;

        Arr[i].rank[0] = s[i] - 'a';

        Arr[i].rank[1] = ((i == n-1) ? -1 : s[i+1] - 'a');
    }

    sort(Arr , Arr + n , comp);

    int ind[n];

    for(int k = 4 ; k < 2 * n ; k *= 2)
    {
        int rank = 1 , rank0 = Arr[0].rank[0] , rank1 = Arr[0].rank[1];

        Arr[0].rank[0] = rank;

        ind[Arr[0].ind] = 0;

        for(int i= 1 ; i < n ; i++)
        {
            if(Arr[i].rank[0] != rank0 || Arr[i].rank[1] != rank1)  rank++;

            rank0 = Arr[i].rank[0] , rank1 = Arr[i].rank[1];

            Arr[i].rank[0] = rank;

            ind[Arr[i].ind] = i;
        }

        for(int i = 0 ; i < n ; i++)
        {
            int next = Arr[i].ind + k/2;

            Arr[i].rank[1] = ((next < n) ? Arr[ind[next]].rank[0] : 0);
        }

        radixsort(Arr , n);		
    }

    int* suffarr = new int[n];

    for(int i = 0 ; i < n ; i++)
    suffarr[i] = Arr[i].ind;

    return suffarr;
}
int* Kasai(string &s , int n , int* suffarr)
{
    int* LCP = new int[n];

    memset(LCP , 0 , sizeof(int) * n);

    int ind[n];

    int k = 0;

    for(int i = 0 ; i < n ; i++)
    ind[suffarr[i]] = i;

    for(int i = 0 ; i < n ; i++)
    {
        if(ind[i] == n-1)
        {
            k = 0;

            continue;
        }

        int j = suffarr[ind[i] + 1];

        while(i + k < n && j + k < n && s[i+k] == s[j+k])
        k++;

        LCP[ind[i]] = k;

        if(k > 0)  k--;
    }

    return LCP;
}
signed main()
{
	string s = "banana";
	int n = s.length();
	
	int* suffarr = Construct(s , n);
	
	int* LCP = Kasai(s , n , suffarr);
	
	cout << "Suffix Array : ";
	
	for(int i = 0 ; i < n ; i++)
	cout << suffarr[i] << " ";
	cout << endl;
	
	cout << "LCP Array : ";
	
	for(int i = 0 ; i < n ; i++)
	cout << LCP[i] << " ";
	cout << endl;
	
	return 0;
}
