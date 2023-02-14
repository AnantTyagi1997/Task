#include<bits/stdc++.h>
using namespace std;
string ones[20]={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ",
    "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"};
string tens[20]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string numToWords(int n,string s)
    {
        string str="";
        if(n>19)
        {
            str+=tens[n/10];
            if(n%10)
            {
                str+="-";
            }
                str+=ones[n%10];
        }
        else
        {
            str+=ones[n];
        }
        if(n)
        {
            str+=s;
        }
        return str;
    }
    
string convertToWords(int n)
    {
    string res;
    if(n>99)
    {
    res+=numToWords((n/1000)%100,"thousand ");
    res+=numToWords((n/100)%10,"hundred ");
    res+=numToWords((n%100),"");
    }
    else if(n>19)
    {
        res+=tens[n/10];
        if(n%10)
        {
            res+="-";
        }
        res+=ones[n%10];
    }
    else if(n>0)
    {
       res+=ones[n]; 
    }
    else                
    {
        return "zero";
    }
    return res;
}
int main()
{
    int num;
    cout<<"Enter a number:";
    std::cin>>num;
    cout<<convertToWords(num)<<endl;
    return 0;
}
