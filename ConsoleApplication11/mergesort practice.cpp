

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> tosort;

void merge(int min_index, int mid_index, int max_index) {
    int left_length, right_length;
    left_length = mid_index - min_index+1;
    right_length = max_index - mid_index;

    vector<int> left(left_length), right(right_length);
    for (int i = 0; i < left_length; i++) {
        left[i] = tosort[min_index+i];
    }
    for (int j = 0; j < right_length; j++) {
        right[j] = tosort[mid_index+j+1];
    }

    int left_index=0, right_index=0, sort_index=min_index;

    while (left_index < left_length && right_index < right_length) {
        if (left[left_index] >= right[right_index]) {
            tosort[sort_index] = left[left_index];
            left_index++;
        }
        else {
            tosort[sort_index] = right[right_index];
            right_index++;
        }
        sort_index++;
    }

    while (left_index < left_length) {
        tosort[sort_index] = left[left_index];
        left_index++;
        sort_index++;
    }

    while (right_index < right_length) {
        tosort[sort_index] = right[right_index];
        right_index++;
        sort_index++;
    }

}

void mergesort(int min_index, int max_index) {
    if (min_index < max_index) {
        int mid_index = (min_index + max_index) / 2;
        mergesort(min_index, mid_index);
        mergesort( mid_index + 1, max_index);
        merge(min_index, mid_index, max_index);
    }

}

int main()
{
    string input;
    char token;
    int token_int;
    int temp=0;
    bool negative=false;

    //please dont enter any spaces!!
    cout << "Please enter the list: ";
    cin >> input;

    auto i = input.begin();
    token = *i;

    while (token != '*') {
        token_int = (int)token - '0';
        if (token_int>=0 && token_int <=9) {
            temp = temp*10+token_int;
            
        }
        else if(token =='-'){
            negative = true;
        }
        else {
            if (negative == true) {
                tosort.push_back(temp*-1);
            }
            else {
                tosort.push_back(temp);
            }

            temp = 0;
            negative = false;
        }
        token = *(++i);
        if (token == '*') {
            if (negative == true) {
                tosort.push_back(temp * -1);
            }
            else {
                tosort.push_back(temp);
            }

        }
    }

    mergesort(0, tosort.size() - 1);

    for (int i = 0; i < tosort.size()-1; i++) {
        cout << tosort[i] << ", ";
    }
    cout << tosort[tosort.size() - 1];
}
