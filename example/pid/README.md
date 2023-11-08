# サンプルコードの動かし方
プラントが積分器の場合の趣味レーション \


ビルド
```
gcc -o pid_program.out ../../src/pid.c pid.c -I ../../src
```
実行
```
./pid_program.out
```

`pid_output.csv`が出力されるのでグラフで表示させてみる.

![](pid_output.png)