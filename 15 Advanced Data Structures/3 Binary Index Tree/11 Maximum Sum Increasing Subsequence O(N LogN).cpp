#include <bits/stdc++.h>
using namespace std;

int getSum(int BITree[] , int index)
{
	int sum = 0;

	while (index > 0)
	{
		sum = max(sum , BITree[index]);
	
		index -= index & (-index);
	}
	
	return sum;
}

void updateBIT(int BITree[] , int newIndex , int index , int val)
{
	while (index <= newIndex)
	{
		BITree[index] = max(val , BITree[index]);
	
		index += index & (-index);
	}
}

int maxSumIS(int arr[] , int n)
{
	int newindex = 0 , max_sum;

	map<int, int> uniqueArr;

	for (int i = 0 ; i < n ; i++)
	uniqueArr[arr[i]] = 0;
	
	for (map<int, int>::iterator it = uniqueArr.begin() ; it != uniqueArr.end() ; it++)
	{
		newindex++;

		uniqueArr[it->first] = newindex;
	}
	
	int* BITree = new int[newindex + 1];

	for (int i = 0 ; i <= newindex ; i++)
	BITree[i] = 0;

	for (int i = 0 ; i < n ; i++)
	{
		max_sum = getSum(BITree , uniqueArr[arr[i]] - 1);

		updateBIT(BITree , newindex , uniqueArr[arr[i]] , max_sum + arr[i]);
	}

	return getSum(BITree , newindex);
}

int main()
{
	int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Maximum sum is = " << maxSumIS(arr , n) << endl;

	return 0;
}

