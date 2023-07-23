#include <iostream>
using namespace std;

//Function to perfom Insertion Sort
void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int key = arr[i]; //current element to be inserted at its correct position
        int j = i - 1;

        //shift elements greated than the key to the right
        //untill a smaller element is found or the beginning of the array is reached
        while(j >= 0 and arr[j] > key){
            arr[j + 1] = arr[j]; //Move the element one position to the right
            j--;

        }

        arr[j + 1] = key; //Place the key in its correct sorted position

    }
}

int main(){
    int size;
    cout<< "Enter the number of elements: ";
    cin >>size;

    int* arr = new int[size]; //Dynamically allocate memory for the array

    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i]; // input each element from the user
    }

    cout <<"Unsorted Array: ";
    for (int i = 0; i <size; i++){
        cout << arr[i] << " "; //Print each element of the array
    }
    cout << endl;

    insertionSort(arr, size); //Call the Insertion Sort function

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] <<" "; //Print each element of the sorted array

    }
    cout<< endl;


    return 0;

}
