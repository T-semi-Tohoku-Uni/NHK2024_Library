# サンプルコードの動かし方

ビルド
今のディレクトリで次のコマンドを実行する
```
gcc -o clip_number_example.out ../../src/clip_number.c clip_number_example.c -I ../../src 
```
実行
```
./clip_number_example.out 
```

出力結果
```
❯ ./clip_number_example.out // <-コマンドの入力
clip_int_number(10, 0, 5) = 5
clip_double_number(10.000000, 0.000000, 5.000000) = 5.000000
clip_zero_one(10.000000, 0.000000, 5.000000) = 1.000000
clip_zero_one(2.500000, 0.000000, 5.000000) = 0.500000
```