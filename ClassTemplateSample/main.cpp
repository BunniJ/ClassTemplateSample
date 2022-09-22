//
//  main.cpp
//  ClassTemplateSample
//
//  Created by Tracy W on 2022-09-22.
//

#include <iostream>
#include "MyArray.hpp"

void printArray(MyArray<int> &arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << endl;
    }
}

void test01() {
    // Test 1: constructor
    MyArray<int>arr1(5);
    
    // Test 1 : update capacity
    MyArray<int>arr3(100);
    // Test 3 : operator(cleanup then deepcopy)
    arr3 = arr1;
    
    // Test 4 : Test push back, instert new value to tail
    for(int i = 0; i < 5; i++) {
        arr1.pushBack(i);
    }
    printArray(arr1);
    cout << "Arr1 Capacity is: " << arr1.getCapacity() << endl;
    cout << "Arr1 Size is: " << arr1.getSize() << endl;
    
    // Test 2 : Copy constructor (with deepcopy)
    MyArray<int>arr2(arr1);
    // Test 5 : Test pop back, remove value from tail
    printArray(arr2);
    arr2.popBack();
    cout << "Arr2 after popback" << endl;
    cout << "Capacity is: " << arr2.getCapacity() << endl;
    cout << "Size is: " << arr2.getSize() << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    test01();
    
    return 0;
}
