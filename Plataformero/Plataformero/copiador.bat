@echo off

set solutiondir=%1
set target=%2

echo Copiando archivos...

xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-window-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-system-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\SFML-2.5.1\bin\sfml-graphics-d-2.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\STP\bin\STP-d.dll" "%target%" /E /Y /S
xcopy "%solutiondir%libs\STP\bin\zlibd.dll" "%target%" /E /Y /S

echo Copia finalizada
