/**
* Merge sort time comparison where the merge is removed when not needed
*
* Original merge sort algorithm based on code shared by Dr. Yuehua Wang
*
* @Corrales, Aidan
* @CSCI 520 lab 04
* @date 10/31/2024
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#define N  32000

using namespace std;

int mergeCount = 0, mergePrimeCount = 0;						//Global variables to count merges

void merge(int a[], int aux[], int lo, int mid, int hi){		//Non recursive merge
	
    for (int k = lo; k <= hi; k++)      aux[k] = a[k];

        int i = lo, j = mid+1;

        for (int k = lo; k <= hi; k++)
        {
            if(i > mid)                      a[k] = aux[j++];
            else if (j > hi)                 a[k] = aux[i++];
            else if (aux[j] < aux[i])		a[k] = aux[j++];
            else                             a[k] = aux[i++];
        }
}

void sort(int a[], int aux[], int lo, int hi){					//Unedited sort algorithm
    if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
    mergeCount++;												//I lied, I added this counter >:)
}

double sort(int a[]){
	double duration;											//Variable to return timer value
    int *aux = new int[N];
    clock_t start = clock();									//Start ctime call
    sort(a, aux, 0, N-1);
    clock_t end = clock();										//End ctime call
    duration = static_cast<double>(end-start)/CLOCKS_PER_SEC;	//Convert to time elapsed
    delete[] aux;												//Free up memory
    return duration;
}

void sortPrime(int a[], int aux[], int lo, int hi){				//Updated sort
    if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
    sortPrime(a, aux, lo, mid);
    sortPrime(a, aux, mid+1, hi);
    if (a[mid] > a[mid + 1]) {									//Check if merge is needed
		merge(a, aux, lo, mid, hi);
		mergePrimeCount++;										//Updated counter
    }
}

double sortPrime(int a[]){										//Virtually the same as sort
	double duration;
    int *aux = new int[N];
    clock_t start = clock();
    sortPrime(a, aux, 0, N-1);
    clock_t end = clock();
    duration = static_cast<double>(end-start)/CLOCKS_PER_SEC;
    delete[] aux;
    return duration;
}

void nearlySorted(int A[], int B[], int size){					//32k array generator
    for (int i = 0; i < N; ++i)
        A[i]=B[i]=i;											//Generate sorted array
        
    for (int i = 0; i < N; ++i){
    	if(i%20==0){											//Every 20th element swap with random element
    		int a = rand()%size;								//Which gives 10% unsorted
    		swap(A[a],A[i]);									//Which is 90% sorted
    		swap(B[a],B[i]);									//Note: The values of A[] and B[] are the same
		}
	}
}

void print(int A[]) {
    for (int i = 0; i < 100; i++)								//Print first 100 elements
        cout << A[i] << ", ";									//Change 100 to N to see full arrays
    cout << endl << endl;
}

int main(int argc, const char * argv[]){
    int  A[N]={0}, P[N]={0};									//Create 2 empty arrays
    double mergeTime, mergePrimeTime;							//Doubles to hold timer values

    nearlySorted(A, P, N);										//Fill arrays nearly sorted
    cout << "Original nearly sorted array, first 100 items: ";
    print(A);

    mergeTime = sort(A);										//Sort using merge
    cout << "Sorted array, first 100 items: ";
    print(A);

    mergePrimeTime = sortPrime(P);								//Sort using merge'
    cout << "Sorted array with check, first 100 items: ";
    print(P);
    
	cout<<"Sorting Type\tTime Taken\tMerges"<<endl;				//Formatted results
    cout<<"Merge\t\t"<<mergeTime<<"s\t\t"<<mergeCount<<endl;
    cout<<"Merge'\t\t"<<mergePrimeTime<<"s\t\t"<<mergePrimeCount<<endl;
}

