
from conans import ConanFile, CMake, tools

class AdaptiveFiniteElementSolver(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package"

    def requirements(self):
        self.requires('zlib/[>=1.2.11]@conan/stable')
        self.requires('libpng/[>=1.6.37]@bincrafters/stable')
        self.requires('libjpeg/9c@bincrafters/stable')

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="lib", src="lib")
        self.copy('*.so*', dst='lib', src='lib')