#include <iostream>
#include "lab9.h"
#include "lab9.cpp"

using namespace std;

int main() {
  try {
    while(true) {
      cout << "Enter type of data (1 - int, 2 - double)" << endl;
      int what;
      cin >> what;
      if(what == 1) {

        CSingleLinkedList<int> list;
        taskbar(list);

      } else if(what == 2) {

        CSingleLinkedList<double> list;
        taskbar(list);

      } else {
        cout << " ops, some unknown symbol" << endl;
      }
      cout << "Do you want continie with else type or list?(1 - YES, 0 - NO)";
      int ans = 0;
      cin >> ans;
      if(ans == 0) break;
      system("cls");
    }
    while(true) {
      cout << "Enter type of data (1 - int, 2 - CSingleLinkedList)" << endl;
      int what;
      cin >> what;
      int size;
      cout << "enter size of array" << endl;
      cin >> size;
      if(what == 1) {
        int* arr = new int[size];
        for(int i = 0; i < size; i++) {
          cin >> arr[i];
        }
        cout << "enter element you want find" << endl;
        cin >> what;
        cout << findElementInArray(arr, size, what);
      } else if(what == 2) {
        CSingleLinkedList<int>* arr = new CSingleLinkedList<int>[size];
        for(int i = 0; i < size; i++) {
          cin >> arr[i];
        }
        cout << "enter element you want find" << endl;
        CSingleLinkedList<int> find;
        cin >> find;
        cout << findElementInArray(arr, size, find);
      } else {
        cout << "ops, some unknown error" << endl;
      }
      cout << "Do you want continie with other array?(1 - YES, 0 - NO)";
      int ans = 0;
      cin >> ans;
      if(ans == 0) break;
      system("cls");

    }
  }
  catch(const char* message) {
    cout << message;
  }
  catch(const exception& exc) {
    cout << exc.what();
  }
  catch(...) {
    cout << "some unknown error" << endl;
  }
  return 0;
}