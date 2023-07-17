#include "lab9.h"
#include <set>
#include <vector>
#include <unordered_map>
#include <stack>

template<typename T>
int findElementInArray(T arr[], int size, const T& element) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == element) return i;
  }
  return size;
}

template<typename T>
void taskbar(CSingleLinkedList<T>& data) {
  CSingleLinkedList<T> list;
  stack<T> st;
  multiset<T> ms;
  unordered_map<int, T> um;
  cout << "Enter list" << endl;
  getchar();
  cin >> data;
  cout << data << endl;
  while(true) {
    cout << "chose the action" << endl;
    cout << "0) print list" << endl;
    cout << "1) add to end" << endl;
    cout << "2) add to start" << endl;
    cout << "3) remove first" << endl;
    cout << "4) remove last" << endl;
    cout << "5) remove all" << endl;
    cout << "6) get first" << endl;
    cout << "7) get last" << endl;
    cout << "8) get min" << endl;
    cout << "9) get max" << endl;
    cout << "10) get count" << endl;
    cout << "11) get element [i]" << endl;
    cout << "12) add two list" << endl;
    cout << "13) each element increase " << endl;
    cout << "14) each element decrease" << endl;
    cout << "15) each element  multiple" << endl;
    cout << "16) reverse" << endl;
    cout << "17) get avg" << endl;
    cout << "-------------------------------------" << endl;
    cout << "18) print multiset" << endl;
    cout << "19) insert in multiset" << endl;
    cout << "20) find in multiset" << endl;
    cout << "21) delete from multiset" << endl;
    cout << "-------------------------------------" << endl;
    cout << "22) print unordered_map" << endl;
    cout << "23) insert in unordered_map" << endl;
    cout << "24) find in unordered_map" << endl;
    cout << "25) delete from unordered_map" << endl;
    cout << "-------------------------------------" << endl;
    cout << "26) insert in stack " << endl;
    cout << "27) print stack " << endl;

    int ans = 0;
    T temp;
    cin >> ans;
    T num;
    switch(ans) {
      case 0:
        cout << data << endl;
        break;
      case 1:
        cin >> temp;
        data.addToEnd(temp);
        break;
      case 2:
        cin >> temp;
        data.addToStart(temp);
        break;
      case 3:
        data.removeFirst();
        break;
      case 4:
        data.removeLast();
        break;
      case 5:
        data.removeAll();
        break;
      case 6:
        cout << data.getFirst() << endl;
        break;
      case 7:
        cout << data.getLast() << endl;
        break;
      case 8:
        cout << data.getMin() << endl;
        break;
      case 9:
        cout << data.getMax() << endl;
        break;
      case 10:
        cout << data.getCount() << endl;
        break;
      case 11:
        int index;
        cin >> index;
        cout << data[index] << endl;
        break;
      case 12:
        cout << "enter second list" << endl;
        getchar();
        cin >> list;
        cout << data + list << endl;
        break;
      case 13:
        cout << "enter number" << endl;
        getchar();
        cin >> num;
        data += num;
        break;
      case 14:
        cout << "enter number" << endl;
        getchar();
        cin >> num;
        data -= num;
        break;
      case 15:
        cout << "enter number" << endl;
        getchar();
        cin >> num;
        data *= num;
        break;
      case 16:
        data.reverse();
        break;
      case 17:
        cout << data.getAvg() << endl;
        break;
      case 18:
        for(auto& i : ms) {
          cout << i << " ";
        }
        cout << endl;
        break;
      case 19:
        cout << "enter number you want insert" << endl;
        getchar();
        cin >> num;
        ms.insert(num);
        break;
      case 20:
        cout << "enter number you want find" << endl;
        getchar();
        cin >> num;
        {
          auto isFind = ms.find(num);
          if(isFind == ms.end()) {
            cout << "There is no this element";
          } else {
            cout << "Element has been find: " << num;
          }
          cout << endl;
        }
        break;
      case 21:
        cout << "enter number" << endl;
        getchar();
        cin >> num;
        {
          bool isDel = ms.erase(num);
          if(!isDel) {
            cout << "There is no element you want delete";
          } else {
            cout << "Element " << num << " has been deleted";
          }
          cout << endl;
        }
        break;
      case 22:
        for(auto& i : um) {
          cout << i.first << "-[" << i.second << "] ";
        }
        cout << endl;
        break;
      case 23:
        cout << "enter key" << endl;
        getchar();
        {
          int key;
          cin >> key;
          cout << "enter value" << endl;
          cin >> num;
          um.emplace(key, num);
        }

        break;
      case 24:
        cout << "enter index" << endl;
        getchar();
        cin >> num;
        {
          auto isFind = um.find(num);
          if(isFind == um.end()) {
            cout << "There is no element with this index";
          } else {
            cout << isFind->second;
          }
        }
        cout << endl;
        break;
      case 25:
        cout << "enter index" << endl;
        getchar();
        cin >> num;
        {
          bool isDel = um.erase(num);
          if(!isDel) {
            cout << "There is no element you want delete";
          } else {
            cout << "Element " << num << " has been deleted";
          }
          cout << endl;
        }
        break;
      case 26:
        cout << "enter number you want insert in stack" << endl;
        getchar();
        cin >> num;
        st.push(num);
        break;
      case 27:
        cout << "printing stack" << endl;
        {
          auto a = st._Get_container();
          for(auto& i : a) {
            cout << i << " ";
          }
        }
        cout << endl;
        break;

    }
    cout << "do you want continie?(1 - YES, 0 - NO)";
    getchar();
    int lastAns;
    cin >> lastAns;
    if(lastAns == 0) break;
    system("cls");
  }
}