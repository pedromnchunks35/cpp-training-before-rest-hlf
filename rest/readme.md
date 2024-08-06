# Info
- Prototype for creating a REST API using CPP beast from boost library
- In order to start constructing we must download the beast librarie
- After we download it there is a .sh file in it that we must run
- After running it it says for for ./p2
- It will install all boost dependencies
- In the end we can assign it in the CMakeLists 
- We should change the current path and create a standard path where we can place our C++ libraries
# Notes
- Our vscode detects the code using `.vscode` config
- In the `c_cpp_properties.json` we must put in the include settings the path to our headers in order for it to detect it
- In the google test it was detecting it because the folder was on our workspace so it could use it there
- Thats why i putted `/home/pedromn35/cpp-libraries/boost_1_85_0/*` in our include so it could detect it without problems
- Intellisense uses this headers files which are interfaces to know which methods it can invoke to make the autocomplete