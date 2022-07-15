# jebanjemozka
A brainfuck interpreter.

_"Where there's a way, there's a day. And when there's a day, oh nay."_ - Amar Tabakovic, 2022

## Usage
### Building
```plaintext
$ make jebanjemozka
```

### Running
#### With a `.bf` file
```plaintext
$ ./jebanjemozka [file_name]
```

#### REPL
```plaintext
$ ./jebanjemozka
```

Afterwards, a read-eval-print-loop prompt will open:

```

```

## TODO
- [ ] Parsing and counting `[` and `]` occurences
- [ ] File input (a single file name as command line argument)
- [ ] REPL (no command line argument given)
- [ ] Error handling