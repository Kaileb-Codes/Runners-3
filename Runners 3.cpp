


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;


void readData(string names[], int miles[][NUM_DAYS]);
void calculateData(int miles[][NUM_DAYS], int total[], double average[]);
void displayResults(string names[], int miles[][NUM_DAYS],
    int total[], double average[]);

int main()
{
    string names[NUM_RUNNERS];
    double miles[NUM_RUNNERS][NUM_DAYS];
    double total[NUM_RUNNERS];
    double average[NUM_RUNNERS];


    readData(names, miles);

    calculateData(miles, total, average);

    displayResults(names, miles, total, average);

    return 0;
}

void readData(string names[], double miles[][NUM_DAYS])
{
    ifstream file("runners.txt");


    for (int i = 0; i < NUM_RUNNERS; i++)
    {
        file >> names[i];

        for (int j = 0; j < NUM_DAYS; j++)
        {
            file >> miles[i][j];
        }
    }

    file.close();
}

void calculateData(double miles[][NUM_DAYS],
    double total[],
    double average[])
{
    for (int i = 0; i < NUM_RUNNERS; i++)
    {
        total[i] = 0;

        for (int j = 0; j < NUM_DAYS; j++)
        {
            total[i] += miles[i][j];
        }

        average[i] = static_cast<double>(total[i]) / NUM_DAYS;
    }
}

void displayResults(string names[],
    double miles[][NUM_DAYS],
    double total[],
    double average[])
{
    cout << fixed << setprecision(2);

    cout << setw(12) << "Runner"
        << setw(8) << "Day 1"
        << setw(8) << "Day 2"
        << setw(8) << "Day 3"
        << setw(8) << "Day 4"
        << setw(8) << "Day 5"
        << setw(8) << "Day 6"
        << setw(8) << "Day 7"
        << setw(12) << "Total"
        << setw(12) << "Average"
        << endl;

    cout << string(108, '-') << endl;

    for (int i = 0; i < NUM_RUNNERS; i++)
    {
        cout << setw(12) << names[i];

        for (int j = 0; j < NUM_DAYS; j++)
        {
            cout << setw(8) << miles[i][j];
        }

        cout << setw(12) << total[i]
            << setw(12) << average[i]
            << endl;
    }
}