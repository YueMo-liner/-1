#include<stdio.h>
#include<math.h>

long long mod_pow(long long base,long long exponent,long long modification);



long long mod_pow(long long base,long long exponent,long long modification)
{
	long long result;
	
	base%=modification;
	result=1;
	while(exponent!=0)
	{
		if(exponent%2!=0)
			{
				result=(result*base)%modification;		
			}
	base=(base*base)%modification;		
	exponent/=2;
	}
	
	return result;
}
