## Arduinoをコマンドライン経由で制御する
=====

#### 目的
JenkinsのステータスをArduinoに出力したい

Node.jsサーバを作成して、node-serial経由で制御するという回り道...

#### Arduinoの制御の方法
下記のようなコマンドをJenkinsのシェルスクリプト実行で投げてやる

```
$ curl http://localhost:3000/status?status=e  # error
$ curl http://localhost:3000/status?status=g  # start
$ curl http://localhost:3000/status?status=s  # success
$ curl http://localhost:3000/status?status=r  # reset
```

#### インストール情報

```
$ express -e node-arduino
$ npm install -g serialport #node-serialportはグローバルインストールとしてある
$ npm link serialport でリンク作成
```
