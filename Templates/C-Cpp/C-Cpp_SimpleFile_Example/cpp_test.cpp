/*
 * @Author: Ken Kaneki
 * @Date: 2020-04-08 13:28:49
 * @LastEditTime: 2021-05-01 16:55:02
 * @Description: README
 * @FilePath: \C-Cpp_SimpleFile_Example\cpp_test.cpp
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(T &t)
{
    cout << "left..." << endl;
}

template <typename T>
void print(T &&t)
{
    cout << "right..." << endl;
}
template <typename T>
void test(T &&t)
{
    print(t);                  // ��������������ֵ
    print(std::string(t));     // move�Ժ�����ֵ
    print(std::forward<T>(t)); // ����test��������ǰ�Ĳ�����������
}
class baseA
{
    virtual ~baseA();
};
class baseB
{
    virtual ~baseB();
};
class baseC : public baseA, public baseB
{
};

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    baseC *pC = new baseC();
    baseA *pA = (*baseA)pC;
    baseB *pB = (*baseB)pC;
    if (pC == pB)
    {
        cout << "yes";
    }
    system("pause");
    return 0;
}
