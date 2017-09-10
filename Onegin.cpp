#include "TXLib.h"

struct line
    {
    char line_[40];
    size_t position;

    uint8_t operator[] (size_t num)
        {
        assert (num < 40);

        return  line_[num];
        }

    line operator< (line in)
        {
        for (int i = 0; i < 10; i++)
            {
            if ((*this)[i] < in[i])
                return *this;
            else if ((*this)[i] > in[i])
                return in;
            }

        return *this;
        }
    };

bool line_comp_alphabet (line first, line second);

void print_arr (std :: vector <line> onegin);

int main()
    {
    std :: vector <line> test;

    line buf;
    FILE* onegin = fopen("Onegin.txt", "r");

    int counter = 0;

    while (!feof(onegin))
        {
        fscanf (onegin, "%[^\n]\n", buf.line_);
        printf ("%s\n", buf.line_);

        buf.position = counter;

        test.push_back (buf);

        counter++;
        }

    fclose (onegin);

    printf("\n\n\n");

    getch();

    print_arr (test);

    std :: sort (test.begin(), test.end(), line_comp_alphabet);

    print_arr (test);

    return 0;
    }

void print_arr (std :: vector <line> onegin)
    {
    for (auto str = onegin.begin(); str != onegin.end(); str++)
        {
        printf("[%u]%s\n", str->position, str->line_);
        }

    printf("\n\n\n");

    getch();
    }

bool line_comp_alphabet (line first, line second)
    {
    for (int i = 0; i < 40; i++)
        {
        if (first[i] < second[i])
            return true;
        else if (first[i] > second[i])
            return false;
        }

    return true;
    }
