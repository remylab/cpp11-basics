#include <iostream>
using namespace std;


// Template class
template<class T>
class mypair 
{
    T a, b;
    public:
        mypair (T first, T second) {a=first; b=second;}
        T getmax ();
};

// Template class member function
template<class T>
T mypair<T>::getmax()
{
  T retval = a>b? a : b;
  return retval;
};

// Template class specialization
template<>
class mypair<string>
{
    string a, b;
    public:
        mypair (string first, string second) {a=first; b=second;};
        string concat() { return a + b ;};
};


// Template function
template<typename T>
void hello(const T& obj)
{
    cout << "hello " << obj << endl;
};

// function overload (no specializatinon allowed)
void hello(char* a) 
{
    cout << "hey " << a << endl;
}


class Box {
    
    public:
        enum Sizes {small, big};

        Box(string n, Box::Sizes s): name(n), size(s) {};
        Box(){};
        bool operator>(const Box& b) {
            if ( this->size == big && b.size == small) {
                return true;
            }
            return false;
        }
        friend ostream& operator<<(ostream& os, const Box& b) 
        {
            os << "box=" << b.name;
            return os;
        }

    private:
        string name;
        Box::Sizes size;
};

int main () 
{
    // test template class
    mypair<int> p1 (100, 75);
    cout << p1.getmax() << endl;

    mypair<Box> p2 (Box("b1", Box::big), Box("b2", Box::small));
    cout << p2.getmax() << endl; 

    // test template class specializatin
    mypair<string> p3("hello, ", "world");
    //cout << p3.getmax() << endl; // nope.. getmax has not been defined in the specialized class mypair<string>
    cout << p3.concat() << endl;

    // test template function
    hello("I am a string");
    hello(Box("b3", Box::big));

    // test function overload (of a template function)
    char arr[3] = {'a','b','c'};
    hello(arr);

    return 0;
}