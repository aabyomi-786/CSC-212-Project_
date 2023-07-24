#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

int partition(std::vector<int>& numArray, int low, int high) {
    int pivot = numArray[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (numArray[j] <= pivot) {
            i++;
            std::swap(numArray[i], numArray[j]);
        }
    }
    std::swap(numArray[i + 1], numArray[high]);
    return i + 1;
}

void quickSort(std::vector<int>& numArray, int low, int high) {
    if (low < high) {
        int pi = partition(numArray, low, high);
        quickSort(numArray, low, pi - 1);
        quickSort(numArray, pi + 1, high);
    }
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
        quickSort(numArray, 0, numArray.size() - 1);
    }else if(choice == 1){
        int size, newNum;
        std::cout << "How many numbers will you test? ";
        std::cin >> size;
        std::cout << "Enter Numbers: " << std::endl;
        for(int i = 0; i < size; i++){
            std::cin >> newNum;
            numArray.push_back(newNum);
        }
        quickSort(numArray, 0, numArray.size() - 1);
    }else{
        std::cout << "ERROR invalid input exiting program";
        return 1;
    }
    for(int i = 0; i < numArray.size(); i++){
        std::cout << numArray[i] << ' ';
    }
    return 0;
}