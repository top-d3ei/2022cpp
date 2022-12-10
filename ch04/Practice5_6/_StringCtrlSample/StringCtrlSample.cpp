#include "stdafx.h"
#include "MyString.h"

// void TestFunc(const CMyString& param) {
//     const char* data = param.GetString();
//     if (data != nullptr && (int)strlen(data) != 0) {
//         cout << data << endl;
//     }
// }

// void TestFunc(const CMyString& strParam) {
//     // cout << strParam.GetString() << endl;
//     cout << strParam << endl;
// }

CMyString TestFunc(void) {
    CMyString strTest("TestFunc() return");
    cout << strTest << endl;

    return strTest;
}

int main(){
    // CMyString a(move(TestFunc()));
    // cout << "__" << a << endl;

    // TestFunc();// 컴파일러가 최적화 되었나??? 이동 생성자 호출이 되지 않는다 20221207, 윈도우, vs2022에서도 마찬가지다...

    // Test Code    
    // CMyString strLeft("Hello"), strRight("World");
    // CMyString strResult(strLeft + strRight);        // shallow copy?
    // CMyString strResult = strLeft + strRight;    // shallow copy?
    // CMyString strResult(move(strLeft + strRight));   // 이동 생성자
    // CMyString strResult = move(strLeft + strRight);  // 이동 생성자

    // Test this
    // cout << &strLeft << endl;
    // strLeft.printThis();
    // cout << strLeft.returnThis() << endl;
    // cout << "-----------------------" << endl;
    // cout << &strResult << endl;
    // strResult.printThis();
    // cout << strResult.returnThis() << endl;
    // cout << "-----------------------" << endl;

    CMyString strLeft("Hello"), strRight("World"), strResult;
    // strResult = strRight;
    strResult = strLeft + strRight;
    cout << strResult << endl;

    cout << endl;

    cout << strLeft << endl;
    strLeft += CMyString("World");
    cout << strLeft << endl;

    cout << endl;
    return 0;
}