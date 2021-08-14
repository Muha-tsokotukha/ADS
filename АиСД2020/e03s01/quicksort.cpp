#include <iostream>
using namespace std;


void quickSortMiddle(int *a, int left, int right)
{
    if(left >=right) return;
    int leftI = left;
    int rightI = right;
    int pivot = a[left + (right - left)/2];
    while(leftI<=rightI)
    {
        while(a[leftI]  < pivot )leftI++;  
        while(a[rightI] > pivot )rightI--; 
        if(leftI <=rightI)
        {
            swap(a[leftI], a[rightI]);
            leftI++;
            rightI--;
        }
    }
    if(left < rightI)quickSortMiddle(a,left,rightI); 
    if(leftI < right)quickSortMiddle(a,leftI,right); 
}

int main(){
    int a[5] = {5,4,3,4,1};
    quickSortMiddle(a, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    
}