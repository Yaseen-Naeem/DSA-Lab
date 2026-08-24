#include <iostream>
using namespace std;

int main(){
    int rows = 3;
    int size[rows];

    int** arr = new int*[rows];
    for(int i =0; i<rows; i++){
        cout << "Enter Size Of Row " << i+1 << ":" << endl;
        cin >> size[i];
        arr[i] = new int[size[i]];
    }

    for(int i =0; i<rows; i++){
        cout << "Enter " << size[i] << " Elements for row " << i+1 << ": " << endl;
        for(int j=0; j<size[i]; j++){
            cin >> arr[i][j];
        }
        cout << endl;
    }

    cout << "\nJagged Array Elements: " << endl;
    for(int i =0; i<rows; i++){
        cout << "Row " << i+1 << ": ";
        for(int j =0; j<size[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int sum;
    float avg;

    for(int i =0; i<rows; i++){
        sum = avg = 0;
        cout << "Sum And Average Of Row " << i+1 << ": " << endl;;
        for(int j=0; j<size[i]; j++){
            sum += arr[i][j];
        }
        avg = sum / size[i];
        cout << "SUM: " << sum << "\nAVERAGE: " << avg << endl << endl;;
    }

    // Find row with most and fewest elements
    int most = 0;
    int fewest = 0;

    for(int i = 1; i < rows; i++)
    {
        if(size[i] > size[most])
        {
            most = i;
        }

        if(size[i] < size[fewest])
        {
            fewest = i;
        }
    }

    cout << "\nRow with most elements: Row " << most + 1;
    cout << " (" << size[most] << " elements)" << endl;

    cout << "Row with fewest elements: Row " << fewest + 1;
    cout << " (" << size[fewest] << " elements)" << endl;


    for(int i=0; i<rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}