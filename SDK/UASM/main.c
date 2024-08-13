#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool compile = false;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("UASM: No arguments specified.\n");
        return 1; // Return an error code if no file is specified
    }
    else
    {
        compile = true;
    }

    if (compile)
    {
        FILE *filetoassemble = fopen(argv[1], "r");

        if (filetoassemble == NULL)
        {
            printf("UASM: Cannot assemble file %s. It does not exist.\n", argv[1]);
            return 1; // Return an error code if the file cannot be opened
        }
        else
        {
            printf("UASM: Compiling %s\n", argv[1]);

            char line[1024]; // Buffer to hold each line of the file
            bool add = false;
            bool comment = false;

            while (fgets(line, sizeof(line), filetoassemble))
            {
                if (strstr(line, "ADD") != NULL)
                {
                    add = true;
                }

                if (strstr(line, "//") != NULL)
                {
                    comment = true;
                }
            }

            fclose(filetoassemble); // Close the file after processing all lines

            FILE *outputFile = fopen("app.bin", "w");

            if (outputFile == NULL)
            {
                printf("UASM: Could not create file app.bin.\n");
                return 1; // Return an error code if the file cannot be created
            }

            if (add)
            {
                // Write "1001" to the file
                fprintf(outputFile, "1001\n");
            }

            if (comment)
            {
                // Write "0010" to the file, after checking the 'add' flag
                fprintf(outputFile, "0010\n");
            }

            fclose(outputFile); // Close the file after writing
            printf("UASM: Output written to app.bin\n");
        }
    }

    return 0; // Return 0 to indicate successful completion
}
