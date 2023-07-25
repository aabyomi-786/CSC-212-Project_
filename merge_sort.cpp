#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Function to merge two sorted sub-arrays into one sorted array
void merge(std::vector<int>& numArray, int left, int mid, int right, int& runtime){
    // Sizes for temporary sub-arrays
    int merge1 = mid - left + 1;
    int merge2 = right - mid;
    // Temporary sub-arrays
    std::vector<int> leftArray(merge1);
    std::vector<int> rightArray(merge2);
    // Copy data to temporary sub-arrays
    for(int i = 0; i < merge1; ++i){
        leftArray[i] = numArray[left + i];
        runtime++;
    }
    for(int j = 0; j < merge2; ++j){
        rightArray[j] = numArray[mid + 1 + j];
        runtime++;
    }
    // Merge the two sub-arrays back into the main array
    int i = 0, j = 0, k = left;
    while(i < merge1 && j < merge2){
        if(leftArray[i] <= rightArray[j]){
            numArray[k] = leftArray[i];
            i++;
        } else {
            numArray[k] = rightArray[j];
            j++;
        }
        k++;
        runtime++;
    }
    // Copy remaining elements from leftArray, if any
    while(i < merge1){
        numArray[k] = leftArray[i];
        i++;
        k++;
        runtime++;
    }
    // Copy remaining elements from rightArray, if any
    while(j < merge2){
        numArray[k] = rightArray[j];
        j++;
        k++;
        runtime++;
    }
}

// Function that divides the array into halves and sorts them
void mergeSort(std::vector<int>& numArray, int left, int right, int& runtime){
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    // Sort the left and right halves
    mergeSort(numArray, left, mid, runtime);
    mergeSort(numArray, mid + 1, right, runtime);
    // Merge the sorted halves
    merge(numArray, left, mid, right, runtime);
}

int main(){
    int runtime = 0, choice;
    std::cout << "Please input 0 for file name or 1 for testing numbers through your IDE: ";
    std::cin >> choice;
    std::vector<int> numArray;
    // Input from file
    if(choice == 0){
        std::string filename;
        std::cout << "Input file name: ";
        std::cin >> filename;
        std::fstream file(filename);
        int temp;
        if(file.is_open()){
            // Store each number from the file in the vector
            while(file >> temp){
                numArray.push_back(temp);
            }
        }else{
            std::cout << "Unable to open file";
        }
        file.close();
        // Call merge sort with vector data and the starting and ending indexes
        mergeSort(numArray, 0, numArray.size() - 1, runtime);
    }else if(choice == 1){ // Manual Input
        int size, newNum;
        std::cout << "How many numbers will you test? ";
        std::cin >> size;
        std::cout << "Enter Numbers: " << std::endl;
        // Store each input number into the vector
        for(int i = 0; i < size; i++){
            std::cin >> newNum;
            numArray.push_back(newNum);
        }
        mergeSort(numArray, 0, numArray.size() - 1, runtime);
    }else{
        // Invalid input error
        std::cout << "ERROR invalid input exiting program";
        return 1;
    }
    // Print the sorted array
    for(int i = 0; i < numArray.size(); i++){
        std::cout << numArray[i] << ' ';
    }
    //Print benchmark
    std::cout << std::endl;
    std::cout << "Total Runtime: " << runtime;
    return 0;
}