//
//  main.cpp
//  ambition
//
//  Created by Tae Keun Jeong on 19.05.21.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unistd.h>
#include <math.h>
#include <thread>

using namespace std;

int sum(int a, int b){
    
    return a+b;
    
}

void dtypes(){
    
    cout << "The size of char is:" << sizeof(char) <<"\n";
    cout << "The size of short is:" << sizeof(short) << "\n";
    cout << "The size of int is:" << sizeof(int) <<"\n";
    cout << "The size of long is:" << sizeof(long) <<"\n";
    cout << "The size of long long is:" << sizeof(long long)<< "\n";
    cout << "The size of float is:" << sizeof(float) << "\n";
    cout << "The size of double is:" << sizeof(double) << "\n";
    cout << "The size of long double is:" << sizeof(long double) << "\n";
    cout << "The size of bool is:" << sizeof(bool) << endl;
    
}

void max_val(){
    
    cout << "the maximum limit of int data type:" << INT_MAX << "\n";
    
    cout << "the minimum limit of int data type: " << INT_MIN << endl;
    
    
}

void checkvalues(){
    
    char gender = 'F';
    int married = 1;
    int sons = 2;
    int salary = 1500000;
    float height = 79.48;
    float gpa = 4.69f;
    long upto = 12047235L;
    long long balance = 995324987LL;
    
    
    cout << "check whether the primitive values cross the limit" << "\n";
    
    cout << "The Gender is :" << gender << "\n";
    cout << "married status:" << married  << "\n";
    cout << "number of sons:" << sons << "\n";
    cout << "salary wished:" << salary << "\n";
    cout << "height" << height << "\n";
    cout << "gpa:" << gpa << "\n";
    cout << "upto" << upto << "\n";
    cout << "balance" << balance << endl;
    
}

void increment(){
    
    int current = 57;
    
    for(int i = 0; i < 3; i++){
        
        cout << "increment :" << current<< "\n";
        current += 1;
        
    }
    
    for(int i = 0; i < 4; i++){
        
        cout << "decrement : " << current << "\n";
        current -= 1;
        
    }
    
    cout << endl;
    
}

void thread_function(){
    
    cout << "thread function\n";
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << M_PI << endl;
    
    return 0;
}

