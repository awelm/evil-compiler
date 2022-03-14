# evil-compiler
An evil compiler that adds undetectable backdoors into programs it compiles

# Verifying the Backdoor For Yourself
1. Verify for yourself that the [Login program](https://github.com/awelm/evil-compiler/blob/master/Login.cpp) only authorizes the password "test123"
2. Clone this repo and compile the Login program from source using `./Compiler Login.cpp -o Login`.
3. Run the login program with `./Login` and then enter the password "backdoor". You should be successfully logged in.

# Backdoor Still Exists When You Recompile The Compiler
Follow the steps below to verify this backdoor still exists even when you recompile the compiler from clean source:
1. Verify that [Compiler.cpp](https://github.com/awelm/evil-compiler/blob/master/Compiler.cpp) is clean (don't worry it's just a 10-line wrapper over g++)
2. Recompile the compiler from source using `./Compiler Compiler.cpp -o cleanCompiler`
3. Now use the clean compiler to compile the Login program with `./cleanCompiler Login.cpp -o Login`
4. Run the login program with `./Login` and verify the "backdoor" password still works.
