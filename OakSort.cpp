#include "OakSort.h"

using namespace std;

void print_tree (Node* root, FILE* file);
void sort_tree  (Node* root);

int main(int argc, char** argv)
    {
    try {

    FILE* oneg = NULL;

    if (argc < 2)
        {
        oneg = fopen("Onegin.txt", "r");
        assert (oneg);
        }
    else
        {
        oneg = fopen(argv[1], "r");
        assert (oneg);
        }

    Node root;

    root.next = LIST_END_POINTER;
    root.level = 0;

    Node buf;
    buf.data =  new line();

    sprintf (buf.data->line_, "");

    int counter = 0;

    Node* iter = &root;

    for (int i = 0; i < 256; i++)
        iter -> children[i] = LIST_END_POINTER;

    while (!feof(oneg))
        {
        if (!(counter % 2000))
        printf ("load %u string\n", counter);

        iter -> next = new Node();
        assert (iter -> next);
        iter -> next -> level = 0;

        for (int i = 0; i < 256; i++)
            iter -> next ->children[i] = LIST_END_POINTER;

        iter -> next -> data = new line();
        assert(iter -> next -> data );

        fscanf (oneg, "%[^\n]\n", iter -> next -> data->line_);

        iter -> next -> data -> last_symb = strlen(iter -> next -> data->line_);

        //printf ("%s\n\tlast position[%u]\n", buf.line_, buf.last_symb);

        iter -> next -> data -> position  = counter;

        iter = iter -> next;
        iter -> next = LIST_END_POINTER;

        counter++;
        }

    fclose (oneg);

    root.data = buf.data;

    iter = &root;

    printf ("start sort.\n");

    clock_t time = clock();

    sort_tree (&root);

    time = clock() - time;

    printf ("Sorted by %lu ms.\n", time);

    FILE* sorted = fopen ("SORTED_TEXT.txt", "w");

    //print_tree (&root, stdout);

    print_tree (&root, sorted);

    fclose (sorted);
    }
    catch (std::bad_alloc &ex)
    {
    printf ("Your problem is out of memory. Be luky next time.\n");
    }
    catch (...)
    {
    printf ("Huston, we have a problem.\n");
    }

    getch();
    return 0;
    }


//#define DEBUG

void print_tree (Node* root, FILE* file)
    {
    assert (root);

    #ifdef DEBUG
    fprintf (file, "Node[%s]. Level %d.\n\n", root->data->line_, root->level);
    #else
    if (root->data->line_ != 0)
        fprintf (file, "%s\n", root->data->line_);
    #endif

    if (root -> next)
        {
        print_tree(root -> next, file);

        //delete root -> next;
        }

    for (int i = 0; i < 256; i++)
        {
        if (root -> children[i] != LIST_END_POINTER)
            {
            print_tree (root -> children[i], file);
            //delete root -> children[i];
            }
        };
    }

void sort_tree  (Node* root)
    {
    assert (root);

    MakeTreeIteration (root);

    for (int i = 0; i < 256; i++)
        {
        if (root -> children[i] != LIST_END_POINTER)
            MakeTreeIteration(root -> children[i]);
        }
    }
