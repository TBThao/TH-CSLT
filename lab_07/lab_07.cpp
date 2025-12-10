#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int *a, int *b);
int* sum(int *a, int *b);

void inputArray(int *&a, int &n);
void printArray(int *a, int n);

int* findMax(int *a, int n);
int* copyArray(int *a, int n);

int* countEvens(int *arr, int n, int *evens);
int* generateEvenArray(int *arr, int n, int *count);

int* findLargestSumSubarray(int *a, int n,
                            int &largestSum,
                            int &subarrayLength);

int* findLongestAscendingSubarray(int *a, int n,
                                int &subarrayLength);

void swapArrays(int *&a, int *&b,
                int &na, int &nb);

int* concatenateTwoArrays(int *a, int *b,
                        int na, int nb);

int* mergeTwoArrays(int *a, int *b,
                    int na, int nb,
                    int &nc);

void generateRandomMatrix(int **&A,
                        int &m, int &n);

int** calculateProductMatrix(int *a, int *b,
                            int na, int nb);

void swapRows(int **a, int rows, int cols,
            int firstRow, int secondRow);

void swapColumns(int **a, int rows, int cols,
                int firstCol, int secondCol);

int** transposeMatrix(int **a, int m, int n);

int** concatenateMatricesByRow(int **a, int **b,
                            int m, int n);

int** concatenateMatricesByCol(int **a, int **b,
                            int m, int n);

int** multiplyMatrices(int **a, int **b,
                    int ma, int na,
                    int mb, int nb);

int** findLargestSubmatrix(int **a,
                        int m, int n,
                        int &m_sub, int &n_sub);


// TODO
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int* sum(int *a, int *b){
    int sum = *a + *b;
    int *ans = new int;
    *ans = sum;
    return ans;
}

void inputArray(int *&a, int &n){
    cin >> n;
    a =  new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void printArray(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int* findMax(int *a, int n){
    int *p = &a[0];
    for(int i = 1; i < n; i++){
        if(*p < a[i]){
            p = &a[i];
        }
    }
    return p;
}

int* copyArray(int *a, int n){
    int *p = new int[n];
    for(int i = 0; i < n; i++){
        p[i] = a[i];
    }
    return p;
}

int* countEvens(int *arr, int n, int *evens){
    for(int i = 0; i < n; i++){
        if(arr[i]%2 == 0){
            (*evens)++;
        }
    }
    return evens;
}

int* generateEvenArray(int *arr, int n, int *count){
    
}
// END TODO
#include <fstream>
int main() {

    // TODO
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int *a = nullptr;
    int n = 0;
    inputArray(a, n);
    int cnt = 0;
    int *p = countEvens(a, n, &cnt);
    cout << *p;
    // printArray(a, n);
    // printArray(a, n);
    delete []a;
    // END TODO

    return 0;
}
