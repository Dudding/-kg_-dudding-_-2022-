#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class NumStrings{
    unordered_map<int, string> nums;
    vector<int>dgt;

public:

    NumStrings(){
        nums[1] = "One";
        nums[2] = "Two";
        nums[3] = "Three";
        nums[4] = "Four";
        nums[5] = "Five";
        nums[6] = "Six";
        nums[7] = "Seven";
        nums[8] = "Eight";
        nums[9] = "Nine";
        nums[0] = "Zero";
        dgt.reserve(1000);
    }


    void printAsString(const int* arr, int size){
        string str;
        for(int i = 0; i < size; ++i) {
            int num1 = *(arr + i);
            int j = 0;
            if(num1 == 0)
                str += nums[dgt[j]];
            else
                while (num1 != 0) {
                    dgt[j] = num1 % 10;
                    num1 = num1 / 10;
                    ++j;
                }
            while( j > 0){
                --j;
                str += nums[dgt[j]];
            }
            if(i < size - 1){
                str += ",";
            }
            dgt.clear();
        }
        cout << str;
    }



};





int main() {

    {
        int arr[3] = {1, 2, 3};
        NumStrings obj;
        obj.printAsString(arr, 3);
        cout << endl;
    }
    {
        int arr2[3] = {1, 25, 3};
        NumStrings obj;
        obj.printAsString(arr2, 3);
        cout << endl;
    }

    {
        int arr3[4] = {1, 205, 30, 0};
        NumStrings obj;
        obj.printAsString(arr3, 4);
        cout << endl;
    }

    return 0;
}
