@echo off

rem Apagar arquivos .o e .exe na pasta raiz
del *.o *.exe /s /q

rem Apagar arquivos .o e .exe no subdiretório insertion_sort/
del insertion_sort\*.o insertion_sort\*.exe /s /q

for /r %%d in (.) do (
   rd "%%d" 2>nul
)
