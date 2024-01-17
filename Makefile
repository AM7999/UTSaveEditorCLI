compileLinux:
	rm -rf ./build && mkdir ./build
	g++ ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/UTSaveEditorCLI.x86_64

runLinux:
	rm -rf ./build && mkdir ./build
	g++ ./UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./build/UTSaveEditorCLI.x86_64
	./build/UTSaveEditorCLI.x86_64

packageDebian:
	mkdir UTSaveEditorCLI_amd64_1.0
	cd UTSaveEditorCLI_amd64_1.0
	mkdir data
	cd data
	mkdir bin
	cd bin
	g++ ../../../UTSaveEditorCLI/UTSaveEditorCLI.cpp -o ./UTSaveEditor
	cd ../..

clean:
	rm -rf ./build