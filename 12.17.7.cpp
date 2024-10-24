/**
      Project id: Group Project C 
      Project Name: Group 3
      Programmer: [Ethan Bailey]
      Date: October 23, 2024
      Version: 1.1  
      Description: The code conducts merge sort
      instad of it being recursive it become iterative
*/


#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void merge(int *array, int l, int m, int r) {   
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      } else {
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {
      array[k] = rarr[j];
      j++; k++;
   }
}

/* the orignial mergeSort function was making the sorting recursive so do to that we have to change this function to make it iterative
we can do this by instead cutting the original array in half we treat each subarray as size of 1 after putting them all in the size of 
1 and merge them so it will be like 21 and 19 and merge it to 19 and 20 it will then go to the size of 2 then merge then after they merge 
it will move to the next subarray and merge and keep going until they are all merge then it will go to the size of 2 and merge them and so on */
void mergeSort(int *array, int n) {
   int curr_size; // 
    int left_start;

   //This makes it so that the array size starts at 1 and merges subarrays that are divisible by 2.
    for (curr_size = 1; curr_size <= n - 1; curr_size *= 2){

      // picks a starting point for the arrays based on the current size
      for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size){
         // finds the middle point and the end point of the subarrays 
         int mid = min(left_start + curr_size - 1, n-1);

         int right_end = min(left_start + 2 * curr_size - 1, n-1);
         
         // merges the two subarrays 
         merge(array, left_start, mid, right_end);
      }
    }
}

int main(){
   int array[] = {23, 45, 19, 2, 80, 37, 15, 91};
   int n = sizeof(array) / sizeof(array[0]);

   cout << "Original array: ";
   for (int i = 0; i < n; i++)
      cout << array[i] << " "; 
      cout << endl;

mergeSort(array, n);

   cout << "Sorted array: ";
   for (int i= 0; i < n; i++)
      cout << array[i] << " ";
      cout << endl;

return 0;
}

