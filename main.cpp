#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class NumStrings {
    unordered_map<int, string> numMap;
    vector<int> digit;

public:

    NumStrings() {
        numMap[1] = "One";
        numMap[2] = "Two";
        numMap[3] = "Three";
        numMap[4] = "Four";
        numMap[5] = "Five";
        numMap[6] = "Six";
        numMap[7] = "Seven";
        numMap[8] = "Eight";
        numMap[9] = "Nine";
        numMap[0] = "Zero";
        digit.reserve(1000);
    }


    void printAsString(const int *arr, int size) {
        string str;
        int j;
        for (int i = 0; i < size; ++i) {
            int num1 = *(arr + i);
            j = 0;

            if (num1 == 0)
                str += numMap[digit[j]];
            else
                while (num1 != 0) {
                    digit[j] = num1 % 10;
                    num1 = num1 / 10;
                    ++j;
                }

            while (j > 0) {
                --j;
                str += numMap[digit[j]];
            }


            if (i < size - 1) {
                str += ",";
            }
            digit.clear();
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
