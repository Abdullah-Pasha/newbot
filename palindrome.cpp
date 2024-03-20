#include<iostream>
using namespace std;
bool is_palindromic(int num)
{
	int get.reverse;
	int reverse=get.reverse(num)
	if (num==reverse)
	return true;
	else 
	return false;
}
int get.reverse(int num)
{
	int r=0;
	int R=0;
	while(num>0)
	{
		R=num%10;
		r=(r*10)+R;
		num=num/10;
	}
	return r;
}
int main()
{
	int n,num,reverse;
	cout<<"Enter a number";
	cin>>num;
	if(reverse==num)
	{
		cout<<"palindrome";
	}
	else
	cout<<"not a palindrome";
	return 0;
}
