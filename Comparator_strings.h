#pragma once
#include "Service_str.h"
#include "Done_Comparing.h"

namespace comparator_string {

srs::Service service;


int What_count_of_lines (const ufs::fsp& path)
{
    int result = 0;
    std::ifstream rec (path);
    str lines;
    while (std::getline(rec, lines))
        result++;


        
    rec.clear();                      // Clear EOF
    rec.seekg(0, std::ios_base::beg); // System srs::read the file again


    rec.close();

    return result;
}


double recorded_result = 0.000001;
bool have_you_had_other_element_yet = false; // If (true) system find antagonist for OBJECT_2, else for OBJECT_1
str Recorded_result()
{
    str element = !have_you_had_other_element_yet? srs::First_compared_element : srs::Second_compared_element;
    static const double recorded_result_add = 0.000001;
    str path = srs::Result_folder_path + "/" + to_str(recorded_result);
    str need = path + "/" + element;
    while (ufs::there_is(need))
    {
        recorded_result += recorded_result_add;
        path = srs::Result_folder_path + "/" + to_str(recorded_result);
        need = path + "/" + element;
    }
    return path;
}


int what_types_to_compare = 0;

void What_types_to_compare(str obj_1, str obj_2)
{
    if (ufs::What_is_type_of_file(obj_1) == ufs::What_is_type_of_file(obj_2))
    {
        if (ufs::there_is(obj_1))
        {
            if (ufs::is_dir(obj_1))
                what_types_to_compare = 1;          // Folders
            else if (ufs::is_reg(obj_1))
                what_types_to_compare = 2;          // Regulars
            else if (ufs::is_slk(obj_1))
                what_types_to_compare = 3;          // Symlinks
            else if (ufs::is_block(obj_1))
                what_types_to_compare = 4;          // Blocks
            else if (ufs::is_char_file(obj_1))
                what_types_to_compare = 5;          // Characters
            else if (ufs::is_fifo_file(obj_1))
                what_types_to_compare = 6;          // Fifos
            else if (ufs::is_sock(obj_1))
                what_types_to_compare = 7;          // Sockets
            /*else if (is_none_type_file(obj_1))
                what_types_to_compare = 8;          // Non-types*/
            else
                what_types_to_compare = 8;          // Unknowns
        }
        else
            what_types_to_compare = 0;              // No-fount
    }
    else 
        what_types_to_compare = -1;                 // They're different
}






/*str antagonist(const str& path)    //  ./OBJECT_1/FILE.txt      <==[It antagonist]==>     ./OBJECT_2/FILE.txt
{
    vec<str> object_split = split(OBJECT_1, {'/', '\\'});    // We cut OBJECT piece by piece
    str anti_object = OBJECT_2;                             // Antagonist for OBJECT
    if (have_you_had_other_element_yet)
    {
        object_split = split(OBJECT_2, {'/', '\\'});
        anti_object = OBJECT_1;
    }


    vec<str> path_split = split(path, {'/', '\\'});
    vec<str> path_split_mirror = mirror_str(path_split);
    for (const str& rubbish : object_split)
    {
        path_split_mirror.pop_back();
    }
    if (path_split_mirror.size() == 0)
        return anti_object;
    vec<str> path_split_mirror_mirror = mirror_str(path_split_mirror);


    return anti_object + "/" + join(path_split_mirror_mirror, '/');     // Our result
}*/



void Writing(const str& text, const str& path, const str& Randomly, str line = space)          // If your OBJECTs are FOLDERS , system use the function
{
    if (what_types_to_compare == 1)
    {
        str message = text;
        if (line != space)  {
            message=path+" :: "+line;
            srs::news.ThirdPrint(message);
        }

        
        ufs::make_dir(srs::Result_folder_path);
        ufs::make_dir(Randomly);
        str number_in_random = !have_you_had_other_element_yet ? srs::First_compared_element : srs::Second_compared_element;
        
        str number_in_random_path = Randomly + "/" + number_in_random;       // ./Result_folder/0.000001/#1_element/

        //print(number_in_random_path);

        ufs::make_dir(number_in_random_path);

        str Where_is_this_file_path = number_in_random_path + "/" + srs::Where_is_this_file;

        if (srs::Where_is_this_file == ufs::FOF_without_path(path))
            Where_is_this_file_path = number_in_random_path + "/" + srs::Where_is_this_file_alt;

  
        srs::write(message, Where_is_this_file_path);

        if (line != space)      
        {
            str compared_line_in_text_path = number_in_random_path + "/" + ufs::FOF_without_path(path);

            srs::write(text, compared_line_in_text_path);
        }
    }   
}

void Comparing(const str& Victim, const str& anti_Victim)
{
    
    //print(what_types_to_compare);
    if (what_types_to_compare == 1)      // If two elements are folders
    {
        vec<str> Files_in_Victim = ufs::in_dir(Victim);
        for (const str& file_in_Victim : Files_in_Victim)          // For each element in Victim. Elements are PATH
        {
            srs::news.FirstPrint("I GOT PATH: " + file_in_Victim);
            if (ufs::there_is(file_in_Victim)) // If Victim is exist
            {
                str anti_file_in_Victim = anti_Victim + "/" + ufs::FOF_without_path(file_in_Victim); // It is antagonist to Victim
                if (ufs::What_is_type_of_file(file_in_Victim) == ufs::What_is_type_of_file(anti_file_in_Victim))
                {
                    if (ufs::is_dir(file_in_Victim))             // If element from Victim is folder
                    {
                        srs::news.FourthPrint(ufs::What_is_type_of_file(file_in_Victim));
                        Comparing(file_in_Victim, anti_file_in_Victim);
                    }
                    else if (ufs::is_reg(file_in_Victim))
                    {
                        if (ufs::is_text_file(file_in_Victim))
                        {
                            str what_is_regular = ufs::What_is_type_of_file(file_in_Victim) + " AND TEXT FILE";
                            srs::news.FourthPrint(what_is_regular);
                        }
                        else 
                        {
                            str what_is_regular = ufs::What_is_type_of_file(file_in_Victim) + " AND BINARY FILE";
                            srs::news.FourthPrint(what_is_regular);
                        }
                        

                        if (ufs::is_text_file(file_in_Victim) && ufs::is_text_file(anti_file_in_Victim))
                        {
                            str our_full_text = srs::read(file_in_Victim);
                            str enemies_full_text = srs::read(anti_file_in_Victim);

                            if (our_full_text != enemies_full_text)
                            {
                                our_full_text = space;
                                enemies_full_text = space;

                                int count_of_lines_from_antagonist = What_count_of_lines(anti_file_in_Victim);
                                int count_of_lines = 0;

                                ufs::fsp p (file_in_Victim);
                                ufs::fsp a_p(anti_file_in_Victim);
                                std::ifstream file_rec(p);
                                std::ifstream anti_file_rec(a_p);

                                str Lines_in_our_file, Lines_in_enemies_file;

                                str random_double = Recorded_result();

                                while (std::getline(file_rec, Lines_in_our_file))
                                {
                                    count_of_lines++;
                                    if (count_of_lines <= count_of_lines_from_antagonist)
                                    {
                                        std::getline(anti_file_rec, Lines_in_enemies_file);
                                        if (Lines_in_our_file != Lines_in_enemies_file)
                                        {
                                            Writing(Lines_in_our_file, file_in_Victim, random_double, to_str(count_of_lines));
                                        }
                                    }
                                    else 
                                    {
                                        Writing(Lines_in_our_file, file_in_Victim, random_double, to_str(count_of_lines));
                                    }
                                }
                                file_rec.clear();
                                file_rec.seekg(0, std::ios_base::beg);
                                anti_file_rec.clear();
                                anti_file_rec.seekg(0, std::ios_base::beg);

                                file_rec.close();
                                anti_file_rec.close();
                            }
                        }
                        else 
                        {

                            std::error_code er;             // ERROR FOR file_in_Victim
                            std::error_code a_er;           // ERROR FOR anti_file_in_Victim
                            ufs::fsp p(file_in_Victim);
                            ufs::fsp a_p(anti_file_in_Victim);
                            std::uintmax_t size = ufs::fs::file_size(p, er);
                            std::uintmax_t a_size = ufs::fs::file_size(a_p, a_er);

                            if (er)
                                size = 0;
                            if (a_er)
                                a_size = 0;

                            if (size != a_size)
                            {
                                str what_is_regular_file = "BINARY-FILE";
                                if (ufs::is_text_file(file_in_Victim))
                                    what_is_regular_file = "TEXT-FILE";
                                
                                str message_for_output = "THE REGULAR FILE \"" + file_in_Victim + "\" HAS SOME DIFFERENT SIZE: " + to_str(size) + " BYTES AND IT IS A " + what_is_regular_file;

                                str random_double = Recorded_result();

                                Writing(message_for_output, file_in_Victim, random_double);
                                
                            }
                            
                        }
                        
                    }
                    else if (ufs::is_slk(file_in_Victim))
                    {
                        srs::news.FourthPrint(ufs::What_is_type_of_file(file_in_Victim));

                        str target_our = ufs::read_target(file_in_Victim);
                        str target_enemies = ufs::read_target(anti_file_in_Victim);

                        if (target_our != target_enemies)
                        {
                            str message = "THE SYMLINK \"" + file_in_Victim + "\" HAS A DIFFERENT TARGET: \"" + target_our + "\".";

                            str random_double = Recorded_result();

                            Writing(message, file_in_Victim, random_double);
                        }
                    }
                    else 
                    {
                        srs::news.FourthPrint(ufs::What_is_type_of_file(file_in_Victim));
                    }
                    // I don't srs::write for Sockets, Fifos, Characters, Blocks and Unknowns, because they must be equal more and I can't get data them
                }
                else // If a type for file_in_Victim and a type for anti_file_in_Victim are not equal, system srs::write file to srs::Result_file_path.txt
                {
                    srs::news.FourthPrint(ufs::What_is_type_of_file(file_in_Victim));
                    str record = "THE FILE \"" + file_in_Victim + "\" IS " + ufs::What_is_type_of_file(file_in_Victim)
                                 + "\n\t\t\tAND THE FILE \"" + anti_file_in_Victim
                                 + "\" IS " + ufs::What_is_type_of_file(anti_file_in_Victim);
                    srs::news.SecondPrint(record);
                    str path_to_write = have_you_had_other_element_yet ? srs::Result_file_path_2 : srs::Result_file_path_1;
                    srs::write(record, path_to_write);
                }
            }
            else            //   If the Victim is not exist, system srs::write file to Ghost_files.txt
            {
                srs::news.FourthPrint(ufs::What_is_type_of_file(file_in_Victim));
                str record = "THE FILE \"" + file_in_Victim + "\" IS " + ufs::What_is_type_of_file(file_in_Victim);
                str path_to_write = have_you_had_other_element_yet? srs::Ghost_file_path_2 : srs::Ghost_file_path_1;
                
                srs::write(record, path_to_write);
            }
        }
    }
    else if (what_types_to_compare == 2)      // If two elements are regulars
    {
        str what_is_regular_file = " AND IT IS A BINARY-FILE";
        if (ufs::is_text_file(Victim))
        {
            what_is_regular_file = " AND IT IS A TEXT-FILE";
        }

        srs::news.FourthPrint(what_is_regular_file);




        if (ufs::is_text_file(Victim) && ufs::is_text_file(anti_Victim))
        {
            str number = !have_you_had_other_element_yet? srs::First_compared_element : srs::Second_compared_element;

            str where_to_write = srs::Project_path + "/" + number;


            str read_text_our = srs::read(Victim);
            str read_text_enemies = srs::read(anti_Victim);

            if (read_text_enemies != read_text_our)
            {
                ufs::make_dir(where_to_write);

                ufs::fsp p (Victim);
                ufs::fsp a_p (anti_Victim);
                std::ifstream   rec_our (p);
                std::ifstream rec_enemies(a_p);

                int enemies_count_of_lines = What_count_of_lines(anti_Victim);
                int our_count_of_lines = 0;

                str Line_our, Line_enemies;

                while (std::getline(rec_our, Line_our))
                {
                    our_count_of_lines++;
                    if (our_count_of_lines <= enemies_count_of_lines)
                    {
                        std::getline(rec_enemies, Line_enemies);
                        if (Line_enemies != Line_our)
                        {
                            str where_message = Victim + " :: " + to_str(our_count_of_lines);
                            srs::news.ThirdPrint(where_message);
                            str path_for_Victim = where_to_write + "/" + ufs::FOF_without_path(Victim);
                            str Where_is_this_file_path = where_to_write + "/" + srs::Where_is_this_file;
                            if (srs::Where_is_this_file == ufs::FOF_without_path(Victim))
                                Where_is_this_file_path = where_to_write + "/" + srs::Where_is_this_file_alt;

                            srs::write(where_message, Where_is_this_file_path);

                            srs::write(Line_our, path_for_Victim);
                        }
                    }
                    else 
                    {
                        str where_message = Victim + " :: " + to_str(our_count_of_lines);
                        srs::news.ThirdPrint(where_message);
                        str path_for_Victim = where_to_write + "/" + ufs::FOF_without_path(Victim);
                        str Where_is_this_file_path = where_to_write + "/" + srs::Where_is_this_file;
                        if (srs::Where_is_this_file == ufs::FOF_without_path(Victim))
                            Where_is_this_file_path = where_to_write + "/" + srs::Where_is_this_file_alt;

                        srs::write(where_message, Where_is_this_file_path);

                        srs::write(Line_our, path_for_Victim);
                    }
                }

                rec_our.clear();
                rec_our.seekg(0, std::ios_base::beg);
                rec_enemies.clear();
                rec_enemies.seekg(0, std::ios_base::beg);

                rec_our.close();
                rec_enemies.close();
            }
            else 
            {
                str message = "THEY ARE " + ufs::What_is_type_of_file(Victim) + "S" + what_is_regular_file + "S AND THEIR TEXTS ARE EQUAL";
                srs::write(message, srs::Result_file_path, 0);
            }
        }
        else 
        {
            std::error_code er;   // ERROR FOR Victim
            std::error_code a_er; // ERROR FOR anti_Victim
            ufs::fsp p(Victim);
            ufs::fsp a_p(anti_Victim);
            std::uintmax_t size = ufs::fs::file_size(p, er);
            std::uintmax_t a_size = ufs::fs::file_size(a_p, a_er);

            if (er)
                size = 0;
            if (a_er)
                a_size = 0;

            if (size != a_size)
            {
                str message_for_output = "THE REGULAR FILE \"" + Victim + "\" HAS SOME DIFFERENT SIZE: " + to_str(size) + " BYTES" + what_is_regular_file;
                srs::news.ThirdPrint(message_for_output);

                str where_to_write = !have_you_had_other_element_yet? srs::Result_file_path_1 : srs::Result_file_path_2;
                srs::write(message_for_output, where_to_write);
            }
            else 
            {
                str message = "THEY ARE " + ufs::What_is_type_of_file(Victim) + " AND HAVE EQUAL SIZES";
                srs::write(message, srs::Result_file_path, 0);
            }
        }
    }
    else if (what_types_to_compare == 3)      // If two elements are symlinks
    {
        str target_our = ufs::read_target(Victim);
        str target_enemies = ufs::read_target(anti_Victim);

        if (target_our != target_enemies)
        {
            str message = "THE SYNLINK \"" + Victim + "\" HAS A DIFFERENT TARGET: \"" + target_our + "\".";

            srs::news.ThirdPrint(message);

            str where_to_write = !have_you_had_other_element_yet? srs::Result_file_path_1 : srs::Result_file_path_2;

            srs::write(message, where_to_write);
        }
    }
    else if (what_types_to_compare >= 4 && what_types_to_compare <= 8) // If two elements are blocks, characters, fifo, socket, unknown
    {
        str message = "THEY ARE " + ufs::What_is_type_of_file(Victim) +"S";
        srs::write(message, srs::Result_file_path, 0);
    }
    else if (what_types_to_compare == 0)      // If two elements are not exists
    {
        str message = "THEY ARE " + ufs::What_is_type_of_file(Victim) + "S";
        srs::write(message, srs::Ghost_file_path, 0);
    }
    else        // If two elements are different
    {
        str message = "WE FILE \"" + Victim + "\" IS " + ufs::What_is_type_of_file(Victim)
                                 + "\n\t\t\tAND THE FILE \"" + anti_Victim
                                 + "\" IS " + ufs::What_is_type_of_file(anti_Victim);
        srs::news.SecondPrint(message);

        str where_to_write = !have_you_had_other_element_yet ? srs::Result_file_path_1 : srs::Result_file_path_2;
        if (!ufs::there_is(Victim))
        {
            where_to_write = !have_you_had_other_element_yet ? srs::Ghost_file_path_1 : srs::Ghost_file_path_2;
        }

        srs::write(message, where_to_write);
    }
}



int my_program_main() {

    if (!service.service_start()) return 0;

    What_types_to_compare(srs::OBJECT_1, srs::OBJECT_2);

    for (int i = 0; i < srs::OBJECTS.size(); i++, have_you_had_other_element_yet = true)
    {
        srs::news.FirstPrint("I GOT PATH: " + srs::OBJECTS[i]);
        srs::news.FourthPrint(ufs::What_is_type_of_file(srs::OBJECTS[i]));
        Comparing(srs::OBJECTS[i], srs::OBJECTS[srs::OBJECTS.size() - 1 - i]);
        recorded_result = 0.000001;
    }



    print(Beautiful_Done());

    return break_program();
}

}