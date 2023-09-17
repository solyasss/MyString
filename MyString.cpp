#include "MyString.h"
#include <iostream>
#include <cstring>

using namespace std;

int MyString::object_count = 0;

MyString::MyString()
{
    length = 80;
    str = new char[length];
    str[0] = '\0';
    object_count++;
}

MyString::MyString(int size)
{
    length = size;
    str = new char[length];
    str[0] = '\0';
    object_count++;
}

MyString::MyString(const char *input)
{
    length = strlen(input) + 1;
    str = new char[length];
    strcpy(str, input);
    object_count++;
}

MyString::~MyString()
{
    delete[] str;
    object_count--;
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

MyString MyString::operator+(const MyString &other) const
{
    int new_length = length + other.length - 1;
    MyString result(new_length);
    strcpy(result.str, str);
    strcat(result.str, other.str);
    return result;
}

MyString &MyString::operator+=(const MyString &other)
{
    int new_length = length + other.length - 1;
    char *new_str = new char[new_length];
    strcpy(new_str, str);
    strcat(new_str, other.str);
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

void MyString::my_strcpy(const MyString &other)
{
    delete[] str;
    length = other.length;
    str = new char[length];
    strcpy(str, other.str);
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

void MyString::my_strcat(const MyString &other)
{
    int new_length = length + other.length - 1;
    char *new_str = new char[new_length];
    strcpy(new_str, str);
    strcat(new_str, other.str);
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

int MyString::my_strcmp(const MyString &other) const
{
    return strcmp(str, other.str);
}

int MyString::get_object_count()
{
    return object_count;
}
