## Arduinoをシェルスクリプトで制御する
=====

JenkinsのステータスをArduinoに出力したい(未完成)

Node.jsサーバを作成して、node-serial経由で制御するという回り道...

#### スクリプトの使い方
```
$ ./status.sh e  # error
$ ./status.sh g  # start
$ ./status.sh s  # success
$ ./status.sh r  # reset
```

#### インストール情報

```
$ express -e node-arduino
$ npm install -g serialport としてある
$ npm link serialport でリンク作成
```

