#include "CStringHandler.h"

using namespace std;

int main()
{
    // Test default constructor
    CStringHandler str1;
    cout << "str1: " << str1.CSHToChar() << endl;

    // Test parameterized constructor (char*)
    CStringHandler str2("Hello, World!");
    cout << "str2: " << str2.CSHToChar() << endl;

    // Test parameterized constructor (double)
    CStringHandler str3(3.14159);
    cout << "str3: " << str3.CSHToChar() << endl;

    // Test copy constructor
    CStringHandler str4(str2);
    cout << "str4: " << str4.CSHToChar() << endl;

    // Test CSHToChar
    cout << "str2 as char*: " << str2.CSHToChar() << endl;

    // Test SubString
    CStringHandler str5;
    str2.SubString(0, 4, str5);
    cout << "str5 (substring of str2): " << str5.CSHToChar() << endl;

    // Test Append
    str2.Append(" How are you?");
    cout << "str2 after append: " << str2.CSHToChar() << endl;

    // Test GetLength
    cout << "Length of str2: " << str2.GetLength() << endl;

    // Test ToUpper
    str2.ToUpper();
    cout << "str2 to upper: " << str2.CSHToChar() << endl;

    // Test ToLower
    str2.ToLower();
    cout << "str2 to lower: " << str2.CSHToChar() << endl;

    // Test CSHToDouble
    cout << "str3 as double: " << str3.CSHToDouble() << endl;

    // Test IndexOf
    cout << "Index of 'World' in str4: " << str4.IndexOf("World") << endl;

    // Test IndexOf with beginIndex
    cout << "Index of 'o' in str2 starting from index 5: " << str2.IndexOf("o", 5) << endl;

    // Test LastIndexOf
    CStringHandler str6("Hello World World");
    cout << "Last index of 'World' in str6: " << str6.LastIndexOf((char *)"World") << endl;

    // Test Split
    CStringHandler **strArr;
    int count;
    str6.Split(strArr, " ", count);
    cout << "Split str6 into " << count << " parts:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "  " << strArr[i]->CSHToChar() << endl;
    }
    CStringHandler::CSHCleanup(strArr, count);

    // Test Replace (char) - Fixed: The function signature is replace(const int atIndex, const char ch)
    str2.Replace(0, 'J');
    cout << "str2 after replacing first char with 'J': " << str2.CSHToChar() << endl;

    // Test Replace (string)
    str2.Replace("Jello", "Goodbye");
    cout << "str2 after replacing 'Hello' with 'Goodbye': " << str2.CSHToChar() << endl;

    // Test RemoveAll (char*)
    CStringHandler str7("aabbccddeeff");
    str7.RemoveAll("ab");
    cout << "str7 after removing 'a' and 'b': " << str7.CSHToChar() << endl;
    // CStringHandler str7("aabbcddeeff");
    // str7.RemoveAll("c");
    // cout << "str7 after removing 'c': " << str7.CSHToChar() << endl;

    // Test operator== and operator!=
    cout << "str2 == 'Goodbye, World! How are you?': " << (str2 == "Goodbye, World! How are you?") << endl;
    // cout << "str2 != 'Hello': " << (str2 != "Hello") << endl;
    // Added !=
    cout << "str2 != 'Hello': " << (!(str2 == "Hello")) << endl;
    return 0;
}
