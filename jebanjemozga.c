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

#define REPL_PROMPT "\xE2\xB2\x96 > "
#define EXIT_KEYWORD "exit\n"

int memory_cells[MEM_SIZE];
int current_cell = 0;

/**
 * @brief Parses a given string according to the brainfuck rules.
 *
 * @param input string in brainfuck format
 * @param position reference to the current command position
 * @return int 0 if no errors occurred, 1 otherwise
 */
int parse_brainfuck(char *input, size_t *position)
{
    for (size_t i = *position; i < strlen(input); i++)
    {
        int brackets_count = 1;
        switch (input[i])
        {
        case MV_PTR_R:
            // Current cell position goes beyond cell array size
            if (current_cell > MEM_SIZE - 1)
                return 1;
            current_cell++;
            break;
        case MV_PTR_L:
            // Current cell position goes beyond cell array size
            if (current_cell > MEM_SIZE - 1)
                return 1;
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
            if (!memory_cells[current_cell])
            {
                while (brackets_count)
                {
                    i++;
                    if (input[i] == JMP_IF_Z)
                        brackets_count++;
                    else if (input[i] == JMP_IF_NZ)
                        brackets_count--;
                }
            }
            break;
        case JMP_IF_NZ:
            if (memory_cells[current_cell])
            {
                while (brackets_count)
                {
                    i--;
                    if (input[i] == JMP_IF_Z)
                        brackets_count--;
                    else if (input[i] == JMP_IF_NZ)
                        brackets_count++;
                }
            }
            break;
        }
        *position = i;
    }
    return 0;
}

/**
 * @brief Initializes the parsing process when an input file is given.
 *
 * @param file_name name of the file to parse
 * @return int 0 if no errors occurred, 1 otherwise
 */
int init_file(char *file_name)
{
    FILE *file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL)
        return 1;

    // Source: https://stackoverflow.com/questions/14002954/c-programming-how-to-read-the-whole-file-contents-into-a-buffer
    fseek(file_pointer, 0, SEEK_END);
    long file_size = ftell(file_pointer);
    rewind(file_pointer);

    char *file_content = malloc(sizeof(char) * (file_size + 1));
    fread(file_content, file_size, 1, file_pointer);
    fclose(file_pointer);
    file_content[file_size] = 0;

    size_t position = 0;

    int ret = parse_brainfuck(file_content, &position);
    free(file_content);

    return ret;
}

/**
 * @brief Initializes the parsing process with a REPL.
 *
 * @return int 0 if no errors occurred, 1 otherwise
 */
int init_repl()
{
    printf("jebanjemozga (REPL mode)\n"
           "(c) 2022 Amar Tabakovic\n");

    char *commands = malloc(sizeof(char));
    char *line = NULL;
    commands[0] = '\0';
    size_t position = 0;

    size_t len = 0;
    ssize_t n_read;

    printf(REPL_PROMPT);

    while ((n_read = getline(&line, &len, stdin)) != -1)
    {
        // If "exit" was entered
        if (!strcmp(line, EXIT_KEYWORD))
        {
            free(line);
            free(commands);
            return 0;
        }

        // Resize commands string and concatenate newly read line
        commands = realloc(commands, strlen(commands) + strlen(line));
        strcat(commands, line);

        if (parse_brainfuck(commands, &position) != 0)
            return 1;

        printf(REPL_PROMPT);
    }

    free(line);
    free(commands);
    return 0;
}

/**
 * @brief Entry point of the application.
 *
 * @param argc number of command line arguments
 * @param argv list of command line arguments
 * @return int exit code
 */
int main(int argc, char *argv[])
{
    if (argc == 1)
        return init_repl();
    else if (argc == 2)
        return init_file(argv[1]);

    printf("%s: Too many arguments given", argv[0]);
    return 1;
}
