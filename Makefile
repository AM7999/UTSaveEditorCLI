compileLinux:
	rm -rf ./build && mkdir ./build
	g++ ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/bin/UTSaveEditorCLI.x86_64

runLinux:
	rm -rf ./build && mkdir ./build
	g++ ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/bin/UTSaveEditorCLI.x86_64
	./build/UTSaveEditorCLI.x86_64

packageDebian:
	mkdir -p ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/usr/bin
	mkdir -p ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/DEBIAN
	g++ ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/bin/UTSaveEditorCLI
	cp ./build/bin/UTSaveEditorCLI ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/usr/bin
	cp ./build/Resources/control ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/DEBIAN
	dpkg-deb --build ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0

clean:
	rm -rf ./build/bin/*