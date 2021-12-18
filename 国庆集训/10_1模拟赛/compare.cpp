#include<cstdio>
#include<cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int tmp=0;
    for(int i=1;i<=10000;i++)
    {
        system("/Users/lukealpha/Documents/Trainer/Code/DebugFiles/data.out");
        system("/Users/lukealpha/Documents/Trainer/Code/DebugFiles/arrangement_dfsarrange.out");
        system("/Users/lukealpha/Documents/Trainer/Code/DebugFiles/arrangement_dfsexchange.out");
         
        if(i/100>tmp) {printf("-- %d --\n",i);tmp=i/100;}
        if(system("diff test1.out test2.out"))
        {
            printf("wrong in --> %d \n",i);
            break;
        }
        else{
            cout << "Test OK!" << endl;
        }

    }
    return 0;
}

