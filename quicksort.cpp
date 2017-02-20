

#include<cstdio>
#include<iostream>
using namespace std;

// c++ program to perform quick sort

class quicksort {
    int A[50];
    int n;
public:
    void readelements(void);
    void printelements(void);
    void sortnumbers(int, int);
    int arraysize(void) { return n;}
};

void quicksort::readelements(void) {
    cout << "Enter the n value (max 50) : " ;
    cin >> n;
    cout << "Enter the elements in the NON sorted order " << endl;
    for (int i=0; i < n ; i++) {
    cout << "Enter element [" << i+1 << "] : " ;
    cin >> A[i];
    }
}

void quicksort::printelements(void) {
    cout << "Array elements are ..." << endl;
    for(int i=0; i <n ; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void quicksort::sortnumbers(int left, int right) {
    
    int pivot;
    int l=left;
    int r=right;
    int tmp;

    //cout << "-- Array elements --" << endl;
      //      printelements();

            
        if ( left < right ) {
        
    pivot = A[left]; // pick 1st element as pivot
    left = left + 1;

    while ( left <= right ) {
        
                //cout << "pivot = " << pivot << " left = " << left << " right = " << right << endl;
        
        while ( A[left] <= pivot && left <= right ) {
            //cout << "A[left] = " << A[left] << " left = " << left << endl;
            left++;
        }
        
        while ( A[right] > pivot && right >= left) {
        //cout << "A[right] = " << A[right] << " right = " << right << endl;
                right--;

        }
        
        //cout << "left = " << left << " right = " << right << endl;
        
        if ( left > right ) break;  // cross-over detected
        
        // swap A[left], A[right]
        tmp = A[left];
        A[left] = A[right];
        A[right] = tmp;
        
        // update ptrs
        left++;
        right--;
        
        //printelements();
        
    }
    
    //cout << "swapping " << A[right] << " and " << A[l] << endl;
    // swap pivot and A[right]
    tmp = A[right];
    A[right] = A[l];
    A[l] = tmp;
    
    //printelements();
    //cout << "calling sortnumbers("<< l << "," << right-1 << ")" << endl;
    sortnumbers(l, right-1);
    //cout << "calling sortnumbers("<< right+1 << "," << r << ")" << endl;
    sortnumbers(right+1, r);
    }  // if
   
}

int main()
{
    quicksort b1;
    b1.readelements();
    cout << " before sorting " << endl;
    b1.printelements();
    b1.sortnumbers(0, b1.arraysize()-1);
    cout << " after sorting " << endl;

    b1.printelements();
    return 0;
}