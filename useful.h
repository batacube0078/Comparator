#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // for std::runtime_error()

// string
using str = std::string;

//  vectors
using vec_str = std::vector<str>;
using vec_int = std::vector<int>;
using vec_char = std::vector<char>;
using vec_bool = std::vector<bool>;
using vec_double = std::vector<double>;
using vec_float = std::vector<float>;

// ERRORS
str er_wd = "\n      ERROR: YOU HAVE ENTERED THE WRONG DATA!";
str er_cur = "\n      ERROR: I CAN NOT SHOW CURRENT DIRECTORY!";
str er_del = "\n      ERROR: I CAN NOT DELETE THE ELEMENT!";
str er_mk = "\n      ERROR: I CAN NOT CREATE FOLDER!";
str er_open = "\n       ERROR: I CAN NOT OPEN THE FILE!";

// Useful
str space; // This is always empty. Use and don't touch !!!
vec_char vec_space_char; // This is always empty. Use and don't touch !!!

// for answer
str a = "===> ";

//////////////////////////////////////////
void print(vec_str texts, bool b = 1, bool b1 = 1)
{
    if (b1)
        std::cout << "{ " << std::flush;
    else 
        std::cout << "{ ";

    for (const str &text : texts)
    {
        if (b1)
            std::cout << "\"" << text << "\"," << std::flush;
        else
            std::cout << "\"" << text << "\",";
    }
    if (b1)
        std::cout << " }" << std::flush;
    else 
        std::cout << " }";

    if (b)
        std::cout << std::endl;
}

template <typename T>
void print(T text, bool b = 1, bool b1 = 1)
{
    if (b1)
        std::cout << text  << std::flush;
    else 
        std::cout << text/* << std::flush*/;

    if (b)
        std::cout << std::endl;
}

str input(str text = a)
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

str to_str(vec_char C) 
{
    str result;
    for (char c : C) {
        result.push_back(c);
    }
    return result;
}

template <typename T>
str to_str(T v)
{
    return std::to_string(v);
}



template <typename T>
bool inside(T ELEMENT, std::vector<T> ARRAY)     //  9 in array with has {1, 2, 8, 6}?  No
{
    for (T element : ARRAY)
    {
        if (ELEMENT == element)
            return true;
    }
    return false;
}


vec_str mirror_str(vec_str usual) //  {1, 2, 3, 4, 5} ==> {5, 4, 3, 2, 1}
{
    vec_str result;

    for (int i = 0; i < usual.size(); i++) 
    {
        result.push_back(usual[usual.size() - 1 - i]);
    }
    return result;
}

vec_int mirror_int(vec_int usual)
{
    vec_int result;

    for (int i = 0; i < usual.size(); i++)
    {
        result.push_back(usual[usual.size() - 1 - i]);
    }
    return result;
}





void break_program(str text = "THE PROGRAM IS BROKEN")
{
    throw std::runtime_error(text);
}


str join (vec_str array_str, char c = 0) 
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

vec_str split(str text, vec_char C = vec_space_char)   // "C" this is vector of characters, "c" this is character
{
    vec_str array;
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


vec_str split(str text, char c)
{
    vec_str result;
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


