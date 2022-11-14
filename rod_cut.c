//     // *programing recursive
// #include<stdio.h>
// #include<limits.h>

// int cut_rod(int profit[],int n){
// //  int  max_rev=INT_MIN; //
//     if (n==0)
//     {
//         return 0;
//     }
    
//   int max_rev=profit[n];//last wale index ko max prifit man liya.
//     for (int i = 1; i <=n-1; i++)
//     {
//      int  rev_val=cut_rod(profit,n-i);
//      if (max_rev<(profit[i]+rev_val))  //yadi hum rev_val me recursive ko store na kare to hum do bar recursive call karna padega.
//      {
//         max_rev=profit[i]+rev_val;
//      }
     
//     }
    
//     return max_rev;
// }

// int main()
// {
// int n;
// printf("enter the size of rod");
// scanf("%d",&n);
// int profit[n+1]; // we start from index 
// for (int i = 1; i <=n; i++)
// {
// 	scanf("%d",&profit[i]);//1 to n tak ka profit
// }

//   printf("%d",cut_rod(profit,n));
//     return 0;
// }



// ****************by memoize(like recursive)****

// #include<stdio.h>
// #include<limits.h>

// int memo_cut_rec(int pro[],int n,int rev[]){
// if (rev[n]>=0)
// {
// 	return rev[n];
// }
// if (n==0)
// {
// 	rev[0]=0;
// 	return rev[0];
// }
// int max_rev=pro[n]; //last element of profit
// for (int i = 1; i <=n-1; i++)
// {
//  int rev_val=memo_cut_rec(pro,n-i,rev);
//  if (max_rev<(pro[i]+rev_val))
//  {
// 	max_rev=(pro[i]+rev_val);
//  }
 
// }
// rev[n]=max_rev;
// return rev[n];
// }


// int main()
// {
// int n;
// printf("enter the size of rod");
// scanf("%d",&n);
// int pro[n+1];
// for (int i = 1; i <=n; i++)
// {
// 	scanf("%d",&pro[i]);//1 to n tak ka profit
// }
// 	int rev[n+1]; //revenue array
// 	for (int  i = 1; i <=n; i++)
// 	{
// 		rev[i]=INT_MIN;
// 	}

// 	printf("%d",memo_cut_rec(pro,n,rev));

// 	return 0;
// }


// *********************non_recursive approch*************

#include<stdio.h>
#include<limits.h>

int memo_cut_rec(int pro[],int n,int rev[],int c[]){
int i,j,max_rev,val;
rev[0]=0;
c[0]=0;

for ( j= 1; j <=n; j++)
{
	max_rev=INT_MIN;
   for (i = 1;  i<=j; i++)
{
	 val=rev[j-i];
	if (max_rev<(pro[i]+val))
	{
		max_rev=pro[i]+val;
		c[j]=i;
	}
	
}
rev[j]=max_rev;
}
return rev[n];


}

int main()
{
	int n;
printf("enter the size of rod");
scanf("%d",&n);
int pro[n+1];
for (int i = 1; i <=n; i++)
{
	scanf("%d",&pro[i]);//1 to n tak ka profit
}
	int rev[n+1];
	int c[n+1];
	
    
	printf("%d",memo_cut_rec(pro,n,rev,c));

	return 0;
}
