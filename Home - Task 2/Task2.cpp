#include <iostream>
using namespace std;

void insertMark(int** arr, int* size, int row, int mark){
    int oldSize = size[row];
    int* newRow = new int[oldSize + 1];

    for(int i = 0; i < oldSize; i++){
        newRow[i] = arr[row][i];
    }

    newRow[oldSize] = mark;

    delete[] arr[row];
    arr[row] = newRow;
    size[row]++;

    cout << "\nUpdated Marks: ";

    for(int i = 0; i < size[row]; i++){
        cout << arr[row][i] << " ";
    }
}


int main(){
    int nums;
    cout << "Enter Number Of Students: " << endl;
    cin >> nums;

    int rows = nums;
    int marks;
    int size[rows];

    int** arr = new int*[rows];
    for(int i =0; i< rows; i++){
        cout << "Enter Number Of Courses For Student " << i+1 << ":" << endl;
        cin >> size[i];
        arr[i] = new int[size[i]];
    }

    int sum[rows] = {0};
    float avg[rows] = {0.0};

    for(int i=0; i<rows; i++){
        for(int j=0; j<size[i]; j++){
            cout << "Enter Marks " << j+1 << " For Student " << i+1 << ":" << endl;
            cin >> arr[i][j];
            sum[i]+=arr[i][j];
            }
    }

    cout << "\nStudents' Details: " << endl;
    
    cout << "Number Of Students : " << nums << endl;

    for(int i =0; i<rows; i++){
        cout << "Student " << i+1 << " - " << " Courses " << size[i] << " -> " << " Marks: ";
        for(int j=0; j<size[i]; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i<rows; i++){
        avg[i] = (float)sum[i] / size[i];

        cout << "Student " << i+1 << "  Average: " << avg[i] << endl;
    }

    float max = avg[0];
    float min = avg[0];

    int maxstudent = 0;
    int minstudent = 0;

    for(int i = 1; i < rows; i++)
    {
        if(avg[i] > max)
        {
            max = avg[i];
            maxstudent = i;
        }

        if(avg[i] < min)
        {
            min = avg[i];
            minstudent = i;
        }
    }

    cout << "\nHighest Average: Student " << maxstudent + 1 << " | " << max << endl;
    cout << "Lowest Average: Student " << minstudent + 1 << " | " << min << endl;


    int row;
    int mark;

    cout << "\nEnter student number to add a course: ";
    cin >> row;

    cout << "Enter new mark: ";
    cin >> mark;

    insertMark(arr, size, row - 1, mark);

    return 0;
}