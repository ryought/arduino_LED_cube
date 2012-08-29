##Arduino_LED_cube
###概要
LEDを立方体状につなげたLEDcubeをArduinoで制御します
任意のパターンを点灯できます。ぐちゃぐちゃです。なんとかします
###環境
Arduino uno (Atmega328p)で製作

pin0~15が行　pin16~19が列（層指定）

ダイナミック点灯方式


###使い方
Arduino IDE 1.0推奨

* `pattern[]` 
	* 点灯パターン定義ファイル（配列）
	* すべてのパターンファイルが一緒になっちゃってる。大きくなってきたら分離してもいいかも
	* int型にする必要があるのかどうかは不明
	* **1で点灯、0で消灯**です。
* `loop`　
	* メインループ　Arduinoに転送して実行するとここがループ実行される
* `floors(FLOOR)`
	* 共通GNDの設定。**FLOOR**は何列目（何層目）を点灯させるかを設定
* `patterns(PATTERN_NUMBER)`
	* パターン点灯用。
	* **PATTERN_NUMBER**の番号のパターン定義ファイルを反映する。
* `surface(PATTERN, FLOOR)`
	* 指定のパターン**PATTERN**を、指定の列・層**FLOOR**に適用する。
	* 列が不規則に動く場合などに便利かも？
* `turn_light(BEGIN_NUMBER)`
	* 上から見てぐるっと一周するパターン
	* パターンの番号は**BEGIN_NUMBER**で指定可能。
* `wipe_plate(DELAY_TIME)`
	* 全点灯パターン(No.8)を縦に一列づつスライドする感じ。
	* パターン番号は適宜読み替えて下さい
	
	
	
###todo
* ちょっと環境依存なところあるから直す
* もうちょっと整理する