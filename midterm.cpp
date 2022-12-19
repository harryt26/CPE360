#include <iostream>
using namespace std;
 
//defining array size and initialize head/tail as -1 since 0 is 1st element
#define ARR_SIZE 1024
int head = -1;
int tail = -1;
int arr[ARR_SIZE];
 
void enqueue(int enqArr[30]){
    if(tail == ARR_SIZE-1){ //check to see if queue is already filled
        cout << "Queue is full :(";
    } else{
        if(head == -1){
            head == 0; //change to first index of arr[x]
            tail++;
            arr[tail] = enqArr[30];
        }
    }
}
