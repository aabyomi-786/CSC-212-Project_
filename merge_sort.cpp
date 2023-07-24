#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

void merge(std::vector<int>& numArray, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);
    for(int i = 0; i < n1; ++i) {
        leftArray[i] = numArray[left + i];
    }
    for(int j = 0; j < n2; ++j) {
        rightArray[j] = numArray[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(leftArray[i] <= rightArray[j]){
            numArray[k] = leftArray[i];
            ++i;
        }else{
            numArray[k] = rightArray[j];
            ++j;
        }
        ++k;
    }
    while(i < n1){
        numArray[k] = leftArray[i];
        ++i;
        ++k;
    }
    while(j < n2){
        numArray[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& numArray, int left, int right){
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(numArray, left, mid);
    mergeSort(numArray, mid + 1, right);
    merge(numArray, left, mid, right);
}

int main(){
    int choice;
    std::cout << "Please input 0 for file name or 1 for testing numbers through your IDE" << std::endl;
    std::cin >> choice;
    std::vector<int> numArray;
    if(choice == 0){
        std::string filename, line;
        std::cout << "Input file name: ";
        std::cin >> filename;
        std::fstream file(filename);
        int temp;
        if(file.is_open()){
            while(file >> temp){
                numArray.push_back(temp);
            }
        }else{
            std::cout << "Unable to open file";
        }
        mergeSort(numArray, 0, numArray.size() - 1);
    }else if(choice == 1){
        int size, newNum;
        std::cout << "How many numbers will you test? ";
        std::cin >> size;
        std::cout << "Enter Numbers: " << std::endl;
        for(int i = 0; i < size; i++){
            std::cin >> newNum;
            numArray.push_back(newNum);
        }
        mergeSort(numArray, 0, numArray.size() - 1);
    }else{
        std::cout << "ERROR invalid input exiting program";
        return 1;
    }
    for(int i = 0; i < numArray.size(); i++){
        std::cout << numArray[i] << ' ';
    }
    return 0;
}