#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    //Start with a large gap and reduce

    for (int gap = n/2; gap > 0; gap /= 2){

        //Insertion sort performed
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j;

            //Shift gap-sorted elements until they're in the correct index
            for (j = i; j >= gap && arr[ j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }

            //Place current element in correct index
            arr[j] = temp;
        }
    }
}

int main() {
    std::cout << "Enter number of elements:";
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter elements:\n";
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    std::cout << "Elements entered:";
    for (int num : arr){
        std::cout << num << " ";
    }

    shellSort(arr);

    std::cout << "\nElements after Shell Sort:";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}