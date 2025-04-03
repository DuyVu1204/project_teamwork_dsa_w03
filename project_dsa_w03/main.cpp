#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


void heapify(int* a, int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<n && a[left]>a[max])
    {
        max = left;
    }
    if (right<n && a[right]>a[max])
    {
        max = right;
    }
    if (max != i)
    {
        swap(a[i], a[max]);
        heapify(a, n, max);
    }

}
void heapSort(int* a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void insertionSort(int* a, int n) {
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int* a, int n){
    for (int i=0; i<n-1; i++)
    {
        int min=i;
        for (int j=i+1; j<n; j++)
        {
            if (a[j]<a[min])
            min=j;
        }
        swap(a[i], a[min]);
    }
}

void bubbleSort(int* a, int n){
    for (int i=1; i<n; i++)
    {
        for (int j=n-1; j>=i; j--)
        {
            if (a[j-1]>a[j])
            swap(a[j-1],a[j]);
        }
    }
}
void merge(int* a, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int* temp = new int[right - left + 1];

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {  
        temp[k++] = a[j++];
    }

    for (int x = 0; x < k; x++) {
        a[left + x] = temp[x];
    }

    delete[] temp;
}
void mergeSort(int* a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int partition(int arr[], int left, int right) {
    int randomIndex = left + rand() % (right - left + 1);
    swap(arr[randomIndex], arr[right]); 
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); 
    return i + 1;
}
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right); 

        quickSort(arr, left, pi - 1); 
        quickSort(arr, pi + 1, right);
    }
}
void read_input_file(int* &a, int &n,const char *name){
    FILE* f;
    fopen_s(&f, name, "r");
    if (f!=NULL)
    {
        fscanf_s(f, "%d", &n);
        a=new int[n];
        for (int i=0; i<n; i++)
        fscanf_s(f,"%d", &a[i]);
    }
    else
    {
        cout<<"Not open file input.txt\n";
    }
    fclose(f);
}

void write_output_file(int* a, int n,const char* name){
    FILE* f;
    fopen_s(&f, name, "w");
    if (f!=NULL)
    {
        fprintf(f,"%d\n", n);
        for (int i=0; i<n; i++)
        fprintf(f,"%d ", a[i]);
    }
    else
    {
        cout<<"Not open file output.txt"<<endl;
    }
    fclose(f);
}

void parse_arguments(int argc, char* argv[], char*& algorithm, char*& input_file, char*& output_file) {
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];

        if (strcmp(arg, "-a") == 0 && i + 1 < argc) {
            algorithm = argv[++i];
        } else if (strcmp(arg, "-i") == 0 && i + 1 < argc) {
            input_file = argv[++i];
        } else if (strcmp(arg, "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        }
    }
}

void shakerSort(int* a, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        right--;

        for (int i = right; i > left; i--) {    
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }
        }
        left++;
    }
}

void shellSort(int* a, int n){
    int i, j, interval, temp;
    for (interval=n/2; interval>0; interval/=2)
    {
        for (i=interval; i<n; i++)
        {
            temp=a[i];
            for (j=i; j>=interval && a[j-interval]>temp; j-=interval)
            {
                a[j]=a[j-interval];
            }
            a[j]=temp;
        }
    }
}

int getmax(int* a, int n){
    return *max_element(a, a+n);
}

void countingsort_radix(int* a, int n, int exp){
    int* output; 
    output=new int[n];
    int count[10]={0};
    for (int i=0; i<n; i++)
    count[(a[i]/exp)%10]++;
    for (int i=1; i<10; i++)
    count[i]+=count[i-1];
    for (int i=n-1; i>=0; i--)
    {
        int digit=(a[i]/exp)%10;
        output[count[digit]-1]=a[i];
        count[digit]--;
    }
    for (int i=0; i<n; i++)
    a[i]=output[i];
    delete[]output;
}

void radixSort(int* a, int n){
    int maxNum=getmax(a,n);
    for (int exp=1; maxNum/exp>0; exp*=10)
    countingsort_radix(a, n, exp);
}

void countingSort(int* a, int n){
    int maxArr=getmax(a, n);
    int* count=new int[maxArr+1]();
    for (int i=0; i<n; i++)
    count[a[i]]++;
    for (int i=1; i<=maxArr; i++)
    count[i]+=count[i-1];
    int* output=new int[n];
    for (int i=n-1; i>=0; i--)
    {
        output[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    for (int i=0; i<n; i++)
    a[i]=output[i];
    delete[]count;
    delete[]output;
}

int main(int argc, char* argv[]){
    int* a, n;

    char* algorithm = nullptr;
    char* input_file = nullptr;
    char* output_file = nullptr;

    parse_arguments(argc, argv, algorithm, input_file, output_file);

    read_input_file(a, n, "input.txt");
    if (algorithm != NULL && strcmp(algorithm, "selection-sort") == 0) 
    {
        selectionSort(a, n);
    } 
        else if (algorithm!=NULL && strcmp(algorithm, "bubble-sort")==0)
    {
        bubbleSort(a, n);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "shell-sort")==0)
    {
        shellSort(a, n);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "shaker-sort")==0)
    {
        shakerSort(a, n);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "insertion-sort")==0)
    {
        insertionSort(a, n);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "heap-sort")==0)
    {
        heapSort(a, n);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "merge-sort")==0)
    {
        mergeSort(a,0, n-1);
    }
        else if (algorithm!=NULL && strcmp(algorithm, "quick-sort")==0)
    {
        quickSort(a,0, n-1);
    }   
        else if (algorithm!=NULL && strcmp(algorithm, "radix-sort")==0)
    {
        radixSort(a, n);
    }   
        else if (algorithm!=NULL && strcmp(algorithm, "counting-sort")==0)
    {
        countingSort(a, n);
    }   
    else
    {
        cout << "Algorithm not specified or not recognized!" << endl;  
    }
    write_output_file(a, n, "output.txt");
    delete[]a;
    return 0;
}
