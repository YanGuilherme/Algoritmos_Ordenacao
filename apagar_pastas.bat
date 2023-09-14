
@echo off
cd Algoritmos/
for /d %%i in (*) do (
    echo Apagando pastas em %%i
    rmdir /s /q "%%i\arquivos_entrada"
    rmdir /s /q "%%i\arquivos_saida"
    rmdir /s /q "%%i\arquivos_tempo"
)