#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[100000];
int temp[100000];
 void merge(int a[],int low,int mid,int high){

    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=mid) temp[k++]=a[i++];
    while(j<=high) temp[k++]=a[j++];
    for(int z=low;z<=high;z++) a[z]=temp[z];
 }
 void mergesort(int a[], int low, int high)
{
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
 int main(){
    int n;
    srand(time(0));
    printf("enter total number of elemnts:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a[i]=rand()%(n+1);
    }
    clock_t start,end;
    double timetaken;
    start=clock();
    mergesort(a,0,n-1);
    printf("the sorted array is:");
    end=clock();
    timetaken=(double)(end-start)*1000.0/CLOCKS_PER_SEC;

    for(int i=0;i<5;i++){
        printf("%d  ",a[i]);
    }
    printf("\nThe time taken is: %f ms",timetaken);

    return 0;
 }
