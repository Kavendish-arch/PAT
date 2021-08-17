## Makefile的规则
```
        target ... : prerequisites ...
                command
                ...
                ...
 ```
        target也就是一个目标文件，可以是Object File，也可以是执行文件。还可以是一个标签（Label），对于标签这种特性，在后续的“伪目标”章节中会有叙述。
        prerequisites就是，要生成那个target所需要的文件或是目标。
        command也就是make需要执行的命令。（任意的Shell命令）
这是一个文件的依赖关系，target这一个或多个的目标文件依赖于prerequisites中的文件，其生成规则定义在command中
prerequisites中如果有一个以上的文件比target文件要新的话，command所定义的命令就会被执行，这就是Makefile的规则也是Makefile中最核心的内容。



例如
```
    edit : main.o kbd.o command.o display.o insert.o search.o files.o utils.o
            gcc -o edit main.o kbd.o command.o display.o insert.o search.o files.o utils.o
    main.o : main.c defs.h
            gcc -c main.c
    kbd.o : kbd.c defs.h command.h
            gcc -c kbd.c
    command.o : command.c defs.h command.h
            gcc -c command.c
    display.o : display.c defs.h buffer.h
            gcc -c display.c
    insert.o : insert.c defs.h buffer.h
            gcc -c insert.c
    search.o : search.c defs.h buffer.h
            gcc -c search.c
    files.o : files.c defs.h buffer.h command.h
            gcc -c files.c
    utils.o : utils.c defs.h
            gcc -c utils.c
    clean :
            rm edit main.o kbd.o command.o display.o insert.o search.o files.o utils.o
```
我们可以把这个内容保存在文件为Makefile或makefile的文件中，然后在该目录下直接输入命令“make”就可以生成执行文件edit。
要删除执行文件和所有的中间目标文件，执行一下make clean

在这个makefile中，目标文件（target）包含：执行文件edit和中间目标文件（*.o）
依赖文件（prerequisites）就是冒号后面的那些 .c 文件和 .h文件。
每一个 .o 文件都有一组依赖文件，而这些 .o 文件又是执行文件 edit 的依赖文件。
依赖关系的实质上就是说明了目标文件是由哪些文件生成的，换言之，目标文件是哪些文件更新的。

在定义好依赖关系后，定义了如何生成目标文件的操作系统命令，
一定要以一个Tab键作为开头。记住，make并不管命令是怎么工作的，
他只管执行所定义的命令。make会比较targets文件和prerequisites文件的修改日期，
如果prerequisites文件的日期要比targets文件的日期要新，或者target不存在的话，那么，make就会执行后续定义的命令。

这里要说明一点的是，clean不是一个文件，它只不过是一个动作名字，有点像C语言中的lable一样，其冒号后什么也没有，
那么，make就不会自动去找文件的依赖性，也就不会自动执行其后所定义的命令。要执行其后的命令，就要在make命令后明显得指出这个lable的名字。
这样的方法非常有用，我们可以在一个makefile中定义不用的编译或是和编译无关的命令，比如程序的打包，程序的备份，等等。
