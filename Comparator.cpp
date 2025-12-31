#include "useful_fs.h"
#include "Information_for_Using_text.h"
#include <random>

// Dangerous    
str dangerous_chars = "\\/:*?\"<>|";        // "Dangerous" characters with you mush not use for get name files 


str random_string(size_t length)
{
    static const std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "+-;'^&%$#@!()=.,`~[{}]";

    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, chars.size() - 1);

    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i)
    {
        result += chars[dist(gen)];
    }
    return result;
}

void write(str text, str path, bool b = 1)      // Write "text" in "path". The bool "!b", if it true, system turn on std::ios_base::app else system only rewrite
{
    if (!b) {
        fs::path p (path);
        std::ofstream recording (p);
        recording << text << std::endl;
        recording.close();
    } else {
        fs::path p(path);
        std::ofstream recording(p, std::ios_base::app);
        recording << text << std::endl;
        recording.close();
    }
}

str read(str path, bool b = 1) {
    try {
        if (!b) {
            fs::path p (path);
            std::ifstream file_stream (p, std::ios_base::binary); 
            if (!file_stream) return space;

            str content;            // what are there in path
            char c;                 // for each character

            while (file_stream.get(c))
            {
                content.push_back(c);
            }

            file_stream.close();

            return content;
        }
        else {
            fs::path p (path);
            std::ifstream file_stream(p);
            if (!file_stream)
                return space;


            int count = 0;      // Count of lines in text file
            str Full_content;
            str content;
            //file_stream >> content;            // It can not read text with " "

            while (std::getline(file_stream, content))
            {
                count++;
            }
            file_stream.clear();            // Clear EOF
            file_stream.seekg(0, std::ios_base::beg);     // System read the file again 

            for (int i = 0; i < count; i++) {
                std::getline(file_stream, content);
                Full_content+=content;
                if (i != count - 1)
                    Full_content+="\n";
            }


            file_stream.close();

            return Full_content;
        }
    } catch (...) {
        return space;
    }
}


// My scheme of directories:

/*  v myProject
        v Comparator
            v In_other_paths
                v project_exemple_1
                    OBJECT_1.txt
                    OBJECT_2.txt
                    Result_file.txt
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
                    Ghost_file.txt
                > project_exemple_2
                > project_exemple_3
                ...
            v In_this_paths
                v project_exemple_1
                    v For_comparator
                        [Object_1]
                        [Object_2]
                    Result_file.txt
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
                    Ghost_file.txt
                > project_exemple_2
                > project_exemple_3
                ...

*/

/////////////////////////////////////////////////////////////////////[ REGISTRATION ]//////////////////////////////////////////////////////////////////////////

str PATH = current(); // Your current path

/////////////////////////////////////////[ FIRST FUNCTION ]////////////////////////////////////////

str Comparator = "Comparator";
str Comparator_path; // path

str Information_for_Using = "Information.txt"; // It talk about how use "Comparator"
str Information_for_Using_path;  // path

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
str OBJ__2;   // path in "Comparator". This is a text file

str For_comparator = "For_comparator";
str For_comparator_path;  // path

/////////////////////////////////////////////////

str OBJECT_1; // path for comparing
str OBJECT_2; // path for comparing

/////////////////////////////////////////////[ SIXTH FUNCTION ]////////////////////////////////////

str Result_file = "Result_file.txt";
str Result_file_path; // path

str Ghost_file = "Ghost_file.txt";
str Ghost_file_path; // path



str Result_folder = "Result_folder";
str Result_folder_path; // path

str First_compared_element = "#1_element";          // \0.000001\#1 element
str Second_compared_element = "#2_element";         // \0.000001\#2 element

str Where_is_this_file = "Where.txt";                       // \0.000001\#1 element\Where.txt
str Where_is_this_file_alt = "Where_is_this.txt";    // \0.000001\#1 element\Where_is_this.txt       Used if compared folder has regular file with name "Where.txt"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Print_main(bool q = false, int Q = 0) {     // I use it for checking variable these main paths
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
            print(Result_file);
            print(Result_file_path);
            if (q)
                break;
        case 9:
            print(Ghost_file);
            print(Ghost_file_path);
            if (q)
                break;
        case 10: 
            print(Information_for_Using);
            print(Information_for_Using_path);
        default:
            break;
    }
    print("\n");
}




class Zav
{

    void six()          // System remove Result_folder, Result_file.txt and Ghost_file.txt
    {
        while (true)
        {
            Result_file_path = Project_path + "/" + Result_file;
            Result_folder_path = Project_path + "/" + Result_folder;
            Ghost_file_path = Project_path + "/" + Ghost_file;
            vec_str Victims_for_removing = {Result_file_path, Result_folder_path, Ghost_file_path};

            for (const str &victim : Victims_for_removing)
            {
                while (there_is(victim))
                {
                    str q = "Can I remove \"" + victim + "\". It miss me.";
                    str v0 = "[#] No and I move it to other folder";
                    str v1 = "[Other] Yeah";

                    if (input() == "#") {
                        str text = "Ok. I wait.";
                        q = "Are you ready?";
                        str v = input();
                    }

                    remove(victim);
                    if (there_is(victim))
                    {
                        print("I can not remove it");
                        continue;
                    }
                }
            }

            return;

        }
    }


    bool five_1()        // System take OBJECT_1 and OBJECT_2 from folder For_Comparator, if you choose In_this_paths
    {   while (true)    {
            For_comparator_path = Project_path + "/" + For_comparator;

            while (!is_dir(For_comparator_path))       // Fix problem with the folder For_Comparator
            {
                str q = "Can I create it?";
                str v0 = "[#] No and CANCEL THE WAY";
                str v1 = "[Other] Yes";
                str text = "Folder \"" + In_this_paths + "\" in \"" + In_this_paths + "\" is not created by me!";

                if (there_is(For_comparator_path)) {
                    text = "Folder \"" + In_this_paths + "\" in " + Comparator + " is not folder!";
                    q = "Can I recreate it to folder? \n(If this file is important for you, you should move to other directory)";
                }


                print(text);
                print(q);
                print(v0);
                print(v1);

                if (input() == "#") return false;

                if (there_is(For_comparator_path))
                {
                    remove(For_comparator_path);
                    if (there_is(For_comparator_path))
                    {
                        print("I can not remove it");
                        continue;
                    }
                }

                if (!there_is(For_comparator_path)) {
                    make_dir(For_comparator_path);
                    if (there_is(For_comparator_path))
                        break;
                }
            }

            while (number_of_in_dir(For_comparator_path) != 2)      // Fix problem with number of folder, if there is more 2 files or less
            {
                str text = "In the \"" + For_comparator + "\" there would be 2 elements for comparing and not " 
                + to_str(number_of_in_dir(For_comparator_path)) + " elements!";
                str q = "You have to correct your sins";
                str v0 = "[#] No and CANCEL THE WAY!";
                str v1 = "[Other] Yes";
                print(text);
                print(q);
                print(v0);
                print(v1);
                if (input("Are you ready?: ") == "#") return false;
            } 

            while (true)        // Take OBJECT_1 and OBJECT_2 in the folder For_comparator_path
            {
                vec_str OBJECTS = in_dir(For_comparator_path); // ./For_comparator/[OBJECT1]     and     ./For_comparator/[OBJECT2]
                OBJECT_1 = OBJECTS[0];                         // FIRST ELEMENT
                OBJECT_2 = OBJECTS[1];                         // SECOND ELEMENT

                str text1 = "The first element is \"" + OBJECT_1 + "\" and the second element is \"" + OBJECT_2 + "\".";
                str q = "Right?";
                str v0 = "[#] No";
                str v1 = "[0] No and I change elements";
                str v2 = "[Other] Yes";

                print(text1);
                print(q);
                print(v0);
                print(v1);
                print(v2);
                str v = input();

                if (v == "0")
                {
                    print("Are you ready?");
                    print("[#] No and CANCEL THE WAY!");
                    print(v1);
                    if (input() == "#") return false;
                    break;
                }
                return true;
            }
        }
    }

    bool five_2()        // System take OBJECT_1 and OBJECT_2 from OBJ__1 and OBJ__2, if you choose In_other_paths
    {
        while (true)    {


            OBJ__1 = Project_path + "/" + OBJ_1;
            OBJ__2 = Project_path + "/" + OBJ_2;
            bool b  = !is_text_file(OBJ__1) || !is_text_file(OBJ__2);
            while (b)       // You input data or create text files alone
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

                if (v == "#") return false;

                while (v == "0") // You create text files alone
                {
                    str text = "OK, I wait when your write or rewrite paths in \"" + OBJ_1 + "\" and \"" + OBJ_2 + "\". Not forget create them!";
                    q = "Are you ready?";
                    v1 = "[0] My paths have already had changing";

                    print(text);
                    print(q);
                    print(v0);
                    print(v1);
                    print(v2);
                    v = input();

                    if (v == "#") return false;
                    if (v == "0") break;
                    else {
                        
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

                        if (v == "#") return false;
                        if (v == "0") continue;
                        return true;
                    }
                }

                if (v != "0" && v != "#")   // System create text files
                {
                    while ((there_is(OBJ__1) && !is_text_file(OBJ__1)) || (there_is(OBJ__2) && !is_text_file(OBJ__2))) // Removing notext files: OBJ__1 and OBJ__2
                    {
                        str text = "I remove your ";
                        str text1 = "it is";
                        str text2;
                        if (there_is(OBJ__1)) {
                            text += "\"" + OBJ__1 + "\"";
                        }
                        if (there_is(OBJ__1) && there_is(OBJ__2)) {
                            text+=" and ";
                            text1 = "they are";
                            text2 = "s";
                        }
                        if (there_is(OBJ__2))
                        {
                            text += "\"" + OBJ__2 + "\"";
                        }
                        text+=" because " + text1 + " not a text file.";
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
                        if (v == "#") return false;
                        if (v == "0") {
                            print("Are you ready?");
                            print(v0);
                            print(v2);
                            if (input() == "#") return false;
                            continue;
                        }
                        while (!is_text_file(OBJ__1)) // Remove OBJ__1
                        {
                            remove(OBJ__1);
                            if (there_is(OBJ__1)) {
                                text = "I can not remove \"" + OBJ__1 + "\". Can you remove alone?";
                                print(text);
                                print(v0);
                                print(v1);
                                if (input() == "#") return false;
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

            while (!b)      // System take OBJECT_1 and OBJECT_2 from OBJ__1 and OBJ__2
            {
                OBJECT_1 = read(OBJ__1);
                OBJECT_2 = read(OBJ__2);

                str text = "Your elements for comparing are \"" + OBJECT_1 + "\" and \"" + OBJECT_2 + "\".";
                str q = "Right?";
                str v0 = "[#] No and CANCEL THE WAT!";
                str v1 = "[0] No and I change the elements";
                str v2 = "[Other] Yeah";

                str v = input();

                if (v == "#") return false;
                if (v == "0") {
                    print("Are you ready?");
                    print(v0);
                    print(v2);
                    if (input() == "#") return false;
                    break;
                }

                return true;
            }
        }
    }

    bool five(str path)      // You have two ways of taking OBJECT_1 and OBJECT_2
    {
        if (path == In_this_paths__path) return five_1();
        else if (path == In_other_paths__path) return five_2();
        else return false;
    }



    bool four_1(str path) { // You create a new folder in In_(other, this)_path
        while (true)
        {
            str r = random_string(15);
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
                    str text2 = "What name do you want to choose? (PLease, write without (SPACE ? \" \\ / : * | < > ), I will change the char to \" _ \"): ";
                    n = input(text2);

                    str n2;
                    int coll_dangerous_char = 0;

                    for (const char & check_dangerous_char : n) {
                        bool dangerous = false;
                        for (const char &dangerous_char : dangerous_chars) {
                            //std::cout << "D" << dangerous_char << "D" << std::endl; // rubbish
                            if (dangerous_char == check_dangerous_char) {

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
                    if (coll_dangerous_char > 0) n = n2;

                    if (there_is_FOF(n, path)) {
                        str text4 = "The folder with name \"" + n + "\" is already created. \nChoose other name!";
                        print(text4);
                        //n = input(text2);
                        continue;
                    }
                }

                str name = path + "/" + n;
                make_dir(name);
                if (there_is(name))
                {
                    Project_path = name;
                    return true;
                }
            }
            else
            {
                print(er_wd);
            }
        }
    }


    bool four(str path) {   // If In_(other, this)_path is empty, \
                        create folder. For exemple: project_exemple or you choose name.\
                        If In_(other, this)_path is not empty, you choose folder for comparing \
                        or you create a new but creating in different function "four_1" \
                        \
                        the method is key of break in loop inmethod "two"
        
        
        if (empty(path)) {
            if (!four_1(path)) return false;
            return true;
        }
        else {
            vec_str containings = in_dir(path);

            str vs = "[Other] CREATE A NEW";
            str v0 = "[#] CANCEL AND BACK";


            print(v0);

            vec_str containings_vec_str;


            int n_containing = 0;
            for (const str &containing : containings)   // You take PATHS from in_dir(path)
            {
                str vn = "[" + to_str(n_containing) + "] " + FOF_without_path(containing);      // [0] Name_file
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
                if (v == to_str(n_containing)) {
                    condition_containing = true;
                    chosen_v_file = containings_vec_str[n_containing];
                    break;
                }
            }

            

            if (v == "#") return false;
            else if (condition_containing) {
                Project_path = path + "/" + chosen_v_file;
                return true;
            }
            else                        // If you chose [Other]
            {
                if (!four_1(path))
                    return false;
                return true;
            }
        }


    }


    void three() // It create or recreate "In_other_paths__path" and "In_this_paths__path"
    {
        In_other_paths__path = Comparator_path + "/" + In_other_paths;
        In_this_paths__path = Comparator_path + "/" + In_this_paths;

        vec_str Victims_for_making = {In_this_paths, In_other_paths};
        vec_str Victims_for_making_path = {In_this_paths__path, In_other_paths__path};

        str q = "Can I create it?";
        str v0 = "[#] No and BREAK program";
        str v1 = "[Other] Yes";

        for (int i = 0; i < Victims_for_making.size(); i++)
        {

            while (!is_dir(Victims_for_making_path[i]))
            {
                str text = "Folder \"" + Victims_for_making[i] + "\" in \"" + Comparator + "\" is not created by me!";
                if (there_is(Victims_for_making_path[i]))
                {
                    text = "The folder \"" + Victims_for_making[i] + "\" in " + Comparator + " is not folder!";
                    q = "Can I recreate it to folder? /n(If this file is important for you, you should move to other directory)";
                }

                print(text);
                print(q);
                print(v0);
                print(v1);

                str v = input(a);
                if (v == "#")
                    break_program();

                if (there_is(Victims_for_making_path[i])) // I don't create variable bools because I wart give user time for move undirectory
                {
                    remove(Victims_for_making_path[i]);
                    print("I can not remove it");
                    continue;
                }
                if (!there_is(Victims_for_making_path[i]))
                {
                    make_dir(Victims_for_making_path[i]);
                    if (there_is(Victims_for_making_path[i]))
                        break;
                }
            }     
        }
    }


    void two() // You choose where system compare your files/folders
    {
        str text = "Where should I compare your files/folders/ect?";
        str v1 = "[1] In folder \"" + Comparator + "\" and I move elements inside the folder";
        str v2 = "[2] I show you the way with my written path";
        str v0 = "[#] BREAK PROGRAM";



        three();
        

        while (true)        // For getting OBJECT_1 and OBJECT_2 and create construction
        {
            print(text);
            print(v0);
            print(v1);
            print(v2);

            str v = input(a);

            if (v == "#") {
                break_program();
            }
            else if (v == "1") {
                if (four(In_this_paths__path))
                {
                    if (five(In_this_paths__path))
                        break;
                }
            }
            else if (v == "2") {
                if (four(In_other_paths__path))
                {
                    if (five(In_other_paths__path))
                        break;
                }
            }
            else print(er_wd);
            
        }

        six();
    
    
    }


    void one()      // It create or recreate a folder "Comparator" and write Informaiton.txt in the folder
    {    
        Comparator_path = PATH + "/" + Comparator;  
        while (!is_dir(Comparator_path))
        {
            str text = "Folder \"" + Comparator + "\" in \"" + PATH + "\" is not created by me";
            str q = "Can I create it?";

            if (there_is(Comparator_path)) {
                text = "\"" + Comparator + "\" is not folder";
                q = "Can I recreate it to folder? \n(If this file is important for you, you should move to other directory)";

            }
            
            str v1 = "[Other] Yes";
            str v0 = "[#] No and BREAK PROGRAM";
            print(text);
            print(q);
            print(v0);
            print(v1);
            if (input(a) == "#") break_program(); 

            
            if (there_is(Comparator_path))         // I don't create variable bools because I want give user time for move undirectory
                remove(Comparator_path);
            if (!there_is(Comparator_path))
            {
                make_dir(Comparator_path);
                if (there_is(Comparator_path))
                    break;
            }
                
        }








        // Informaiton

        Information_for_Using_path = Comparator_path + "/" + Information_for_Using;
        str Information_for_Using_text_is_read = read(Information_for_Using_path);
        str Information_for_Using_text = Information_for_Using_text_function(
            Comparator, In_other_paths, In_this_paths,
            OBJ_1, OBJ_2, For_comparator, Result_file,
            Result_folder, First_compared_element,
            Second_compared_element, Where_is_this_file,
            Where_is_this_file_alt, Ghost_file);


        bool b = Information_for_Using_text_is_read == Information_for_Using_text;

        while (!is_text_file(Information_for_Using_path) || !b) {

            str text =  !is_text_file(Information_for_Using_path) ? "an" : "to update the";
            print("Do you need " + text + " information of using the program?");
            print("[#] No");
            print("[Other] Yeah [RECOMMENDED]");
            
            

            if (input() != "#") {

                while (there_is(Information_for_Using_path) && !is_text_file(Information_for_Using_path)) // Removing Information.txt
                {
                    print("I remove the " + Information_for_Using + " in \"" + Comparator_path + "\". It miss me. If the notext file is important for you, you move the file in other directories\nCan I remove it?");
                    print("[#] No and I don't want to get " + Information_for_Using + " more");
                    print("[Other] Yeah");

                    if (input() != "#") {
                        remove(Information_for_Using_path);
                        if (there_is(Information_for_Using_path)) {
                            print("I can not remove " + Information_for_Using + ".");
                            //break;        // I would not put the code. Because: If System can't remove file => break, Else not break
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
        two();
    }

    public: 


        void zav() {
            one();
        }
};

Zav z;

int main() {
    z.zav();
    return 0;
}