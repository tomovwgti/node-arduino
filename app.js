/**
 * Module dependencies.
 */

var express = require('express')
    , routes = require('./routes')
    , path = require('path')
    , serialport = require('serialport');


var app = express()
    , http = require('http')
    , server = http.createServer(app)
    , io = require('socket.io').listen(server);

// Serial Port
var portName = '/dev/tty.usbmodemfd13431'; // Mac環境
var sp = new serialport.SerialPort(portName, {
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
    parser: serialport.parsers.readline("\n")
});

app.configure(function(){
    app.set('port', process.env.PORT || 3000);
    app.set('views', __dirname + '/views');
    app.set('view engine', 'ejs');
    app.use(express.favicon());
    app.use(express.logger('dev'));
    app.use(express.bodyParser());
    app.use(express.methodOverride());
    app.use(express.cookieParser('your secret here'));
    app.use(express.session());
    app.use(app.router);
    app.use(express.static(path.join(__dirname, 'public')));
});

app.configure('development', function(){
    app.use(express.errorHandler());
});

// Routes
app.get('/', routes.index);
server.listen(app.get('port'));

// クライアントが接続してきたときの処理
io.sockets.on('connection', function(socket) {
    console.log("connection");

});

sp.on('close', function(err) {
    console.log('port closed');
});

sp.on('open', function(err) {
    console.log('port opened');
});

// Web APIエントリポイント
app.get('/status', function(req, res) {

    res.writeHead(200, {'Content-Type':'text/html; charset=utf-8'});
    res.end('OK');

    var msg = new Object();
    msg.status = req.query.status;
    console.log('status ' + msg.status);

    sp.write(msg.status, function(err, bytesWritten) {
        console.log('bytes written: ', bytesWritten);
    });
});