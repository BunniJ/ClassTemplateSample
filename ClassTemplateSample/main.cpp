//
//  main.cpp
//  ClassTemplateSample
//
//  Created by Tracy W on 2022-09-22.
//

#include <iostream>
#include <string>
#include "MyArray.hpp"

class Person {
public:
    Person(){};
    Person(string name, int age){
        this->mName = name;
        this->mAge = age;
    };
    
    string mName;
    int mAge;
};

void printArray(MyArray<int> &arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << endl;
    }
}

void printPersonArray(MyArray<Person> &arr) {
    for(int i = 0; i < arr.getSize(); i++) {
        cout << "Name: " << arr[i].mName << " "
        << "Age: " << arr[i].mAge << endl;
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

void test02() {
    // Test custom datatype
    MyArray<Person> arr(10);
    Person p1("Bob", 99);
    Person p2("Jim", 3);
    Person p3("Ada", 10);
    
    // Test tail insertion
    arr.pushBack(p1);
    arr.pushBack(p2);
    arr.pushBack(p3);
    
    // print Person array
    printPersonArray(arr);
    
    // Get capacity and size
    cout << "Custom datatype arrray capacity is: " << arr.getCapacity() << " "
    << "and size is: " << arr.getSize() << endl;
}

int main(int argc, const char * argv[]) {
    
    // test build-in datatypre
    test01();
    
    // test custom datatype
    test02();
    
    return 0;
}
