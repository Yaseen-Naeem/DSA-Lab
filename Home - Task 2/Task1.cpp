#include <iostream>
using namespace std;

class SafeMatrix
{
public:
    int rows;
    int cols;
    int** mat;

    SafeMatrix(int r, int c){
        rows = r;
        cols = c;

     mat = new int*[rows];

        for(int i = 0; i < rows; i++){
         mat[i] = new int[cols];
        }
    }

    void set(int r, int c, int val){
        if(r < 0 || r >= rows || c < 0 || c >= cols){
            cout << "Boundary Error!" << endl;
            return;
        }

     mat[r][c] = val;
    }

    int get(int r, int c){
        if(r < 0 || r >= rows || c < 0 || c >= cols){
            cout << "Boundary Error!" << endl;
            return -1;
        }

        return mat[r][c];
    }

    void display(){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~SafeMatrix(){
        for(int i = 0; i < rows; i++){
            delete[] mat[i];
        }

        delete[] mat;
    }
};

int main(){
    SafeMatrix m(4, 4);

    // Filling Matrix
    int value = 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m.set(i, j, value);
            value++;
        }
    }

    cout << "Matrix:" << endl;
    m.display();

    cout << "\nInvalid accesses:" << endl;

    m.set(-1, 2, 50);       

    cout << m.get(1, 10) << endl;  

    m.set(4, 2, 100);       

    return 0;
}