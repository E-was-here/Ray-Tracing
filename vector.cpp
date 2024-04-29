#include "vector.h"
#include "math.h"
#include <iostream>

#define ABS(a) ((a>=0)? a : -a)

// ---------- CONSTRUCTORS ----------

Vector::Vector() : x(0.0f), y(0.0f) {}
Vector::Vector(int a, int b) : x(static_cast<float>(a)), y(static_cast<float>(b)) {
}
Vector::Vector(float a, float b) : x(a), y(b) {
}

// ---------- OPERATORS ----------

Vector Vector::operator+(const Vector& v) const {
    return Vector(x + v.get_x(), y + v.get_y());
}
Vector Vector::operator-(const Vector& v) const {
    return Vector(x - v.get_x(), y - v.get_y());
}
Vector Vector::operator/(float a) const {
    return Vector(x / a, y / a);
}
Vector Vector::operator/(int a) const {
    return Vector(x / a, y / a);
}

// ---------- ACCESSORS ----------

float Vector::get_x() const {
    return x;
}
float Vector::get_y() const {
    return y;
}
float Vector::get_norm() const {
    return calc_norm();
}

// ---------- MUTATORS ----------

void Vector::set(float x_value, float y_value) {
    x = x_value;
    y = y_value;
}
void Vector::set(Vector v) {
    x = v.scalar_prod(Vector(1, 0));
    y = v.scalar_prod(Vector(0, 1));
}

// ---------- METHODS ----------

void Vector::normalize() {
    float norm = calc_norm();
    x /= norm;
    y /= norm;
}
float Vector::scalar_prod(const Vector& v) const {
    return (x * v.get_x() + y * v.get_y());
}
Vector Vector::perpendicular() const {
    Vector perp(y, -x);
    perp.normalize();
    return perp;
}
void Vector::show(bool f) const {
    if (f) {
        std::cout << "x=" << x << " ; y=" << y << std::endl;
    }
    else {
        std::cout << "x=" << x << " ; y=" << y;
    }
}
float Vector::squared_norm() const {
    return (x * x + y * y);
}
float Vector::calc_norm() const {
    if (((ABS(x)) >= std::numeric_limits<float>::epsilon()) || ((ABS(y)) >= std::numeric_limits<float>::epsilon())) {
        // checks if x != 0 or y != 0
        return static_cast<float>(sqrt(x * x + y * y));
    }
    else {
        // avoid division by 0
        return static_cast<float>(1e-15);
    }
}

// ---------- COMMUTATIVE OPERATORS ----------

Vector operator*(int a, const Vector& v) {
    return Vector(a * v.get_x(), a * v.get_y());
}
Vector operator*(const Vector& v, int a) {
    return a * v;
}
Vector operator*(float a, const Vector& v) {
    return Vector(a * v.get_x(), a * v.get_y());
};
Vector operator*(const Vector& v, float a) {
    return a * v;
}
