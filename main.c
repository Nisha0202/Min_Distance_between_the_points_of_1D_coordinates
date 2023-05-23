#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {


  int n1 = mid - low + 1;
  int n2 = high - mid;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[low + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[mid + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = low;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  //When we run out of elements in either L or M, pick up the remaining elements and put in 
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int a[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int findDiff( int a[], int n){
    int m;
    int min = a[1] - a[0];
    for(int i = 1; i <=n; i++){
        m = a[i + 1] - a[i];
        if (m < min){
            min = m;
        }
        
    }
    return min;
}
//5
//7 10 9 -5 5



// Driver program
int main() {
  int len;
    scanf("%d",&len); //taking input

  int arr[len];

for(int i=0;i<len;i++){
    scanf("%d",&arr[i]);}

  mergeSort(arr, 0, len - 1);

  //printf("Sorted array: \n");
 // printArray(arr, len);
  
  int min = findDiff(arr, len);
  printf("%d", min);
 
}