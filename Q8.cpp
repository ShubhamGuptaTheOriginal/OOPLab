#include <iostream>
using namespace std;

class alpha{
    int a;
public:
    alpha(int x){
        this->a = x;
        cout << "Constructor of A is called.\n";
    }
    int get_data(){
        cout << "Data in alpha - " << this->a << endl;
    }
    ~alpha(){
        cout << "Destructor of A is called.\n";
    }
};

class beta{
    int b;
public:
    beta(int x){
        this->b = x;
        cout << "Constructor of B is called.\n";
    }

    void get_data(){
        cout << "Data in beta - " << this->b << endl;
    }
    ~beta(){
        cout << "Destructor of A is called.\n";
    }
};

class gamma: public alpha,public beta{
    int c;
public:
    gamma(int a, int b,int c):alpha(a),beta(b){
        this->c = c;
        cout << "Constructor of C is called.\n";

    }
    void get_data(){
        alpha::get_data();
        beta::get_data();
        cout << "Data in gamma - " << this->c << endl;
    }
    ~gamma(){
        cout << "Destructor of C is called.\n";
    }
};

int main(){
    gamma G(10,12,2);
    G.get_data();
}