#include <iostream>
#include <fstream>
#include <string>

class CodeGenerator {
public:
    CodeGenerator(const std::string& className, const std::vector<std::string>& memberVariables)
        : className(className), memberVariables(memberVariables) {}

    void generateCode() {
        std::ofstream outputFile(className + ".cpp");

        if (outputFile.is_open()) {
            generateHeader(outputFile);
            generateImplementation(outputFile);

            std::cout << "Code generation successful. Check " << className << ".cpp file.\n";
        } else {
            std::cerr << "Unable to open file for code generation.\n";
        }
    }

private:
    void generateHeader(std::ofstream& outputFile) {
        outputFile << "#ifndef " << className << "_H\n";
        outputFile << "#define " << className << "_H\n\n";
        outputFile << "#include <iostream>\n\n";
        outputFile << "class " << className << " {\n";
        outputFile << "public:\n";

        for (const auto& variable : memberVariables) {
            outputFile << "    " << variable << ";\n";
        }

        outputFile << "\n";
        outputFile << "    " << className << "();\n";
        outputFile << "    ~" << className << "();\n\n";

        outputFile << "private:\n";
        for (const auto& variable : memberVariables) {
            outputFile << "    " << variable << ";\n";
        }

        outputFile << "};\n\n";
        outputFile << "#endif // " << className << "_H\n";
    }

    void generateImplementation(std::ofstream& outputFile) {
        outputFile << "#include \"" << className << ".h\"\n\n";
        outputFile << className << "::" << className << "() {\n";
        for (const auto& variable : memberVariables) {
            outputFile << "    // Initialize " << variable << "\n";
        }
        outputFile << "}\n\n";

        outputFile << className << "::~" << className << "() {\n";
        outputFile << "    // Destructor implementation\n";
        outputFile << "}\n";
    }

    std::string className;
    std::vector<std::string> memberVariables;
};

int main() {
    std::vector<std::string> variables = { "int x;", "double y;", "std::string name;" };
    CodeGenerator generator("MyClass", variables);
    generator.generateCode();

    return 0;
}
