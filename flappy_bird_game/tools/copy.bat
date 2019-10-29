@echo  off

copy %1 %3 /y
xcopy %2 %3 /s /y

echo archivos copiados