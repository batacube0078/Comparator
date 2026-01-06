#pragma once
#include "useful.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

bool there_is_FOF(str fof, str path) //  Is there element in folder
{
    str full = path + "/" + fof;
    fs::path p(full);
    if (fs::exists(p))
        return true;
    return false;
}

bool there_is(str path) //  Is there path in your OC
{
    fs::path p(path);
    if (fs::exists(p))
        return true;
    return false;
}

void make_dir(str path)             // Create folder
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
                //return false;
            }
            else
            {
                if (!ok)
                {
                    print("Folder is already created or ERROR");
                    //return false;
                }
            }
            //return true;
        }
        catch (...)
        {
            //return false;
            print(er_mk);
        }
    }
}

bool empty(str path)            // Is this file empty?
{
    fs::path p(path);

    if (fs::is_empty(p))
        return true;
    return false;
}

str current()                   // Return your current path
{

    try
    {
        fs::path file = fs::current_path();
        str file_string = file.string();
        return file_string;
    }
    catch (...)
    {
        print(er_cur);
        return "";
    }
}


bool is_dir(str path)       // Is this path directory
{
    if (there_is(path)) {
        fs::path p(path);
        if (fs::is_directory(p))
            return true;
    }
    return false;
}

bool is_reg(str path)      // Is this path regular
{
    if (there_is(path)) {
        fs::path p (path);
        if (fs::is_regular_file(p)) return true;
    }
    return false;
}

bool is_binary_file(str path)           // Is this path binary file?
{
    try
    {
        fs::path p(path);
        if (!is_reg(path))
            return false;

        std::ifstream file(p, std::ios::binary);
        if (!file.is_open())
            return false;

        char buffer[2000000];
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
        return ratio > 0.05; // >5% of spacial characters ==> binary file
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool is_text_file(str path)         // Is this a text file?
{
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

bool is_slk(str path)       // Is this path symlink
{
    if (there_is(path)) {
        fs::path p (path);
        if (fs::is_symlink(p)) return true;
    }
    return false;
}

bool is_block(str path)         // Is this path block
{
    if (there_is(path))
    {
        fs::path p (path);
        if (fs::is_block_file(p))
            return 1;
    }
    return 0;
}

bool is_char_file(str path)          // Is this path character file
{
    if (there_is(path))
    {
        fs::path p (path);
        if (fs::is_character_file(p)) return 1;
    }
    return 0;
}

bool is_fifo_file(str path)         // Is this path fifo
{
    if (there_is(path))
    {
        fs::path p (path);
        if (fs::is_fifo(p))
            return 1;
    }
    return 0;
}

bool is_sock (str path)
{
    if (there_is(path))
    {
        fs::path p (path);
        if (fs::is_socket(p)) return 1;
    }
    return 0;
}

bool is_unknown (str path)
{
    if (there_is(path))
    {
        fs::path p (path);
        if (fs::is_other(p)) return 1;
    }
    return 0;
}

str read_target (str path)          // System read symlink's target 
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
    catch (...)
    {
        return space;
    }
}



/*bool is_none_type_file (str path)           // IT IS FUCKING WRONG
{
    if (there_is(path))
    {
        if (is_dir(path))
            return 0;
        if (is_reg(path))
            return 0;
        if (is_block(path))
            return 0;
        if (is_slk(path))
            return 0;
        if (is_char_file(path))
            return 0;
        if (is_fifo_file(path))
            return 0;
        if (is_sock(path))
            return 0;
        if (is_unknown(path))
            return 0;
        return 1;
    }
    return 0;
}*/


vec_str in_dir(str path)        // Input array which elements are full paths
{
    fs::path p(path);
    vec_str result_in_dir; // All containing

    if (!is_dir(path))
    { // If the path is not folder
        str text = "        ERROR: PATH \"" + path + "\" IS NOT FOLDER";
        print(text);
        return result_in_dir;
    }

    for (const auto &containing : fs::directory_iterator(p))
    {
        fs::path containing_p = containing.path(); // I don't understand method "path()". Maybe it does variable in fs::path
        str Containing = containing_p.string();    // Containing is string
        result_in_dir.push_back(Containing);       // Push containing in result_in_dir
    }

    return result_in_dir;
}

int number_of_in_dir(str path)      // number of elements in folder
{
    if (is_dir(path)) {
        int count = 0;
        vec_str elements_in_dir = in_dir(path);
        for (const str& rubbish1 : elements_in_dir) count++;

        return count;
    }

    return 0;
}


void remove(str path)       // delete file and folder
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
    catch (...)
    {
        print(er_del);
    }
}

str FOF_without_path(str path)      // For exemple: {"C:", "User", "Document", "Project"} ===> "Project"
{ 
    vec_str split_path = split(path, {'\\', '/'});
    return split_path[split_path.size() - 1];
}

str Exit (str path) 
{
    vec_str result = split(path, {'\\', '/'});
    result.pop_back();
    return join(result, '/');
}


str What_is_type_of_file(str path) 
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
        /*if (is_none_type_file(path))
            return "NON-TYPE";*/
        return "UNKOWN-TYPE";
    }
    return "NOT-EXIST";
}


/*void recreate(str path)
{
    //if (there_is(path))
    //    remove(path);
    if (!there_is(path))
        make_dir(path);
}*/