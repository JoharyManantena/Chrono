@REM @echo off

rem Compile
g++ -Ilib/sfml/include -Ilib/libpq -c src/main.cpp

rem Link
g++ main.o -o rallye -Llib/libpq -lpq -Llib/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

.\rallye
pause