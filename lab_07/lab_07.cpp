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
    *evens = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]%2 == 0){
            (*evens)++;
        }
    }
    return evens;
}

int* generateEvenArray(int *arr, int n, int *count){
    int *ans = new int[*count+1];
    int p = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]%2 == 0){
            ans[p] = arr[i];
            p++;
        }
    }
    return ans;
}

int* findLargestSumSubarray(int *a, int n, int &largestSum, int &subarrayLength){
    int *p = nullptr;

    for(int i = 0; i < n; i++){
        int sum = a[i];
        for(int j = i+1; j < n; j++){
            sum+=a[j];
            if(sum > largestSum){
                subarrayLength = j-i+1;
                p = (a+i);
                largestSum = sum;
            }
        }
    }
    return p;
}

int* findLongestAscendingSubarray(int *a, int n, int &subarrayLength){
    int *p = nullptr;
    int cnt = 1, start = 0, mx = 0;
    for(int i = 1; i < n; i++){
        if(a[i]>a[i-1]){
            cnt++;
        }
        else{
            start = i;
            cnt = 1;
        }
        if(cnt > mx){
            mx = cnt;
            p = (a+start);
        }
    }
    subarrayLength = mx;
    return p;
}
void swapArrays(int *&a, int *&b, int &na, int &nb){
    int loop = (na>nb)? na:nb;
    int *aa = new int[nb];
    int *bb = new int[na];
    for(int i = 0; i < loop; i++){
        int tmp = *(a+i);
        *(aa+i) = *(b+i);
        *(bb+i) = tmp;
    }
    int tmp = na;
    na = nb;
    nb = tmp;
    a = aa;
    b = bb;
}

int* concatenateTwoArrays(int *a, int *b, int na, int nb){
    int *p = new int[na+nb];
    for(int i = 0; i < na+nb; i++){
        if(i < na) *(p+i) = *(a+i);
        else *(p+i) = *(b+ (i-na));
    }
    return p;
}

int* mergeTwoArrays(int *a, int *b, int na, int nb, int &nc){
    nc = na+nb;
    int *p = concatenateTwoArrays(a, b, na, nb);
    for(int i = 0; i < nc; i++){
        for(int j = i+1; j < nc; j++){
            if(p[i] > p[j]){
                int tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
    return p;
}

void generateRandomMatrix(int **&A, int &m, int &n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            A[i][j] = rand()%101;
        }
    }
}
// END TODO

int main() {

    // TODO
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    srand(time(NULL));
    int n, m;
    cin >> n >> m;
    int **a = new int*[n];
    for(int i = 0; i < n; i++){
        *(a+i) = new int[m];
    }
    generateRandomMatrix(a, m, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // END TODO

    return 0;
}
