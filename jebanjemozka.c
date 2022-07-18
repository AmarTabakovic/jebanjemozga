#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <stdbool.h>
#include <stdlib.h>

#define MV_PTR_R '>'
#define MV_PTR_L '<'
#define INC_CELL '+'
#define DEC_CELL '-'
#define INP_CHR ','
#define OUT_CHR '.'
#define JMP_IF_Z '['
#define JMP_IF_NZ ']'

#define MEM_SIZE 32768

int memory_cells[MEM_SIZE];
int current_cell = 0;

/**
 * @brief
 *
 * @param input
 * @return int
 */
int parse_brainfuck(char *input)
{
    for (size_t i = 0; i < strlen(input); i++)
    {
        int brackets_count = 1;
        switch (input[i])
        {
        case MV_PTR_R:
            // TODO: Pointer out of bounds?
            current_cell++;
            break;
        case MV_PTR_L:
            // TODO: Pointer out of bounds?
            current_cell--;
            break;
        case INC_CELL:
            memory_cells[current_cell]++;
            break;
        case DEC_CELL:
            memory_cells[current_cell]--;
            break;
        case INP_CHR:
            memory_cells[current_cell] = getchar();
            break;
        case OUT_CHR:
            putchar(memory_cells[current_cell]);
            break;
        case JMP_IF_Z:
            if (memory_cells[current_cell] == 0)
            {
                while (brackets_count != 0)
                {
                    i++;
                    if (input[i] == JMP_IF_Z)
                    {
                        brackets_count++;
                    }
                    else if (input[i] == JMP_IF_NZ)
                    {
                        brackets_count--;
                    }
                }
            }
            break;
        case JMP_IF_NZ:
            if (memory_cells[current_cell] != 0)
            {
                while (brackets_count != 0)
                {
                    i--;
                    if (input[i] == JMP_IF_Z)
                    {
                        brackets_count--;
                    }
                    else if (input[i] == JMP_IF_NZ)
                    {
                        brackets_count++;
                    }
                }
            }
            break;
        }
    }
    return 0;
}

/**
 * @brief
 *
 * @param file_name
 * @return int
 */
int init_file(char *file_name)
{
    FILE *file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL)
    {
        return 1;
    }

    // Source: https://stackoverflow.com/questions/14002954/c-programming-how-to-read-the-whole-file-contents-into-a-buffer
    fseek(file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    rewind(file_pointer);

    char *file_content = malloc(sizeof(char) * (file_size + 1));
    fread(file_content, file_size, 1, file_pointer);
    fclose(file_pointer);
    file_content[file_size] = 0;

    parse_brainfuck(file_content);
    free(file_content);

    return 0;
}

/**
 * @brief
 *
 */
void init_repl()
{
    printf("jebanjemozka (REPL mode)\n");
    printf("(c) 2022 Amar Tabakovic\n");
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        init_repl();
    }
    else if (argc == 2)
    {
        init_file(argv[1]);
    }
    else
    {
        printf("%s: File error", argv[0]);
        return 1;
    }
}
