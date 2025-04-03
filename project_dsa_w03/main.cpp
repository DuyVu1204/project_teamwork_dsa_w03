#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void selectionsort(int* a, int n){
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

void bubblesort(int* a, int n){
    for (int i=1; i<n; i++)
    {
        for (int j=n-1; j>=i; j--)
        {
            if (a[j-1]>a[j])
            swap(a[j-1],a[j]);
        }
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

int main(int argc, char* argv[]){
    int* a, n;

    char* algorithm = nullptr;
    char* input_file = nullptr;
    char* output_file = nullptr;

    parse_arguments(argc, argv, algorithm, input_file, output_file);

    read_input_file(a, n, "input.txt");
    if (algorithm != nullptr && strcmp(algorithm, "selection-sort") == 0) 
    {
        selectionsort(a, n);
    } 
    else if (algorithm!=NULL && strcmp(algorithm, "bubble-sort")==0)
    {
        bubblesort(a, n);
    }
    else
    {
        cout << "Algorithm not specified or not recognized!" << endl;  
    }
    write_output_file(a, n, "output.txt");
    delete[]a;
    return 0;
}