#include "OakSort.h"

void print_arr (std :: vector <line> onegin, FILE* file = stdout);

int main(int argc, char** argv)
    {
    if (argc < 2)
        {
        printf ("No input file!\n");

        return 0;
        }

    Node root;

    root.next = LIST_END_POINTER;

    Node buf;
    buf.data = new line();

    sprintf (buf.data->line_, "ROOT_DON' T_TOUCH");

    FILE* oneg = fopen(argv[1], "r");
    assert (oneg);

    int counter = 0;

    Node* iter = &root;

    while (!feof(oneg))
        {
        iter -> next = new Node();
        assert(iter -> next);

        iter -> next -> data = new line();
        assert(iter -> next -> data );

        fscanf (oneg, "%[^\n]\n", iter -> next -> data->line_);

        iter -> next -> data -> last_symb = strlen(iter -> next -> data->line_);

        //printf ("%s\n\tlast position[%u]\n", buf.line_, buf.last_symb);

        iter -> next -> data->position  = counter;

        iter = iter -> next;
        iter -> next = LIST_END_POINTER;

        counter++;
        }

    fclose (oneg);

    root.data = buf.data;

    iter = &root;

    while (iter != LIST_END_POINTER)
        {
        printf ("%s\n", iter->data->line_);

        iter = iter->next;
        }

    return 0;
    /*
    std :: vector <line> test;

    load_file ("Onegin.txt", test);

    //print_arr (test);

    size_t time = GetTickCount();


    time = GetTickCount() - time;

    printf ("Sort time: %u\n", time);
    //getch();

    //print_arr (test);


    FILE* onegin = fopen("Onegin_SORT_alph.txt", "w");

    print_arr (test, onegin);

    fclose(onegin);

    return 0;*/
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

