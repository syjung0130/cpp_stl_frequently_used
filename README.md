# cpp_stl_frequently_used
----------------------------------------------------
## 자주 사용하는 C++ STL library
코딩테스트는 검색을 할 수 없는 환경에서 치뤄지므로 외워둬야한다.  
자동완성기능을 사용할 수 없는 경우나 손코딩을 해야하는 경우도 있다.  
자주 보고, 사용하다보면 외워진다.  
코딩테스트 전에 복기하면 좋을 듯하다.

## string::find()
 - return type은 size_t, 찾지 못하면 string::npos를 return, 찾으면 찾는 문자열이 문장 내에서 시작하는 위치(index)를 return.
 - 특정 위치부터 찾으려면 두번째 인자로 index를 추가해서 아래처럼 사용이 가능하다.  
   find(찾을 문자열 or 문자 , 찾기 시작할 위치)  
~~~C++
size_t offset = tmp.find(",");//index 0부터 ',' 의 위치를 찾는다. 
offset = tmp.find(",", offset+1);//offset+1위치 부터 ','의 위치를 찾는다.
 
int main()
{
    std::size_t n;
    std::string const s = "This is a string";
 
    // search from beginning of string
    n = s.find("is");
    cout << "found: " << s.substr(n) << endl;
    // found: is is a string
 
    // search from position 5
    n = s.find("is", 5);
    cout << "found: " << s.substr(n) << endl;
    // found: is a string
 
    // find a single character
    n = s.find('a');
    cout << "found: " << s.substr(n) << endl;
    // found: a string
 
    // find a single character
    n = s.find('q');
    if (n == string::npos)
        cout << "not found character" << endl;
    else
        cout << "found: " << s.substr(n) << endl;
    //not found character
}
~~~

## std::find()
 - vector, list등의 container에서 찾을 경우,  
  return type은 iterator이다.  
 - 찾지 못하면 iterator::end()를 return한다.  
 - 전달 인자로 찾을 범위(시작 위치, 끝 위치), 찾을 대상을 전달한다.  
~~~C++
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40 };
  int * p;

  p = std::find (myints, myints+4, 30);
  if (p != myints+4)
    std::cout << "Element found in myints: " << *p << '\n';
  else
    std::cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";
~~~

## substr()
 - 첫번째 전달인자로 문자열을 자르기 시작할 위치, 자를 길이를 전달한다.  
~~~C++
// string substr (size_t pos = 0, size_t len = npos) const;
int main()
{
    std::string a = "0123456789abcdefghij";
 
    // count is npos, returns [pos, size())
    std::string sub1 = a.substr(10);
    std::cout << sub1 << '\n';
    // abcdefghij
 
    // both pos and pos+count are within bounds, returns [pos, pos+count)
    std::string sub2 = a.substr(5, 3);
    std::cout << sub2 << '\n';
    // 567
 
    // pos is within bounds, pos+count is not, returns [pos, size()) 
    std::string sub4 = a.substr(a.size()-3, 50);
    // this is effectively equivalent to
    // std::string sub4 = a.substr(17, 3);
    // since a.size() == 20, pos == a.size()-3 == 17, and a.size()-pos == 3
 
    std::cout << sub4 << '\n';
    // hij
 
    try {
        // pos is out of bounds, throws
        std::string sub5 = a.substr(a.size()+3, 50);
        std::cout << sub5 << '\n';
    } catch(const std::out_of_range& e) {
        std::cout << "pos exceeds string size\n";
    }
}
~~~

## count
~~~C++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
        vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
        for (int i = 1; i <= 5; i++) {
                cout << i << ": " << count(a.begin(), a.end(), i) << endl;
        }

        int evenNumCount = count_if(a.begin(), a.end(), [](int x){return x % 2 == 0;});
        cout << "even num count: " << evenNumCount << endl;

        return 0;
}
~~~

## fill
~~~C++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
        vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
        cout << "before fill: ";
        for (auto d : a)
                cout << d << ' ';
        cout << endl << endl;

        fill(a.begin(), a.end(), 0);
        cout << "after fill: ";
        for (int x : a)
                cout << x << ' ';
        cout << endl;

        return 0;
}
~~~

## tokenize
C 의 string.h를 include해서 strtok을 사용할 수 있지만,  
C++스럽지 못하다.  
substr()을 사용하는 것이 좋다.
~~~C++
#include <iostream>
#include <string>

using namespace std;

int main() {
        string const cur_day = "2022:06:30";
        string const cur_time = "10:41:33";

        size_t n = 0;
        string token = ":";
        string day_buf = cur_day;
        while ((n = day_buf.find(token)) != string::npos) {
                //size_t offset = day_buf.find(token);
                string tmp = day_buf.substr(0, n);
                cout << tmp << endl;
                day_buf = day_buf.substr(n+(token.size()));
                cout << "current buf: " << day_buf << endl;
        }
        cout << day_buf << endl;


        return 0;
}

~~~

## sort
 - 일반적인 사용법
~~~C++
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int main() {
        int n = 0;
        vector<pair<int, int>> a = {{1, 3}, {7, 5}, {5, 2}, {3, 7}};

        cout << "before sort: {";
        for (auto p: a) {
                cout << "{" << p.first << ", " << p.second << "}, ";
        }
        cout << "}" << endl;

        sort(a.begin(), a.end());
        cout << "after sort: {";
        for (auto p: a) {
                cout << "{" << p.first << ", " << p.second << "}, ";
        }
        cout << "}" << endl;

        sort(a.begin(), a.end(), [](pair<int, int> p1, pair<int, int> p2){
                if (p1.first > p2.first) return true;
                else return false;
        });
        cout << "after lambda sort: {";
        for (auto p: a) {
                cout << "{" << p.first << ", " << p.second << "}, ";
        }
        cout << "}" << endl;


        //sort(a.begin(), a.end(), greater<pair<int, int>>());
        sort(a.begin(), a.end(), less<pair<int, int>>());
        cout << "after std greater sort: {";
        for (auto p: a) {
                cout << "{" << p.first << ", " << p.second << "}, ";
        }
        cout << "}" << endl;

       //before sort: {{1, 3}, {7, 5}, {5, 2}, {3, 7}, }
       //after sort: {{1, 3}, {3, 7}, {5, 2}, {7, 5}, }
       //after lambda sort: {{7, 5}, {5, 2}, {3, 7}, {1, 3}, }
       //after std greater sort: {{1, 3}, {3, 7}, {5, 2}, {7, 5}, }

        return 0;
}

~~~

 - 중첩된 vector를 sort할 경우, 
   - 정렬할 값을 앞으로 이동시켜서 정렬할 수 있다.
   - customize된 sort를 사용
   - container를 정렬 시에 customize된 sort를 사용할 경우에 대한 사용법  
    https://www.geeksforgeeks.org/sort-c-stl/

 - 같은 값이 중복될 경우, index순으로 정렬하기 위해서는 stable_sort를 사용해야한다.
 - custom comparator를 사용할 경우, 매개변수가 참조값일 경우, error가 발생한다.
    단순 값을 매개변수로 해야한다.
~~~C++
bool customHeadNumCompare(vector<string> lhs, vector<string> rhs) {
    if (lhs[0] < rhs[0])
        return true;
    else if (lhs[0] == rhs[0]) {
        if (stoi(lhs[1]) < stoi(rhs[1]))    return true;
        else                                return false;
    }
    else
        return false;
}

int main() {
    vector<vector<string>> vv = {
        {"a-", "10", "2"},
        {"b-", "50", "1"},
        {"f-", "14", "3"},
        {"f-", "5", "0"},
    };
    cout << "before sort: " << endl;
    printVV(vv);
    sort(vv.begin()+2, vv.end(), customHeadNumCompare);
    stable_sort(vv.begin(), vv.end(), customHeadNumCompare);
    cout << "after sort: " << endl;
    printVV(vv);

    return 0;
}
~~~
  

실행 결과  
~~~
before sort: 
a-, 10, 2, 
b-, 50, 1, 
f-, 14, 3, 
f-, 5, 0, 
after sort: 
a-, 10, 2, 
b-, 50, 1, 
f-, 5, 0, 
f-, 14, 3, 
~~~

## string
 - compare()  
 string을 compare할 경우, 아래처럼 <, >연산자로 사전순을 비교할 수 있다.  
~~~C++
str1 > str2
~~~
  
 - find()  
 아래의 두가지가 가능
 str.find(ch);
 str.find(ch, pos);
 - to_string()  
 int를 string 으로 변환
 - stoi()  
 string을 int로 변환
 - atoi()  
 c type의 문자열을 int로 변환
 stdlib.h를 사용

## lambda
 - 이름 없는 함수.  
   이름으로 부르는 보통의 함수와는 달리, 람다는 이름이 없기 때문에  
   std::function 변수로 저장을 해놓고 나중에 부르는 방식으로 콜백처럼 사용이 가능하다.  
   (한번만 일회적으로 불리는 함수일 경우에는 콜백이 필요 없겠지만..)  
 - 함수와는 달리 선언+정의가 합쳐진 특이한 함수이다.  
   아래와 같은 함수의 선언과 정의가 한번에 된다.  
   int func1(int); int func(int a) { return a;}  
   위 함수를 람다로 바꾸면, 이렇게 된다.  
   ~~~C++
   [=](int a){return a;};  
   ~~~
   C++17부터는 반환타입도 명시적으로 표시할 수 있다.  
   ~~~C++
   [=](int a) -> int {return a;};  
   ~~~
   일반화해서 표현하면, 아래처럼 표현이 가능하다.  
   ~~~C++
   [captures](parameters) -> return type { body }  
   ~~~
   &은 주변 변수들을 참조할 수 있고, =은 단순 값의 전달이다.  
   객체 내에서 사용해보면 &을 사용하면 멤버변수에 접근이 가능한 것을 확인할 수 있다.  
 - 그 당시의 주변 변수를 캡쳐할 수 있는 기능이 있다.  
  
## list, vector, queue, pair
  
## isdigit()
 - ctype.h 를 include 해야한다.
 - 전달 인자로는 char타입의 변수를 전달
 - 숫자이면 1, 숫자가 아니면 0을 반환한다.
  
## priority_queue
  
## programmers
programmers 문제 중 기본 테스트케이스는 통과했으나  
다른 문제들이 통과되지 않을 경우,  
전달 인자를 참조해서 값을 바꿔서 문제가 되는 경우도 있다.  
주로 core dump 에러가 발생한다.  
파일명정렬(lv2_sorting_filename)이나 다른 문제들도 같은 케이스가 몇번 있었다.  
코딩테스트 시에는 가급적이면 참조 매개변수 보다는 값에 의히나 전달을 사용하는 것이 좋을 듯하다.  
