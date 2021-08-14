#include <iostream>
using namespace std;



int findK(int *a, int left, int right, int k)
{
    if(left >=right) return a[k-1] ; // l == k, r == k+1
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
    if(left < rightI)findK(a,left,rightI,k); 
    else findK(a,leftI,right, k); 
}

int main(){
    int a[10] = {5,4,3,4,1,8,2,5,9,10};
    cout << findK(a, 0, 10, 7);
    
    
}