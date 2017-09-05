var express = require('express');
var router = express.Router();

var board = require('../controllers/board.ctrl');

/* GET home page. */
router.get('/toglleLED/:color', board.toggleLED);
router.get('/cycle/:amount', board.cycle);

module.exports = router;
