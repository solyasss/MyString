#include "MyString.h"
#include <iostream>
#include <cstring>

using namespace std;

int MyString::count = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length];
    str[0] = '\0';
    count++;
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length];
    str[0] = '\0';
    count++;
}

MyString::MyString(const char *input)
{
    length = strlen(input) + 1;
    str = new char[length];
    strcpy(str, input);
    count++;
}

MyString::MyString(const MyString &obj)
{
    length = obj.length;
    str = new char[length];
    strcpy(str, obj.str);
    count++;
}

MyString::MyString(MyString &&obj)
{
    length = obj.length;
    str = obj.str;
    obj.str = nullptr;
    count++;
}

MyString::~MyString()
{
    delete[] str;
    count--;
}

MyString &MyString::operator=(const MyString &obj)
{
    if (this != &obj)
    {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }
    return *this;
}

MyString &MyString::operator=(MyString &&obj)
{
    if (this != &obj)
    {
        delete[] str;
        length = obj.length;
        str = obj.str;
        obj.str = nullptr;
    }
    return *this;
}

void MyString::input_string()
{
    cout << "Enter string: ";
    cin.getline(str, length);
}

void MyString::display_string() const
{
    cout << "String: " << str << endl;
}

MyString MyString::operator+(const MyString &obj) const
{
    int new_length = length + obj.length - 1;
    MyString result(new_length);
    strcpy(result.str, str);
    strcat(result.str, obj.str);
    return result;
}

MyString &MyString::operator+=(const MyString &obj)
{
    int new_length = length + obj.length - 1;
    char *new_str = new char[new_length];
    strcpy(new_str, str);
    strcat(new_str, obj.str);
    delete[] str;
    str = new_str;
    length = new_length;
    return *this;
}

char &MyString::operator[](int index)
{
    if (index >= 0 && index < length)
    {
        return str[index];
    }
}

const char &MyString::operator[](int index) const
{
    if (index >= 0 && index < length)
    {
        return str[index];
    }
}

void MyString::my_strcpy(const MyString &obj)
{
    delete[] str;
    length = obj.length;
    str = new char[length];
    strcpy(str, obj.str);
}

bool MyString::my_strstr(const char *substr) const
{
    return (strstr(str, substr) != nullptr);
}

int MyString::my_chr(char c) const
{
    char *ptr = strchr(str, c);
    if (ptr != nullptr)
    {
        return ptr - str;
    }
    return -1;
}

int MyString::my_strlen() const
{
    return length;
}

void MyString::my_strcat(const MyString &obj)
{
    int new_length = length + obj.length - 1;
    char *new_str = new char[new_length];
    strcpy(new_str, str);
    strcat(new_str, obj.str);
    delete[] str;
    str = new_str;
    length = new_length;
}

void MyString::my_del_chr(char c)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    length = count + 1;
}

int MyString::my_strcmp(const MyString &obj) const
{
    return strcmp(str, obj.str);
}

int MyString::get_object_count()
{
    return count;
}

MyString::MyString(initializer_list<char> param)
{
    length = param.size();
    str = new char[length];
    int i = 0;
    for (auto pt = param.begin(); pt != param.end(); pt++)
    {
        str[i] = *pt;
        i++;
    }
    str[length] = '\0';
}

char *MyString::get_str() const
{
    return str;
}

void MyString::set_str(const char *n)
{
    if (str != nullptr)
    {
        delete[] str;
    }
    length = strlen(n);
    str = new char[length + 1];
    strcpy(str, n);
}

int MyString::get_length() const
{
    return length;
}

void MyString::set_length(int n)
{
    if (n >= 0)
    {
        length = n;
    }
    else
    {
        length = 0;
    }
}

ostream &MyString::operator<<(ostream &o) const
{
    o << str;
    return o;
}

istream &MyString::operator>>(istream &i)
{
    char buff[1000];
    i.getline(buff, 1000);
    set_str(buff);
    return i;
}