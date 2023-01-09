
//
// Lab 6: 
// In this lab, we simulate the 3 probing methods: Linear, Quadratic, and Cubic probing.
// Simple hash function will be used: hashCode = x % SIZE
// Main goal is to minimize the number of collision encountered during hashing
// 
// Cubic probing should encounter slightly fewer collisions than quadratic probing
//
// Assignment:
// 1- Run the supplied code in your visual studio IDE
// 2- Add two more probing methods similar to the linear probing to simulate the Quadratic and Cubic probing 
// 3-Is Linear probing any better than quadratic probing?
// 4-Is cubic probing any better than quadratic?
// 5-Study of clustering induced by each method
// 
// Create a report highlighting the above research topic featuring your run data.
//

#include<iostream>
#include<vector>
#include<cmath>

#include <chrono>


using namespace std;
const int SIZE = 100;   // prime number over 9,000 is 9001
const int MAX = SIZE / 2;


int main()
{
    vector<int>linear(SIZE, -1);
    vector<int>quadratic(SIZE, -1);
    vector<int>cubic(SIZE, -1);

    int linearCollisions = 0;
    int quadraticCollisions = -1;
    int cubicCollisions = -1;


    cout << "Number of collisions for each type of probing:\n";
    // Generate random indices to occupy in the hash tables.
    // seed the random # generator
    srand((unsigned)time(NULL));

    for (int i = 0; i < MAX; ++i)
    {
        int hashCode = rand() % SIZE;
        int offset = 0;
        while (linear[hashCode] == 1) // hashed already?
        {
            ++linearCollisions;
            ++offset;
            hashCode += offset;

            if (hashCode >= SIZE)
                hashCode %= SIZE;
        }
        linear[hashCode] = 1;
    }
    cout << "Linear Collisions = " << linearCollisions << endl;


    srand((unsigned)time(NULL));
    
    for (int i = 0; i < MAX; ++i)
    {
        int hashCode = rand() % SIZE;
        int offset = 0;
        while (quadratic[hashCode] == 1)
        {
            ++quadraticCollisions;
            ++offset;
            hashCode += offset * offset;

            if (hashCode >= SIZE)
                hashCode %= SIZE;
        }
        quadratic[hashCode] = 1;

    }
    cout << "Quadratic Collisions = " << quadraticCollisions << endl;


    
    srand((unsigned)time(NULL));
    
    for (int i = 0; i < MAX; ++i)
    {
        int hashCode = rand() % SIZE;
        int offset = 0;
        while (cubic[hashCode] == 1) 
        {
            ++cubicCollisions;
            ++offset;
            hashCode +=offset*offset*offset;

            if (hashCode >= SIZE)
                hashCode %= SIZE;
        }
        cubic[hashCode] = 1;

    }
    cout << "Cubic Collisions = " << cubicCollisions << endl;
    
    
    
    int arr[SIZE][100] = {};
    int newCollisions = 0;

    srand((unsigned)time(NULL));
    for (int i = 0; i < MAX; ++i)
    {
        int hashCode = rand() % SIZE;
        int offset = 0;
        int k = 0;
        while (arr[hashCode][k] == 1) 
        {
            ++newCollisions;
            k++;
            if (hashCode >= SIZE)
                hashCode %= SIZE;
        }
        arr[hashCode][k] = 1;

    }
    cout << "New Collisions = " << newCollisions << endl;



    return 0;
}



