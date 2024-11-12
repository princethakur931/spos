#ifdef CALCULATIONDLL_EXPORTS
#define CALCULATION_API_decispec(dllexport)
#else
#define CALCULATION_API_decispec(dllimport)
#endif

class CALCULATION_API_CalculationApi
{
	public:
		void addition(int x, int y);
		void subtraction(int x, int y);
		void multiply(int x, int y);
};

#include "math.h"
#include<iostream>
using namespace std;

void CALCULATION_API_CalculationApi::addition(int x, int y)
{
	cout<<"Enter the numbers for Addition:"<<endl;
	cin>>x>>y;
	cout<<"Addition is "<<(x+y)<<endl;
};

void CALCULATION_API_CalculationApi::subtraction(int x, int y)
{
	cout<<"\n\nEnter the numbers for Subtraction :"<<endl;
	cin>>x>>y;
	cout<<"Subtractoin is "<<(x-y)<<endl;
};

void CALCULATION_API_CalculationApi::multiply(int x, int y)
{
	cout<<"\n\nEnter the numbers for multiplication:"<<endl;
	cin>>x>>y;
	cout<<"Multiplication is "<<(x*y)<<endl;
};

int main()
{
	int x, y;
	CALCULATION_API_CalculationApi cal;
	cal.addition(x,y);
	cal.subtraction(x,y);
	cal.multiply(x,y);
	return 0;
}
