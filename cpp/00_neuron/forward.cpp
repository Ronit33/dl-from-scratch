#include <iostream>
#include <random>

using namespace std;

double get_random_number(){
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_real_distribution<> dis(0.0, 1.0);
    
    return dis(gen);
}

double neuron(int inputs[], int n){
    double forward = 0;

    double weights[4];
    double bias = get_random_number();

    cout<<"WEIGHTS: ";
    for(int i=0; i<n; i+=1){
        weights[i] = get_random_number();
        cout<<weights[i]<<" ";
    }
    cout<<"\nBIAS: "<<bias<<endl;;

    for(int i=0; i<n; i+=1){
        forward += weights[i] * inputs[i];
    }

    forward += bias;
    return forward;
}


int main(){

    int inputs[] = {1, 2, 3, 4};

    cout<<neuron(inputs, 4)<<endl;

    return 0;
}