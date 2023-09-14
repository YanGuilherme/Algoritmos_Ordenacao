@echo off

rem Apagar arquivos .o e .exe na pasta raiz
del *.o *.exe /s /q

rem Apagar arquivos .o e .exe no subdiretório insertion_sort/
del insertion_sort\*.o /s /q
del Algoritmos\*.o /s /q
for /r %%d in (.) do (
   rd "%%d" 2>nul
)
