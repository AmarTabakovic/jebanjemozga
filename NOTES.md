# Notes
## TODO
- [x] Parsing and counting `[` and `]` occurences
    - [ ] Explore potential alternative solution with mapping `[`-positions to `]`-positions and vice versa for O(1) access time (although with O(n) additional space if using an arary)
- [x] File input (when a single file name as command line argument given)
- [x] REPL (when no command line argument is given)
    - [ ] Decide between:
        - Pushing new commands to existing commands and realloc()
        - Resetting the memory table and pointer on every command
- [ ] Error handling
    - [ ] Invalid number of brackets
    - [ ] Cell pointer out of bounds
- [ ] Timeout after running for too long
- [ ] Cleaning up code
