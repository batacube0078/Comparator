#include "useful.h"

str Information_for_Using_text_function(
    str Comparator,
    str In_other_paths,
    str In_this_paths,
    str OBJ_1,
    str OBJ_2,
    str For_comparator,
    str Result_file,
    str Result_folder,
    str First_compared_element,
    str Second_compared_element,
    str Where_is_this_file,
    str Where_is_this_file_alt,
    str Ghost_file
)
{
    str text =
        "It is a program called \"" + Comparator + "\". \"" + Comparator + "\" is used to compare two files, folders, or other elements.\n\n"
                                                                           "How to use it:\n\n"
                                                                           "In the folder \"" +
        Comparator + "\", there are two subfolders for two types of comparison. "
                     "If these folders do not exist, run " +
        Comparator + ".exe to create them: \"" + In_other_paths + "\" and \"" + In_this_paths + "\". "
                                                                                                "If your elements are located within the \"" +
        Comparator + "\" folder, use \"" + In_this_paths + "\". "
                                                           "If your elements are elsewhere on your computer, use \"" +
        In_other_paths + "\".\n\n"
                         "Both \"" +
        In_this_paths + "\" and \"" + In_other_paths + "\" can contain projects. "
                                                       "If no projects exist, you can create one by running " +
        Comparator + ".exe. "
                     "Inside a project in \"" +
        In_this_paths + "\", you will find a folder \"" + For_comparator + "\" used for comparing two elements. "
                                                                           "Paste the two elements (files, folders, etc.) there and run " +
        Comparator + ".exe, selecting the comparison method and project.\n\n"
                     "When using \"" +
        In_other_paths + "\", provide existing paths on your computer or create a project. "
                         "When creating a project, you specify the paths. "
                         "After creating a project, the program generates two text files, \"" +
        OBJ_1 + "\" and \"" + OBJ_2 + "\", in your project. "
                                      "You can also open an existing project in \"" +
        In_other_paths + "\"; the program will read the text files and use the stored paths. "
                         "\"" +
        OBJ_1 + "\" and \"" + OBJ_2 + "\" store the paths to your elements (files, folders, etc.).\n"
                                      "Be careful: if you use non-English characters in paths when creating a project in \"" +
        In_other_paths + "\", the program may not recognize them. "
                         "In this case, manually create the text files \"" +
        OBJ_1 + "\" and \"" + OBJ_2 + "\" and write the paths there.\n\n"
                                      "What happens after comparing?\n\n"
                                      "The program creates a result folder \"" +
        Result_folder + "\" and two text files, \"" + Result_file + "\" and \"" + Ghost_file + "\", regardless of the chosen method. "
                                                                                               "Some files or folders may not be created, which is normal.\n\n"
                                                                                               "The folder \"" +
        Result_folder + "\" is created if your elements are folders and the program finds files that differ between them. "
                        "It creates subfolders (e.g., \"0.000001\") containing \"" +
        First_compared_element + "\" and \"" + Second_compared_element + "\" folders. "
                                                                         "Each folder contains a text file \"" +
        Where_is_this_file + "\" listing paths, differing lines, and their line numbers. "
                             "If the second element's file is named \"" +
        Where_is_this_file + "\", then the first element's corresponding file, which would normally be named \"" + Where_is_this_file + "\", "
                                                                                                                                        "is automatically renamed to \"" +
        Where_is_this_file_alt + "\" to avoid a conflict. "
                                 "Another text file with the same name as the original in the compared element stores only the differing lines.\n\n"
                                 "In \"" +
        Result_file + "\", the program lists differences including missing files or files of different types (e.g., folder vs. regular file). "
                      "For text files, it outputs differing lines; for binary files, it outputs sizes. "
                      "Symlinks are compared by their targets. "
                      "If elements are not folders, files, or symlinks, the comparison is skipped and \"" +
        Result_file + "\" will not be created. "
                      "Comparison requires exactly two elements; otherwise, an error is thrown.\n\n"
                      "In \"" +
        Ghost_file + "\", paths to files that exist but are inaccessible or 'ghosted' are listed. "
                     "This file is created only when comparing folders, like \"" +
        Result_folder + "\".\n\n"
                        "Why can a regular file be text or binary?\n\n"
                        "Text files can be read normally, while binary files may appear as garbage characters (ASCII <32 or 127). "
                        "Tabs (#9) and newlines (#10) are valid in text files. "
                        "If more than 5% of characters are non-text, the file is considered binary. "
                        "During comparison, strange characters may appear; text files may contain special characters (<=5%) or Unicode characters (>=128).\n\n"
                        "The program was developed by Priymak Roman.\n\n\n\n"
                        "My scheme of directories:\n\n"
                        "\tmyProject v\n"
                        "\t\t" +
        Comparator + " v\n"
                     "\t\t\t" +
        In_other_paths + " v\n"
                         "\t\t\t\tproject_example_1 v\n"
                         "\t\t\t\t\t" +
        OBJ_1 + "\n"
                "\t\t\t\t\t" +
        OBJ_2 + "\n"
                "\t\t\t\t\t" +
        Result_file + "\n"
                      "\t\t\t\t\t" +
        Result_folder + " v\n"
                        "\t\t\t\t\t\t0.000001 v\n"
                        "\t\t\t\t\t\t\t" +
        First_compared_element + " v\n"
                                 "\t\t\t\t\t\t\t\t" +
        Where_is_this_file + "\n"
                             "\t\t\t\t\t\t\t\t[name_compared_file]\n"
                             "\t\t\t\t\t\t\t" +
        Second_compared_element + " v\n"
                                  "\t\t\t\t\t\t\t\t" +
        Where_is_this_file + "\n"
                             "\t\t\t\t\t\t\t\t[name_compared_file]\n"
                             "\t\t\t\t\t\t0.000002 >\n"
                             "\t\t\t\t\t\t0.000003 >\n"
                             "\t\t\t\t\t\t0.000004 >\n"
                             "\t\t\t\t\t\t" +
        Ghost_file + "\n"
                     "\t\t\t\tproject_example_2 >\n"
                     "\t\t\t\tproject_example_3 >\n"
                     "\t\t\t\t...\n"
                     "\t\t\t" +
        In_this_paths + " v\n"
                        "\t\t\t\tproject_example_1 v\n"
                        "\t\t\t\t\t" +
        For_comparator + " v\n"
                         "\t\t\t\t\t\t[OBJECT_1]\n"
                         "\t\t\t\t\t\t[OBJECT_2]\n"
                         "\t\t\t\t\t" +
        Result_file + "\n"
                      "\t\t\t\t\t" +
        Result_folder + " v\n"
                        "\t\t\t\t\t\t0.000001 v\n"
                        "\t\t\t\t\t\t\t" +
        First_compared_element + " v\n"
                                 "\t\t\t\t\t\t\t\t" +
        Where_is_this_file + "\n"
                             "\t\t\t\t\t\t\t\t[name_compared_file]\n"
                             "\t\t\t\t\t\t\t" +
        Second_compared_element + " v\n"
                                  "\t\t\t\t\t\t\t\t" +
        Where_is_this_file + "\n"
                             "\t\t\t\t\t\t\t\t[name_compared_file]\n"
                             "\t\t\t\t\t\t0.000002 >\n"
                             "\t\t\t\t\t\t0.000003 >\n"
                             "\t\t\t\t\t\t0.000004 >\n"
                             "\t\t\t\t\t\t" +
        Ghost_file + "\n"
                     "\t\t\t\tproject_example_2 >\n"
                     "\t\t\t\tproject_example_3 >\n"
                     "\t\t\t\t...\n";

    return text;
}