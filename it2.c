//Time_O(log n)

#include <stdio.h>

int power(int x,int n)
{    
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n%2==0)
	{
            return power(x*x,n/2);
        }
        else
	{
            return x*power(x,n-1);
        }
    

}



int main()
{
	int x,n,r;
	printf("Enter X:\n");
	scanf("%d",&x);

	printf("Enter n\n");
	scanf("%d",&n);
 
     	r= power(x,n);
   	printf("Result: %d\n",r);
	return 0;
} 
