#pragma once
#include "useful.h"

class NEWS {

    bool set = 0;
    vec<bool> Setting_for_PRINT = {set, set, set};
    bool print_types = 0;

    public:
        

        template <typename T>
        void FirstPrint(const T& text)       //  System say that it got paths. Outputting about scan all files/folders/etc
        {
            if (Setting_for_PRINT[0])
            {
                print(text);
            }
        }

        template <typename T>
        void SecondPrint(const T& text)      //  System say that types files are different
        {
            if (Setting_for_PRINT[1])
            {
                print(text);
            }
        }

        template <typename T>
        void ThirdPrint(const T& text)       // System say what lines in text files are different
        {
            if (Setting_for_PRINT[2])
            {
                print(text);
            }
        }

        template <typename T>
        void FourthPrint(const T& text)      // System say the type of files
        {
            if (print_types)
            {
                print(text);
            }
        }

        void Setting_for_output_news(int setting_message)
        {
            if (setting_message == 1)
            {
                Setting_for_PRINT[0] = 1;
            }
            else if (setting_message == 2)
            {
                Setting_for_PRINT[1] = 1;
            }
            else if (setting_message == 3)
            {
                Setting_for_PRINT[2] = 1;
            }
            else if (setting_message == 4)
            {
                Setting_for_PRINT[0] = 1;
                Setting_for_PRINT[1] = 1;
            }
            else if (setting_message == 5)
            {
                Setting_for_PRINT[2] = 1;
                Setting_for_PRINT[1] = 1;
            }
            else if (setting_message == 6)
            {
                Setting_for_PRINT[0] = 1;
                Setting_for_PRINT[2] = 1;
            }
            else if (setting_message == 7)
            {
                Setting_for_PRINT[0] = 1;
                Setting_for_PRINT[1] = 1;
                Setting_for_PRINT[2] = 1;
            }
            else if (setting_message == 8)
            {
                Setting_for_PRINT[0] = 1;
                Setting_for_PRINT[1] = 1;
                Setting_for_PRINT[2] = 1;
                print_types = 1;
            }
        }
};