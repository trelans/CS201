#include <iostream>
#include "ctime"
#include <time.h>
#include <stdlib.h>
#include <random>
using namespace std;

// funcs
int binarySearch(int* arr, int low, int high, int key );
bool isSubsetLinearSearch (int* arr1 , int* arr2, int n , int m );
bool isSubsetBinarySearch(int* arr1 , int* arr2, int n , int m);
bool isSubsetFrequencyTable(int* arr1, int* arr2, int n , int m);

int randomIntegerGenerator(int  upperBound);
int randomMake(int range_to);

void measureAlgorithm1(int* arr1 , int* arr2 , int n , int m );
void measureAlgorithm2(int* arr1 , int* arr2 , int n , int m );
void measureAlgorithm3(int* arr1 , int* arr2 , int n , int m );

bool isSubsetLinearSearch (int* arr1 , int* arr2, int n , int m ) {

    int i = 0; int j = 0;

    for ( i = 0; i < m ; ++i) {
        for ( j = 0; j < n; ++j) {
            if (arr1[j] == arr2[i]) {
                break;
            }
        }
        if(j == n) { return false;}
    }
    return true;
}

bool isSubsetBinarySearch(int* arr1 , int* arr2, int n , int m) {
    for (int i = 0; i < m; i++) {
        if (binarySearch(arr1,0, n - 1, arr2[i]) == -1)
            return false;
    }
    return true;
}

bool isSubsetFrequencyTable(int* arr1, int* arr2, int n , int m) {
    // default max
    int max = arr1[0];
    //map<int, int> elementFrequency;

    // finding max of arr1
    for (int i = 0; i < n; ++i) {
        if (arr1[i] > max) {
            max = arr1[i];
        }
    }

    int* elementFrequency = new int[max];
    // init all array elements to 0
    for (int i = 0; i < max; ++i) {
        elementFrequency[i] = 0;

    }

    for (int i = 0; i < n; i++)
    {
        int currentElement = arr1[i];
        elementFrequency[ currentElement - 1]++;


    }
    for (int i = 0; i < m; i++)
    {
        int currentElement = arr2[i];
        if (elementFrequency[currentElement - 1] > 0) {
            elementFrequency[ arr1[i] - 1]--;
        } else {
            return false;
        }

    }
    return true;
}

int binarySearch(int* arr, int low, int high, int key ) {
    if ( high >= low) {

        int mid = low + ((high - low) / 2);
        if (arr[mid] > key) {
            // left
            return binarySearch(arr, low, mid - 1, key);

        } else if (arr[mid] < key) {
            // right
            return binarySearch(arr, mid + 1, high, key);

        } else if (arr[mid] == key) {
            return mid;
        }
    }
    return  -1;

}

int main() {

    srand(time(0));



    int n =   1000000;
    int m = 1000;
    // determining arr1 size according to bounds
    // lowerBoundArr1 = 0;
    int upperBoundArr1= n;
    // constructing arr1
    int* arr1 = new int[n];
    for (int i = 0; i < n ; ++i) {
        arr1[i] = i+1;
    }
    int* arr2 = new int[n];
    // constructing arr2
    for (int i = 0; i < m; ++i) {

     arr2[i] = (rand() % upperBoundArr1);
    }
   measureAlgorithm1(arr1 , arr2 , n , m );
    measureAlgorithm2(arr1 , arr2 , n , m );
    measureAlgorithm3(arr1 , arr2 , n , m );


    return 0;
}


void measureAlgorithm1(int* arr1 , int* arr2 , int n , int m ) {
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        double duration;
        clock_t startTime = clock();
        //
        isSubsetLinearSearch(arr1 , arr2 , n, m);
        //
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds. FOR ALGO 1" << endl;
        sum = sum + duration;

    }
    double avg = sum / 10;
    cout <<  "Average = " << avg << " FOR ALGO 1 N= " << n ;

}

void measureAlgorithm2(int* arr1 , int* arr2 , int n , int m ) {
    double sum = 0;
    for (int i = 0; i < 1000; ++i) {
        double duration;
        clock_t startTime = clock();
        //
        isSubsetBinarySearch(arr1 , arr2 , n, m);
        //
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds. . FOR ALGO 2" << endl;
        sum = sum + duration;
    }
    double avg = sum / 1000;
    cout <<  "Average = " << avg << " FOR ALGO 2 N= " << n ;

}

void measureAlgorithm3(int* arr1 , int* arr2 , int n , int m ) {
    double sum = 0;
    for (int i = 0; i < 1000; ++i) {
        double duration;
        clock_t startTime = clock();
        //
        isSubsetFrequencyTable(arr1 , arr2 , n, m);
        //
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took " << duration << " milliseconds.. FOR ALGO 3" << endl;
        sum = sum + duration;
    }
    double avg = sum / 1000;
    cout <<  "Average = " << avg << " FOR ALGO 3 N= " << n ;
}

