#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Matrix;
class Vector;
#ifndef VECTOR_H
#define VECTOR_H
class Matrix {
public:    
    double m[3][3];   
    Matrix();
    Matrix(double k);
    Matrix(double m[3][3]);
    friend std::ostream& operator<<(std::ostream &out, Matrix &matrix);
    friend std::istream& operator>>(std::istream &in, Matrix &matrix);
    Matrix operator+(const Matrix &matrix);
    Matrix operator-(const Matrix &matrix);
    Matrix operator*(const Matrix &matrix);
    Vector operator*(Vector &vec);
    friend class Vector;
};
class Vector {
public:
    double x, y, z;
    Vector();
    Vector(double x_, double y_, double z_); 
    friend std::ostream& operator<<(std::ostream &out, const Vector &vec);
    friend std::istream& operator>>(std::istream &in, const Vector &vec);
    Vector operator+(const Vector &vec);
	Vector operator-(const Vector &vec);
    Vector operator*(const Vector &vec);
    Vector operator/(double k);
    Vector operator*(double k);
    double operator[](char letter);
    friend Matrix operator*(const Vector &vec);
    double operator[](int index);
}; 
#endif
Vector Matrix::operator*(Vector &vec) {
    Vector result;
    double res[3];
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            res[i] += m[i][j] * vec.operator[](j);            
        }
    }
    result.x = res[0];
    result.y = res[1];
    result.z = res[2];
    return result;
}
Matrix Matrix::operator+(const Matrix &matrix) {
    Matrix matrix_;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            matrix_.m[i][j] = m[i][j] + matrix.m[i][j];
        }
    }
    return matrix_;
}
Matrix Matrix::operator*(const Matrix &matrix) {
    Matrix matrix_;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            matrix_.m[i][j] = 0;
            for(int k = 0; k < 3; ++k) {
                matrix_.m[i][j] += m[i][k] * matrix.m[k][j];
            }
        }
    }
    return matrix_;
}

Matrix Matrix::operator-(const Matrix &matrix) {
    Matrix matrix_;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            matrix_.m[i][j] = m[i][j] - matrix.m[i][j];
        }
    }
    return matrix_;
}
Matrix::Matrix(double k) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == j) {
                m[i][j] = 1 * k;
            }
            else {
                m[i][j] = 0;
            }
            cout << setw(5) << m[i][j];
        }
        cout << "\n";
    }
}
Matrix::Matrix() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == j) {
                m[i][j] = 1;
            }
            else {
                m[i][j] = 0;
            }
        }
    }
}
Matrix::Matrix(double m[3][3]) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> m[i][j];
        }
    }    
}
std::ostream& operator<<(std::ostream &out, Matrix &matrix) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            out << setw(5) << matrix.m[i][j];
        }
        out << "\n";
    }
    return out;
}
std::istream& operator>>(std::istream &in, Matrix &matrix) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            in >> matrix.m[i][j];
        }
    }
    return in;
}
double Vector::operator[](int index) {
    if(index >=3 || index < 0) {
        cout << "Error: incorrect index\n";
        throw 0;
    }
    if(index == 0) {
        return x;
    } 
    if(index == 1) {
        return y;
    }
    if(index == 2) {
        return 
        z;
    }          
}
Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}
Vector::Vector(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}
Vector Vector::operator+(const Vector &vec) {
    return Vector(x + vec.x, y + vec.y, z + vec.z);
}
Vector Vector::operator-(const Vector &vec) {
    return Vector(x - vec.x, y - vec.y, z - vec.z);
}

Vector Vector::operator*(const Vector &vec) {
	Vector res;
    res.x = y * vec.z - z * vec.y;
    res.y = z * vec.x - x * vec.z;
    res.z = x * vec.y - y * vec.x;
    return res;
}
Vector Vector::operator*(double k) {
	return Vector(x * k, y * k, z * k);
}
Vector Vector::operator/(double k) {
    if (k > 0) {
        return Vector(x / k, y / k, z / k);
    }
    else 
        return Vector();
}
std::ostream& operator<<(std::ostream &out, const Vector &vec) {
    out << "(" << vec.x << "; " << vec.y << "; " << vec.z << ")" << endl;
    return out;
}
std::istream& operator>>(std::istream &in, Vector &vec) {
    in >> vec.x;
    in >> vec.y;
    in >> vec.z;
    return in;
}
double Vector::operator[](char letter) {
    if(letter != 'x' && letter != 'y' && letter != 'z') {
        cout << "Error: incorrect index\n";
        throw 0;
    }
    if(letter == 'x') {
        return x;
    } 
    if(letter == 'y') {
        return y;
    }
    if(letter == 'z') {
        return z;
    }             
}