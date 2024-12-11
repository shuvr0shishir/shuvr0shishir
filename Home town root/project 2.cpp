#include <iostream>

using namespace std;

int main()
{
    cout << "#The Shortest path and time to Reach my Hometown:\n";
    cout<<"(DSC) to (Mirzapur): \n\n";

    string paths[3][7] = {
        {"DSC", "Asuliya", "Jamgora", "Baipail", "Chandra", "Kaliyakoir", "Mirzapur"},
        {"DSC", "C&B", "Nobinagar", "Baipail", "Chandra", "Kaliyakoir", "Mirzapur"},
        {"DSC", "C&B", "Nobinagar", "Kalampur", "Kawalipara", "Warshi", "Mirzapur"}};

    int distances[3][6] = {
        {5, 6, 5, 11, 5, 14},
        {6, 10, 4, 11, 5, 14},
        {6, 10, 8, 10, 9, 8}};

    int totalDistance[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            totalDistance[i] += distances[i][j];
        }
    }

    int minIndex = 0;

    for (int i = 0; i < 3; i++)
    {
        if (totalDistance[minIndex] > totalDistance[i])
        {
            minIndex = i;
        }
    }
    cout << "The Shortest Path is Root no : " << minIndex + 1 << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << paths[minIndex][i];
        if (i < 6)
        {
            cout << " -> ";
        }
    }
    cout << endl<< endl;
    cout << "Distance: " << totalDistance[minIndex] << endl;

    int totalMinute = totalDistance[minIndex] * 2; // assume 1km -> 2min
    cout << "Time: " << totalMinute / 60 << " hour and " << totalMinute % 60 << "minute. (Approximately) " << endl;

    return 0;
}