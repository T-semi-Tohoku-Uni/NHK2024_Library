# NHK2024_Library

## 作ったライブラリたち
### PID
格納場所 : `src/pid.c` \
サンプルコード : `example/pid/pid.c`

### 移動平均フィルタ
格納場所 : `src/filter.c` \
サンプルコード : `example/filter/moving_average_filter.c`

### クリップ関数
内容 : 最小値と最大値の間に丸める（センサに使えるかも）\
格納場所 : `stc/clip_number.c` \
サンプルコード : `example/clip_number/clip_number.c`

## 注意
STM32CubeIDEでこのリポジトリを使う場合は以下の点に注意してください.

### インクルードパスの設定
1. STM32CubeIDEの`Core/Src`ディレクトリで右クリック
2. `Properties`を選択
3. `C/C++ General`を開き, `Path and Symbols`を選択
4. ここにライブラリのパスを追加する.(例: `Core/NHK2024Library`)
5. 次に, ライブラリのディレクトリを右クリック
6. `Add/remove include Path`を選択し, `Debug`, `Release`ともにチェックマークをつけてOKで閉じる
7. ビルドする（`Project` -> `Build All`）　

### ビルドの設定
`example`ディレクトリ内のサンプルコードをビルドすると, エラーが生じる可能性があるので, ビルドツリーから削除してください. \
手順は 
1. STM32CubeIDEの左の画面（Project Exproler）で`example`ディレクトリを右クリック 
2. `Resoruse Configuration`を選択
3. `Exclude from build`を選択
4. `Debug`と`Release`にチェックを入れる