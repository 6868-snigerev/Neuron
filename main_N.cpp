#include <iostream>
#include <cmath>
using namespace std;

typedef double (*func)(double);

double Foo(double x) {
    return 1 / (1 + exp(-x));
}

class Neuron {
public:
    double *mas;
    double *kff;
    int size_;
    func inputFunction;
    void start(){
        cout << "enter *mas" << endl;
        for (int i = 0; i < size_; i++){
            cin >> mas[i];
        }
        for (int i = 0; i < size_; i++){
            kff[i] = 1;
        }
    }
    void weight(){
        cout << "change *kff" << endl;
        for (int i = 0; i < size_; i++){
            cin >> kff[i];
        }
    }
    double returnValue(){
        double sum;
        for (int i = 0; i < size_; i++){
            sum = mas[i] * kff[i];
        }
        return inputFunction(sum);
    }
    Neuron(int lenArr, func inputF){
        this->mas = new double[lenArr];
        this->kff = new double[lenArr];
        this->inputFunction = inputF;
        this->size_ = lenArr;
    };
    Neuron(const Neuron &a){
        this->mas = new double[a.size_];
        this->kff = new double[a.size_];
        this->inputFunction = a.inputFunction;
        this->size_ = a.size_;
    };
    Neuron & operator = (const Neuron &a){
        this->mas = new double[a.size_];
        this->kff = new double[a.size_];
        this->inputFunction = a.inputFunction;
        this->size_ = a.size_;
        return *this;
    }
};


int main()
{
    int input;
    cout << "number of input" << endl;
    cin >> input;
    Neuron a(input, Foo);
    a.start();
    a.weight();
    return 0;
}
