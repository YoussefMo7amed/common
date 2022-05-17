#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<vector<double> > > Matrix3D;

vector<double> CreateVector(Matrix3D matrix) {
    vector<double> flatten_vector;
    for (auto page : matrix) {
        for (auto row : page) {
            for (auto element : row) {
                flatten_vector.push_back(element);
            }
        }
    }

    return flatten_vector;
}

int ConvertIndex(Matrix3D matrix, int i, int j, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    int p = matrix[0][0].size();

    int y = i * (m * p) + (j * (m - 1)) + (k);

    return y;
}

double GetElement(Matrix3D matrix, int i, int j, int k) {
    int y = ConvertIndex(matrix, i, j, k);
    vector<double> v = CreateVector(matrix);

    return v[y];
}

Matrix3D readFromUser() {
    Matrix3D matrix;
    int n, m, p, x;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        vector<vector<double> > table;
        for (int j = 0; j < m; j++) {
            vector<double> row;
            for (int k = 0; k < p; k++) {
                cin >> x;
                row.push_back(x);
            }
            table.push_back(row);
        }
        matrix.push_back(table);
    }
    return matrix;
}

int main() {
    // uncomment the next line if you want to store the output in "output.txt"
    // file freopen("ouput.txt", "w", stdout);

    // The 3D Matrix.
    Matrix3D Matrix = {
        // 00
        {   
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}
        },
        // 01
        {
            {13, 14, 15},
            {16, 17, 18},
            {19, 20, 21},
            {22, 23, 24}
        }    
    };

    // Convert 3D Matrix into 1D vector.
    vector<double> flat = CreateVector(Matrix);

    int i, j, k;
    // The user enter the indexes of the element (i, j ,k)
    // then ConvertIndex() function get the position of that element in the new
    // vector (y) index.
    while (cin >> i >> j >> k) {
        if (i == -1 || j == -1 || k == -1) break;
        int index = ConvertIndex(Matrix, i, j, k);
        cout << index << ":  " << flat[index] << endl;
    }
    return 0;
}
