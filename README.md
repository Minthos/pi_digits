# pi_digits
A simple program to compare the decimals of pi starting at the Nth decimal with the number N

The digits of pi should be provided by the user in a text file. The path to the file should be the command line argument. The file should begin with `3.1415`.

To generate digits of pi, I recommend using the program "y-cruncher". Here is an example command to generate the first 10 billion digits using 8 GB of RAM and a single swap drive (takes several hours on my computer):
`./y-cruncher custom pi -dec:10b -mode:swap -M:8g -swap:raid0 /media/minthos/bluechip/ycs-10b`

The python version is very simple and has the filename hardcoded. It uses more memory than the C version but isn't significantly slower.
