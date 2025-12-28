#ifndef POINT_H
#define POINT_H

class Point {
private:
    float _x, _y;
public:
    Point() {_x = _y = 0;}                                // constructor
    Point(float x, float y) {_x = x; _y = y;}             // constructor
    Point(const Point& p) {_x = p.GetX(); _y = p.GetY();} // copy constructor
    ~Point() {};                                          // destructor
    void Set(float x, float y) {_x = x; _y = y;}          // mutator
    float GetX() const {return _x;}                       // inspector
    float GetY() const {return _y;}                       // inspector
};

#endif // POINT_H
