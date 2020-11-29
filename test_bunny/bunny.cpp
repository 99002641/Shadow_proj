#include<bits/stdc++.h>
#include"bunny.h"
using namespace std;

void bunny::GetRandomName()
{
    vector<string> thenames;
    readthat(thenames);

    name=thenames[rand()%100];
}

void bunny::GetRandomGender()
{
    int flag=rand()%2;
    if(flag==0)
        gender="male";
    else if(flag==1)
        gender="female";

}

void bunny::GetRandomColour()
{
    int flag=rand()%4;

    if(flag==0)
        colour="white";
    else if(flag==1)
        colour="black";
    else if(flag==2)
        colour="brown";
    else if(flag==3)
        colour="spotted";

}

void bunny::GetRadioactiveOrNot()
{
    int flag=rand()%1000;

    if(flag>0 && flag<20)
        radioactive=true;
    else
        radioactive=false;

    if(radioactive)
        cout<<"radioactive :"<<flag<<"\n";

}
void bunny::readthat(vector<string>&bunnynames)
{
    string S;
    fstream fin;
    fin.open("Names.csv",ios::in);
    while(getline(fin,S))
    {
        bunnynames.push_back(S);

    }
    fin.close();

}
