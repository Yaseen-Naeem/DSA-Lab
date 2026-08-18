#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Copy assignment operator
    Matrix& operator=(const Matrix& other) {

        if (this != &other) {

            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }

            delete[] data;

            rows = other.rows;
            cols = other.cols;

            data = new int*[rows];

            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];

                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }

        delete[] data;
    }

    void set(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        }
    }

    int get(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }

        return 0;
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Addition operator
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }
};

int main() {

    Matrix m1(2, 2);
    Matrix m2(2, 2);

    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);

    cout << "Matrix 1:" << endl;
    m1.display();

    cout << "\nMatrix 2:" << endl;
    m2.display();

    Matrix m3 = m1 + m2;

    cout << "\nMatrix 1 + Matrix 2:" << endl;
    m3.display();

    Matrix m4 = m1;

    Matrix m5(2, 2);
    m5 = m1;

    m1.set(0, 0, 100);

    cout << "\nAfter changing Matrix 1:" << endl;

    cout << "\nMatrix 1:" << endl;
    m1.display();

    cout << "\nCopy constructed Matrix:" << endl;
    m4.display();

    cout << "\nCopy assigned Matrix:" << endl;
    m5.display();

    return 0;
}