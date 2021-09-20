@echo off

rem You can change your compile flag
set flags=g++ -std=c++11 -o "%1" "%1.cpp" -DLOCAL -Wall -Wextra -Wfatal-errors -Wunused-variable -pedantic -Wfloat-equal
echo %flags%

echo.
%flags%
echo.

if errorlevel 1 (
  echo Compilation failed
  exit /b 1
)
echo Compilation finished successfully
echo.
