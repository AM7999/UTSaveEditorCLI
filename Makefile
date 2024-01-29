compileLinux:
	rm -rf ./build/bin && mkdir -p ./build/bin
	g++ -s ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/bin/UTSaveEditorCLI.x86_64

runLinux:
	rm -rf ./build/bin && mkdir -p ./build/bin
	g++ -s ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/bin/UTSaveEditorCLI.x86_64
	./build/bin/UTSaveEditorCLI.x86_64

packageDebian:
	mkdir -p ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/usr/bin
	mkdir -p ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/DEBIAN
	g++ -s ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/bin/UTSaveEditorCLI
	cp ./build/bin/UTSaveEditorCLI ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/usr/bin
	cp ./build/Resources/control ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0/DEBIAN
	dpkg-deb --build ./build/bin/pkg/UTSaveEditorCLI_amd64_1.0

clean:
	rm -rf ./build/bin/*