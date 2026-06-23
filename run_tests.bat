@echo off
chcp 65001 >nul
set "PROGRAM=C:\new_repos\ivanov_47_knpo\Debug\ivanov_47_knpo.exe"
set "TESTS=C:\new_repos\ivanov_47_knpo\tests"
set "RESULTS=C:\new_repos\ivanov_47_knpo\results"

if not exist "%RESULTS%" mkdir "%RESULTS%"

echo ========================================
echo Запуск обычных тестов (1-20)
echo ========================================

for %%f in ("%TESTS%\*.txt") do (
    mkdir "%RESULTS%\%%~nf" 2>nul
    "%PROGRAM%" "%%f" "%RESULTS%\%%~nf\output.txt"
)

echo.
echo ========================================
echo Дополнительные тесты на редкие ошибки
echo ========================================

:: Тест на inFileNotExist — несуществующий входной файл
echo [Специальный тест 1] Несуществующий входной файл
mkdir "%RESULTS%\special_nonexistent_input" 2>nul
"%PROGRAM%" "C:\this_path_does_not_exist\fake.txt" "%RESULTS%\special_nonexistent_input\output.txt"

:: Тест на createOutFileFail — попытка записать в несуществующий путь
echo [Специальный тест 2] Невозможный выходной путь
"%PROGRAM%" "%TESTS%\1.txt" "Z:\nonexistent_disk\fake\output.txt"


echo.
