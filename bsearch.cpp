

#include<cstdio>
#include<iostream>
using namespace std;

// c++ program to perform binary search

class binsearch {
    int A[50];
    int n;
public:
    void readelements(void);
    void printelements(void);
    void binarysearch(int);
};

void binsearch::readelements(void) {
    cout << "Enter the n value (max 50) : " ;
    cin >> n;
    cout << "Enter the elements in the sorted order " << endl;
    for (int i=0; i < n ; i++) {
    cout << "Enter element [" << i+1 << "] : " ;
    cin >> A[i];
    }
}

void binsearch::printelements(void) {
    cout << "Array elements are ..." << endl;
    for(int i=0; i <n ; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void binsearch::binarysearch(int elem) {
    int high, mid, low;
    
    high = n-1;
    low = 0;
    
    while ( low <= high ) {
        mid = (low + high) / 2 ;
        if ( A[mid] == elem ) {
            cout << "Element " << elem << " is found at " << mid+1 << " location in the array " << endl;
            return;
        }
        else {
            if ( elem < A[mid] ) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
            
        }
    }
    cout << "Element " << elem  << " NOT found in the array " << endl;
    
}

int main()
{
    int t;
    binsearch b1;
    b1.readelements();
    b1.printelements();
    cout << "Enter the element to be searched : " ;
    cin >> t;
    b1.binarysearch(t);
    return 0;
}