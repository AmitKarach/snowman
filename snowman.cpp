//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)

#include<stdlib.h>
#include<iostream>
// #include "surce.hpp"
#include <array>
#include<string>

using namespace std;
namespace clothing
{
    const std::array<string,4> hats = {"      \n _===_","  ___ \n .....","   _  \n  /_\\ ","  ___ \n (_*_)",};
    const std::array<string,4> noses = {",",".","_"," ",};
    const std::array<string,4> eyes = {".","o","O","-",};
    const std::array<string,4> leftArmsUp  = {" ","\\"," "," ",};
    const std::array<string,4> leftArmsDown  = {"<"," ","/"," ",};
    const std::array<string,4> rightArmsUp  = {" ","/"," "," ",};
    const std::array<string,4> rightArmsDown  = {">"," ","\\"," ",};
    const std::array<string,4> Belly={"( : )","(] [)","(> <)","(   )",};
    const std::array<string,4> Base={" ( : ) "," (\" \") "," (___) "," (   ) ",
};

namespace ariel
{
    const int size=8;
    const int divider=10;

    void breakNum( int* arr,int num)
    {
        const int low=1;
        const int high=4;
        int current=0;
        for (int i = 0; i < size; i++)
        {
            current = num%divider;
            if(current<low || current>high)
            {
                throw std::out_of_range{"not a legal digit!"};
            } 
            num= num/divider;
            current--;
            arr[size-1-i] = current;
        }
        
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

        std::array<int,size> arr ={0};
        breakNum(arr,num);

        string answer="";
        //now we will build a snow man by dividing it to four parts:

        //part 1 the hat 
        //  HHHHH
        //  HHHHH
        answer.append(clothing::hats[arr[H]]);
        answer.append("\n");

        //part 2 the head
        // X(LNR)Y
        answer.append(clothing::leftArmsUp[arr[X]]);
        answer.append("(");
        answer.append(clothing::eyes[arr[L]]);
        answer.append(clothing::noses[arr[N]]);
        answer.append(clothing::eyes[arr[R]]);
        answer.append(")");
        answer.append(clothing::rightArmsUp[arr[Y]]);
        answer.append("\n");
        
        //part 3 the belly:
        // X(TTT)Y
        
        answer.append(clothing::leftArmsDown[arr[X]]);
        answer.append(clothing::belly[arr[T]]);
        answer.append(clothing::rightArmsDown[arr[Y]]);
        answer.append("\n");

        //part 4 bass:
        //  (BBB)
        answer.append(clothing::Base[arr[B]]);


        return answer;
    }
}