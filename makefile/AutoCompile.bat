@echo off

g++ -I../include ../src/*.cpp -o ../output/EDC_App.exe

if %ERRORLEVEL% NEQ 0 (
    echo Error en la compilación. Verifica el código.
    pause
    exit
)


cls
color a

echo.
echo Termino la Compilacion Correctamente !!
echo.


start ../output/EDC_App.exe

