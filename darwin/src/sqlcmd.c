#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char arg[4000], str[4000];
    int empty = 0;

    for(int i = 0; i < argc; i++)
    {
        if(i == 0)
        {
            strcpy(str, "pwsh -Command 'Invoke-SqlCmd");
            continue;
        }

             if(strcmp(argv[i], "-S") == 0) { strcpy(arg, "-ServerInstance"); }
        else if(strcmp(argv[i], "-d") == 0) { strcpy(arg, "-Database"); }
        else if(strcmp(argv[i], "-U") == 0) { strcpy(arg, "-Username"); }
        else if(strcmp(argv[i], "-P") == 0) { strcpy(arg, "-Password"); }
        else if(strcmp(argv[i], "-b") == 0) { strcpy(arg, "-AbortOnError"); }
        else if(strcmp(argv[i], "-i") == 0) { strcpy(arg, "-InputFile"); empty = 1; }
        else if(strcmp(argv[i], "-q") == 0) { strcpy(arg, "-Query"); empty = 1; }
        else if(strcmp(argv[i], "-Q") == 0) { strcpy(arg, "-Query"); empty = 1; }
        else if(strcmp(argv[i], "-r") == 0) { strcpy(arg, "-OutputSqlErrors"); }
        else if(strcmp(argv[i], "-t") == 0) { strcpy(arg, "-ConnectionTimeout"); }
        else
        {
            if(strcmp(argv[i-1], "-r") == 0)
            {
                if(strcmp(argv[i], "1") == 0) { strcpy(arg, "$True"); }
                else                          { strcpy(arg, "$False"); }
            }
            else
            {
                strcpy(arg, "\"");
                strcat(arg, argv[i]);
                strcat(arg, "\"");
            }
        }

        strcat(str, " ");
        strcat(str, arg);
    }

    if (empty == 0)
    {
        strcat(str, " -Query \"declare @r int; select @r = 1;\"");
        strcat(str, " -ConnectionTimeout \"30\"");
    }

    strcat(str, "'");

    printf("%s\n", str);
    system(str);

    return 0;
}