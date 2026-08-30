#include <iostream>
using namespace std;

void display(int** arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Add(int** A, int** B, int rows, int cols){
    int** result = new int*[rows];

    for(int i = 0; i < rows; i++){
        result[i] = new int[cols];

        for(int j = 0; j < cols; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nAddition Result:\n";
    display(result, rows, cols);

    for(int i = 0; i < rows; i++){
        delete[] result[i];
    }
    delete[] result;
}


void Multiply(int** A, int** B, int rows1, int cols1, int cols2){
    int** result = new int*[rows1];

    for(int i = 0; i < rows1; i++){
        result[i] = new int[cols2];

        for(int j = 0; j < cols2; j++){
            result[i][j] = 0;

            for(int k = 0; k < cols1; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMultiplication Result:\n";
    display(result, rows1, cols2);


    for(int i = 0; i < rows1; i++){
        delete[] result[i];
    }
    delete[] result;
}


int main(){
    int rows1, cols1;
    int rows2, cols2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rows1 >> cols1;

    int** A = new int*[rows1];

    for(int i = 0; i < rows1; i++){
        A[i] = new int[cols1];

        cout << "Enter elements of row " << i + 1 << ": ";

        for(int j = 0; j < cols1; j++){
            cin >> A[i][j];
        }
    }

    cout << "\nEnter rows and columns of Matrix B: ";
    cin >> rows2 >> cols2;

    int** B = new int*[rows2];

    for(int i = 0; i < rows2; i++;){
        B[i] = new int[cols2];

        cout << "Enter elements of row " << i + 1 << ": ";

        for(int j = 0; j < cols2; j++){
            cin >> B[i][j];
        }
    }

    int choice = 0;

    while(choice != 3){
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add" << endl;
        cout << "2. Multiply" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;


        if(choice == 1){
            if(rows1 != rows2 || cols1 != cols2){
                cout << "Addition not possible! Dimensions do not match." << endl;
            }
            else{
                Add(A, B, rows1, cols1);
            }
        }

        else if(choice == 2){
            if(cols1 != rows2){
                cout << "Multiplication not possible!" << endl;
            }
            else{
                Multiply(A, B, rows1, cols1, cols2);
            }
        }


        else if(choice == 3){
            cout << "Exiting..." << endl;
        }
        else{
            cout << "Invalid choice!" << endl;
        }
    }


    for(int i = 0; i < rows1; i++){
        delete[] A[i];
    }


    delete[] A;
    for(int i = 0; i < rows2; i++){
        delete[] B[i];
    }
    delete[] B;

    return 0;
}