# evil-compiler
An evil compiler that adds undetectable backdoors into programs it compiles. See my [blog post](https://www.awelm.com/posts/evil-compiler) for more details

# Verifying the Backdoor For Yourself
Clone this repo and do the following:
1. First verify for yourself that this simple [Login.cpp program](https://github.com/awelm/evil-compiler/blob/master/Login.cpp) only accepts the password "test123"
2. Use the evil compiler to compile the Login program with `./Compiler Login.cpp -o Login`
3. Run the login program with `./Login` and then enter the password "backdoor". You should be successfully logged in.

# Backdoor Still Exists When You Recompile The Compiler
A cautious user may decide to read and recompile the evil compiler’s source code before using it. Try the following and see for yourself that the “backdoor” password still works.
1. Verify that [Compiler.cpp](https://github.com/awelm/evil-compiler/blob/master/Compiler.cpp) is clean (don't worry it's just a 10-line wrapper over g++)
2. Recompile the compiler from source using `./Compiler Compiler.cpp -o cleanCompiler`
3. Use the clean compiler to compile the Login program with `./cleanCompiler Login.cpp -o Login`
4. Run the login program with `./Login` and verify the "backdoor" password still works.
