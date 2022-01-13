
#include<iostream>
using namespace std;


template <typename T>
class Vector {
private:
    size_t sz;
    T *elem;

public:
    explicit Vector(size_t size): sz(size), elem(new T[sz])
    {
    }

    T& operator[] (int i) {
        return elem[i];
    }

    size_t size(){
        return sz;
    }

    Vector(const Vector& other);

    ~Vector() { delete[] elem; }
};

template<typename T>
Vector::Vector(const Vector& other)
    :sz(size()),
    elem(new T[sz]) {
    for (int i = 0; i != sz; i ++) {
        elem[i] = other.elem[i];
    }
}



class Base{
public:
    unsigned int sizej_l;
    int * elem;
    inline void say_hello(){};

    Base(unsigned int size):
        sizej_l(size),
        elem(new int[size])
    {};

    int& operator[](unsigned int size){
        return elem[size];
    };

    unsigned int size(){
        return sizej_l;
    }
    ~Base(){};
private:

protected:

};

/**
 * @brief 
 * 模板 泛型编程
 * 
 * 
 */

template<typename T>
inline T const & Max(T const & a, T const& b ){
    return a > b ? a : b;
}

template<typename T1, class T2>
class A
{
public:
    T1 data1;
    T2 data2;
}



int main(int argc, char const *argv[])
{
    int i = 20;
    int j = 30;
    cout << Max(i, j) << endl;
    return 0;
}
