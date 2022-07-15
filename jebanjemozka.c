#include <stdio.h>
#include <string.h>

#define MV_PTR_R '>'
#define MV_PTR_L '<'
#define INC_CELL '+'
#define DEC_CELL '-'
#define INP_CHR ','
#define OUT_CHR '.'
#define JMP_IF_Z '['
#define JMP_IF_NZ ']'

/*
Steps:
1. Get filename
2. Read text file content
3. Parse text file content
*/

/**
 * @brief Struct for matching bracket pairs.
 */
struct bracket_pairs
{
    int left_bracket_pos;
    int right_bracket_pos;
};

int memory_cells[30000];
int current_cell = 0;

struct bracket_pairs pairs[15000];

// prints "Hello world!"
char* example = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

/*
Idea: Use a stack to save position of "[" and pop whenever "]" appears. 
Save all positions to a list of pairs. Surely there must a be a better way though.
*/

/**
 * @brief 
 * 
 * @return int 0 if parsing successful, 1 otherwise
 */
int parse_bracket_pairs() {

    return 0;
}

/**
 * @brief 
 * 
 */
void parse() {
    for (size_t i = 0; i < strlen(example); i++)
    {
        switch (example[i]) {
            case MV_PTR_R:
                // TODO: Pointer out of bounds
                current_cell++;
            break;
            case MV_PTR_L:
                // TODO: Pointer out of bounds
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
                if (memory_cells[current_cell] == 0) {
                    // TODO
                }
            break;
            case JMP_IF_NZ:
                if (memory_cells[current_cell] != 0) {
                    // TODO
                }
            break;
        }
    }
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
    parse();
    return 0;
}