// Programmer - Ethan Bailey
// Tester - Ethan Bailey
//https://www.youtube.com/watch?v=XiuSW_mEn7g

#include <iostream>
#include <vector>

using namespace std;

int getDigit(int element, int place){
    return (element / place) % 10;
}
void radixSort(vector<int>& arr){
    for(int place = 1; place <= 100; place *= 10){
        vector<vector<int>> buckets(10);

    for (int i = 0; i < arr.size(); i++){
    int digit = getDigit(arr[i], place);
    buckets[digit].push_back(arr[i]);
}

arr.clear();

for(int i = 0; i < buckets.size(); i++){
    for(int j = 0; j < buckets[i].size(); j++){
        arr.push_back(buckets[i][j]);

         }
    }
    }
}

int main(){
    vector<int> arr = {110, 32, 79, 221, 555, 901, 343, 627};
    cout << " Orinial array: " ;
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