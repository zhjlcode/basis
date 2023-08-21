# 语法特性
- 基本语法：指令(参数1 参数2...)
  - 参数使用括弧括起
  - 参数之间用空格或者逗号分隔

- 指令是大小写无关的，参数和变量区分大小写
    ``` cmake
    set(HELLO hello.cpp)
    add_excutable(hello main.cpp hello.cpp)
    ADD_excutable(hello main.cpp ${HELLO})
    ```

 - 注意：变量使用${}方式取值，但在if语句中是直接使用变量名
    ``` cmake
    if($VARIABLE) # error
    if(VARIABLE) # yes
    ```

# 重要指令
    ``` c
    # 指定CMake的最小版本要求
    cmake_minimum_required  
    语法：cmake_minimum_required(VERSION versionNumber [FATAL_ERROR]) 

    # 定义工程名称，并可指定工程支持的语言 
    project 
    语法：project(projectname [CXX] [C] [Java]) 

    # 显式的定义变量 
    set 
    语法：set(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]]) 

    # 向工程添加多个特定的头文件搜索路径 -> 相当于指定g++编译器的-I参数
    include_directories
    语法：include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)

    # - 向工程添加多个特定的库文件搜索路径 -> 相当于指定g++编译器的-L参数
    link_directories 
    语法： link_directories(dir1 dir2 ...) 

    # 生成库文件
    add_library 
    语法： add_library(libname [SHARED|STATIC|MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)

    # 添加编译参数
    add_compile_options 
    语法：add_compile_options(-Wall -O2 -std=c++11)

    # 生成可执行文件
    add_executable
    语法：add_executable(exename source1 source2 ... sourceN)

    # 为target添加需要链接的共享库 --->相同于指定g++编译器-l参数
    target_link_libraries 
    语法： target_link_libraries(target library1<debug | optimized> library2...) 

    # 向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置 
    add_subdirectory 
    语法： add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL]) 

    # - 发现一个目录下所有的源代码文件并将列表存储在一个变量中，这个指令临时被用来自动构建源文件列表 
    aux_source_directory 
    语法： aux_source_directory(dir VARIABLE) 
    ```

# 常用变量
- 编译选项
    ``` cmake
    CMAKE_C_FLAGS gcc编译选项
    CMAKE_CXX_FLAGS g++编译选项
    CMAKE_BUILD_TYPE 编译类型(Debug, Release)
    CMAKE_C_COMPILER：指定C编译器
    CMAKE_CXX_COMPILER：指定C++编译器
    ``` sh
- 文件、目录
    ``` cmake
    # 输入输出路径
    EXECUTABLE_OUTPUT_PATH：可执行文件输出的存放路径
    LIBRARY_OUTPUT_PATH：库文件输出的存放路径
    
    # 工程目录 
    CMAKE_BINARY_DIR 
    PROJECT_BINARY_DIR
    _BINARY_DIR
    1. 这三个变量指代的内容是一致的。
    2. 如果是in source build，指的就是工程顶层目录。
    3. 如果是out-of-source编译,指的是工程编译发生的目录。
    4. PROJECT_BINARY_DIR跟其他指令稍有区别，不过现在，你可以理解为他们是一致的。
- 代码例子
    ``` cmake
    # 编译main.cpp生成可执行文件main
    add_executable(main main.cpp)

    # 将hello动态库文件链接到可执行文件main
    target_link_libraries(main hello)

    # 添加src子目录，src中需有一个CMakeLists.txt
    add_subdirectory(src)

    # 定义SRC变量，其值为当前目录下所有的源代码文件
    aux_source_directory(.SRC)

    # 编译SRC变量所代表的源代码文件，生成main可执行文件
    add_executable(main ${SRC})

    # 在CMAKE_CXX_FLAGS编译选项后追加-std=c++11
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

    # 设定编译类型为debug，调试时需要选择debug
    set(CMAKE_BUILD_TYPE Debug)
    # 设定编译类型为release，发布时需要选择release
    set(CMAKE_BUILD_TYPE Release)

    # 
    CMAKE_SOURCE_DIR
    PROJECT_SOURCE_DIR
    _SOURCE_DIR
    1. 这三个变量指代的内容是一致的,不论采用何种编译方式,都是工程顶层目录。
    2. 也就是在 in source build时,他跟 CMAKE_BINARY_DIR 等变量一致。
    3. PROJECT_SOURCE_DIR 跟其他指令稍有区别,现在,你可以理解为他们是一致的。
    ```   