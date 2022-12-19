#ifndef __TIME_H__
#define __TIME_H__
#include <sys/time.h>
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
#define N 128

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//================Question 1==============================
void bubbleSort(int arr[], int n){
    int i; //loop through each element
    int j; //compare each element
    
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < (n - i - 1); j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n){

    int i;
    int j;
    int val;

    for(int i = 1; i < n; i++){
        val = arr[i];
        j = i;
        while(arr[j-1] > val && j > 0){
            arr[j] = arr[j-1];
            j = j - 1;
        }
        arr[j] = val;
    }
}

//================Question 2==============================
void selectionSort(int arr[], int n){
    int i;
    int j;
    int min;
    
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min])
            min = j;
        }
        swap(arr[i], arr[min]);
        /*temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;*/
    }
}

//================Question 3==============================
void merge(int arr[], int l, int m, int r){

    //initialize length of subarrays
    int lengthL = m - l + 1;
    int lengthR = r - m;

    //initialize ints for subarray indexes
    int iL = 0;
    int jR = 0;
    int kM = l;

    //temp arrays 
    int arrL[lengthL];
    int arrR[lengthR];

    
    for(int i = 0; i < lengthL; i++){
        arrL[i] = arr[l+i];
    }
    for(int j = 0; j < lengthR; j++){
        arrR[j] = arr[m+1+j];
    }
    
    while(iL < lengthL && jR < lengthR){
        if(arrL[iL] <= arrR[jR]){
            arr[kM] = arrL[iL];
            iL++;
        } else{
            arr[kM] = arrR[jR];
            jR++;
        }
        kM++;
    }

    //while left index < left length, copy left half
    while(iL < lengthL){
        arr[kM] = arrL[iL];
        iL++;
        kM++;
    }

    //while right index < right length, copy right half
    while(jR < lengthR){
        arr[kM] = arrR[jR];
        jR++;
        kM++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r-l) / 2; //midpoint to divide into 2 arrays
        
        mergeSort(arr, l, m); //mergesort first array half
        mergeSort(arr, m+1, r); //mergesort second half
        merge(arr, l, m, r); //merge two sorted arrays
    }
}

//================Question 4==============================

//utility function to get max. value of arr[]
int getMax(int arr[], int n){
    int mx = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    return mx;
}

//function to do counting sort of arr[] to digit exp
void countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};

    //get # of times digit is at exp place for each element
    for(i = 0; i < n; i++){
        count[(arr[i]/exp)%10]++;
    }

    //calculate sum of each digit count
    for(i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    //calculate (arr[i]/exp)%10 and insert into arr[i]
    for(i = n-1; i >= 0; i--){
        output[count[(arr[i]/exp%10)]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);

    for(int exp = 1; m/exp > 0; exp *= 10){
        countSort(arr, n, exp);
    }
}

//========================================

double wtime()
{
	double time[2];	
	struct timeval time1;
	gettimeofday(&time1, NULL);

	time[0]=time1.tv_sec;
	time[1]=time1.tv_usec;

	return time[0]*1.0e6 + time[1];
}

#endif

int main(){
	int n= 1000;
    int arr[n];

    for(int i = 0; i < n; i ++)
	{
		int num = rand()%100; //change to 8mil for unsorted, change to num = n for sorted.
		arr[i] = num;
		
		for(int j = 0; j < i; j ++)
			if(num == arr[j])
			{
				i--;
				break;
			}
	}

    double time_begin = wtime();
	std::clock_t c_start = std::clock();

    //int arr[] = {23, 78, 45, 8, 32, 58};
    //int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);
    //insertionSort(arr, n);
    //selectionSort(arr, n);
    //mergeSort(arr, 0, n-1);
    //radixSort(arr, n);

    cout << "Sorted Array: \n";
    print(arr, n);
    //printMerge(arr, n);

    double my_time = wtime() - time_begin;
	std::clock_t c_end = std::clock();

    std::cout << "The time consumption is: " << my_time << " (us).\n";
	long double time_elapsed_ms = 1000000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
	std::cout << "The CPU time used: " << time_elapsed_ms << " (us).\n";
}