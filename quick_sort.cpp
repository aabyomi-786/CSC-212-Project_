#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Function to partition the array into two parts based on the pivot
int partition(std::vector<int>& numArray, int low, int high, int& runtime){
    // Last element and current index variables
    int pivot = numArray[high], currentIndex = low - 1;
    // Loop through the array and check ff the current element is less than or equal to the pivot
    for(int j = low; j < high; j++){
        if(numArray[j] <= pivot){
            // Swap the elements at currentIndex and j if true
            currentIndex++;
            std::swap(numArray[currentIndex], numArray[j]);
        }
        runtime++;
    }
    // Swap the pivot (last element) to its correct position
    std::swap(numArray[currentIndex + 1], numArray[high]);
    runtime++;
    // Return the index of the pivot's final position
    return currentIndex + 1;
}

// Function to perform Quick Sort on the array recursively
void quickSort(std::vector<int>& numArray, int low, int high, int& runtime){
    if(low < high){
        // Partition the array into two sub-arrays and get the pivot's index
        int partitionIndex = partition(numArray, low, high, runtime);
        // Recursively perform Quick Sort on the left and right sub-arrays respectively
        quickSort(numArray, low, partitionIndex - 1, runtime);
        quickSort(numArray, partitionIndex + 1, high, runtime);
    }
}

int main(){
    int choice, runtime = 0;
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
        // Call quick sort with vector data and the starting and ending indexes
        quickSort(numArray, 0, numArray.size() - 1, runtime);
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
        // Sort the array using Quick Sort algorithm
        quickSort(numArray, 0, numArray.size() - 1, runtime);
    }else{
        // Invalid Input error
        std::cout << "ERROR invalid input exiting program";
        return 1;
    }

    // Print the sorted array
    for(int i = 0; i < numArray.size(); i++){
        std::cout << numArray[i] << ' ';
    }
    //Print Benchmark
    std::cout << std::endl;
    std::cout << "Total Runtime: " << runtime;
    return 0;
}
