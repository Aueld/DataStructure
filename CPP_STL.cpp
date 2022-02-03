#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template<typename T>

void stlPrint(const T& container, string message = "") // 인자가 하나만 필요한 STL 출력 가능 함수
{
    typename T::const_iterator iter; // typename인지 명시적으로 선언
    cout << message << "\t( ";
    for (iter = container.begin(); iter != container.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << ")" << endl;
}

bool checkT(string s) {
    if (s.find("t") != string::npos) return true;
    else return false;
}

template<typename T>
bool is_even(const T& num) {
    return ((num % 2) == 0);
}

int main()
{
    vector<int> vt;
    for (int i = 0; i < 10; i++) {
        vt.push_back(i);
    }
    vector<int>::iterator iter;


    stlPrint(vt, "메세지");

    iter = vt.begin();
    cout << iter[2] << endl;
    cout << *(iter + 2) << endl;
    iter += 5;
    cout << *iter << endl;
    iter--;
    cout << *iter << endl;

    list<int> li;
    for (int i = 0; i < 10; i++) {
        li.push_back(i);
    }
    list<int>::iterator it = li.begin();
    cout << *it << endl;
    //cout << *(it + 1) << endl; // 리스트는 제대로 작동하지 않음


    string ff[] = { "aa", "bb", "cc", "dd", "tff" };
    vector<string> vec(&ff[0], &ff[5]);
    vector<string>::iterator ite;

    ite = find(vec.begin(), vec.end(), "cc");
    if (ite == vec.end())
        cout << "데이터를 찾지 못헀습니다." << endl;
    else {
        cout << distance(vec.begin(), ite) << " 번째 인덱스에서 " << *ite << "를 찾았습니다." << endl;
        //두 값 사이의 거리 계산 함수
        cout << distance(vec.begin(), ite) + 1 << " 번째에서 " << *ite << "를 찾았습니다." << endl;
    }

    ite = find_if(vec.begin(), vec.end(), checkT);
    if (ite == vec.end())
        cout << "데이터를 찾지 못헀습니다." << endl;
    else {
        cout << distance(vec.begin(), ite) << " 번째 인덱스에서 " << *ite << "를 찾았습니다." << endl;
        //두 값 사이의 거리 계산 함수
        cout << distance(vec.begin(), ite) + 1 << " 번째에서 " << *ite << "를 찾았습니다." << endl;
    }


    // search = 여러개 찾는 함수
    vector<int> veci;
    for (int i = 0; i < 10; i++) {
        veci.push_back(i);
    }
    list<int> lis;
    for (int i = 3; i < 6; i++) {
        lis.push_back(i);
    }
    stlPrint(veci, "int vector");
    stlPrint(lis, "int list");
    vector<int>::iterator itS;
    itS = search(veci.begin(), veci.end(), lis.begin(), lis.end());

    // 배열값이 전부 같아야만 서칭됨.
    if (itS != veci.end()) {
        cout << distance(veci.begin(), itS) + 1 << "번째 배열에서 찾았습니다." << endl;
    }
    else cout << "발견하지 못하였습니다." << endl;

    const char* str = "I go to the school";
    vector<int> vecs;
    for (int i = 0; i < 10; i++) {
        vecs.push_back(i);
    }

    size_t n1 = count(str, str + strlen(str), 'o');
    size_t n2 = count_if(vecs.begin(), vecs.end(), is_even<int>);
    cout << n1 << endl << n2 << endl;

    return 0;
}