rm a.out
rm windows/a.exe
make
chmod a+x a.out
make a.exe
mv a.exe windows/
./a.out