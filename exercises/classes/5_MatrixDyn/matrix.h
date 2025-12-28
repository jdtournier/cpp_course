#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
    public:
        Matrix (int rows, int columns) :
            _rows (rows), _cols (columns), _m (rows*columns) { }
        int rows () const { return _rows; }
        int cols () const { return _cols; }

        // two versions needed: one to be used
        // when object is used in a const setting,
        // the other when it is used in a modifiable
        // (non-const) context:
        const double& Coef(int i, int j) const {
            return _m[i*_cols + j];
        }
        double& Coef(int i, int j) {
            return _m[i*_cols + j];
        }

        void Display();
        Matrix Multiply (const Matrix& b);
    private:
        int _rows, _cols;
        std::vector<double> _m;
};

#endif // MATRIX_H
