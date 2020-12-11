//
//  main.cpp
//  inversec
//
//  Created by Colton Shepherd on 10/3/20.
//  Copyright © 2020 Colton Shepherd. All rights reserved.
//

#include <iostream>
using namespace std;

int determinant(int *, int, int);
int *cofactors(int *, int, int);
int *negative(int *, int, int);
int *flip(int *, int, int);
double *inverse(int *, int, int);
int *matmult(int *, int *, int, int, int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int *ptr = nullptr;
    int rows, cols, addup = 0;
    cout << "what is the dimension nxn dimension, only input rows. \n";
    cin >> rows;
    cols = rows;
    int arr[rows*cols];
    double *doubleptr = nullptr;
    
//    input the entries of the desired matrix.
    cout << " now input entries of the matrix. \n ";
    for (int first=0; first < rows; first++) {
        cout << " input row " << first+1 << endl;
        for (int second = 0; second < cols; second++) {
            cout << "input your value. \n";
            cin >> arr[addup];
            addup++;
        }
    }
    
    cout << "input matrix \n";
    
//    reads out the input matrix.
    for (int s = 0; s < rows*cols; s++) {
        if (!(s%rows)) {
            cout << endl;
        }
        cout << arr[s] << "  ";
    }
    
    cout << endl;
//    reads out the determinant of the input matrix.
    int det = determinant(arr, rows, cols);
    
    if (!det) {
        cout << "determinant zero so won't have an inverse" << endl;
        return 0;
    }
    doubleptr = inverse(ptr, rows, cols);

    
    return 0;
}

// start of determinant function *****************
//############################################################
int determinant(int *array, int rows, int cols) {
    
    int nums = 0, rev, sum_minors = 0;
    int newarr[(rows-1)*(cols-1)];
    
    if (rows == 1) {
        return array[0];
    }
    else if (rows == 2) {
        sum_minors = array[0]*array[3] - array[1]*array[2];
        return sum_minors;
    }
    
    else {
        for (int index = 0; index < rows; index++) {
            int addup = 0;
            for (int value = 0; value < rows; value++) {
                for (int val = 0; val < cols; val++) {
                    if (value != index && val != 0) {

                        newarr[addup] = array[(value*rows)+val];
                        addup++;
                    }
                    
                }
            }
            if (index % 2) {
                               rev = -1;
                           }
                           else {
                               rev = 1;
                           }
            int current_value = array[index*cols];
            nums = determinant(newarr, rows-1, cols-1);
            sum_minors += (nums*current_value*rev);
        }
    }

    return sum_minors;
    
}

//creates the minors matrix
int *cofactors(int *array, int rows, int cols) {
    
    int *newarrptr = new int[(rows-1)*(cols-1)], *cofarray = new int[(rows)*(cols)] ;
    
    
    for (int index = 0; index < rows; index++) {
        for (int columns = 0; columns < cols; columns++) {
            int addup = 0;
            for (int value = 0; value < rows; value++) {
                for (int val = 0; val < cols; val++) {
                    if (value != index && val != columns) {
                        newarrptr[addup] = array[(value*rows)+val];
                        addup++;
                    }
                }
            }
            cofarray[(index*rows)+columns] = determinant(newarrptr, rows-1, cols-1);
        }
    }
    return cofarray;
}
//makes checkerboard of negatives for creating cofactors matrix.
int *negative(int *arr, int rows, int cols) {
    
    
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            if (!(j%2) ) {
                
                if (i%2) {
                    arr[j*rows+i] *= -1;
                }
                
            }
            else if (j%2 ){
                if (!(i%2)) {
                    arr[j*rows+i] *= -1;
                }
                
            }
        }
    }
    return arr;
}


//reflects the numbers across the diagonal.
int *flip(int *arr, int rows, int cols) {
    int *poitr = new int[rows*cols];
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            poitr[i*rows+j] = arr[j*rows+i];
        }
    }
    for (int k = 0; k < rows*cols; k++) {
        arr[k] = poitr[k];
    }
    delete [] poitr;
    poitr = nullptr;
    return arr;
}

//puts together the other functions and divides by the determinant to get the
//inverse matrix.
double *inverse(int * arr, int rows, int cols) {
    
    int *ptr = nullptr;
    double *doubleptr = nullptr;
    int det = determinant(arr, rows, cols);
        
        if (!det) {
            cout << "determinant zero so won't have an inverse" << endl;
            return 0;
        }
        
    //    cout << "determinant is " << det << endl;
    //    cout << endl;
        ptr = cofactors(arr, rows, cols);
        ptr = negative(ptr, rows, cols);
        ptr = flip(ptr, rows, cols);

        
        doubleptr = new double(rows*cols);
        
        for (int deter = 0; deter < rows*cols; deter++) {
            doubleptr[deter] = double(ptr[deter]) / det;
        }
    return doubleptr;
}


int *matmult(int *array1, int *array2, int rows1, int cols1, int rows2, int cols2) {
    int *multarray = nullptr;
    
    for (int j = 0; j < rows1; j++) {
        <#statements#>
    }
    
    return multarray;
}
