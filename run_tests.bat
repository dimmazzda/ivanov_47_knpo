@echo off
set "PROGRAM=C:\new_repos\ivanov_47_knpo\Debug\ivanov_47_knpo.exe"
set "TESTS=C:\new_repos\ivanov_47_knpo\tests"
set "RESULTS=C:\new_repos\ivanov_47_knpo\results"

if not exist "%RESULTS%" mkdir "%RESULTS%"

for %%f in ("%TESTS%\*.txt") do (
    mkdir "%RESULTS%\%%~nf" 2>nul
    "%PROGRAM%" "%%f" "%RESULTS%\%%~nf\output.txt"
)