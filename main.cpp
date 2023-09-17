#include "MyString.h"
#include <iostream>

using namespace std;

int main()
{
    MyString str1;
    MyString str2(100);
    MyString str3("Programming ");

    str1.input_string();
    str1.display_string();

    str3.display_string();

    str3 += "C++";
    str3.display_string();

    MyString str4 = str1 + str2;
    str4.display_string();

    cout << "Length str4: " << str4.my_strlen() << endl;

    int index = str4.my_chr('p');
    if (index != -1)
    {
        cout << "The character 'p' is found at index " << index << endl;
    }
    else
    {
        cout << "The character 'p' is not found in the string" << endl;
    }

    str4.my_del_chr('a');
    str4.display_string();

    int cmp_result = str1.my_strcmp(str2);
    if (cmp_result == 0)
    {
        cout << "The strings are equal" << endl;
    }
    else if (cmp_result < 0)
    {
        cout << "The first string is less than the second one" << endl;
    }
    else
    {
        cout << "The first string is greater than the second one" << endl;
    }

    cout << "The number of created MyString objects: " << MyString::get_object_count() << endl;

    return 0;
}
