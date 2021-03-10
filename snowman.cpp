//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)

// #include<stdlib.h>
#include<iostream>
// #include "surce.hpp"
#include <array>
#include<string>

using namespace std;
namespace clothing
{
    const array<string,4> hats = {
    "      \n _===_",
    "  ___ \n .....",
    "   _  \n  /_\\ ",
    "  ___ \n (_*_)",
};
    const array<string,4> noses = {
    ",",
    ".",
    "_",
    " ",
};
    const array<string,4> eyes = {
    ".",
    "o",
    "O",
    "-",
};
    const array<string,4> leftArmsUp  = {
    " ",
    "\\",
    " ",
    " ",
};
    const array<string,4> leftArmsDown  = {
    "<",
    " ",
    "/",
    " ",
};
    const array<string,4> rightArmsUp  = {
    " ",
    "/",
    " ",
    " ",
};
    const array<string,4> rightArmsDown  = {
    ">",
    " ",
    "\\",
    " ",
};
    const array<string,4> belly={
    "( : )",
    "(] [)",
    "(> <)",
    "(   )",
};
    const array<string,4> base={
    " ( : ) ",
    " (\" \") ",
    " (___) ",
    " (   ) ",
};
}

namespace ariel
{
    const int size=8;
    const int divider=10;

    array<int,size> breakNum(int num)
    {
        array<int,size> arr ={};
        const int lowD=1;
        const int highD=4;
        int current=0;
        for (int i = 0; i < size; i++)
        {
            current = num%divider;
            if(current<lowD || current>highD)
            {
                throw std::out_of_range{"not a legal digit!"};
            } 
            num= num/divider;
            current--;
            arr.at(size-1-i) = current;
        }
        return arr;
        
    }
    string snowman(int num)
    {
        const int lowestN=11111111;
        const int highestN=44444444;
        const int H=0;
        const int N=1;
        const int L=2;
        const int R=3;
        const int X=4;
        const int Y=5;
        const int T=6;
        const int B=7;
        if(num<lowestN || num>highestN)
        {
            throw std::out_of_range{"not enough numbers"};
        } 

        array<int,size> arr = breakNum(num);

        string answer;
        //now we will build a snow man by dividing it to four parts:

        //part 1 the hat 
        //  HHHHH
        //  HHHHH
        answer.append(clothing::hats.at(arr.at(H)));
        answer.append("\n");

        //part 2 the head
        // X(LNR)Y
        answer.append(clothing::leftArmsUp.at(arr.at(X)));
        answer.append("(");
        answer.append(clothing::eyes.at(arr.at(L)));
        answer.append(clothing::noses.at(arr.at(N)));
        answer.append(clothing::eyes.at(arr.at(R)));
        answer.append(")");
        answer.append(clothing::rightArmsUp.at(arr.at(Y)));
        answer.append("\n");
        
        //part 3 the belly:
        // X(TTT)Y
        
        answer.append(clothing::leftArmsDown.at(arr.at(X)));
        answer.append(clothing::belly.at(arr.at(T)));
        answer.append(clothing::rightArmsDown.at(arr.at(Y)));
        answer.append("\n");

        //part 4 bass:
        //  (BBB)
        answer.append(clothing::base.at(arr.at(B)));


        return answer;
    }
}