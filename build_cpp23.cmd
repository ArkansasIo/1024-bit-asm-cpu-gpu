@echo off
setlocal

set "VCVARS=C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
set "CMAKE_EXE=C:\Program Files\CMake\bin\cmake.exe"
set "ALT_NINJA=C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja\ninja.exe"
set "NINJA_EXE=%ALT_NINJA%"

if not exist "%VCVARS%" (
  echo vcvars64.bat not found.
  exit /b 1
)

if not exist "%CMAKE_EXE%" (
  echo cmake.exe not found.
  exit /b 1
)

if not exist "%NINJA_EXE%" (
  echo ninja.exe not found.
  exit /b 1
)

call "%VCVARS%" >nul
if errorlevel 1 exit /b 1

"%CMAKE_EXE%" -S "%~dp0cpp23" -B "%~dp0cpp23\build-ninja" -G Ninja -DCMAKE_MAKE_PROGRAM="%NINJA_EXE%" -DCMAKE_C_COMPILER=cl.exe -DCMAKE_CXX_COMPILER=cl.exe
if errorlevel 1 exit /b 1

"%CMAKE_EXE%" --build "%~dp0cpp23\build-ninja"
if errorlevel 1 exit /b 1

echo Build complete.
