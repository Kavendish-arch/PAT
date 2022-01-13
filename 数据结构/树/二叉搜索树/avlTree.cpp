#include<iostream>
using namespace std;

template<class T>
struct Node
{
    T data;
    Node * left;
    Node * right;
    Node():data(),left(),right();
    Node(T data):data(data),left(nullptr),right(nullptr);
    Node(T data, Node *left, Node *right):data(data),left(left),right(right);
};


int main(int argc, char const *argv[])
{
    Node A;
    return 0;
}
