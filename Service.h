#include "useful_fs.h"
#include "Information_for_Using_text.h"
#include "random.h"
#include "News_in_Comparing.h"

//  CLASSES
NEWS news;

// Dangerous
str dangerous_chars = "\\/:*?\"<>|"; // "Dangerous" characters that must not be used in file names

void write(str text, str path, bool b = 1) // Writes "text" to "path". If b is true, the system uses std::ios_base::app, otherwise it rewrites the file
{
    if (!b)
    {
        fs::path p(path);
        std::ofstream recording(p);
        if (text != space)
            recording << text << std::endl;
        recording.close();
    }
    else
    {
        fs::path p(path);
        std::ofstream recording(p, std::ios_base::app);
        if (text != space)
            recording << text << std::endl;
        recording.close();
    }
}

str read(str path, bool b = 1)      // If "b" is false, system use std::ios_base::binary
{
    try
    {
        if (!b)
        {
            fs::path p(path);
            std::ifstream file_stream(p, std::ios_base::binary);
            if (!file_stream)
                return space;

            str content; // content of the file at the given path
            char c;      // for each character

            while (file_stream.get(c))
            {
                content.push_back(c);
            }

            file_stream.close();

            return content;
        }
        else
        {
            fs::path p(path);
            std::ifstream file_stream(p);
            if (!file_stream)
                return space;

            int count = 0; // Count of lines in text file
            str Full_content;
            str content;
            // file_stream >> content;            // It can not read text with " "

            while (std::getline(file_stream, content))
            {
                count++;
            }
            file_stream.clear();                      // Clear EOF
            file_stream.seekg(0, std::ios_base::beg); // System read the file again

            for (int i = 0; i < count; i++)
            {
                std::getline(file_stream, content);
                Full_content += content;
                if (i != count - 1)
                    Full_content += "\n";
            }

            file_stream.close();

            return Full_content;
        }
    }
    catch (...)
    {
        return space;
    }
}

// My directory structure:

/*  v myProject
        v Comparator
            v In_other_paths
                v project_exemple_1
                    OBJECT_1.txt
                    OBJECT_2.txt
                    Result_file_1.txt
                    Result_file_2.txt
                    v Result_folder
                        v 0.000001
                            v #1_element
                                Where.txt
                                [name_compared_file]
                            v #2_element
                                Where.txt
                                [name_compared_file]
                        > 0.000002
                        > 0.000003
                        > 0.000004
                        ...
                    Ghost_file_1.txt
                    Ghost_file_2.txt
                > project_exemple_2
                > project_exemple_3
                ...
            v In_this_paths
                v project_exemple_1
                    v For_comparator
                        [Object_1]
                        [Object_2]
                    Result_file_1.txt
                    Result_file_2.txt
                    v Result_folder
                        v 0.000001
                            v #1_element
                                Where.txt
                                [name_compared_file]
                            v #2_element
                                Where.txt
                                [name_compared_file]
                        > 0.000002
                        > 0.000003
                        > 0.000004
                        ...
                    Ghost_file_1.txt
                    Ghost_file_2.txt
                > project_exemple_2
                > project_exemple_3
                ...

*/

/////////////////////////////////////////////////////////////////////[ REGISTRATION ]//////////////////////////////////////////////////////////////////////////

str PATH = current(); // Your current path

/////////////////////////////////////////[ FIRST FUNCTION ]////////////////////////////////////////

str Comparator = "Comparator";
str Comparator_path; // path

str Information_for_Using = "Information.txt"; // It explains how to use "Comparator"
str Information_for_Using_path;                // path

//////////////////////////////////////////[ THIRD FUNCTION ]///////////////////////////////////////

str In_other_paths = "In_other_paths";
str In_other_paths__path; // path

str In_this_paths = "In_this_paths";
str In_this_paths__path; // path

//////////////////////////////////////////[ FOURTH FUNCTION ]//////////////////////////////////////

str Project_path; // For exemple: C:\User\Document\Project\er4EF77r

///////////////////////////////////////////[ FIFTH FUNCTION ]//////////////////////////////////////

str OBJ_1 = "OBJECT_1.txt";
str OBJ__1; // path in "Comparator". This is a text file

str OBJ_2 = "OBJECT_2.txt";
str OBJ__2; // path in "Comparator". This is a text file

str For_comparator = "For_comparator";
str For_comparator_path; // path

/////////////////////////////////////////////////

str OBJECT_1; // path for comparing.    It is the most IMPORTANT in Service
str OBJECT_2; // path for comparing.    It is the most IMPORTANT in Service
vec_str OBJECTS;        //  For using LOOP
/////////////////////////////////////////////[ SIXTH FUNCTION ]////////////////////////////////////

str Result_file = "Result_file.txt";
str Result_file_path; // path
str Result_file_1 = "Result_file_1.txt";
str Result_file_path_1; // path
str Result_file_2 = "Result_file_2.txt";
str Result_file_path_2; // path

str Ghost_file = "Ghost_files.txt";
str Ghost_file_path; // path
str Ghost_file_1 = "Ghost_files_1.txt";
str Ghost_file_path_1; // path
str Ghost_file_2 = "Ghost_files_2.txt";
str Ghost_file_path_2; // path

str Result_folder = "Result_folder";
str Result_folder_path; // path

str First_compared_element = "#1_element";  // \0.000001\#1 element
str Second_compared_element = "#2_element"; // \0.000001\#2 element

str Where_is_this_file = "Where.txt";             // \0.000001\#1 element\Where.txt
str Where_is_this_file_alt = "Where_is_this.txt"; // \0.000001\#1 element\Where_is_this.txt       Used if compared folder has regular file with name "Where.txt"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Print_main(bool q = false, int Q = 0)
{ // Used to check the main path variables

    print("\n");
    switch (Q)
    {
    case 0:
        print(Comparator);
        print(Comparator_path);
        if (q)
            break;
    case 1:
        print(In_other_paths);
        print(In_other_paths__path);
        if (q)
            break;
    case 2:
        print(In_this_paths);
        print(In_this_paths__path);
        if (q)
            break;
    case 3:
        print(Project_path);
        if (q)
            break;
    case 4:
        print(OBJ_1);
        print(OBJ__1);
        print(OBJECT_1);
        if (q)
            break;
    case 5:
        print(OBJ_2);
        print(OBJ__2);
        print(OBJECT_2);
        if (q)
            break;
    case 6:
        print(For_comparator);
        print(For_comparator_path);
        if (q)
            break;
    case 7:
        print(Result_folder);
        print(Result_folder_path);
        if (q)
            break;
    case 8:
        print(Result_file_1);
        print(Result_file_path_1);
        if (q)
            break;
    case 9:
        print(Result_file_2);
        print(Result_file_path_2);
        if (q)
            break;
    case 10:
        print(Result_file);
        print(Result_file_path);
        if (q)
            break;
    case 11:
        print(Ghost_file_1);
        print(Ghost_file_path_1);
        if (q)
            break;
    case 12:
        print(Ghost_file_2);
        print(Ghost_file_path_2);
        if (q)
            break;
    case 13:
        print(Ghost_file);
        print(Ghost_file_path);
        if (q)
            break;
    case 14:
        print(Information_for_Using);
        print(Information_for_Using_path);
    default:
        break;
    }
    print("\n");
}

class Service
{

    void seven()
    {
        print("What information from Comparing do you want to see?");
        print("[Something] Nothing");
        print("[1] I want see news that program got or opened file/folder/etc");
        print("[2] I want see news that program font different types in paths");
        print("[3] I want see news that program font different lines in text file");
        print("[4] I choose [1] and [2]");
        print("[5] I choose [2] and [3]");
        print("[6] I choose [1] and [3]");
        print("[7] I choose [1], [2] and [3]");
        print("[8] I choose [7] and I want to see type in paths");

        str v = input();
        int Set_message = 0; // It used for class NEWS in file News_for_Comparing.h
        try
        {
            Set_message = std::stoi(v);
        }
        catch (...)
        {
        }

        news.Setting_for_output_news(Set_message);
    }

    bool six() // System remove Result_folder, Result_file.txt and Ghost_file.txt
    {
        while (true)
        {
            Result_file_path = Project_path + "/" + Result_file;
            Result_file_path_1 = Project_path + "/" + Result_file_1;
            Result_file_path_2 = Project_path + "/" + Result_file_2;
            Result_folder_path = Project_path + "/" + Result_folder;
            Ghost_file_path_1 = Project_path + "/" + Ghost_file_1;
            Ghost_file_path_2 = Project_path + "/" + Ghost_file_2;
            Ghost_file_path = Project_path + "/" + Ghost_file;
            str First_path = Project_path + "/" + First_compared_element;
            str Second_path = Project_path + "/" + Second_compared_element;
            vec_str Victims_for_removing = {Result_file_path_1, Result_file_path,
                                            Result_file_path_2, Result_folder_path,
                                            Ghost_file_path_1, Ghost_file_path_2, Ghost_file_path,
                                            First_path, Second_path};

            print("Do you want to clear to full \"" + Project_path + "\" from rubbish?");
            print("[0] No");
            print("[Other] Yes");

            if (input() != "0")
            {
                remove(Result_file_path_1);
                remove(Result_file_path_2);
                remove(Result_file_path);
                remove(Result_folder_path);
                remove(Ghost_file_path_1);
                remove(Ghost_file_path_2);
                remove(Ghost_file_path);
                remove(First_path);
                remove(Second_path);

                bool b = there_is(Result_file_path) || there_is(Result_file_path_1) ||
                         there_is(Result_file_path_2) || there_is(Ghost_file_path) ||
                         there_is(Ghost_file_path_1) || there_is(Ghost_file_path_2) ||
                         there_is(Result_folder_path) || there_is(First_path) ||
                         there_is(Second_path);
                if (b) {
                    print("I can not delete some from they");
                    continue;
                }
            }
            else 
            {
                for (const str &victim : Victims_for_removing)
                {
                    while (there_is(victim))
                    {
                        str q = "Can I remove \"" + victim + "\"? I don't need it. It can let me!";
                        str v0 = "[#] No and I move it to other folder";
                        str v1 = "[Other] Yeah";

                        print(q);
                        print(v0);
                        print(v1);

                        if (input() == "#")
                        {
                            str text = "Ok. I wait.";
                            q = "Are you ready? [Something]: ";
                            print(text);
                            print(q, 0);
                            print(v1);
                            str v = input();
                        }

                        remove(victim);
                        if (there_is(victim))
                        {
                            print("I cannot remove it. If you don't fix the problem or you don't move it to other folder, \nI break the running!");
                            str q666 = "Are you ready? [Something]: ";
                            print(q666, 0);
                            str v = input();

                            if (there_is(victim))
                            {
                                print("I said you");
                                str fuck_break_135 = "THE RUNNING IS BROKEN BY PROGRAM, BECAUSE IT WAS OFFERED BY USER!";
                                return break_program(fuck_break_135);
                            }

                            continue;
                        }
                    }
                }
            }

            
            break;
        }
        return 1;
    }



    bool five_1() // System take OBJECT_1 and OBJECT_2 from folder For_Comparator, if you choose In_this_paths
    {
        while (true)
        {
            For_comparator_path = Project_path + "/" + For_comparator;

            while (!is_dir(For_comparator_path)) // Fix problem with the folder For_Comparator
            {
                str q = "Can I create it?";
                str v0 = "[#] No and CANCEL THE WAY";
                str v1 = "[Other] Yes";
                str text = "The folder \"" + For_comparator + "\" in \"" + In_this_paths + "\" was not created by me!";

                if (there_is(For_comparator_path))
                {
                    text = "Folder \"" + For_comparator + "\" in " + In_this_paths + " is not folder!";
                    q = "Can I recreate it to folder? \n(If this file is important for you, you should move to other directory)";
                }

                print(text);
                print(q);
                print(v0);
                print(v1);

                if (input() == "#")
                    return false;

                if (there_is(For_comparator_path))
                {
                    remove(For_comparator_path);
                    if (there_is(For_comparator_path))
                    {
                        print("I cannot remove it");
                        continue;
                    }
                }

                if (!there_is(For_comparator_path))
                {
                    make_dir(For_comparator_path);
                    if (there_is(For_comparator_path))
                        break;
                }
            }

            while (number_of_in_dir(For_comparator_path) != 2) // Fix problem with number of folder, if there is more 2 files or less
            {
                str text = "The folder \"" + For_comparator + "\" must contain exactly 2 elements for comparison, not " + to_str(number_of_in_dir(For_comparator_path)) + " elements!";
                str q = "You have to correct your sins";
                str v0 = "[#] No and CANCEL THE WAY!";
                str v1 = "[Other] Yes";
                print(text);
                print(q);
                print(v0);
                print(v1);
                if (input("Are you ready?: ") == "#")
                    return false;
            }

            while (true) // Take OBJECT_1 and OBJECT_2 in the folder For_comparator_path
            {
                vec_str OBJECTS_in_service = in_dir(For_comparator_path); // ./For_comparator/[OBJECT1]     and     ./For_comparator/[OBJECT2]
                OBJECT_1 = OBJECTS_in_service[0];                         // FIRST ELEMENT
                OBJECT_2 = OBJECTS_in_service[1];                         // SECOND ELEMENT

                str text1 = "The first element is \"" + OBJECT_1 + "\" and the second element is \"" + OBJECT_2 + "\".";
                str q = "Right?";
                str v0 = "[#] No and CANCEL THE WAY!";
                str v1 = "[0] No and I change elements";
                str v2 = "[Other] Yes";

                print(text1);
                print(q);
                print(v0);
                print(v1);
                print(v2);
                str v = input();

                if (v == "#")
                    return false;
                if (v == "0")
                {
                    print("Are you ready?");
                    print("[#] No and CANCEL THE WAY!");
                    print(v2);
                    if (input() == "#")
                        return false;
                    break;
                }
                return true;
            }
        }
    }

    bool five_2() // System take OBJECT_1 and OBJECT_2 from OBJ__1 and OBJ__2, if you choose In_other_paths
    {
        while (true)
        {

            OBJ__1 = Project_path + "/" + OBJ_1;
            OBJ__2 = Project_path + "/" + OBJ_2;
            bool b = !is_text_file(OBJ__1) || !is_text_file(OBJ__2);
            while (b) // You input data or create text files alone
            {
                str q = "Are you ready to write data (paths)?";
                str v0 = "[#] No and CANCEL THE WAY!";
                str v1 = "[0] No, my paths don't have only English character";
                str v2 = "[Other] Yes";

                print(q);
                print(v0);
                print(v1);
                print(v2);

                str v = input();

                if (v == "#")
                    return false;

                while (v == "0") // You create text files alone
                {
                    if (!there_is(OBJ__1))
                        write("", OBJ__1);
                    if (!there_is(OBJ__2))
                        write("", OBJ__2);

                    str text = "OK, I will wait until you write or rewrite the paths in \"" + OBJ_1 + "\" and \"" + OBJ_2 + "\".";
                    q = "Are you ready?";
                    v1 = "[0] My paths have already had changing and my paths have only English text";

                    print(text);
                    print(q);
                    print(v0);
                    print(v1);
                    print(v2);
                    v = input();


                    if (v == "#")
                        return false;
                    if (v == "0")
                        break;
                    else
                    {

                        OBJECT_1 = read(OBJ__1);

                        OBJECT_2 = read(OBJ__2);

                        text = "Your elements are \"" + OBJECT_1 + "\" and \"" + OBJECT_2 + "\".";
                        q = "Right?";

                        v1 = "[0] No and I REWRITE PATH";

                        print(text);
                        print(q);
                        print(v0);
                        print(v1);
                        print(v2);

                        v = input();

                        print("OK");

                        if (v == "#")
                            return false;
                        if (v == "0")
                            continue;
                        return true;
                    }
                }

                if (v != "0" && v != "#") // System create text files
                {
                    while ((there_is(OBJ__1) && !is_text_file(OBJ__1)) || (there_is(OBJ__2) && !is_text_file(OBJ__2))) // Removing notext files: OBJ__1 and OBJ__2
                    {
                        str text = "I remove your ";
                        str text1 = "it is";
                        str text2;
                        if (there_is(OBJ__1))
                        {
                            text += "\"" + OBJ__1 + "\"";
                        }
                        if (there_is(OBJ__1) && there_is(OBJ__2))
                        {
                            text += " and ";
                            text1 = "they are";
                            text2 = "s";
                        }
                        if (there_is(OBJ__2))
                        {
                            text += "\"" + OBJ__2 + "\"";
                        }
                        text += " because " + text1 + " not a text file.";
                        q = "OK?";
                        v0 = "[#] No and CANCEL THE WAY!";
                        v1 = "[0] No and I change the file" + text2 + " or remove the file" + text2 + " alone";
                        v2 = "[Other] Yeah";
                        print(text);
                        print(q);
                        print(v0);
                        print(v1);
                        print(v2);
                        v = input();
                        if (v == "#")
                            return false;
                        if (v == "0")
                        {
                            print("Are you ready?");
                            print(v0);
                            print(v2);
                            if (input() == "#")
                                return false;
                            continue;
                        }
                        while (!is_text_file(OBJ__1)) // Remove OBJ__1
                        {
                            remove(OBJ__1);
                            if (there_is(OBJ__1))
                            {
                                text = "I can not remove \"" + OBJ__1 + "\". Can you remove alone?";
                                print(text);
                                print(v0);
                                print(v1);
                                if (input() == "#")
                                    return false;
                                continue;
                            }
                        }
                        while (!is_text_file(OBJ__2)) // Remove OBJ__2
                        {
                            remove(OBJ__2);
                            if (there_is(OBJ__2))
                            {
                                text = "I can not remove \"" + OBJ__2 + "\". Can you remove alone?";
                                print(text);
                                print(v0);
                                print(v1);
                                if (input() == "#")
                                    return false;
                                continue;
                            }
                        }
                    }

                    while (true) //  Input OBJECT_1 and OBJECT_2
                    {
                        if (!there_is(OBJ__1))
                            OBJECT_1 = input("What is your First element?: ");
                        else
                            OBJECT_1 = read(OBJ__1);
                        if (!there_is(OBJ__2))
                            OBJECT_2 = input("What is your Second element?: ");
                        else
                            OBJECT_2 = read(OBJ__2);

                        str text = "Your elements are \"" + OBJECT_1 + "\" and \"" + OBJECT_2 + "\".";
                        q = "Right?";
                        v0 = "[#] No and CANCEL THE WAY";
                        v1 = "[0] No and REWRITE PATHS";
                        v2 = "[Other] Yeah";

                        print(text);
                        print(q);
                        print(v0);
                        print(v1);
                        print(v2);

                        v = input();

                        if (v == "#")
                            return false;
                        if (v == "0")
                            break;

                        write(OBJECT_1, OBJ__1, 0);
                        write(OBJECT_2, OBJ__2, 0);
                        return true;
                    }
                }
            }

            while (!b) // System take OBJECT_1 and OBJECT_2 from OBJ__1 and OBJ__2
            {
                OBJECT_1 = read(OBJ__1);
                OBJECT_2 = read(OBJ__2);

                str text = "The elements for comparison are \"" + OBJECT_1 + "\" and \"" + OBJECT_2 + "\".";
                str q = "Right?";
                str v0 = "[#] No and CANCEL THE WAY!";
                str v1 = "[0] No and I change the elements";
                str v2 = "[Other] Yeah";

                print(text);
                print(q);
                print(v0);
                print(v1);
                print(v2);

                str v = input();

                if (v == "#")
                    return false;
                if (v == "0")
                {
                    print("Are you ready?");
                    print(v0);
                    print(v2);
                    if (input() == "#")
                        return false;
                    break;
                }

                return true;
            }
        }
    }

    bool five(str path) // You have two ways of taking OBJECT_1 and OBJECT_2
    {
        if (path == In_this_paths__path)
            return five_1();
        else if (path == In_other_paths__path)
            return five_2();
        else
            return false;
    }

    bool four_1(str path)
    { // You create a new folder in In_(other, this)_path
        while (true)
        {
            str r = random_string_each(15, dangerous_chars, 0, '_');
            if (there_is_FOF(r, path))
                continue;
            str text = "I create folder with name \"" + r + "\" in \"" + path + "\"";
            str text1 = "Do you want to rename the folder?";
            str v0 = "[#] CANCEL";
            str v1 = "[1] No";
            str v2 = "[2] Yeah";

            print(text);
            print(text1);
            print(v1);
            print(v2);
            print(v0);

            str v = input(a);

            if (v == "#")
            {
                return false;
            }
            if (v == "1" || v == "2")
            {
                str n = r;
                if (v == "2")
                {
                    str text2 = "What name do you want to choose? (PLease, write without ( ? \" \\ / : * | < > ), I will change the char to \" _ \"): ";
                    n = input(text2);

                    str n2;
                    int coll_dangerous_char = 0;

                    for (const char &check_dangerous_char : n)
                    {
                        bool dangerous = false;
                        for (const char &dangerous_char : dangerous_chars)
                        {
                            // std::cout << "D" << dangerous_char << "D" << std::endl; // rubbish
                            if (dangerous_char == check_dangerous_char)
                            {

                                print("Changed!");
                                coll_dangerous_char++;
                                dangerous = true;
                                n2 += '_';
                                break;
                            }
                        }
                        if (!dangerous)
                            n2 += check_dangerous_char;
                    }
                    if (coll_dangerous_char > 0)
                        n = n2;

                    if (there_is_FOF(n, path))
                    {
                        str text4 = "The folder with name \"" + n + "\" is already created. \nChoose other name!";
                        print(text4);
                        // n = input(text2);
                        continue;
                    }
                }

                str name = path + "/" + n;
                make_dir(name);
                if (there_is(name))
                {
                    Project_path = name;
                    if (path == In_this_paths__path)
                    {
                        For_comparator_path = Project_path + "/" + For_comparator;
                        make_dir(For_comparator_path);
                    }

                    return true;
                }
            }
            else
            {
                print(er_wd);
            }
        }
    }

    bool four(str path)
    { // If In_(other, this)_path is empty, \
                        create folder. For exemple: project_exemple or you choose name.\
                        If In_(other, this)_path is not empty, you choose folder for comparing \
                        or you create a new but creating in different function "four_1" \
                        \
                        the method is key of break in loop inmethod "two"

        if (empty(path))
        {
            if (!four_1(path))
                return false;
            return true;
        }
        else
        {
            vec_str containings = in_dir(path);

            str vs = "[Other] CREATE A NEW";
            str v0 = "[#] CANCEL AND BACK";

            print(v0);

            vec_str containings_vec_str;

            int n_containing = 0;
            for (const str &containing : containings) // You take PATHS from in_dir(path)
            {
                str vn = "[" + to_str(n_containing) + "] " + FOF_without_path(containing); // [0] Name_file
                containings_vec_str.push_back(FOF_without_path(containing));
                print(vn);
                n_containing++;
            }

            print(vs);

            str v = input();

            bool condition_containing = false;
            str chosen_v_file; // if you choose 0 where "[0] Project555". The variable has \
                                    "Project555". str chosen_v_file = "Project555";
            for (int n_containing = 0; n_containing < containings_vec_str.size(); n_containing++)
            {
                if (v == to_str(n_containing))
                {
                    condition_containing = true;
                    chosen_v_file = containings_vec_str[n_containing];
                    break;
                }
            }

            if (v == "#")
                return false;
            else if (condition_containing)
            {
                Project_path = path + "/" + chosen_v_file;
                return true;
            }
            else // If you chose [Other]
            {
                if (!four_1(path))
                    return false;
                return true;
            }
        }
    }

    bool three_1(str path) // It create or recreate "In_other_paths__path" and "In_this_paths__path"
    {
        while (true) {
            

            while (!is_dir(path))
            {
                //str text = "Folder \"" + path + "\" in \"" + Comparator + "\" is not created by me!";
                if (there_is(path))
                {
                    str text = "The folder \"" + path + "\" in " + Comparator + " is not folder!";
                    str q = "Can I recreate it to folder? /n(If this file is important for you, you should move to other directory)";
                    str v0 = "[#] No";
                    str v1 = "[Other] Yes";

                    print(text);
                    print(q);
                    print(v0);
                    print(v1);

                    str v = input(a);
                    if (v == "#")
                        return false;
                }



                if (there_is(path)) // I don't create variable bools because I wart give user time for move undirectory
                {
                    remove(path);
                    print("I cannot remove it");
                    continue;
                }
                if (!there_is(path))
                {
                    make_dir(path);
                    if (there_is(path))
                        break;
                }
            }
            if (is_dir(path))
                return true;
        }
    }

    bool three(str variant_of_answer) // It create or recreate "In_other_paths__path" and "In_this_paths__path"
    {

        if (variant_of_answer == "1")
        {
            In_this_paths__path = Comparator_path + "/" + In_this_paths;
            return three_1(In_this_paths__path);
        }
        if (variant_of_answer == "2")
        {
            In_other_paths__path = Comparator_path + "/" + In_other_paths;
            return three_1(In_other_paths__path);
        }
        else
            return false;
    }

    bool two() // You choose where system compare your files/folders
    {
        str text = "Where should I compare your files/folders/etc?";
        str v1 = "[1] In folder \"" + Comparator + "\" and I move elements inside the folder";
        str v2 = "[2] I show you the way with my written path";
        str v0 = "[#] BREAK THE RUNNING";

        while (true) // For getting OBJECT_1 and OBJECT_2 and create construction
        {
            print(text);
            print(v0);
            print(v1);
            print(v2);

            str v = input(a);

            if (v == "#")
            {
                return break_program();
            }
            else if (v == "1")
            {
                if (three(v))
                {
                    if (four(In_this_paths__path))
                    {
                        if (five(In_this_paths__path))
                            break;
                    }
                }
            }
            else if (v == "2")
            {
                if (three(v))
                {
                    if (four(In_other_paths__path))
                    {
                        if (five(In_other_paths__path))
                            break;
                    }
                }
            }
            else
                print(er_wd);
        }


        if (!six()) return 0;
        seven();
        return 1;
    }

    bool one() // It create or recreate a folder "Comparator" and write Informaiton.txt in the folder
    {
        Comparator_path = PATH + "/" + Comparator;
        while (!is_dir(Comparator_path))
        {
            str text = "Folder \"" + Comparator + "\" in \"" + PATH + "\" is not created by me";
            str q = "Can I create it?";

            if (there_is(Comparator_path))
            {
                text = "\"" + Comparator + "\" is not folder";
                q = "Can I recreate it to folder? \n(If this file is important for you, you should move to other directory)";
            }

            str v1 = "[Other] Yes";
            str v0 = "[#] No and BREAK THE RUNNING";
            print(text);
            print(q);
            print(v0);
            print(v1);
            if (input(a) == "#")
                return break_program();

            if (there_is(Comparator_path)) // I don't create variable bools because I want give user time for move undirectory
                remove(Comparator_path);
            if (!there_is(Comparator_path))
            {
                In_other_paths__path = Comparator_path + "/" + In_other_paths;
                In_this_paths__path = Comparator_path + "/" + In_this_paths;
                make_dir(Comparator_path);

                if (there_is(Comparator_path))
                {
                    make_dir(In_other_paths__path);
                    make_dir(In_this_paths__path);
                    break;
                }
            }
        }

        // Informaiton

        Information_for_Using_path = Comparator_path + "/" + Information_for_Using;
        str Information_for_Using_text_is_read = read(Information_for_Using_path);
        str Information_for_Using_text = Information_for_Using_text_function(
            Comparator, In_other_paths, In_this_paths,
            OBJ_1, OBJ_2, For_comparator, Result_file_1, Result_file_2,
            Result_file, Ghost_file_1, Ghost_file_2, Ghost_file,
            Result_folder, First_compared_element,
            Second_compared_element, Where_is_this_file,
            Where_is_this_file_alt, Information_for_Using);

        bool b = Information_for_Using_text_is_read == Information_for_Using_text;

        while (!is_text_file(Information_for_Using_path) || !b)
        {

            str text = !is_text_file(Information_for_Using_path) ? "an" : "to update the";
            print("Do you need " + text + " information of using the program?");
            print("[#] No");
            print("[Other] Yeah [RECOMMENDED]");

            if (input() != "#")
            {

                while (there_is(Information_for_Using_path) && !is_text_file(Information_for_Using_path)) // Removing Information.txt
                {
                    print("I remove the " + Information_for_Using + " in \"" + Comparator_path + "\". It can let me. If the notext file is important for you, you move the file in other directories\nCan I remove it?");
                    print("[#] No and I don't want to get " + Information_for_Using + " more");
                    print("[Other] Yeah");

                    if (input() != "#")
                    {
                        remove(Information_for_Using_path);
                        if (there_is(Information_for_Using_path))
                        {
                            print("I can not remove " + Information_for_Using + ".");
                            // break;        // I would not put the code. Because: If System can't remove file => break, Else not break
                        }
                    }
                    break;
                }

                while (!there_is(Information_for_Using_path) || !b) // Writing Informations
                {
                    write(Information_for_Using_text, Information_for_Using_path, 0);
                    Information_for_Using_text = space;
                    break;
                }
            }

            break;
        }
        return two();
    }

public:
    bool service_start()
    {
        if (!one()) return 0;
        str error_in_equal = "THE FIRST ELEMENT \"" + OBJECT_1 + "\" AND THE SECOND ELEMENT \"" 
            + OBJECT_2 + "\" ARE EQUAL! THERE IS NO POINT IN COMPARING ELEMENTS!";
        if (OBJECT_1 == OBJECT_2)
            return break_program(error_in_equal);
        OBJECTS = {OBJECT_1, OBJECT_2};   

        return 1;
    }
};
