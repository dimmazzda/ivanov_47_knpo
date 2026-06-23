@echo off
chcp 65001 >nul

set "OPENCPP=C:\Program Files\OpenCppCoverage\OpenCppCoverage.exe"
set "SOURCES=C:\new_repos\ivanov_47_knpo"
set "MODULES=C:\new_repos\ivanov_47_knpo\Debug"
set "OUTPUT=C:\coverDirectory"

:: Проверка существования OpenCppCoverage
if not exist "%OPENCPP%" (
    echo [ОШИБКА] OpenCppCoverage не найден: %OPENCPP%
    pause
    exit /b 1
)

:: Проверка существования внутреннего bat-файла
if not exist "run_tests.bat" (
    echo [ОШИБКА] Файл run_tests.bat не найден в текущей папке
    pause
    exit /b 1
)

:: Создание папки для отчёта
if not exist "%OUTPUT%" mkdir "%OUTPUT%"

:: Запуск OpenCppCoverage
"%OPENCPP%" ^
    --sources "%SOURCES%" ^
    --modules "%MODULES%" ^
    --cover_children ^
    --export_type html:"%OUTPUT%" ^
    -- cmd /c run_tests.bat

echo.
echo ========================================
echo Отчёт о покрытии создан!
echo Откройте: %OUTPUT%\index.html
echo ========================================
pause