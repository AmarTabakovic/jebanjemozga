# jebanjemozga
A brainfuck interpreter.

## Usage
### Building
```plaintext
$ make jebanjemozga
```

### Running
#### With a `.bf` or `.b` file
```plaintext
$ ./jebanjemozga [file_name]
```

#### REPL
```plaintext
$ ./jebanjemozga
```

Afterwards, a read-eval-print-loop prompt will open:

```plaintext
$ ./jebanjemozga
jebanjemozga (REPL mode)
(c) 2022 Amar Tabakovic
λ >
```

The prompt can be exited with `ctrl + d` or by entering `exit`:

```plaintext
λ > exit
$
```