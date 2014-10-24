#include "Builder.h"
#include <iostream>
using namespace std;

Builder::Builder(){
}

ConcreteBuilder1::ConcreteBuilder1(){
}

void ConcreteBuilder1::BuildPart1(){
    cout << "ConcreteBuilder1 -> BuildPart1" << endl;
}

void ConcreteBuilder1::BuildPart2(){
    cout << "ConcreteBuilder1 -> BuildPart2" << endl;
}

void ConcreteBuilder1::BuildPart3(){
    cout << "ConcreteBuilder1 -> BuildPart3" << endl;
}

void ConcreteBuilder1::GetResult(){
    cout << "ConcreteBuilder1 -> GetResult" << endl;
}

ConcreteBuilder2::ConcreteBuilder2(){
}

void ConcreteBuilder2::BuildPart1(){
    cout << "ConcreteBuilder2 -> BuildPart1" << endl;
}

void ConcreteBuilder2::BuildPart2(){
    cout << "ConcreteBuilder2 -> BuildPart2" << endl;
}

void ConcreteBuilder2::BuildPart3(){
    cout << "ConcreteBuilder2 -> BuildPart3" << endl;
}

void ConcreteBuilder2::GetResult(){
    cout << "ConcreteBuilder2 -> GetResult" << endl;
}

Director::Director(){
}

void Director::construct(Builder &builder){
    builder.BuildPart1();
    builder.BuildPart2();
    builder.BuildPart3();
}

Product::Product(){
}

