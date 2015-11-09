#include <iostream>
#include "CMyStack.h"

using namespace std;

int main()
{
    CMyStack<double> stackk;
    stackk.push(8);
    stackk.push(8);
    stackk.push(7);
    stackk.push(7);
    stackk.push(888);
    stackk.push(118);
    //stackk.clear();
    stackk.push(8);

    //double zm;
    //stackk.pop(zm);
    //cout<<"dupa: "<<zm<<endl;
    stackk.removeDuplicates();

    const uint64_t sizet = 10;
    double tab[sizet];
    stackk.getItems(tab,sizet);
    for(uint64_t i=0;i<sizet;i++)
        cout<<tab[i]<<endl;


    try
    {
        //int z = *p;
    }
    catch(...)
    {
        cout<<"Dupa"<<endl;
    }

    return 0;
}

