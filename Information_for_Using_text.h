#include "useful.h"

// I need to rewrite text, because I have new arguments

str Information_for_Using_text_function(
    str Comparator,
    str In_other_paths,
    str In_this_paths,
    str OBJ_1,
    str OBJ_2,
    str For_comparator,
    str Result_file_1,
    str Result_file_2,
    str Result_file,
    str Ghost_file_1,
    str Ghost_file_2,
    str Ghost_file,
    str Result_folder,
    str First_compared_element,
    str Second_compared_element,
    str Where_is_this_file,
    str Where_is_this_file_alt,
    str info
)
{
    str text = 
        "\t\t\t\t\t\t\tABOUT\n" 
        "\tThis is a program \"" + Comparator + "\". We use the program for comparing two files. \n"
        "I would call they \"objects\"\n\n"
        "\t\t\t\t\t\t\tWHAT TYPES OF FILE \""+Comparator+"\" CAN GET DATA?\n\n"
        "\tThe program can get data if there was file. Also can get data in types of file: folders, regular files and symlinks \n"
        "but it can not get data in types of file: blocks, characters, fifos and sockets because because a developer used library <filesystem> and didn't \n"
        "know how to get data from they. I know he could include other library but he was lazy. \n\n"
        "\t\t\t\t\t\t\tWHAT OC I WOULD USE\n"
        "\t If you use POSIX or macOC/Linux, you are lucky because Windows's users can check types only folders and regular files. The program \n"
        "for ect types make to unknown.\n\n"
        "\t\t\t\t\t\t\tWHAT HAPPENING IN START THE PROGRAM\n" 
        "\tThe program creates a text file \""+info+"\". There are information for using the program in this text file. \n"
        "After creating text file, the program gives you choosing. \n"
        "If you chose \"[1] In folder \"" + Comparator + "\" and I move elements inside the folder\", the program creates a folder \""+In_this_paths+"\".\n"
        "Else if you chose \"[2] I show you the way with my written path\", the program create a folder \""+In_other_paths+"\".\n"
        "After choosing, the program create a folder, I would call it \"project\". In active the program, you can ask the program to rename the folder to name which you choose. \n"
        "If you don't want what the program creates too many project, you can choose program in program's proccess. \n"
        "After creating a project, if your choosing is first way - \"" + Comparator + "\" and I move elements inside the folder\", the program creates a folder \"" + For_comparator + "\" \n"
        "and you have to move two objects in the folder for comparing. And if your choosing is second way \"[2] I show you the way with my written path\", \n"
        "the program give you choose objects in writing and program creates text files \""+OBJ_1+"\" and \""+OBJ_2+"\" and they have paths to your objects. \n"
        "\t\tBe careful, if your objects' paths have cyrillic/chines/ect characters, you should write alone in text files \""+OBJ_1+"\" and \""+OBJ_2+"\" \n"
        "else the program won't be able to find objects. \n"
        "After choosing objects the program cleans project from result in comparing. \n"
        "After cleaning, the program give you choose setting news of comparing.\n\n"
        "\t\t\t\t\t\t\tWHAT IS HAPPENING AFTER COMPARING?\n" 
        "After comparing, you can see files of result:\n"
        "\tThe folder \""+Result_folder+"\" has different lines of text files, different sizes of regular files and different targets of symlinks. \n"
        "The folder is created when your objects are folders. \n"
        "\tThe text files\""+Result_file_1+"\" and \""+Result_file_2+"\" have different types or different data (sizes, lines, targets and etc). \n"
        "If objects' data a equal, the text files are not created and the program create a text file \""+Result_file+"\" \n"
        "which text for exemple \"THE ARE BLOCK\". \n"
        "\tThe text files \""+Ghost_file_1+"\" and \""+Ghost_file_2+"\" have paths which are not exists. \n"
        "If two file are not exists, the program doesn't create \""+Ghost_file_1+"\" and \""+Ghost_file_2+"\" and create \""+Ghost_file+"\".\n"
        "\tThe folders \""+First_compared_element+"\" and \""+Second_compared_element+" have different lines in you text objects.\n\n"
        "\t\t\t\t\t\t\tWHO IS DEVELOPERS\n"
        "\tThe developer is Priymak Roman form Z-22. \n"
        "\tThe helpers are ChatGPT and Google AI. \n\n\n\n\n\n"
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