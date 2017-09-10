#include "TXLib.h"

struct line
    {
    char line_[40];
    size_t position;
    size_t last_symb;

    uint8_t operator[] (size_t num)
        {
        assert (num < 40);

        return  line_[num];
        }
    };

bool line_comp_alphabet (line first, line second);
bool line_comp_rhyme (line first, line second);

void print_arr (std :: vector <line> onegin, FILE* file = stdout);

void load_file (char filename[], std :: vector <line>& onegin);

int main()
    {
    std :: vector <line> test;

    load_file ("Onegin.txt", test);

    print_arr (test);

    size_t time = GetTickCount();

    std :: sort (test.begin(), test.end(), line_comp_alphabet);

    time = GetTickCount() - time;

    printf ("Sort time: %u\n", time);
    getch();

    print_arr (test);


    FILE* onegin = fopen("Onegin_SORT_alph.txt", "w");

    print_arr (test, onegin);

    fclose(onegin);


    printf ("Other Sort!\n\n\n");

    time = GetTickCount();

    std :: sort (test.begin(), test.end(), line_comp_rhyme);

    time = GetTickCount() - time;

    print_arr (test);

    onegin = fopen("Onegin_SORT_rhyme.txt", "w");

    print_arr (test, onegin);

    fclose(onegin);

    return 0;
    }

void load_file (char filename[], std :: vector <line>& onegin)
    {
    line buf;
    FILE* oneg = fopen(filename, "r");

    int counter = 0;

    while (!feof(oneg))
        {
        fscanf (oneg, "%[^\n]\n", buf.line_);

        buf.last_symb = strlen(buf.line_);

        printf ("%s\n\tlast position[%u]\n", buf.line_, buf.last_symb);

        buf.position  = counter;


        onegin.push_back (buf);

        counter++;
        }

    fclose (oneg);

    printf("\n\n\n");
    getch();
    }

void print_arr (std :: vector <line> onegin, FILE* file)
    {
    for (auto str = onegin.begin(); str != onegin.end(); str++)
        {
        fprintf(file, "%s\n", str->line_);
        }

    printf("\n\n\n");

    getch();
    }

bool line_comp_alphabet (line first, line second)
    {
    int first_pos = 0;
    int second_pos = 0;

    while (true)
        {
        if (first_pos > 39 || second_pos > 39)
            break;

        if (!(isalpha (first[first_pos])))
            {
            first_pos++;
            continue;
            }

        if (!(isalpha (second[second_pos])))
            {
            second_pos++;
            continue;
            }

        if (tolower(first[first_pos]) < tolower(second[second_pos]))
            return true;
        else if (tolower(first[first_pos]) > tolower(second[second_pos]))
            return false;

        first_pos++;
        second_pos++;
        }

    return true;
    }

bool line_comp_rhyme (line first, line second)
    {
    int first_pos = first.last_symb;
    int second_pos = second.last_symb;

    while (true)
        {
        if (first_pos < 0 || second_pos < 0)
            break;

        if (!(isalpha (first[first_pos])))
            {
            first_pos--;
            continue;
            }

        if (!(isalpha (second[second_pos])))
            {
            second_pos--;
            continue;
            }

        if (tolower(first[first_pos]) < tolower(second[second_pos]))
            return true;
        else if (tolower(first[first_pos]) > tolower(second[second_pos]))
            return false;

        first_pos--;
        second_pos--;
        }

    return true;
    }
