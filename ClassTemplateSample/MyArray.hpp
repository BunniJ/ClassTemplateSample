//
//  MyArray.hpp
//  ClassTemplateSample
//
//  Created by Tracy W on 2022-09-22.
//

#pragma once
#ifndef MyArray_hpp
#define MyArray_hpp
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

template <class T>
class MyArray {
public:
    
    MyArray(int capacity) {
        cout << "1. MyArray constructor with parameter: called!" << endl;
        this->mCapacity = capacity;
        this->mSize = 0;
        // Save the data in an array to heap
        this->pAddress = new T[this->mCapacity];
    }
    
    // Copy Operator
    MyArray(const MyArray &arr) {
        cout << "2. MyArray copy constructor: called!" << endl;

        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        
        // Deep copy, create a newspace
        this->pAddress = new T[arr.mCapacity];
        // If array already had data inside, copy them to the new space
        for(int i = 0; i < this->mSize; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    
    // Operator= to prevent shallow copy issue
    MyArray& operator = (const MyArray& arr) {
        
        cout << "3. MyArray operator= called!" << endl;
        
        // First check if the old heap has data, if so delete first
        if(this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->mCapacity = 0;
            this->mSize = 0;
        }
        
        // Now do the deepcopy
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        this->pAddress = new T[arr.mCapacity];
        
        // Copy all the data
        for(int i = 0; i < this->mSize; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        
        return *this; // return itself
    }
    
    // Tail Insert
    void pushBack(const T &val) {
        // 1. check capacity, if out of size then return
        if(this->mCapacity == this->mSize) {
            return;
        }
        
        // Insert the new value to array tail
        this->pAddress[this->mSize] = val;
        // Update array size
        this->mSize++;
    }
    
    // Tail Delete
    void popBack() {
        // 1. check capacity, if no value left then return
        if(this->mCapacity == 0) {
            return;
        }
        
        // If user cannot check the last value, means the last value is deleted
        // Update array size
        this->mSize--;
    }
    
    // Check array value by index aka reload operator[]
    // e.x. arr[index] = 100
    // Return a reference of T to use this function as left value of =, it returns data itself, then assign it a value.
    T& operator[] (int index) {
        return this->pAddress[index];
    }
    
    // Get the capacity of array
    int getCapacity() {
        return this->mCapacity;
    }
    
    // Get the size of array
    int getSize() {
        return this->mSize;
    }
    
    ~MyArray() {
        if(this->pAddress != NULL) {
            cout << "MyArray destructor: called!" << endl;

            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
    
private:
    T * pAddress; // Point to the real array which created in Heap
    int mCapacity;
    int mSize;
};

#endif /* MyArray_hpp */
