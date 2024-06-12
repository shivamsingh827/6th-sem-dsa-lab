#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{

    int queue[50];
    int initialHead;
    int totalHeadMovement = 0;
    int totalProcess;

    int memorySize;
    cout<<"Enter the memory size"<<endl;
    cin>>memorySize;

    cout << "Enter the number of processes---->" << endl;
    cin >> totalProcess;

    cout << "Enter the sequence of requests" << endl;
    for (int i = 0; i < totalProcess; i++)
    {
        cin >> queue[i];
    }

    for (int i = 0; i < totalProcess; i++)
    {
       if(queue[i]>memorySize-1   ||  queue[i]<0 ){
        cout<<"Error in the requests"<<endl;
        return -1;
       }
    }

    cout << "Enter the position of head" << endl;
    cin >> initialHead;

    int currHead = initialHead;

    cout << "Head Moves from : "<<currHead;

    for (int i = 0; i < totalProcess; i++)
    {

        totalHeadMovement += abs(currHead - queue[i]);
        cout << "-->" << queue[i] ;
        currHead = queue[i];
    }

    cout << "\nTotal head movement is = " << totalHeadMovement << endl;

    return 0;
}