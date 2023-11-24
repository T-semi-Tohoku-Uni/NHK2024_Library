# NHK2024_Library

## 作ったライブラリたち
### PID
格納場所 : `src/pid.c` \
サンプルコード : `example/pid/pid.c`

### 移動平均フィルタ
格納場所 : `src/filter.c` \
サンプルコード : `example/filter/moving_average_filter.c`

## 注意
STM32CubeIDEでこのリポジトリを使う場合は以下の点に注意してください.
### インクルードパスの設定

### ビルドの設定
`example`ディレクトリ内のサンプルコードをビルドすると, エラーが生じる可能性があるので, ビルドツリーから削除してください. \
手順は 
1. STM32CubeIDEの左の画面（Project Exproler）で`example`ディレクトリを右クリック 
2. `Resoruse Configuration`を選択
3. `Exclude from build`を選択
4. `Debug`と`Release`にチェックを入れる