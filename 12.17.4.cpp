/**
      Project id: Group Project C 
      Project Name: Group 3
      Problem: 12.17.4
      Programmer: [Ethan Bailey]
      Date: October 23, 2024
      Version: 1.1  
      Description: This code conducts radix sort
      Radix sort is a sorting that sorts the places
      in order so first it will do the 1's place and
      sort that then go on to the 10's place and the 
      100's place to sort the array
*/

//https://www.youtube.com/watch?v=XiuSW_mEn7g

#include <iostream>
#include <vector>

using namespace std;

// Function to get the digit in a specific place
int getDigit(int element, int place){
    return (element / place) % 10;
}

void radixSort(vector<int>& arr){
    // Goes through each place value
    for(int place = 1; place <= 100; place *= 10){
        vector<vector<int>> buckets(10); // creates 10 bucks 0-9 for each digit
    // Places each number into the appropriate bucket
    for (int i = 0; i < arr.size(); i++){
    int digit = getDigit(arr[i], place);
    buckets[digit].push_back(arr[i]);
}

arr.clear(); // clears original array for next iteration
// Puts the numbers back into the array in order
for(int i = 0; i < buckets.size(); i++){
    for(int j = 0; j < buckets[i].size(); j++){
        arr.push_back(buckets[i][j]);

         }
    }
    }
}

int main(){
    vector<int> arr = {110, 32, 79, 221, 555, 901, 343, 627};
    cout << "Orinial array: " ;
    for(int i = 0; i  < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    radixSort(arr);

    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
   cout << endl;
   return 0;
}
