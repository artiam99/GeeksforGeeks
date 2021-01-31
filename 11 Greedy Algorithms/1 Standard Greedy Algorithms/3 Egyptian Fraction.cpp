#include <bits/stdc++.h>
using namespace std;
void Egyptian_Fraction(int nr,int dr)
{
	if(dr == 0 || nr == 0) return;
	
	if(dr % nr == 0)
	{
		cout<< " 1 / "<< dr/nr <<endl;
		
		return;
	}
	
	if(nr % dr == 0)
	{
		cout<< nr/dr <<endl;
		
		return;
	}
	
	if(nr > dr)
	{
		cout << nr/dr << " + ";
		
		Egyptian_Fraction(nr % dr , dr);
		
		return;
	}
	
	int new_dr = dr/nr + 1;
	
	cout<< "1 / "<< new_dr <<" + ";
	
	nr = nr * new_dr - dr;
	
	dr = dr * new_dr;
	
	for(int i = 2 ; i <= min(nr , dr)  ; i++)
	if(nr % i == 0 && dr % i == 0)
	{
		nr /= i;
		dr /= i;
	}
	
	Egyptian_Fraction(nr,dr);
}
int main()
{
	int nr = 6 , dr = 14;
	
	Egyptian_Fraction(nr,dr);

	return 0;
}
