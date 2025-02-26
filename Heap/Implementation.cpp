#include<iostream>
#include<limits.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0] = INT_MIN;
        size = 0;
    }
    
    void insert(int num){
        size = size + 1;
        int index = size;
        arr[index] = num;
        
        while(index > 1){
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else return ;
        }
    }
    
    void printHeap(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    
    void popHeap(){
        if(size == 0){
            cout<<"nothting to delete";
            return ;
        }
        
        arr[1] = arr[size];
        size--;
        
        int i=1;
        while(i<=size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            int largest = i;
            
            if(leftIndex <= size && arr[largest] < arr[leftIndex]){
                largest = leftIndex;
            }
            if(rightIndex <= size && arr[largest] < arr[rightIndex]){
                largest = rightIndex;
            }
            
            if(largest != i){
                swap(arr[largest],arr[i]);
                i = largest;
            }
            else return ;
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    
    while(size > 1){
        swap(arr[size],arr[1]);
        size--;
        
        heapify(arr,size,1);
    }
}

int main(){
    Heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.insert(8);
    h.insert(9);
    h.printHeap(); 
    
    h.popHeap();
    h.printHeap();
    
    h.popHeap();
    h.printHeap();
    
    int arr[6] = {-1,12,13,41,23,42};
    int n = 5;
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }
    
    cout<<"printing array"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    heapSort(arr,n);
    cout<<"printing sorted array"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    
    return 0;
}
