# OOOOOLD
软件工程基础-个人项目-数独的生成与求解
使用方式：
  1.创建数独终局
    使用命令行调用: sudoku.exe -c num
       num为你想要创建的数独终局的数量：1~1000000
       运行结果会以createSudoku.txt的形式保存在程序的同级目录下
  2.解数独题目
    使用命令行调用：sudoku.exe -s path
        path为你保存数独题目的路径
        运行结果会以solveSudoku.txt的形式保存在程序的同级目录下
