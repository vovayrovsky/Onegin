#include "TXLib.h"

int main (int argc, char** argv)
    {
    if (argc < 2)
        {
        printf ("No input file");

        return 0;
        }

    FILE* file_in = fopen (argv[1], "r");

    char path_out[256] = "";
    sprintf (path_out, "%s_ready_to_sort.txt", argv[1]);

    FILE* file_out = fopen (path_out, "w");

    char buf[40] = "";

    while (!feof (file_in))
        {
        fscanf  (file_in,  "%[^\n]\n", buf);

        //printf ("%s", buf);

        bool IsData = false;

        for (int i = 0; i < 40; i++)
            {
            if (buf[i] == 0)
                break;

            if (isalpha(buf[i]) && buf[i] != 'I' && buf[i] != 'L' && buf[i] != 'V' && buf[i] != 'X')
                {
                IsData = true;
                //printf ("\tdata by %c", buf[i]);

                break;
                }
            }

        //printf ("\n");
        if (!IsData)
            {
            fprintf (file_out, "\n");
            continue;
            }

        fprintf (file_out, "%s\n", buf);
        }

    fclose (file_in);
    fclose (file_out);
    return 0;
    }
