#include <iostream>
#include <vector>
using namespace std;

int quicksort(vector<int>& arr, int left, int right)
{
	int index = arr[left];
	while (left < right)
	{
		/*rightֵ����index��ָ������*/
		while (left < right && arr[right] >= index)
		{
			right--;
		}
		arr[left] = arr[right];/*rightС��index���ƶ���index���*/
		while (left < right && arr[left] <= index)
		{
			left++;
		}
		arr[right] = arr[left];/*left����index���Ƶ�index�ұ�*/
	}
	arr[left] = index;
	return left;
}

void recursion(vector<int>& arr, int left, int right)
{
	if (left > right)
	{
		return;//������������
	}
	int index = quicksort(arr, left, right);
	quicksort(arr, left, index - 1);
	quicksort(arr, index + 1, right);
}

int main()
{
	vector<int> a{ 1,-1,3,-4,5,-6,7,-10,12 ,15,67};
	recursion(a, 0, a.size() - 1);
	for (auto& x: a)
	{
		cout << x << endl;
	}
	return 0;
}