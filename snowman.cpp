//  HHHHH
//  HHHHH
// X(LNR)Y
// X(TTT)Y
//  (BBB)

#include<stdlib.h>
#include<iostream>
#include "closet.hpp"

#include<string>
using namespace std;
namespace ariel
{
    void breakNum( int* arr,int num)
    {
        int current;
        for (int i = 0; i < 9; i++)
        {
            current = num%10;
            if(current>4 || current<1)
            {
                throw std::out_of_range{"not a legal digit!"};
            } 

            arr[7-i]= current-1;
        }
        
    }
    string snowman(int num)
    {
        if(num<11111111 || num>44444444)
        {
            throw std::out_of_range{"not in range of num!"};
        } 

        int  arr[8] ={};
        breakNum(arr,num);

        string answer="";
        //now we will build a snow man by dividing it to four parts:

        //part 1 the hat 
        //  HHHHH
        //  HHHHH
        answer.append(clothing::hats[arr[0]]);
        answer.append("\n");

        //part 2 the head
        // X(LNR)Y
        answer.append(clothing::leftArmsUp[arr[4]]);
        answer.append("(");
        answer.append(clothing::eyes[arr[2]]);
        answer.append(clothing::noses[arr[1]]);
        answer.append(clothing::eyes[arr[3]]);
        answer.append(")");
        answer.append(clothing::rightArmsUp[arr[5]]);
        answer.append("\n");
        
        //part 3 the belly:
        // X(TTT)Y
        
        answer.append(clothing::leftArmsDown[arr[4]]);
        answer.append(clothing::belly[arr[6]]);
        answer.append(clothing::rightArmsDown[arr[5]]);
        answer.append("\n");

        //part 4 bass:
        //  (BBB)
        answer.append(clothing::Base[arr[7]]);


        return answer;
    }
}