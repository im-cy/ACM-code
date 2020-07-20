@echo off
:loop
rand
std
naive
fc naive.out std.out 
if not errorlevel 1 goto loop
pause
goto loop