# depends:
# 	vcpkg integrate install
# 	vcpkg install

build_debug:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
	cmake --build build -j 16 --config Debug 
	cmake --install build

build_release:
	cmake -S . -B target/release -DCMAKE_BUILD_TYPE=Release
	cmake --build target/release --config Release -j 16
	cmake --install target/release
	
run_debug:
	./target/build/qtvtk

run_release:
	./target/release/qtvtk
