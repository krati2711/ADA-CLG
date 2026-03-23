#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a[100000];
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high+1;
    do{
        do{
            i++;
        }while(i<=high && a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
    }
    }while(i<j);
    int temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int a[],int low,int high)
{
    if(low<high){
        int j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    srand(time(0));
    clock_t start,end;
    double timetaken;
    int n;
    printf("enter no of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a[i]=rand()%(n+1);
    }
    start=clock();
    quicksort(a,0,n-1);
    end=clock();
    printf("the sorted array is: ");
    for(int j=0;j<6;j++){
        printf("%d  ",a[j]);
    }
    timetaken=(double)(end-start)*1000.0/CLOCKS_PER_SEC;
    printf("teh time taken is %f",timetaken);
    return 0;
}
