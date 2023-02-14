#include <bits/stdc++.h>
using namespace std;
int minCoins(int coins[],int n,int w)
{
	int table[w+1];
	table[0]=0;
	for(int i=1;i<=w;i++)
		table[i]=INT_MAX;
    for(int i=1;i<=w;i++) 
    {
		for(int j=0;j<n;j++)
			if(coins[j]<=i) 
			{
				int sub_res=table[i-coins[j]];
				if(sub_res!=INT_MAX && sub_res+1<table[i])
					table[i]=sub_res+1;
			}
	}
	if(table[w]==INT_MAX)
		return -1;
	return table[w];
}
int main()
{
	int british_pound[]={1,2,5,10,20,50};
    int us_dollar[]={1,5,10,25};
    int norwegian_krone[]={1,5,10,20};
    int choice,n,w;
    cout<<"Enter the sum:";
	cin>>w;
    cout<<"1. British Pound\n2. US Dollar\n3. Norwegian_Krone";
    cout<<"\nEnter the type of currency: ";
    cin>>choice;
    if(choice==1)
    {
        n=sizeof(british_pound)/sizeof(british_pound[0]);  
	    cout<<"Minimum coins required is "<<minCoins(british_pound,n,w);
    }
    else if(choice==2)
    {
        n=sizeof(us_dollar)/sizeof(us_dollar[0]); 
        cout<<"Minimum coins required is "<<minCoins(us_dollar,n,w);
    }
    else if(choice==3)
    {
        n=sizeof(norwegian_krone)/sizeof(norwegian_krone[0]);
        cout<<"Minimum coins required is "<<minCoins(norwegian_krone,n,w);
    }
    else
        cout<<"\nWrong choice.";
	return 0;
}
