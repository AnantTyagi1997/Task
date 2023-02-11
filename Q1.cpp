#include <bits/stdc++.h>
using namespace std;
int main()
{
    int lb=1,ub=3;
    int pc,player;
    int choice=1,count=0;
    int high_score=INT_MIN;
    string name;
    ofstream fout;
	string line;
    ifstream fin("score.txt");
    fin>>name>>high_score; 
    fin.close();
    cout<<endl<<"Highest Scorer's Name:"<<name<<"\tHighest Score:"<<count<<endl;
    char array[][20]={" ","Rock","Paper","Scissor"};
    cout<<"\nEnter your name:";
    cin>>name;
    while(1)
    {
        cout<<"Menu\n 1. Play \n 2. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        if(choice==2)
            break;
        pc=(rand()%(ub-lb+1))+lb;
        cout<<"1. Rock\t2. Paper\t3. Scissor"<<endl;
        cout<<"Enter your choice:";
        cin>>player;
        cout<<"PC: "<<array[pc]<<" vs "<<"You: "<<array[player]<<endl;
        if(pc==player)
            cout<<"Draw"<<endl;
        else if(pc==1)
        {
            if(player==2)
            {
                cout<<"You win."<<endl;
                count++;
            }
            else
                cout<<"You lose."<<endl;
        }
        else if(pc==2)
        {
            if(player==1)
                cout<<"You lose."<<endl;
            else
            {
                cout<<"You win."<<endl;
                count++;
            }
        }
        else if(pc==3)
        {
            if(player==1)
            {
                cout<<"You win."<<endl;
                count++;
            }
            else
                cout<<"You lose."<<endl;
        }
        cout<<"\n\n";
    }
    cout<<"Your total win is "<<count<<endl;
    if(count>high_score)
    {
        high_score=count;
        cout<<"Congratulations! New High Score."<<endl;
	    fout.open("score.txt");
	    fout<<name<<"\t"<<high_score;
	    fout.close();
    }
    return 0;
}