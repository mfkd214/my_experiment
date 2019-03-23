# Mac(Late 2008 El Capitan)にESP8266_RTOS_SDKをインストール

人からもらった古めのMacにインストールしてみた。

## 参考
- https://github.com/espressif/ESP8266_RTOS_SDK
- https://qiita.com/tyone/items/de413db7763826d4fc02

## インストール

基本的に参考のURL(GitHub側)にのっとって、インストールすれば良い。

1. ツールチェーンをダウンロードして展開したのち、フォルダ内のbinにパスを通す。

2. ESP8266_RTOS_SDKを入手し、パスを通す。

パスは.bash_profileとかに書いておくと後々良い。

## サンプル実行

とりあえず、ESP8266_RTOS_SDK内にサンプルがあり、参考URLにも書いてあるので試す。基本、ターミナル操作。

1.  ESP8266を接続し、シリアルポート確認。

2.  /examples/get-started/project_templateに移動して make manuconfigし、シリアルポートを設定

3.  make all でコンパイル

4.  make flash で書き込み。

5.  make monitorでシリアルモニタの表示。

## その他

- パスを通し忘れると、コンパイルエラー
- デバイスへのアップロードツールがpythonでできていて、pyserialが入ってないとmake all だか make flashでエラーこく。pyserial入れるためにpipしようとするも、俺のMacじゃpython3.4かpython3.5じゃなきゃだめだと怒られたので、pyenvで2.7.13を入れ、上位ディレクトリでlocal設定してpipでpyserial入れたらflushできた。
https://github.com/espressif/esptool/issues/350
- make monitorでシリアルモニタ表示するも、文字化け。原因はmenuconfigでシリアルモニタのレートを115200にしたせい。起動時のシリアルポートの速度は 74880bps らしいので748800に戻す。アップロードのレートじゃなく、モニタのレートなので間違わないように。
- make flash monitorでアップロード->シリアルモニタ表示を一発でやってくれるので便利。
- というか、ハードル高め。当然かもしれないけどArduinoIDEでライブラリ使ってみたいなお手軽さはないので学習コストはそれなりにかかる見込み。
