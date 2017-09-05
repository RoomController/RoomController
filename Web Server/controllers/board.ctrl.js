'use strict';

// Requireing Stuffs
var SerialPort = require('serialport');
var consts = require('../config/consts');

// Setting up serial port
var port = new SerialPort(consts.ARDUINO_COM, {
    baudRate: 9600
});


module.exports.toggleLED = function (req, res, next) {
    var ledId = req.params.color;
    console.log(ledId);
    port.write(ledId.toString(), 'ASCII', function () {
        res.send("Writing successful")
    });
};

module.exports.cycle = function (req, res) {

    for (var i = 0; i < req.params.amount; i++) {
        for (let j = 0; j < 6; j++) {
            setTimeout(function () {
                toggleLED(j)
            }, 1500);
        }
    }

    if (i == req.params.amount) {

        // Shut down all leds
        port.write("o", 'ASCII');
        res.send("Success");
    }
};

module.exports.displayMsg = function (req, res) {

    var msg = req.body.msg;
    var msgSplited = msg.match(/.{1,32}/g)
    for (let msgA in msgSplited) {
        setTimeout(function () {
            port.write(msgSplited[msgA], 'ASCII');
        }, 10000);
    }


};

function toggleLED(ledId) {
    port.write(ledId.toString(), 'ASCII');
    setTimeout(function () {
        port.write(ledId.toString(), 'ASCII');
    }, 1000);
    port.flush();
};

module.exports.shutdown = function (req, res) {
    port.write("o", 'ASCII');
    res.send("Shutdown all")
};