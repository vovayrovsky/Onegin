//#include "C:\program files\codeblocks\MinGW\include\TXLib.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <io.h>
#include <new>
#include <ctime>
#include <conio.h>

//13.09.2017 TODO: Write sort function.   24.09.2017 +
//           TODO: Write print function.             +
//           TODO: Think about crutches.             -

//Defines
//{
#define LIST_END_POINTER NULL
//}

//Over and over you make me crutching you.
//{
#define max_num 128

struct line
    {
    char line_[max_num];
    size_t position;
    size_t last_symb;

    uint8_t operator[] (size_t num)
        {
        assert (num < max_num);

        return  line_[num];
        }
    };
//

//Structures
//{
struct Node
    {
    size_t level;

    Node* children[256];
    Node* next;

    line* data;
    };
//}

//Prototypes
//{
void MakeTreeIteration (Node* root);
//}

//Definitions
//{
void MakeTreeIteration (Node* root)
    {
    assert (root);

    if (root -> next         == LIST_END_POINTER ||
        root -> next -> next == LIST_END_POINTER)
        {
        return;
        }

    Node* buf = NULL;
    Node* pre_buf = NULL;

    for (int i = 0; i < 256; i++)
        {
        root -> children[i] = new Node();
        root -> children[i] -> level = root -> level + 1;
        root -> children[i] -> next  = LIST_END_POINTER;
        }

    buf = root -> next;
    pre_buf = root;

    while (buf != LIST_END_POINTER)
        {
        pre_buf -> next = buf -> next;

        buf -> next = root -> children[(*(buf -> data))[root -> level]] -> next;
        root -> children[(*(buf -> data))[root -> level]] -> next = buf;

        buf = pre_buf -> next;
        pre_buf = pre_buf;
        }

    if (root -> next != LIST_END_POINTER)   //I have no idea in which case this should work. Well, only if I am stupid.
        {                                   //I mean, i wrote non-working code.
        fprintf (stderr, "WHAT THE FUCK IS DOING THERE?!?!?!?!\n");
        fprintf (stderr, "addr  = %x,\n", root);
        fprintf (stderr, "level = %u,\n", root->level);

        assert (0);
        }
    }
//}
