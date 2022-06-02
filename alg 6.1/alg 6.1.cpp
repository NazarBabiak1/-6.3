#include <iostream> 

const unsigned int NUM = 500000;

int A[NUM];            // масив, що буде передано в функцію сортування 

int B[NUM];            // копія масиву A, що буде використовуватися для відновлення 

void CreateArray() {

    srand(1);

    for (int i = 0; i < NUM; i++)

        A[i] = B[i] = (int)rand();
}

void RestoreArray() {

    for (int i = 0; i < NUM; i++)

        A[i] = B[i];

}

void InsertSort(int a[], int N) {
    int x;
    for (int i = 1; i < N; i++) {
        x = a[i];
        int j = i - 1;
        while (x < a[j]&&j>=0) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int findpivot(int i, int j, int* Array) {
    int firstkey = Array[i];     for (int k = i + 1; k <= j; k++) {
        if (Array[k] > firstkey)return k;    
     else if (Array[k] < firstkey)return i;
    }     return -1;
}


int partition(int i, int j, int pivot, int* Array) {
    int l, r;     l = i;     r = j;     do {
        std::swap(Array[l], Array[r]);    
        while (Array[l] < pivot)      
            l++;
        while (Array[r] >= pivot)    
            r--;
    }
        while (l <= r);  
            return l;
}
void QuickSort(int i, int j, int* Array) {

    int pivot, pivotindex, k; 
    pivotindex = findpivot(i, j, Array); 
    if (pivotindex != -1) {
        pivot = Array[pivotindex];       
        k = partition(i, j, pivot, Array);
        QuickSort(i, k - 1, Array);
        QuickSort(k, j, Array);
    }
}
int main()
{
    CreateArray();

    clock_t  begt, endt;

    begt = clock();                      // час початку експерименту  
    QuickSort(0, NUM - 1, A);                   // виклик функції сортування 

    endt = clock();                     // час закінчення експерименту 

    std::cout << "Quick sort time = " << endt - begt << std::endl;

    RestoreArray();

    /////////////////////////////////////////////////////////////////////// 

    begt = clock();                      // час початку експерименту  
    InsertSort(A, NUM);                   // виклик функції сортування 

    endt = clock();                     // час закінчення експерименту 

    std::cout << "Insert sort time = " << endt - begt << std::endl;
}
