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

    MyString str5 = {'H', 'e', 'l', 'l', 'o'};
    str5.display_string();

    cout << "String: " << str5.get_str() << endl;
    cout << "Length: " << str5.get_length() << endl;

    str5.set_str("New:");
    str5.set_length(11);

    cout << "New string: " << str5.get_str() << endl;
    cout << "New length: " << str5.get_length() << endl;

    cout << "At index 3: " << str5[3] << endl;

    MyString s1("Hello");
    MyString s2(" World");
    MyString s3 = s1 + 10;
    MyString s4 = 10 + s2;

    cout << "s3: " << s3.get_str() << endl;
    cout << "s4: " << s4.get_str() << endl;

    s1 += 10;
    cout << "s1: " << s1.get_str() << endl;

    return 0;
}
