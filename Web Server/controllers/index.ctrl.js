'use strict';

var SerialPort = require('serialport');


module.exports.main = function (req, res, next) {
    res.sendFile('./public')
};