#include <stdio.h>
#include <stdlib.h>

double find(int* inputn, int n, int* inputm, int m){
    int arr[n+m];
    int i=0,j=0,k=0;
    while( i < n && j < m){
        if(inputn[i] <= inputm[j]){
            arr[k] = inputn[i];
            i++;
        }else{
            arr[k] = inputm[j];
            j++;
        }
        k++;
    }
    while(i < n){
        arr[k] = inputn[i];
        i++;
        k++;
    }
    while(j < m){
        arr[k] = inputm[j];
        j++;
        k++;
    }
    
    if((n+m)%2)
        return (double)arr[(n+m)/2];
    else
        return ((double)arr[(n+m)/2]+(double)arr[(n+m)/2-1])/2;
}

int solve(void){
    int n,m;
    scanf("%d%d",&n,&m);
    int inputn[n],inputm[m];
    for(int i=0;i<n;i++)
        scanf("%d",&inputn[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&inputm[i]);
    printf("%.1f\n",find(inputn,n,inputm,m));
}

void init(void){
    int n;
    scanf("%d",&n);
    while(n--)
        solve();
}

int main(void){
    init();
    return 0;
}
