
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    system("pwsh -Command Write-Host \"Hello from pwsh\" -ForegroundColor Yellow");

    return 0;
}