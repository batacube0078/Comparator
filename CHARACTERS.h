#pragma once

#include <string>
#include <vector>


std::string ASCII_less_32_or_equal_127 = "☺☻♥♦♣♠•◘○◙♂♀♪♫☼►◄↕‼¶§▬↨↑↓→←∟↔▲▼⌂";

std::string ASCII_not_less_32_and_not_equal_127 = " !\"#$%&'()*+,-./0123456789:;<=>?@"
                                                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                                    "abcdefghijklmnopqrstuvwxyz"
                                                    "[\\]^_`{|}~";


bool Char_in_Vec_char(char S, const std::vector<char>& V) {
    for (char el : V)
    {
        if (S == el)
        {
            return true;
        }
    }
    return false;
}

bool char_in_str(char S, const std::string& V)
{
    for (char el : V)
    {
        if (S == el)
        {
            return true;
        }
    }
    return false;
}

std::string ASCII(std::vector<char> without_vec = {}, bool system_character = true)
{

    std::string result;
    std::string full;


    for (char c : without_vec) {
        full+=c;
    }




    for (char r = 0; r < 128 && r >= 0; r++)
    {
        bool b = !char_in_str(r, full);
        if (!system_character) {
            b = b && r >= 32 && r != 127;
                
        }

        if (b) result+=r;
    }
    

    return result;
}

std::string ASCII(const std::string &without_str = "", bool system_character = true)
{
    std::string result;

    for (char r = 0; r < 128 && r >= 0; r++)
    {
        bool b = !char_in_str(r, without_str);
        if (!system_character)
        {
            b = b && r >= 32 && r != 127;
        }

        if (b)
            result += r;
    }

    return result;
}

std::string ASCII(char without_char = 0, bool system_character = true)
{
    std::string result;

    for (char r = 0; r < 128 && r >= 0; r++)
    {
        bool b = r != without_char;
        if (!system_character)
        {
            b = b && r >= 32 && r != 127;
        }

        if (b)
            result += r;
    }

    return result;
}

