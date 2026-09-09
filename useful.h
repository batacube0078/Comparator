#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdexcept> // for std::runtime_error()

// string
using str = std::string;

//  vector
template <typename T>
using vec = std::vector<T>;



// ERRORS
str er_wd = "\n      ERROR: YOU HAVE ENTERED THE WRONG DATA!";
str er_cur = "\n      ERROR: I CAN NOT SHOW CURRENT DIRECTORY!";
str er_del = "\n      ERROR: I CAN NOT DELETE THE ELEMENT!";
str er_mk = "\n      ERROR: I CAN NOT CREATE FOLDER!";
str er_open = "\n       ERROR: I CAN NOT OPEN THE FILE!";
// Useful
str space;               // This is always empty. Use and don't touch !!!
vec<char> vec_space_char; // This is always empty. Use and don't touch !!!
// for answer
str a = "===> ";
//////////////////////////////////////////

void print(const vec<str> &texts, bool  enter = true, bool  flush = false)
{
    if (flush)
        std::cout << "{ " << std::flush;
    else
        std::cout << "{ ";
    for (const str &text : texts)
    {
        if (flush)
            std::cout << "\"" << text << "\"," << std::flush;
        else
            std::cout << "\"" << text << "\",";
    }
    if (flush)
        std::cout << " }" << std::flush;
    else
        std::cout << " }";
    if (enter)
        std::cout << std::endl;
}

template <typename T>
void print(const T &text, bool enter = true, bool flush = false)
{
    if (flush)
        std::cout << text  << std::flush;
    else 
        std::cout << text;

    if (enter)
        std::cout << std::endl;
}

template <typename T>
void DEBUGGER(const T& text, bool b = true)
{
    if (b) {
        print(text);
    }
}

str input(const str& text = a)
{
    print(text, 0);
    str text_out;
    //std::cin >> text_out;         It can not read SPACEs: "Hello, World!" ==> "Hello,"
    std::getline(std::cin, text_out);
    return text_out;
}

str to_str(char c) 
{
    str result;
    result.push_back(c);
    return result;
}

str to_str(const vec<char>& C) 
{
    str result;
    for (char c : C) {
        result.push_back(c);
    }
    return result;
}

template <typename T>
str to_str(const T& v)
{
    return std::to_string(v);
}



template <typename T>
bool inside(const T& ELEMENT, const std::vector<T> &ARRAY)     //  9 in array with has {1, 2, 8, 6}?  No
{
    for (const T& element : ARRAY)
    {
        if (ELEMENT == element)
            return true;
    }
    return false;
}



template <typename T>
vec<T> mirror_copy(vec<T> vector) {
    std::reverse(vector.begin(), vector.end());
    return vector;
}
template <typename T>
void mirror(vec<T>& vector) {
    reverse(vector.begin(), vector.end());
}






bool break_program(const str& text = "THE RUNNING IS BROKEN")
{
    //throw std::runtime_error(text);
    print(text);
    str message_and = "\n\n\n\n\n\n\n\n\n\n\nWRITE SOMETHING FOR CLOSING THE PROGRAM: ";
    input(message_and);

    return 0;
}


str join (const vec<str>& array_str, char c = 0) 
{
    str result;

    int max_size = array_str.size();

    for (int i = 0; i < max_size - 1; i++)
    {
        result += array_str[i];
        result += c;
    }
    return result + array_str[max_size - 1];
}



vec<str> split(const str& text, const vec<char>& C = vec_space_char)   // "C" this is vector of characters, "c" this is character
{
    vec<str> array;
    str element;

    if (C != vec_space_char) {
        for (char character : text)
        {
            if (inside(character, C)) {
                array.push_back(element);
                element = space;
            }
            else
            {
                element += character;
            }
        }   
    }
    else {
        array.push_back(text);
    }

    if (element != space)
        array.push_back(element);

    return array;
}


vec<str> split(const str& text, char c)
{
    vec<str> result;
    str element;
    if (c != 0) {
        for (char el : text) 
        {
            if (el == c) {
                result.push_back(element);
                element = space;
            }
            else {
                element+=el;
            }
        }
    }
    else {
        result.push_back(text);
    }
    if (element != space)
    {
        result.push_back(element);
        element = space;
    }
    

    return result;
}
/////////////////////////////////////////


