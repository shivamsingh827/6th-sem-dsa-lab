#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{

    vector<int> queue;
    int initialHead;
    int totalHeadMovement = 0;
    int totalProcess;

    int memorySize;
    cout << "Enter the memory size" << endl;
    cin >> memorySize;

    cout << "Enter the number of processes---->" << endl;
    cin >> totalProcess;

    cout << "Enter the sequence of requests" << endl;
    for (int i = 0; i < totalProcess; i++)
    {
        int temp;
        cin >> temp;
        queue.push_back(temp);
    }

    for (int i = 0; i < totalProcess; i++)
    {
        if (queue[i] > memorySize - 1 || queue[i] < 0)
        {
            cout << "Error in the requests" << endl;
            return -1;
        }
    }

    cout << "Enter the position of head" << endl;
    cin >> initialHead;

    bool chk = 0;

    for (int i = 0; i < totalProcess; i++)
    {
        if (queue[i] == initialHead)
        {
            chk = 1;
        }
    }
    if (!chk)
    {

        queue.push_back(initialHead);
    }

    sort(queue.begin(), queue.end());

    int currHead = initialHead;

    int direction;
    cout << "Enter the direction left/right acoording to where to your initial head is +1 for right -1 for left" << endl;
    cin >> direction;

    int initialHeadIndex;

    for (int i = 0; i < queue.size(); i++)
    {
        if (queue[i] == currHead)
        {
            initialHeadIndex = i;
        }
    }

    int temp = initialHeadIndex;
    int temp2 = initialHead;
    int temp1 = totalProcess;

    int smallestPro = queue[0];
    int largestPro;
    if (chk)
    {

        largestPro = queue[totalProcess - 1];
    }
    else
    {

        largestPro = queue[totalProcess];
    }

    if (direction == -1)
    {

        initialHeadIndex--;

        for (int i = initialHeadIndex; i >= 0; i--)
        {
            totalHeadMovement += abs(queue[i] - currHead);

            cout << "Head moves from-->" << currHead << " to " << queue[i] << endl;

            currHead = queue[i];
        }

        if (chk)
        {
            totalProcess--;
        }

        for (int i = initialHeadIndex + 2; i <= totalProcess; i++)
        {
            totalHeadMovement += abs(queue[i] - currHead);

            cout << "Head moves from-->" << currHead << " to " << queue[i] << endl;

            currHead = queue[i];
        }
    }
    else
    {

        initialHeadIndex++;

        if (!chk)
        {
            totalProcess++;
        }

        for (int i = initialHeadIndex; i < totalProcess; i++)
        {
            totalHeadMovement += abs(queue[i] - currHead);
            cout << "Head moves from-->" << currHead << " to " << queue[i] << endl;

            currHead = queue[i];
        }

        for (int i = initialHeadIndex - 2; i >= 0; i--)
        {
            totalHeadMovement += abs(queue[i] - currHead);
            cout << "Head moves from-->" << currHead << " to " << queue[i] << endl;

            currHead = queue[i];
        }
    }

    cout << "\nTotal head movement is = " << totalHeadMovement << endl;

    return 0;
}
