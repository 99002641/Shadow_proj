#include<bits/stdc++.h>
#include"bunny.h"

using namespace std;
void breeding(list<bunny>&);
void  checkRadioactivity(list<bunny>&);
void GenerateNextTurn(list<bunny>&);
void delete_extra(list<bunny>&);

int main()
{
    list<bunny> thelist;
    bunny a[5];
    for(int i=0; i<5; i++)
    {
        thelist.push_back(a[i]);
    }
    fstream fout;
    fout.open("OUTPUT_LOG.txt", ios::out|ios::app );
    fout.close();
    while(1)
    {
        checkRadioactivity(thelist);
        GenerateNextTurn(thelist);
        delete_extra(thelist);
        getchar();
        breeding(thelist);
    }
    return 0;
}


void breeding(list<bunny>&db)
{
    int tcount=0,mcount=0;
    string male="male";
    string female="female";
    int maleCount=0,femCount=0;
    list<bunny>::iterator iter;

    for(iter=db.begin(); iter!=db.end(); ++iter)
    {
        tcount++;

        if((male==iter->gender))
            maleCount++;
        if((female==iter->gender))
            femCount++;
    }
    cout<<"                                          --In Previous Turn: \n";
    cout<<"                                             male:"<<maleCount<<"\n";
    cout<<"                                             female:"<<femCount<<"\n";
    list<bunny>::iterator iter1;
    for(iter1=db.begin(); iter1!=db.end(); ++iter1)
    {
        mcount++;
        if(mcount>=tcount+1)
            break;
        if(iter1->gender==female)
        {

            bunny temp(iter1->colour);
            db.push_back(temp);
        }
    }
}

void checkRadioactivity(list<bunny>&db)
{
    int Rcount=0,remCount=0;
    list<bunny>::iterator iter;

    for(iter=db.begin(); iter!=db.end(); ++iter)
    {
        if(iter->radioactive==true)
            Rcount++;
    }
    cout<<Rcount<<"\n";
    if(Rcount>=1)
    {
        for(iter=db.begin(); iter!=db.end(); ++iter)
        {
            if(iter->radioactive==false)
            {
                remCount++;
                cout<<"                                                                        changed to ra\n";
                iter->radioactive=true;
            }

            if(remCount==Rcount)
                break;

        }
        cout<<remCount<<"\n";

    }
}

void GenerateNextTurn(list<bunny> &db)
{
    int ocount=0;
    list<bunny>::iterator iter;



    for(iter=db.begin(); iter!=db.end(); ++iter)
    {
        cout<<"\nObject count:"<<++ocount<<"\n";



        switch(iter->radioactive)
        {
        case 0:
            if(iter->age>10)
            {
                cout<<"                                      "<<iter->name<<"expired\n";
                db.erase(iter);
                break;
            }

            cout<<"-------------------------------------------------------------------------------------------------------\n";
            cout<<"Name: Bunny "<<iter->name<<"\n";
            cout<<"Gender:"<<iter->gender<<"\n";
            cout<<"Colour:"<<iter->colour<<"\n";
            cout<<"Radioactivity:"<<iter->radioactive<<"\n";
            cout<<"Age:"<<iter->age++<<"\n";
            cout<<"-------------------------------------------------------------------------------------------------------\n";


            break;

        case 1:
            if(iter->age >50)
            {
                cout<<"                                       "<<iter->name<<"expired\n";
                db.erase(iter);
                break;
            }


            cout<<"-------------------------------------------------------------------------------------------------------\n";
            cout<<"Name: Bunny "<<iter->name<<"\n";
            cout<<"Gender:"<<iter->gender<<"\n";
            cout<<"Colour:"<<iter->colour<<"\n";
            cout<<"Radioactivity:"<<iter->radioactive<<"\n";
            cout<<"Age:"<<iter->age++<<"\n";
             cout<<"-------------------------------------------------------------------------------------------------------\n";


            break;


        }

    }



}
void delete_extra(list<bunny>&db)
{int ocount=0;

 list<bunny>::iterator iter;
 for(iter=db.begin(); iter!=db.end(); ++iter)
 {
     ocount++;
 }
     if(ocount>1000)
        {
            list<bunny>::iterator it1,it;
            it=db.begin();
            advance(it,ocount/2);
            db.erase(it1,it);
        }
}
