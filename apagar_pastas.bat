@echo off
cd Arquivos_IO/
for /d %%i in (*) do (
    echo Apagando pastas em %%i
    rmdir /s /q "%%i"
)
