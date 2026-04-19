#pragma once
#include "useful.h"

str Information_for_Using_text_function(
    const str& Comparator,
    const str& In_other_paths,
    const str& In_this_paths,
    const str& OBJ_1,
    const str& OBJ_2,
    const str& For_comparator,
    const str& Result_file_1,
    const str& Result_file_2,
    const str& Result_file,
    const str& Ghost_file_1,
    const str& Ghost_file_2,
    const str& Ghost_file,
    const str& Result_folder,
    const str& First_compared_element,
    const str& Second_compared_element,
    const str& Where_is_this_file,
    const str& Where_is_this_file_alt,
    const str& info
)
{
    str text =
    "\t\t\t\t\t\t\tABOUT\n"
    "\tThis is a program called \"" + Comparator + "\". It is used to compare two files.\n"
    "I call these files \"objects\".\n\n"

    "\t\t\t\t\t\t\tWHAT TYPES OF FILES CAN \"" + Comparator + "\" PROCESS?\n\n"
    "\tThe program can process existing files. It can work with the following file types: "
    "folders, regular files, and symlinks.\n"
    "However, it cannot process block devices, character devices, FIFOs, or sockets. "
    "This is because the developer used the <filesystem> library and did not know how to "
    "retrieve data from these file types.\n"
    "The developer could have included another library, but he was lazy.\n\n"

    "\t\t\t\t\t\t\tWHAT OS CAN I USE?\n"
    "\tIf you use POSIX systems or macOS/Linux, you are lucky. Windows users can only check "
    "folders and regular files.\n"
    "Other file types are marked as unknown.\n"
    "If you use Windows, you must have Windows 8.1 or newer, because Windows 7 does not "
    "have a correct implementation of the <filesystem> library.\n\n"

    "\t\t\t\t\t\t\tWHAT HAPPENS WHEN THE PROGRAM STARTS?\n"
    "\tThe program creates a text file called \"" + info + "\".\n"
    "This file contains information about how to use the program.\n"
    "After creating the text file, the program asks you to make a choice.\n"
    "If you choose \"[1] In folder \"" + Comparator + "\" and move elements into the folder\", "
    "the program creates a folder called \"" + In_this_paths + "\".\n"
    "If you choose \"[2] I show you the path by writing it manually\", "
    "the program creates a folder called \"" + In_other_paths + "\".\n"
    "After that, the program creates a folder called a \"project\".\n"
    "While the program is running, you can rename the project folder to any name you want.\n"
    "If you do not want the program to create too many projects, you can select an existing "
    "project during the program's execution.\n\n"

    "If your choice is the first option, the program creates a folder called \"" + For_comparator + "\".\n"
    "You must place two objects inside this folder for comparison.\n"
    "If your choice is the second option, you must manually specify the paths to the objects.\n"
    "The program creates two text files: \"" + OBJ_1 + "\" and \"" + OBJ_2 + "\", "
    "which contain the paths to your objects.\n"
    "\tBe careful: if your object paths contain Cyrillic, Chinese, or other non-ASCII characters, "
    "you must write the paths manually in the files \"" + OBJ_1 + "\" and \"" + OBJ_2 + "\".\n"
    "Otherwise, the program may not be able to find the objects.\n\n"

    "After selecting the objects, the program cleans the project from previous comparison results.\n"
    "Then, the program allows you to configure new comparison settings.\n\n"

    "\t\t\t\t\t\t\tWHY CAN SOME FILES EXIST FOR ME BUT NOT FOR THE PROGRAM?\n"
    "\tSome files may be visible to you but not accessible to the program for the following reasons:\n"
    "\t1. Unsupported encoding.\n"
    "\t2. Security restrictions.\n"
    "\t3. Symlinks without valid targets.\n"
    "\t4. Invalid characters in file names.\n"
    "\t5. Paths that are too long.\n"
    "\tetc.\n\n"

    "\t\t\t\t\t\t\tWHAT HAPPENS AFTER COMPARISON?\n"
    "After comparison, you may see the following result files:\n"
    "\tThe folder \"" + Result_folder + "\" contains files with different text lines, "
    "different sizes of regular files, or different symlink targets.\n"
    "This folder is created when both objects are folders.\n"
    "\tThe text files \"" + Result_file_1 + "\" and \"" + Result_file_2 + "\" contain differences "
    "in file types or data (size, text lines, targets, etc.).\n"
    "If the objects are equal, these files are not created. Instead, the program creates "
    "a file called \"" + Result_file + "\" with text such as \"THEY ARE EQUAL\".\n"
    "\tThe text files \"" + Ghost_file_1 + "\" and \"" + Ghost_file_2 + "\" contain paths "
    "to files that do not exist.\n"
    "If both files do not exist, the program creates only \"" + Ghost_file + "\".\n"
    "\tThe folders \"" + First_compared_element + "\" and \"" + Second_compared_element +
    "\" contain different lines from your text objects.\n\n"

    "\t\t\t\t\t\t\tWHO ARE THE DEVELOPERS?\n"
    "\tThe developer is Priymak Roman from Z-22.\n"
    "\tHelpers: ChatGPT and Google AI.\n\n"

        "\t\t\t\t\t\t\tSTRUCT FOR EXEMPLE:\n\n"
        "\t"+Comparator+".exe\n"
        "\t"+Comparator+" v\n"
        "\t\t"+info+"\n"
        "\t\t"+In_this_paths+" v\n"
        "\t\t\t[Project_1] v\n"
        "\t\t\t\t"+For_comparator+" v\n"
        "\t\t\t\t\t[Object_1] \n"
        "\t\t\t\t\t[Object_2] \n"
        "\t\t\t\t"+Result_folder+" v\n"
        "\t\t\t\t\t0.000001 v\n"
        "\t\t\t\t\t\t"+First_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t\t\t[Text-File]\n"
        "\t\t\t\t\t\t"+Second_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t\t\t[Text-File]\n"
        "\t\t\t\t\t0.000002 v\n"
        "\t\t\t\t\t\t"+First_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t\t"+Second_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t0.000003 >\n"
        "\t\t\t\t\t0.000004 >\n"
        "\t\t\t\t\t...\n"
        "\t\t\t[Project_2] v\n"
        "\t\t\t\t"+For_comparator+" v\n"
        "\t\t\t\t\t[Object_1] \n"
        "\t\t\t\t\t[Object_2] \n"
        "\t\t\t\t"+Result_file+"\n"
        "\t\t\t\t"+Ghost_file+"\n"
        "\t\t\t[Project_3] >\n"
        "\t\t\t[Project_4] >\n"
        "\t\t\t[Project_5] >\n"
        "\t\t\t...\n"
        "\t\t"+In_other_paths+" v\n"
        "\t\t\t[Project_1] v\n"
        "\t\t\t\t"+OBJ_1+"\n"
        "\t\t\t\t"+OBJ_2+"\n"
        "\t\t\t\t"+Result_folder+" v\n"
        "\t\t\t\t\t0.000001 v\n"
        "\t\t\t\t\t\t"+First_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t\t\t[Text-File]\n"
        "\t\t\t\t\t\t"+Second_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t\t\t[Text-File]\n"
        "\t\t\t\t\t0.000002 v\n"
        "\t\t\t\t\t\t"+First_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t\t"+Second_compared_element+"v\n"
        "\t\t\t\t\t\t\t"+Where_is_this_file+"\n"
        "\t\t\t\t\t0.000003 >\n"
        "\t\t\t\t\t0.000004 >\n"
        "\t\t\t\t\t...\n"
        "\t\t\t[Project_2] >\n"
        "\t\t\t[Project_3] >\n"
        "\t\t\t[Project_4] >\n"
        "\t\t\t[Project_5] >\n"
        "\t\t\t...\n";

    return text;
}