# nextFP

Seek the next floating-point number.

## License

[The MIT License](http://tchel.mit-license.org/)

## Example

Although the statically compiled binary executable file `nextfp` is available on Linux platform, you can compile the source file `nextFP.cpp` on your system.

Help information can be obtained by `./nextfp`:

```shell
Usage:
  nextFP [ -i ] [ -f | -b ] [ -nNUM ] [ fpn1 fpn2 ... ]
    -i: interactive mode where the anchor point list is not needed.
    -f: seek forward the next floating-point number.
    -b: seek backward the next floating-point number.
    -nNUM: seek the next $NUM floating-point number.
    fpn1 fpn2 ... : the anchor point list of floating-point number.
```

As shown above, to seek backward the next 3 floating-point number of the single-precision data set $[2.34, 4.56, 5.67]$, we can run:

```shell
./nextfp -b -n3 2.34F 4.56F 5.67F
```

Besides, to seek forward the next floating-point number of some data by interactive input, we can run:

```shell
./nextfp -i -f
Enter the interactive mode:
>> 3.45F
<<        3.450000047683715820 |        3.450000286102294922
>> 4.56L
<<        4.559999999999999609 |        4.560000000000000497
>> 5.67F
<<        5.670000076293945312 |        5.670000553131103516
>> q
```

The number before the character `|` is the anchor point, and the sequence after the character is the list of next floating-point numbers.

By specifying the command-line option `-i`, the program can enter the interactive mode. By keying in 'q' or 'quit', the program can leave the interactive mode.

## Author

Tche LIU, seistche@gmail.com, USTC
