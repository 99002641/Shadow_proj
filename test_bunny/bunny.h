#ifndef BUNNY_H_INCLUDED
#define BUNNY_H_INCLUDED

#include<bits/stdc++.h>

using namespace std;

class bunny
{
public:
    string name,gender,colour;
    int age;
    bool radioactive;



    bunny()
    {
        GetRandomName();
        cout<<"                                                     Bunny  "<<name<<" was born \n";
        GetRandomGender();
        GetRandomColour();
        GetRadioactiveOrNot();
        age=0;
    }

    bunny(string parentcolour)
    {
        GetRandomName();
        cout<<"                                                       Bunny "<<name<<" was born \n";
        GetRandomGender();
        colour=parentcolour;
        GetRadioactiveOrNot();
        age=0;
    }

    void readthat(vector<string>&);
    void GetRandomName();
    void GetRandomGender();
    void GetRandomColour();
    void GetRadioactiveOrNot();
};

#endif // BUNNY_H_INCLUDED
