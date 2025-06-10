build:
	gcc src/*.c -o svc -I include/ -L lib/x64 -lSDL3 -lwinmm -mwindows src/fuck.res
whatTheFuck:
	candle.exe src\svc.wxs -out src\wix\svc.wixobj
	light.exe -out src\msi\svc.msi src\wix\svc.wixobj
res:
	windres src\fuck.rc -O coff -o src\fuck.res
