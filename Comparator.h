#pragma once
#include "Service.h"
#include "Done_Comparing.h"

namespace comparator_filesystem {

srf::Service service;


int What_count_of_lines (const uff::fsp& path)
{
    int result = 0;
    std::ifstream rec (path);
    str lines;
    while (std::getline(rec, lines))
        result++;


        
    rec.clear();                      // Clear EOF
    rec.seekg(0, std::ios_base::beg); // System srf::read the file again


    rec.close();

    return result;
}




double recorded_result = 0.000001;

bool have_you_had_other_element_yet = false; // If (true) system find antagonist for srf::OBJECT_2, else for srf::OBJECT_1
uff::fsp Recorded_result()
{
    static const double recorded_result_add = 0.000001;
    uff::fsp element = have_you_had_other_element_yet? srf::Second_compared_element : srf::First_compared_element;
    uff::fsp path = srf::Result_folder_path/to_str(recorded_result);
    uff::fsp need = path/element;
    while (uff::there_is(need))
    {
        recorded_result += recorded_result_add;
        path = srf::Result_folder_path/to_str(recorded_result);
        need = path/element;
    }
    return path;
}



int what_types_to_compare = 0;

void What_types_to_compare(const uff::fsp& obj_1, const uff::fsp& obj_2)
{
    if (uff::What_is_type_of_file(obj_1) == uff::What_is_type_of_file(obj_2))
    {
        if (uff::there_is(obj_1))
        {
            if (uff::is_dir(obj_1))
                what_types_to_compare = 1;          // Folders
            else if (uff::is_reg(obj_1))
                what_types_to_compare = 2;          // Regulars
            else if (uff::is_slk(obj_1))
                what_types_to_compare = 3;          // Symlinks
            else if (uff::is_block(obj_1))
                what_types_to_compare = 4;          // Blocks
            else if (uff::is_char_file(obj_1))
                what_types_to_compare = 5;          // Characters
            else if (uff::is_fifo_file(obj_1))
                what_types_to_compare = 6;          // Fifos 
            else if (uff::is_sock(obj_1))
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



/*str antagonist(const str& path)    //  ./srf::OBJECT_1/FILE.txt      <==[It antagonist]==>     ./srf::OBJECT_2/FILE.txt
{
    vec<str> object_split = split(srf::OBJECT_1, {'/', '\\'});    // We cut OBJECT piece by piece
    str anti_object = srf::OBJECT_2;                             // Antagonist for OBJECT
    if (have_you_had_other_element_yet)
    {
        object_split = split(srf::OBJECT_2, {'/', '\\'});
        anti_object = srf::OBJECT_1;
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



void Writing(const str& text, const uff::fsp& path, const uff::fsp& Randomly, const str& line = space)          // If your OBJECTs are FOLDERS , system use the function
{
    if (what_types_to_compare == 1)
    {
        str message = text;
        if (line != space)  {
            message=path.string()+" :: "+line;
            srf::news.ThirdPrint(message);
        }

        
        uff::make_dir(srf::Result_folder_path);
        uff::make_dir(Randomly);
        uff::fsp number_in_random = !have_you_had_other_element_yet ? srf::First_compared_element : srf::Second_compared_element;
        
        uff::fsp number_in_random_path = Randomly/number_in_random;       // ./Result_folder/0.000001/#1_element/

        //print(number_in_random_path);

        uff::make_dir(number_in_random_path);

        uff::fsp Where_is_this_file_path = number_in_random_path/srf::Where_is_this_file;

        if (srf::Where_is_this_file == path.filename())
            Where_is_this_file_path = number_in_random_path/srf::Where_is_this_file_alt;

  
        srf::write(message, Where_is_this_file_path);

        if (line != space)      
        {
            uff::fsp compared_line_in_text_path = number_in_random_path/path.filename();

            srf::write(text, compared_line_in_text_path);
        }
    }   
}

void Comparing(const uff::fsp& Victim, const uff::fsp& anti_Victim)
{
    
    //print(what_types_to_compare);
    if (what_types_to_compare == 1)      // If two elements are folders
    {
        for (const uff::fsp &file_in_Victim : uff::in_dir(Victim)) // For each element in Victim. Elements are PATH
        {
            srf::news.FirstPrint("I GOT PATH: " + file_in_Victim.string());
            if (uff::there_is(file_in_Victim)) // If Victim is exist
            {
                uff::fsp anti_file_in_Victim = anti_Victim/file_in_Victim.filename(); // It is antagonist to Victim
                if (uff::What_is_type_of_file(file_in_Victim) == uff::What_is_type_of_file(anti_file_in_Victim))
                {
                    if (uff::is_dir(file_in_Victim))             // If element from Victim is folder
                    {
                        srf::news.FourthPrint(uff::What_is_type_of_file(file_in_Victim));
                        Comparing(file_in_Victim, anti_file_in_Victim);
                    }
                    else if (uff::is_reg(file_in_Victim))
                    {
                        if (uff::is_text_file(file_in_Victim))
                        {
                            str what_is_regular = uff::What_is_type_of_file(file_in_Victim) + " AND TEXT FILE";
                            srf::news.FourthPrint(what_is_regular);
                        }
                        else 
                        {
                            str what_is_regular = uff::What_is_type_of_file(file_in_Victim) + " AND BINARY FILE";
                            srf::news.FourthPrint(what_is_regular);
                        }
                        

                        if (uff::is_text_file(file_in_Victim) && uff::is_text_file(anti_file_in_Victim))
                        {
                            str our_full_text = srf::read(file_in_Victim);
                            str enemies_full_text = srf::read(anti_file_in_Victim);

                            if (our_full_text != enemies_full_text)
                            {
                                our_full_text = space;
                                enemies_full_text = space;

                                int count_of_lines_from_antagonist = What_count_of_lines(anti_file_in_Victim);
                                int count_of_lines = 0;

                                uff::fsp p (file_in_Victim);
                                uff::fsp a_p(anti_file_in_Victim);
                                std::ifstream file_rec(p);
                                std::ifstream anti_file_rec(a_p);

                                str Lines_in_our_file, Lines_in_enemies_file;

                                uff::fsp random_double = Recorded_result();


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
                            uff::fsp p(file_in_Victim);
                            uff::fsp a_p(anti_file_in_Victim);
                            std::uintmax_t size = uff::fs::file_size(p, er);
                            std::uintmax_t a_size = uff::fs::file_size(a_p, a_er);

                            if (er)
                                size = 0;
                            if (a_er)
                                a_size = 0;

                            if (size != a_size)
                            {
                                str what_is_regular_file = "BINARY-FILE";
                                if (uff::is_text_file(file_in_Victim))
                                    what_is_regular_file = "TEXT-FILE";
                                
                                str message_for_output = "THE REGULAR FILE \"" + file_in_Victim.string() + "\" HAS SOME DIFFERENT SIZE: " + to_str(size) + " BYTES AND IT IS A " + what_is_regular_file;

                                uff::fsp random_double = Recorded_result();

                                Writing(message_for_output, file_in_Victim, random_double);
                                
                            }
                            
                        }
                        
                    }
                    else if (uff::is_slk(file_in_Victim))
                    {
                        srf::news.FourthPrint(uff::What_is_type_of_file(file_in_Victim));

                        uff::fsp target_our = uff::read_target(file_in_Victim);
                        uff::fsp target_enemies = uff::read_target(anti_file_in_Victim);

                        if (target_our != target_enemies)
                        {
                            str message = "THE SYMLINK \"" + file_in_Victim.string() + "\" HAS A DIFFERENT TARGET: \"" + target_our.string() + "\".";

                            uff::fsp random_double = Recorded_result();

                            Writing(message, file_in_Victim, random_double);
                        }
                    }
                    else 
                    {
                        srf::news.FourthPrint(uff::What_is_type_of_file(file_in_Victim));
                    }
                    // I don't srf::write for Sockets, Fifos, Characters, Blocks and Unknowns, because they must be equal more and I can't get data them
                }
                else // If a type for file_in_Victim and a type for anti_file_in_Victim are not equal, system srf::write file to srf::Result_file_path.txt
                {
                    srf::news.FourthPrint(uff::What_is_type_of_file(file_in_Victim));
                    str record = "THE FILE \"" + file_in_Victim.string() + "\" IS " + uff::What_is_type_of_file(file_in_Victim)
                                 + "\n\t\t\tAND THE FILE \"" + anti_file_in_Victim.string()
                                 + "\" IS " + uff::What_is_type_of_file(anti_file_in_Victim);
                    srf::news.SecondPrint(record);
                    uff::fsp path_to_write = have_you_had_other_element_yet ? srf::Result_file_path_2 : srf::Result_file_path_1;
                    srf::write(record, path_to_write);
                }
            }
            else            //   If the Victim is not exist, system srf::write file to Ghost_files.txt
            {
                srf::news.FourthPrint(uff::What_is_type_of_file(file_in_Victim));
                str record = "THE FILE \"" + file_in_Victim.string() + "\" IS " + uff::What_is_type_of_file(file_in_Victim);
                uff::fsp path_to_write = have_you_had_other_element_yet? srf::Ghost_file_path_2 : srf::Ghost_file_path_1;
                
                srf::write(record, path_to_write);
            }
        }
    }
    else if (what_types_to_compare == 2)      // If two elements are regulars
    {
        str what_is_regular_file = " AND IT IS A BINARY-FILE";
        if (uff::is_text_file(Victim))
        {
            what_is_regular_file = " AND IT IS A TEXT-FILE";
        }

        srf::news.FourthPrint(what_is_regular_file);




        if (uff::is_text_file(Victim) && uff::is_text_file(anti_Victim))
        {
            uff::fsp number = !have_you_had_other_element_yet? srf::First_compared_element : srf::Second_compared_element;

            uff::fsp where_to_write = srf::Project_path/number;


            str read_text_our = srf::read(Victim);
            str read_text_enemies = srf::read(anti_Victim);

            if (read_text_enemies != read_text_our)
            {
                uff::make_dir(where_to_write);

                uff::fsp p (Victim);
                uff::fsp a_p (anti_Victim);
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
                            str where_message = Victim.string() + " :: " + to_str(our_count_of_lines);
                            srf::news.ThirdPrint(where_message);
                            uff::fsp path_for_Victim = where_to_write/Victim.filename();
                            uff::fsp Where_is_this_file_path = where_to_write/srf::Where_is_this_file;
                            if (srf::Where_is_this_file == Victim.filename())
                                Where_is_this_file_path = where_to_write/srf::Where_is_this_file_alt;

                            srf::write(where_message, Where_is_this_file_path);

                            srf::write(Line_our, path_for_Victim);
                        }
                    }
                    else 
                    {
                        str where_message = Victim.string() + " :: " + to_str(our_count_of_lines);
                        srf::news.ThirdPrint(where_message);
                        uff::fsp path_for_Victim = where_to_write/Victim.filename();
                        uff::fsp Where_is_this_file_path = where_to_write/srf::Where_is_this_file;
                        if (srf::Where_is_this_file == Victim.filename())
                            Where_is_this_file_path = where_to_write/srf::Where_is_this_file_alt;

                        srf::write(where_message, Where_is_this_file_path);

                        srf::write(Line_our, path_for_Victim);
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
                str message = "THEY ARE " + uff::What_is_type_of_file(Victim) + "S" + what_is_regular_file + "S AND THEIR TEXTS ARE EQUAL";
                srf::write(message, srf::Result_file_path, 0);
            }
        }
        else 
        {
            std::error_code er;   // ERROR FOR Victim
            std::error_code a_er; // ERROR FOR anti_Victim
            uff::fsp p(Victim);
            uff::fsp a_p(anti_Victim);
            std::uintmax_t size = uff::fs::file_size(p, er);
            std::uintmax_t a_size = uff::fs::file_size(a_p, a_er);

            if (er)
                size = 0;
            if (a_er)
                a_size = 0;

            if (size != a_size)
            {
                str message_for_output = "THE REGULAR FILE \"" + Victim.string() + "\" HAS SOME DIFFERENT SIZE: " + to_str(size) + " BYTES" + what_is_regular_file;
                srf::news.ThirdPrint(message_for_output);

                uff::fsp where_to_write = !have_you_had_other_element_yet? srf::Result_file_path_1 : srf::Result_file_path_2;
                srf::write(message_for_output, where_to_write);
            }
            else 
            {
                str message = "THEY ARE " + uff::What_is_type_of_file(Victim) + " AND HAVE EQUAL SIZES";
                srf::write(message, srf::Result_file_path, 0);
            }
        }
    }
    else if (what_types_to_compare == 3)      // If two elements are symlinks
    {
        uff::fsp target_our = uff::read_target(Victim);
        uff::fsp target_enemies = uff::read_target(anti_Victim);

        if (target_our != target_enemies)
        {
            str message = "THE SYNLINK \"" + Victim.string() + "\" HAS A DIFFERENT TARGET: \"" + target_our.string() + "\".";

            srf::news.ThirdPrint(message);

            uff::fsp where_to_write = !have_you_had_other_element_yet? srf::Result_file_path_1 : srf::Result_file_path_2;

            srf::write(message, where_to_write);
        }
    }
    else if (what_types_to_compare >= 4 && what_types_to_compare <= 8) // If two elements are blocks, characters, fifo, socket, unknown
    {
        str message = "THEY ARE " + uff::What_is_type_of_file(Victim) +"S";
        srf::write(message, srf::Result_file_path, 0);
    }
    else if (what_types_to_compare == 0)      // If two elements are not exists
    {
        str message = "THEY ARE " + uff::What_is_type_of_file(Victim) + "S";
        srf::write(message, srf::Ghost_file_path, 0);
    }
    else        // If two elements are different
    {
        str message = "WE FILE \"" + Victim.string() + "\" IS " + uff::What_is_type_of_file(Victim)
                                 + "\n\t\t\tAND THE FILE \"" + anti_Victim.string()
                                 + "\" IS " + uff::What_is_type_of_file(anti_Victim);
        srf::news.SecondPrint(message);

        uff::fsp where_to_write = !have_you_had_other_element_yet ? srf::Result_file_path_1 : srf::Result_file_path_2;
        if (!uff::there_is(Victim))
        {
            where_to_write = !have_you_had_other_element_yet ? srf::Ghost_file_path_1 : srf::Ghost_file_path_2;
        }

        srf::write(message, where_to_write);
    }
}



int my_program_main() {

    if (!service.service_start()) return 0;

    What_types_to_compare(srf::OBJECT_1, srf::OBJECT_2);

    for (int i = 0; i < srf::OBJECTS.size(); i++, have_you_had_other_element_yet = true)
    {
        srf::news.FirstPrint("I GOT PATH: " + srf::OBJECTS[i].string());
        srf::news.FourthPrint(uff::What_is_type_of_file(srf::OBJECTS[i]));
        Comparing(srf::OBJECTS[i].string(), srf::OBJECTS[srf::OBJECTS.size() - 1 - i].string());
        recorded_result = 0.000001;
    }



    print(Beautiful_Done());

    return break_program();
}
}