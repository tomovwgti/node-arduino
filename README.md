## Arduinoをhttpから制御する
=====

JenkinsのステータスをArduinoに出力したい(未完成)

#### スクリプトの使い方
```
$ ./status.sh e  # error
$ ./status.sh g  # start
$ ./status.sh s  # success
$ ./status.sh r  # reset
```

#### インストール情報

```
express -e node-arduino
npm install -g serialport

```

