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

    for(int i=0; i<n; i+=1){
        weights[i] = get_random_number();
    }

    for(int i=0; i<n; i+=1){
        forward += weights[i] * inputs[i];
    }
    forward += bias;

    return forward;
}

double* layer(int inputs[], int n, int num_neurons){
    double* outs =  new double[num_neurons];

    for(int i=0; i<num_neurons; i+=1){
        outs[i] = neuron(inputs, n);
    }

    return outs;
}


int main(){

    int inputs[] = {1, 2, 3, 4};
    int n = sizeof(inputs) / sizeof(inputs[0]);

    double* outs = layer(inputs, n, 3);

    for(int i=0; i<3; i+=1){
        cout<<outs[i]<<" ";
    }
    cout<<endl;

    return 0;
}