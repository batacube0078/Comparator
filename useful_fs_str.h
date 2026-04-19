#pragma once
#include "useful.h"
#include <filesystem>
#include <fstream>

namespace ufs {
// Dangerous
// "Dangerous" characters that must not be used in file names
str dangerous_chars = "\\/:*?\"<>|";
#ifdef _WIN32
    vec<char> cutter_characters = {'\\', '/'};
#elif __APPLE___
    vec<char> cutter_characters = {'/', ':'};
#else
    vec<char> cutter_characters = {'/'};
#endif

namespace fs = std::filesystem;
using fsp = fs::path;
using ferror = fs::filesystem_error;

void print_er(const ferror &er, const str &message = "Error: ")
    {
        std::cerr << message << er.what() << std::endl;
        if (!er.path1().empty())
            std::cerr << er.path1() << std::endl;
        if (!er.path2().empty())
            std::cerr << er.path2() << std::endl;
    }

bool there_is_FOF(const str &fof, const str &path) //  Is there element in folder
{
    try {
        str full = path + "/" + fof;
        fs::path p(full);
        return fs::exists(p);
    } catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

bool there_is(const str &path) //  Is there path in your OC
{
    try
    {
        return fs::exists(path);
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
    
    
}

bool make_dir(const str& path)             // Create folder
{
    if (!there_is(path))
    {
        std::error_code ec;
        try
        {
            fs::path p (path);
            bool ok = fs::create_directory(p, ec);

            if (ec)
            {
                //print("      ERROR: ", 0);
                //print(ec);
                return false;
            }
            else
            {
                if (!ok)
                {
                    print("Folder is already created or ERROR");
                    return false;
                }
            }
            return true;
        }
        catch (const ferror& er)
        {
            print_er(er);
            print(er_mk);
            print(ec);
            return false;
        }
    }
    else return true;
}

bool empty(const str &path) // Is this file empty?
{
    return fs::is_empty(path);
}

str current()                   // Return your current path
{
    try
    {
        fs::path p = fs::current_path();
        return p.string();
    }
    catch (const ferror& er)
    {
        print_er(er);
        print(er_cur);
        return space;
    }
}

bool is_dir(const str &path) // Is this path directory
{
    try {
        if (there_is(path)) {
            fs::path p(path);
            if (fs::is_directory(p))
                return true;
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

bool is_reg(const str &path) // Is this path regular
{
    try {
        if (there_is(path)) {
            fs::path p (path);
            if (fs::is_regular_file(p)) return true;
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
    
}

bool is_binary_file(const str &path) // Is this path binary file?
{
    try
    {
        fs::path p(path);
        if (!is_reg(path))
            return false;

        std::ifstream file(p, std::ios::binary);
        if (!file.is_open())
            return false;

        char buffer[1000000];
        file.read(buffer, sizeof(buffer));
        std::streamsize bytes_read = file.gcount();

        int suspicious = 0;
        for (std::streamsize i = 0; i < bytes_read; i++)
        {
            unsigned char c = buffer[i];
            if ((c < 32 || c == 127) && c != '\t' && c != '\n' && c != '\r' && c >= 0)
                ++suspicious;
        }

        double ratio = (bytes_read > 0) ? (double)suspicious / bytes_read : 0.0;
        return ratio > 0.0; // >0% of spacial characters ==> binary file
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool is_text_file(const str &path) // Is this a text file?
{
    try {
        if (!is_reg(path))
            return false;

        if (is_binary_file(path))
            return false;


        fs::path p (path);
        std::ifstream file (p);
        if (!file.is_open())
        {
            print(er_open);
            return false;
        }


        return true;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

bool is_slk(const str &path) // Is this path symlink
{
    try {
        if (there_is(path)) {
            fs::path p (path);
            if (fs::is_symlink(p)) return true;
        }
        return false;
    } 
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

bool is_block(const str &path) // Is this path block
{
    try {
        if (there_is(path))
        {
            fs::path p (path);
            return fs::is_block_file(p);
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

bool is_char_file(const str &path) // Is this path character file
{
    try {
        if (there_is(path))
        {
            fs::path p (path);
            return fs::is_character_file(p);
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
    
}

bool is_fifo_file(const str &path) // Is this path fifo
{
    try {
        if (there_is(path))
        {
            fs::path p (path);
            return fs::is_fifo(p);
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

bool is_sock(const str &path)
{
    try {
        if (there_is(path))
        {
            fs::path p (path);
            return fs::is_socket(p);
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}   

bool is_unknown (const str& path)
{
    try {
        if (there_is(path))
        {
            fs::path p (path);
            return fs::is_other(p);
        }
        return false;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return false;
    }
}

str read_target (const str& path)          // System read symlink's target 
{
    try 
    {
        if (is_slk(path))
        {
            fs::path p (path);
            fs::path result = fs::read_symlink(p);
            
            return result.string();
        }
        return space;
    }
    catch (const ferror& er)
    {
        print_er(er);
        return space;
    }
}



/*bool is_none_type_file (str path)           // IT IS FUCKING WRONG
{
    if (there_is(path))
    {
        if (is_dir(path))
            return false;
        if (is_reg(path))
            return false;
        if (is_block(path))
            return false;
        if (is_slk(path))
            return false;
        if (is_char_file(path))
            return false;
        if (is_fifo_file(path))
            return false;
        if (is_sock(path))
            return false;
        if (is_unknown(path))
            return false;
        return 1;
    }
    return false;
}*/


vec<str> in_dir(const str &path)        // Input array which elements are full paths
{
    fs::path p(path);
    vec<str> result_in_dir; // All containing

    if (!is_dir(path))
    { // If the path is not folder
        str text = "        ERROR: PATH \"" + path + "\" IS NOT FOLDER";
        print(text);
        return result_in_dir;
    }

    try
    {
        for (const auto &containing : fs::directory_iterator(p))
        {
            fs::path containing_p = containing.path(); // I don't understand method "path()". Maybe it does variable in fs::path
            str Containing = containing_p.string();    // Containing is string
            result_in_dir.push_back(Containing);       // Push containing in result_in_dir
        }

        return result_in_dir;
    }
    catch (const ferror& er) {
        print_er(er);
        return result_in_dir;
    }
}   

int count_of_in_dir(const str& path)      // number of elements in folder
{
    if (is_dir(path))
        return in_dir(path).size();

    return 0;
}


void remove(const str& path)       // delete file and folder
{
    try
    {
        if (there_is(path))
        {
            fs::path p(path);
            if (!is_dir(path) || (is_dir(path) && empty(path)))
            {
                bool rubbish_1 = fs::remove(p); // for files and empty folder
            }
            else
            {
                std::uintmax_t rubbish_1 = fs::remove_all(p);
            }
        }
    }
    catch (const ferror& er)
    {
        print_er(er);
        print(er_del);
    }
}

str FOF_without_path(const str& path)      // For exemple: {"C:", "User", "Document", "Project"} ===> "Project"
{ 
    return fs::path(path).filename().string();
}



str What_is_type_of_file(const str& path) 
{
    if (there_is(path))
    {
        if (is_dir(path))
            return "FOLDER";
        if (is_reg(path))
            return "REGULAR-FILE";
        if (is_slk(path))
            return "SYMLINK";
        if (is_block(path))
            return "BLOCK";
        if (is_char_file(path))
            return "CHARACTER";
        if (is_fifo_file(path))
            return "FIFO";
        if (is_sock(path))
            return "SOCKET";
        return "UNKOWN-TYPE";
    }
    return "NOT-EXIST";
}

}