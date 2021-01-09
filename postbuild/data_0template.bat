@echo off

SET PATH=%PATH%;%CD%

del /Q /F release
mkdir release

call log building world.res...
if exist world.res del /Q /F world.res >nul
if exist world\data.bin del /Q /F world\data.bin >nul
if exist tmp_world rmdir /S /Q tmp_world >nul

copy /Y _data\data_0template.xml world\data.xml >nul

databin2xml.exe "world\data.xml" world\data.bin
mkdir tmp_world
mkdir tmp_world\data
copy world\*.* tmp_world\data >nul
del /Q /F tmp_world\data\data.xml >nul
res.exe ar world.res world tmp_world >nul
del /Q /F world\data.bin >nul

if exist _data\world.res del /Q /F _data\world.res >nul
move /Y world.res _data >nul

call log done!
rem pause
exit
