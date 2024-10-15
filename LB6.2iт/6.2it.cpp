#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;


void create(int* arr, int SIZE, int MIN, int MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
}


static void Print(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

static double FindAverageOfMinMaxIndexes(int* arr, int SIZE)
{
    if (SIZE == 0) {
        return 0; 
    }

    int minIndex = 0, maxIndex = 0;

    
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    
    return (minIndex + maxIndex) / 2.0;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 12;
    int MIN = -12;
    int MAX = 12;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    Print(arr, SIZE);
    cout << "\n\n";

    cout << "Середнє арифметичне індексів мінімального і максимального елементів: "
        << FindAverageOfMinMaxIndexes(arr, SIZE) << endl;

    delete[] arr;

    return 0;
}
