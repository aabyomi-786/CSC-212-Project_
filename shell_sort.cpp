#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//Function to perform Shell Sort
void shellSort(std::vector<int>&numArray, int& runtime){
    int n = numArray.size();

    //Start with a large gap and reduce it
    for (int gap = n/2; gap > 0; gap /= 2){
        //Perform insertion sort on elements separated by 'gap'
        for (int i = gap; i < n; ++i){
            int temp = numArray[i];
            int j;

            //Shift earlier gap-sorted elements until the correct position is located
            for (j = i; j >= gap && numArray[j-gap] > temp; j -= gap) {
                numArray[j] = numArray[j - gap];
                runtime++; //Counts the number of elements
            }

            //Place current element in correct location
            numArray[j] = temp;
            runtime++; //Counts the number of elements
        }
    }
}

int main() {
    int input, runtime = 0;
    std::cout << "Shell Sort: Enter 0 for filename or 1 for IDE: ";
    std::cin >> input;
    std::vector<int> numArray;

    //File Input
    if(input == 0){
        std::string fname;
        std::cout << "Enter filename: ";
        std::cin >> fname;
        std::fstream file(fname);
        int temp;
        if(file.is_open()){
            //Store numbers from file in vector
            while(file >> temp){
                numArray.push_back(temp);
            }
        } else {
            std::cout << "Unable to open";
            return 1;
        }
        file.close();

        //Call shell sort through vector data
        shellSort(numArray, runtime);
    } else if(input == 1){
        int num1, num2;
        std::cout << "How many numbers will you test? ";
        std::cin >> num1;
        std::cout << "Enter numbers: " << std::endl;

        //Store numbers into vector
        for(int i = 0; i < num1; i++){
            std::cin >> num2;
            numArray.push_back(num2);
        }
        //Sort array using Shell Sort
        shellSort(numArray, runtime);
    } else {
        //Invalid input error
        std::cout << "ERROR";
        return 1;
    }

    //Print sorted array
    std::cout << "Sorted Array: ";
    for (int i = 0; i < numArray.size(); i++){
        std::cout << numArray[i] << ' ';
    }

    //Benchmark
    std::cout << "\nTotal Runtime: " << runtime << " comparisions" << std::endl;

}
        std::cout << num << " ";
    }

    return 0;
}
