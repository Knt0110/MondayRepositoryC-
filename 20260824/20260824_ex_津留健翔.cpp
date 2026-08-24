#include <iostream>
using namespace std;

int main(void)
{
	//”z—ñ
	int ary[5];
	int* pAry;

	//pAry‚Í”z—ñ‚Ìæ“ª‚ğw‚·
	pAry = ary;
	/*for (int i = 0; i < 5; i++)
	{
		cout << "&ary[" << i <<  "] : " << & ary[i] << endl;
		cout << "pAry : " << pAry + i << endl;
	}*/

	for (int i = 0; i < 5; i++)
	{
		cout << "pAry : " << *(pAry + i) << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		cin >> *(pAry + i);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "pAry : " << *(pAry + i) << endl;
	}

	return 0;
};