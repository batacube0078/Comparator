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

// ERRORS
str er_wd = "\n      ERROR: YOU HAVE ENTERED THE WRONG DATA!";
str er_cur = "\n      ERROR: I CAN NOT SHOW CURRENT DIRECTORY!";
str er_del = "\n      ERROR: I CAN NOT DELETE THE ELEMENT!";
str er_mk = "\n      ERROR: I CAN NOT CREATE FOLDER!";
str er_open = "\n       ERROR: I CAN NOT OPEN THE FILE!";

// Useful
str space; // This always empty. Use and don't touch !!!
vec_char vec_space_char; // This always empty. Use and don't touch !!!

// for answer
str a = "===> ";

//////////////////////////////////////////
void print(vec_str texts, bool b = 1)
{
    std::cout << "{ " << std::flush;
    for (const str &text : texts)
    {
        std::cout << "\"" << text << "\"," << std::flush;
    }
    std::cout << " }" << std::flush;

    if (b)
        std::cout << std::endl;
}

template <typename T>
void print(T text, bool b = 1)
{
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



void break_program(str text = "THE PROGRAM IS BROKEN")
{
    throw std::runtime_error(text);
}

vec_str split(str text, vec_char C = vec_space_char)   // "C" this is vector of characters, "c" this is character
{
    vec_str array;
    str element;

    if (C != vec_space_char) {
        for (const char& character : text)
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

/////////////////////////////////////////


