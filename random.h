#pragma once


#include <random>
#include "CHARACTERS.h"

static std::string CHARACTERS;

bool can_I_take_more(const std::string& traveler, const std::string& victim)    
{
    for (char t : traveler)
    {
        if (!char_in_str(t, victim)) {
            return true;
        }
    }
    return false;
}

bool can_I_take_more(const std::string& traveler, const std::vector<char>& victim)
{
    for (char t : traveler)
    {
        if (!Char_in_Vec_char(t, victim))
        {
            return true;
        }
    }
    return false;
}

char random_char()
{
    static const std::string chars = CHARACTERS;

    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, chars.size() - 1);

    return chars[dist(gen)];
}

std::string random_string_each( int  Size, 

                                const std::vector<char>& Nochar = {}, 
                                bool   system_char = 0,
 
                                char change = 0
                            )
{
    CHARACTERS = ASCII(Nochar, system_char);

    std::string result;
    for (int i = 0; i < Size; i++)
    {
        while (can_I_take_more(CHARACTERS, Nochar))
        {
            char r = random_char();
            bool b = !Char_in_Vec_char(r, Nochar);
            if (b)
            {
                result += r;
                break;
            }
            else {
                result += change;
                break;
            }
        }
    }

    return result;
}

std::string random_string_each(int  Size,

                               const std::string& Nochar = "",
                               bool   system_char = 0,

                               char change = 0)
{

    CHARACTERS = ASCII(Nochar, system_char);

    std::string result;
    for (int i = 0; i < Size; i++)
    {
        while (can_I_take_more(CHARACTERS, Nochar))
        {
            char r = random_char();
            bool b = !char_in_str(r, Nochar);
            if (b)
            {
                result += r;
                break;
            }
            else
            {
                result += change;
                break;
            }
        }
    }

    return result;
}

std::string random_string_each(int  Size,

                               char Nochar = 0,
                               bool   system_char = 0,

                               char change = 0)
{

    CHARACTERS = ASCII(Nochar, system_char);

    std::string result;
    for (int i = 0; i < Size; i++)
    {
        char r = random_char();
        bool b = r != Nochar;
        if (b)
        {
            result += r;
        }
        else
        {
            result += change;
        }
    }

    return result;
}